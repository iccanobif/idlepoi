#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>
#include <QInputDialog>
#include <QtWebKit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    timer = new QTimer();

    ui->setupUi(this);

    connect(ui->actKeepalive, SIGNAL(toggled(bool)), this, SLOT(switchKeepalive(bool)));
    connect(ui->webView, SIGNAL(loadFinished(bool)), this, SLOT(togliBlank(bool)));
    connect(timer, SIGNAL(timeout()), this, SLOT(doKeepalive()));

    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView->setUrl(QUrl("http://l4cs.jpn.org/gikopoi/"));
}

void MainWindow::doKeepalive()
{
    sendMessage("");
}

void MainWindow::clickInPage(int x, int y)
{
    QMouseEvent ev1(QEvent::MouseButtonPress,
                   QPoint(x, y),
                   Qt::LeftButton,
                   Qt::LeftButton,
                   Qt::NoModifier);
    QApplication::sendEvent(ui->webView, &ev1);
    QMouseEvent ev2(QEvent::MouseButtonRelease,
                   QPoint(x, y),
                   Qt::LeftButton,
                   Qt::LeftButton,
                   Qt::NoModifier);
    QApplication::sendEvent(ui->webView, &ev2);
}

void MainWindow::sendMessage(const QString& msg)
{
    QWebFrame* frame = ui->webView->page()->mainFrame();
    frame->evaluateJavaScript(QString("DocumentGetElementFromName('gikopoi').JSCallBackSendMessage('%1');").arg(msg));
}

void MainWindow::pressKeyInPage(int key, Qt::KeyboardModifiers keyboardModifiers)
{
   QKeyEvent ev1(QEvent::KeyPress,
                 key,
                 keyboardModifiers);
   QApplication::sendEvent(ui->webView, &ev1);
   QKeyEvent ev2(QEvent::KeyRelease,
                 key,
                 keyboardModifiers);
   QApplication::sendEvent(ui->webView, &ev2);
}


void MainWindow::switchKeepalive(bool b)
{
    if (b)
    {
        ui->actKeepalive->setText("Stop keepalive");
        timer->setInterval(10 * 60 * 1000); //10 minutes
        timer->start();
    }
    else
    {
        ui->actKeepalive->setText("Start keepalive");
        timer->stop();
    }
}

void MainWindow::togliBlank(bool ok) {
    if (!ok) {
        return;
    }

    QWebFrame* frame = ui->webView->page()->mainFrame();
    if (frame!=NULL) {
        QWebElementCollection collection = frame->findAllElements("a[target=_blank]");
        foreach (QWebElement element, collection) {
            element.setAttribute("target", "_self");
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
