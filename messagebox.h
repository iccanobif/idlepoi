#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QPlainTextEdit>

class MessageBox : public QPlainTextEdit
{
    Q_OBJECT

public:
     MessageBox(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *e);

signals:
    void messageToSend(QString);
};

#endif // MESSAGEBOX_H
