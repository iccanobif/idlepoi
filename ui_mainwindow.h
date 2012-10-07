/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 7. Oct 20:44:34 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>
#include <messagebox.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWebView *webView;
    MessageBox *txtMessageInput;
    QHBoxLayout *hboxLayout;
    QPushButton *btnToggleKeepalive;
    QPushButton *btnToggleAfk;
    QLabel *label;
    QLineEdit *txtAfkMessage;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRefresh;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(953, 738);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        webView = new QWebView(centralWidget);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setMinimumSize(QSize(680, 620));
        webView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout->addWidget(webView, 1, 0, 1, 1);

        txtMessageInput = new MessageBox(centralWidget);
        txtMessageInput->setObjectName(QString::fromUtf8("txtMessageInput"));

        gridLayout->addWidget(txtMessageInput, 1, 1, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        btnToggleKeepalive = new QPushButton(centralWidget);
        btnToggleKeepalive->setObjectName(QString::fromUtf8("btnToggleKeepalive"));
        btnToggleKeepalive->setCheckable(true);
        btnToggleKeepalive->setChecked(true);

        hboxLayout->addWidget(btnToggleKeepalive);

        btnToggleAfk = new QPushButton(centralWidget);
        btnToggleAfk->setObjectName(QString::fromUtf8("btnToggleAfk"));
        btnToggleAfk->setEnabled(false);
        btnToggleAfk->setCheckable(true);

        hboxLayout->addWidget(btnToggleAfk);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout->addWidget(label);

        txtAfkMessage = new QLineEdit(centralWidget);
        txtAfkMessage->setObjectName(QString::fromUtf8("txtAfkMessage"));
        txtAfkMessage->setMaximumSize(QSize(200, 16777215));

        hboxLayout->addWidget(txtAfkMessage);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(horizontalSpacer);

        btnRefresh = new QPushButton(centralWidget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));

        hboxLayout->addWidget(btnRefresh);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "idlepoi", 0, QApplication::UnicodeUTF8));
        btnToggleKeepalive->setText(QApplication::translate("MainWindow", "Start keepalive", 0, QApplication::UnicodeUTF8));
        btnToggleAfk->setText(QApplication::translate("MainWindow", "Afk", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Afk message:", 0, QApplication::UnicodeUTF8));
        txtAfkMessage->setText(QApplication::translate("MainWindow", "afk", 0, QApplication::UnicodeUTF8));
        btnRefresh->setText(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
