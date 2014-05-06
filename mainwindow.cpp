#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>
#include <QInputDialog>
#include <QtWebKit>

#define DEFAULT_KEEPALIVE_DELAY 600 //10 minutes

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
    connect(ui->btnMove, SIGNAL(clicked()), this, SLOT(btnMoveClicked()));
    connect(ui->btnSkipKeepalive, SIGNAL(clicked()), this, SLOT(btnSkipClicked()));

    ui->btnToggleKeepalive->hide();
    ui->statusBar->hide();

//    applicationSettings = new QSettings("iccanobif", "idlepoi");
    applicationSettings = new QSettings("idlepoi.ini", QSettings::IniFormat);

    ui->webView->setPage(new GikopoiWebPage());

    QVariant zoomFactor = applicationSettings->value("zoomFactor");

    if (!zoomFactor.isNull())
        ui->webView->setZoomFactor(zoomFactor.toReal());

    QVariant keepAliveDelay = applicationSettings->value("keepAliveDelay");

    if (!keepAliveDelay.isNull())
        this->keepAliveDelay = keepAliveDelay.toInt();
    else
    {
        applicationSettings->setValue("keepAliveDelay", DEFAULT_KEEPALIVE_DELAY);
        this->keepAliveDelay = DEFAULT_KEEPALIVE_DELAY;
    }

    toggleKeepalive(true);
}

void MainWindow::updateTimerLabel()
{
    QString txt = QString::number(secondsLeft / 60) + ":" + QString("%1").arg(secondsLeft % 60, 2, 10, QChar('0'));

    ui->LblTimeLeft->setText(txt);

    if (secondsLeft <= 10)
        ui->LblTimeLeft->setStyleSheet("QLabel {color: red; }");
    else
        ui->LblTimeLeft->setStyleSheet("");
}

void MainWindow::doKeepalive()
{
    updateTimerLabel();

    if (secondsLeft-- > 0)
        return;

    secondsLeft = this->keepAliveDelay;

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
        secondsLeft = this->keepAliveDelay;

        ui->btnToggleKeepalive->setText("Stop keepalive");
        timer->setInterval(1000); //1 second
        timer->start();

        doKeepalive();
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

void MainWindow::btnMoveClicked()
{
    sendMessage("#move");
}

void MainWindow::btnSkipClicked()
{
    //I know, this is a pretty lazy way to do it, I'll figure out something better, sometime...
    toggleKeepalive(false);
    toggleKeepalive(true);
}
