/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 9. Mar 20:45:02 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QSpacerItem>
#include <QStatusBar>
#include <QWidget>
#include <QtWebKit>
#include <QWebView>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QPushButton *btnToggleKeepalive;
    QPushButton *btnToggleAfk;
    QLabel *label;
    QLineEdit *txtAfkMessage;
    QLabel *label_2;
    QLabel *LblTimeLeft;
    QPushButton *btnSkipKeepalive;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRula;
    QPushButton *btnList;
    QPushButton *btnMove;
    QPushButton *btnZoomIn;
    QPushButton *btnZoomOut;
    QWebView *webView;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(953, 738);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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
        btnToggleAfk->setMaximumSize(QSize(50, 16777215));
        btnToggleAfk->setCheckable(true);

        hboxLayout->addWidget(btnToggleAfk);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout->addWidget(label);

        txtAfkMessage = new QLineEdit(centralWidget);
        txtAfkMessage->setObjectName(QString::fromUtf8("txtAfkMessage"));
        txtAfkMessage->setMaximumSize(QSize(200, 16777215));

        hboxLayout->addWidget(txtAfkMessage);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        hboxLayout->addWidget(label_2);

        LblTimeLeft = new QLabel(centralWidget);
        LblTimeLeft->setObjectName(QString::fromUtf8("LblTimeLeft"));

        hboxLayout->addWidget(LblTimeLeft);

        btnSkipKeepalive = new QPushButton(centralWidget);
        btnSkipKeepalive->setObjectName(QString::fromUtf8("btnSkipKeepalive"));
        btnSkipKeepalive->setMaximumSize(QSize(40, 16777215));

        hboxLayout->addWidget(btnSkipKeepalive);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(horizontalSpacer);

        btnRula = new QPushButton(centralWidget);
        btnRula->setObjectName(QString::fromUtf8("btnRula"));
        btnRula->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnRula->sizePolicy().hasHeightForWidth());
        btnRula->setSizePolicy(sizePolicy1);
        btnRula->setMaximumSize(QSize(50, 16777215));
        btnRula->setBaseSize(QSize(30, 0));

        hboxLayout->addWidget(btnRula);

        btnList = new QPushButton(centralWidget);
        btnList->setObjectName(QString::fromUtf8("btnList"));
        btnList->setMaximumSize(QSize(50, 16777215));

        hboxLayout->addWidget(btnList);

        btnMove = new QPushButton(centralWidget);
        btnMove->setObjectName(QString::fromUtf8("btnMove"));
        btnMove->setMaximumSize(QSize(50, 16777215));

        hboxLayout->addWidget(btnMove);

        btnZoomIn = new QPushButton(centralWidget);
        btnZoomIn->setObjectName(QString::fromUtf8("btnZoomIn"));
        btnZoomIn->setMaximumSize(QSize(50, 16777215));

        hboxLayout->addWidget(btnZoomIn);

        btnZoomOut = new QPushButton(centralWidget);
        btnZoomOut->setObjectName(QString::fromUtf8("btnZoomOut"));
        btnZoomOut->setMinimumSize(QSize(63, 0));
        btnZoomOut->setMaximumSize(QSize(50, 16777215));

        hboxLayout->addWidget(btnZoomOut);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 2);

        webView = new QWebView(centralWidget);
        webView->setObjectName(QString::fromUtf8("webView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy2);
        webView->setMinimumSize(QSize(680, 620));
        webView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout->addWidget(webView, 2, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "idlepoi 1.0.4", 0));
        btnToggleKeepalive->setText(QApplication::translate("MainWindow", "Start keepalive", 0));
        btnToggleAfk->setText(QApplication::translate("MainWindow", "Afk", 0));
        label->setText(QApplication::translate("MainWindow", "Afk message:", 0));
        txtAfkMessage->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Time until keepalive msg:", 0));
        LblTimeLeft->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        btnSkipKeepalive->setText(QApplication::translate("MainWindow", "Skip", 0));
        btnRula->setText(QApplication::translate("MainWindow", "#rula", 0));
        btnList->setText(QApplication::translate("MainWindow", "#list", 0));
        btnMove->setText(QApplication::translate("MainWindow", "#move", 0));
        btnZoomIn->setText(QApplication::translate("MainWindow", "+", 0));
        btnZoomOut->setText(QApplication::translate("MainWindow", "-", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
