#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtGui>
#include "gikopoiwebpage.h"

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

    void clickInPage(int x, int y);
    void pressKeyInPage(int key, Qt::KeyboardModifiers keyboardModifiers);

private slots:
    void sendMessage(const QString& msg);
    void toggleKeepalive(bool b);
    void toggleAfk(bool b);
    void doKeepalive();
    void togliBlank(bool ok);
    void btnRefreshClicked();
};

#endif // MAINWINDOW_H
