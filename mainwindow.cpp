#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>
#include <QInputDialog>
#include <QWebFrame>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView->setUrl(QUrl("http://l4cs.jpn.org/gikopoi/flash/gikopoi134_for/flash_gikopoi.html"));
    timer = new QTimer();

    connect(ui->actKeepalive, SIGNAL(toggled(bool)), this, SLOT(switchKeepalive(bool)));
    connect(timer, SIGNAL(timeout()), this, SLOT(doKeepalive()));
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

MainWindow::~MainWindow()
{
    delete ui;
}
