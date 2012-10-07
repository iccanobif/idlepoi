#include "messagebox.h"
#include <QDebug>
#include <QPlainTextEdit>

MessageBox::MessageBox(QWidget* parent) : QPlainTextEdit(parent)
{
}

void MessageBox::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter)
    {
        emit messageToSend(toPlainText());
        setPlainText("");
        return;
    }

    QString oldString = toPlainText();
    int oldCursorPosition = textCursor().position();

    QPlainTextEdit::keyPressEvent(e);

    if (this->toPlainText().length() > 500)
    {
        setPlainText(oldString);
        QTextCursor cur = textCursor();
        cur.setPosition(oldCursorPosition);
        setTextCursor(cur);
    }
}
