/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox;
    QLineEdit *selectedDir;
    QPushButton *chooseDirButton;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLineEdit *oldestDirName;
    QLabel *label_2;
    QLineEdit *oldestDirCreateDate;
    QPushButton *pushButton_4;
    QWidget *tab2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 350);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 600, 350));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        pushButton_2 = new QPushButton(tab1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 10, 89, 25));
        pushButton_3 = new QPushButton(tab1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 10, 89, 25));
        groupBox = new QGroupBox(tab1);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 581, 61));
        selectedDir = new QLineEdit(groupBox);
        selectedDir->setObjectName(QStringLiteral("selectedDir"));
        selectedDir->setGeometry(QRect(10, 30, 431, 25));
        chooseDirButton = new QPushButton(groupBox);
        chooseDirButton->setObjectName(QStringLiteral("chooseDirButton"));
        chooseDirButton->setGeometry(QRect(450, 30, 121, 25));
        groupBox_2 = new QGroupBox(tab1);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 110, 581, 161));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 101, 17));
        oldestDirName = new QLineEdit(groupBox_2);
        oldestDirName->setObjectName(QStringLiteral("oldestDirName"));
        oldestDirName->setGeometry(QRect(10, 50, 561, 25));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 131, 17));
        oldestDirCreateDate = new QLineEdit(groupBox_2);
        oldestDirCreateDate->setObjectName(QStringLiteral("oldestDirCreateDate"));
        oldestDirCreateDate->setGeometry(QRect(10, 120, 561, 25));
        pushButton_4 = new QPushButton(tab1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(490, 10, 89, 25));
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        tabWidget->addTab(tab2, QString());
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Unix Programming", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Select directory", Q_NULLPTR));
        chooseDirButton->setText(QApplication::translate("MainWindow", "Choose direcotry", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Search results", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Oldest dir:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Creation date:", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("MainWindow", "Find oldest dir", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("MainWindow", "Delete files with the same name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
