#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void clickInPage(int x, int y);
    void sendMessage(const QString& msg);
    void pressKeyInPage(int key, Qt::KeyboardModifiers keyboardModifiers);

private slots:
    void showConfiguration();
    void switchKeepaliveMode(bool enable);
};

#endif // MAINWINDOW_H
