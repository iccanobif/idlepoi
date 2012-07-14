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
    ui->setupUi(this);

    timer = new QTimer();

    connect(ui->btnToggleKeepalive, SIGNAL(toggled(bool)), this, SLOT(toggleKeepalive(bool)));
    connect(ui->btnToggleAfk, SIGNAL(toggled(bool)), this, SLOT(toggleAfk(bool)));
    connect(ui->webView, SIGNAL(loadFinished(bool)), this, SLOT(togliBlank(bool)));
    connect(timer, SIGNAL(timeout()), this, SLOT(doKeepalive()));

    ui->webView->setPage(new GikopoiWebPage());
}

void MainWindow::doKeepalive()
{
    if (ui->btnToggleAfk->isChecked())
        sendMessage(ui->txtAfkMessage->text());
    else
        sendMessage("");
}

void MainWindow::sendMessage(const QString& msg)
{
    QWebFrame* frame = ui->webView->page()->mainFrame();
    frame->evaluateJavaScript(QString("DocumentGetElementFromName('gikopoi').JSCallBackSendMessage('%1');").arg(msg));
}

void MainWindow::toggleAfk(bool b)
{
    ui->btnToggleKeepalive->setEnabled(!b);

    if (b)
        sendMessage(ui->txtAfkMessage->text());
    else
        sendMessage("");
}

void MainWindow::toggleKeepalive(bool b)
{
    ui->btnToggleAfk->setEnabled(b);

    if (b)
    {
        ui->btnToggleKeepalive->setText("Stop keepalive");
        timer->setInterval(10 * 60 * 1000); //10 minutes
        timer->start();
    }
    else
    {
        ui->btnToggleKeepalive->setText("Start keepalive");
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

//void linkClicked(const QString& url)
//{
//    QMessageBox::information(ui, "lol", url);
//}

MainWindow::~MainWindow()
{
    delete ui;
}
