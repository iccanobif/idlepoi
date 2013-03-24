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
    connect(ui->btnZoomIn, SIGNAL(clicked()), this, SLOT(btnZoomInClicked()));
    connect(ui->btnZoomOut, SIGNAL(clicked()), this, SLOT(btnZoomOutClicked()));
    connect(ui->btnRula, SIGNAL(clicked()), this, SLOT(btnRulaClicked()));
    connect(ui->btnList, SIGNAL(clicked()), this, SLOT(btnListClicked()));

    ui->btnToggleKeepalive->hide();
    ui->statusBar->hide();

    applicationSettings = new QSettings("iccanobif", "idlepoi");

    ui->webView->setPage(new GikopoiWebPage());

    QVariant zoomFactor = applicationSettings->value("zoomFactor");

    if (!zoomFactor.isNull())
        ui->webView->setZoomFactor(zoomFactor.toReal());

    toggleKeepalive(true);
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
    qDebug() << "Sending message " << msg;
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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnZoomInClicked()
{
    qreal newZoomFactor = ui->webView->zoomFactor() * 1.05;
    ui->webView->setZoomFactor(newZoomFactor);
    applicationSettings->setValue("zoomFactor", newZoomFactor);
}

void MainWindow::btnZoomOutClicked()
{
    qreal newZoomFactor = ui->webView->zoomFactor() * 0.95;
    ui->webView->setZoomFactor(newZoomFactor);
    applicationSettings->setValue("zoomFactor", newZoomFactor);
}

void MainWindow::btnRulaClicked()
{
    sendMessage("#rula");
}

void MainWindow::btnListClicked()
{
    sendMessage("#list");
}
