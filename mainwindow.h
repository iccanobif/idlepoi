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
    void sendMessage(const QString& msg);
    void pressKeyInPage(int key, Qt::KeyboardModifiers keyboardModifiers);

private slots:
    void toggleKeepalive(bool b);
    void toggleAfk(bool b);
    void doKeepalive();
    void togliBlank(bool ok);
    void btnRefreshClicked();
//    void checkMessageMaxLength();
};

#endif // MAINWINDOW_H
