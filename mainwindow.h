#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QNetworkDiskCache>
#include <QNetworkAccessManager>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QTimer* timer;
    QNetworkDiskCache* diskCache;
    QNetworkAccessManager* accessManager;
    QNetworkRequest* networkRequest;
    void clickInPage(int x, int y);
    void sendMessage(const QString& msg);
    void pressKeyInPage(int key, Qt::KeyboardModifiers keyboardModifiers);

private slots:
    void switchKeepalive(bool b);
    void doKeepalive();
    void togliBlank(bool ok);
};

#endif // MAINWINDOW_H
