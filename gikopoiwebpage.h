#ifndef GIKOPOIWEBPAGE_H
#define GIKOPOIWEBPAGE_H

#include <QWebPage>
#include <QWebFrame>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkDiskCache>

class GikopoiWebPage : public QWebPage
{
    Q_OBJECT
public:
    explicit GikopoiWebPage(QObject *parent = 0);

private:
    QNetworkAccessManager* accessManager;
    QNetworkRequest* networkRequest;
    QNetworkDiskCache* diskCache;
    bool acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, NavigationType type);
    
signals:
    
public slots:
    
};

#endif // GIKOPOIWEBPAGE_H
