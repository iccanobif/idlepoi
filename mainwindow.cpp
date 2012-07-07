#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>
#include <QInputDialog>
#include <QtWebKit>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer();

    diskCache = new QNetworkDiskCache();
    diskCache->setCacheDirectory(QDesktopServices::storageLocation(QDesktopServices::CacheLocation) + "/gikopoiClientCache");
    qDebug() << diskCache->cacheDirectory();

    accessManager = new QNetworkAccessManager();
    accessManager->setCache(diskCache);

    networkRequest = new QNetworkRequest();
    networkRequest->setUrl(QUrl("http://l4cs.jpn.org/gikopoi/"));

    connect(ui->actKeepalive, SIGNAL(toggled(bool)), this, SLOT(switchKeepalive(bool)));
    connect(ui->webView, SIGNAL(loadFinished(bool)), this, SLOT(togliBlank(bool)));
    connect(timer, SIGNAL(timeout()), this, SLOT(doKeepalive()));

    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView->page()->setNetworkAccessManager(accessManager);
    ui->webView->load(*networkRequest);
}

void MainWindow::doKeepalive()
{
    sendMessage("");
}

void MainWindow::sendMessage(const QString& msg)
{
    QWebFrame* frame = ui->webView->page()->mainFrame();
    frame->evaluateJavaScript(QString("DocumentGetElementFromName('gikopoi').JSCallBackSendMessage('%1');").arg(msg));
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
