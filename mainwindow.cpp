#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>
#include <QInputDialog>
#include <QWebFrame>

#define CENTER_OF_TEXTBOX_X 180
#define CENTER_OF_TEXTBOX_Y 400
#define CENTER_OF_LOG_X 180
#define CENTER_OF_LOG_Y 540

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView->setUrl(QUrl("http://l4cs.jpn.org/gikopoi/flash/gikopoi133_gen/flash_gikopoi.html"));
//    connect(ui->webView, SIGNAL(loadFinished(bool)), this, SLOT(lol()));
    connect(ui->actOptions, SIGNAL(triggered()), this, SLOT(showConfiguration()));
    connect(ui->actSwitchKeepaliveMode, SIGNAL(triggered(bool)), this, SLOT(switchKeepaliveMode(bool)));
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

void MainWindow::switchKeepaliveMode(bool enable)
{
//    if (enable)
//        QMessageBox::information(this, "true", "true");
//    else
//        QMessageBox::information(this, "false", "false");

//    sendMessage(NULL);
//    int x = QInputDialog::getInteger(this, "x", "x");
//    int y = QInputDialog::getInteger(this, "y", "y");

//    clickInPage(x, y);
//    QMessageBox::information(this, "fatto", "fatto");
    qDebug() << "ho cliccato";

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
//   QApplication::sendEvent(ui->webView->page(), &ev1);
   QApplication::sendEvent(ui->webView, &ev1);
   QKeyEvent ev2(QEvent::KeyRelease,
                 key,
                 keyboardModifiers);
//   QApplication::sendEvent(ui->webView->page(), &ev2);
   QApplication::sendEvent(ui->webView, &ev2);
}


void MainWindow::showConfiguration()
{
    sendMessage("lol");
}

MainWindow::~MainWindow()
{
    delete ui;
}
