#include "messagebox.h"
#include <QDebug>
#include <QPlainTextEdit>

MessageBox::MessageBox(QWidget* parent) : QPlainTextEdit(parent)
{
}

void MessageBox::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Return)
    {
//        emit messageToSend(toPlainText());
        setPlainText("");
        return;
    }

    QString oldString = toPlainText();
    int oldCursorPosition = textCursor().position();

    QPlainTextEdit::keyPressEvent(e);

    if (this->toPlainText().length() > 10)
    {
        setPlainText(oldString);
//        moveCursor(QTextCursor::MoveOperation);
        QTextCursor cur = textCursor();
        cur.setPosition(oldCursorPosition);
        setTextCursor(cur);

//        setTextCursor();
    }


}
