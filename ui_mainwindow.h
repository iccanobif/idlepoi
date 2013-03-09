/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWebView *webView;
    QHBoxLayout *hboxLayout;
    QPushButton *btnToggleKeepalive;
    QPushButton *btnToggleAfk;
    QLabel *label;
    QLineEdit *txtAfkMessage;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnZoomIn;
    QPushButton *btnZoomOut;
    QPushButton *btnRefresh;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(954, 738);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        webView = new QWebView(centralWidget);
        webView->setObjectName(QStringLiteral("webView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy1);
        webView->setMinimumSize(QSize(680, 620));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        gridLayout->addWidget(webView, 2, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        btnToggleKeepalive = new QPushButton(centralWidget);
        btnToggleKeepalive->setObjectName(QStringLiteral("btnToggleKeepalive"));
        btnToggleKeepalive->setCheckable(true);
        btnToggleKeepalive->setChecked(true);

        hboxLayout->addWidget(btnToggleKeepalive);

        btnToggleAfk = new QPushButton(centralWidget);
        btnToggleAfk->setObjectName(QStringLiteral("btnToggleAfk"));
        btnToggleAfk->setEnabled(false);
        btnToggleAfk->setCheckable(true);

        hboxLayout->addWidget(btnToggleAfk);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        hboxLayout->addWidget(label);

        txtAfkMessage = new QLineEdit(centralWidget);
        txtAfkMessage->setObjectName(QStringLiteral("txtAfkMessage"));
        txtAfkMessage->setMaximumSize(QSize(200, 16777215));

        hboxLayout->addWidget(txtAfkMessage);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(horizontalSpacer);

        btnZoomIn = new QPushButton(centralWidget);
        btnZoomIn->setObjectName(QStringLiteral("btnZoomIn"));

        hboxLayout->addWidget(btnZoomIn);

        btnZoomOut = new QPushButton(centralWidget);
        btnZoomOut->setObjectName(QStringLiteral("btnZoomOut"));
        btnZoomOut->setMinimumSize(QSize(63, 0));
        btnZoomOut->setMaximumSize(QSize(16777215, 16777215));

        hboxLayout->addWidget(btnZoomOut);

        btnRefresh = new QPushButton(centralWidget);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));

        hboxLayout->addWidget(btnRefresh);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "idlepoi", 0));
        btnToggleKeepalive->setText(QApplication::translate("MainWindow", "Start keepalive", 0));
        btnToggleAfk->setText(QApplication::translate("MainWindow", "Afk", 0));
        label->setText(QApplication::translate("MainWindow", "Afk message:", 0));
        txtAfkMessage->setText(QApplication::translate("MainWindow", "afk", 0));
        btnZoomIn->setText(QApplication::translate("MainWindow", "+", 0));
        btnZoomOut->setText(QApplication::translate("MainWindow", "-", 0));
        btnRefresh->setText(QApplication::translate("MainWindow", "Refresh", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
