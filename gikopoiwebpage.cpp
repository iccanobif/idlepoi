#include "gikopoiwebpage.h"
#include <QMessageBox>
#include <QDesktopServices>
#include <QDebug>

GikopoiWebPage::GikopoiWebPage(QObject *parent) :
    QWebPage(parent)
{
    diskCache = new QNetworkDiskCache();
    diskCache->setCacheDirectory(QDesktopServices::storageLocation(QDesktopServices::CacheLocation) + "/gikopoiClientCache");

    accessManager = new QNetworkAccessManager();
    accessManager->setCache(diskCache);

    setNetworkAccessManager(accessManager);

    settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, false);

    networkRequest = new QNetworkRequest();
    networkRequest->setUrl(QUrl("http://l4cs.jpn.org/gikopoi/"));

    mainFrame()->load(*networkRequest);
}

bool GikopoiWebPage::acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, NavigationType type)
{
    QRegExp regex("^http://l4cs\\.jpn\\.org/r\\.cgi\\?u=");
    if (request.url().toString().contains(regex))
    {
        QString urlToOpen = request.url().toString().replace(regex, "");
        qDebug() << urlToOpen;
        QDesktopServices::openUrl(QUrl(urlToOpen));
    }

    return true;
}
