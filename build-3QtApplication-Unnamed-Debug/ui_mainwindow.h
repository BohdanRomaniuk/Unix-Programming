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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *selectedDir;
    QPushButton *chooseDirButton;
    QPushButton *redoButton1;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *oldestDirName;
    QLabel *label_2;
    QLineEdit *oldestDirCreateDate;
    QPushButton *undoButton1;
    QPushButton *pushButton_4;
    QPushButton *runTestsButton1;
    QWidget *tab2;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *selectedDir2;
    QPushButton *chooseDirButton2;
    QLabel *allowedExt;
    QLineEdit *allowedExtension;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QPushButton *removeSimilarButton;
    QPushButton *redoButton2;
    QPushButton *undoButton2;
    QPushButton *runTestsButton2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 360);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        gridLayout_2 = new QGridLayout(tab1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(tab1);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        selectedDir = new QLineEdit(groupBox);
        selectedDir->setObjectName(QStringLiteral("selectedDir"));

        horizontalLayout_2->addWidget(selectedDir);

        chooseDirButton = new QPushButton(groupBox);
        chooseDirButton->setObjectName(QStringLiteral("chooseDirButton"));

        horizontalLayout_2->addWidget(chooseDirButton);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 5);

        redoButton1 = new QPushButton(tab1);
        redoButton1->setObjectName(QStringLiteral("redoButton1"));

        gridLayout_2->addWidget(redoButton1, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(tab1);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        oldestDirName = new QLineEdit(groupBox_2);
        oldestDirName->setObjectName(QStringLiteral("oldestDirName"));

        verticalLayout->addWidget(oldestDirName);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        oldestDirCreateDate = new QLineEdit(groupBox_2);
        oldestDirCreateDate->setObjectName(QStringLiteral("oldestDirCreateDate"));

        verticalLayout->addWidget(oldestDirCreateDate);


        gridLayout_2->addWidget(groupBox_2, 2, 0, 1, 5);

        undoButton1 = new QPushButton(tab1);
        undoButton1->setObjectName(QStringLiteral("undoButton1"));

        gridLayout_2->addWidget(undoButton1, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(tab1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_2->addWidget(pushButton_4, 0, 4, 1, 1);

        runTestsButton1 = new QPushButton(tab1);
        runTestsButton1->setObjectName(QStringLiteral("runTestsButton1"));

        gridLayout_2->addWidget(runTestsButton1, 0, 3, 1, 1);

        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        gridLayout = new QGridLayout(tab2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_3 = new QGroupBox(tab2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        selectedDir2 = new QLineEdit(groupBox_3);
        selectedDir2->setObjectName(QStringLiteral("selectedDir2"));

        horizontalLayout->addWidget(selectedDir2);

        chooseDirButton2 = new QPushButton(groupBox_3);
        chooseDirButton2->setObjectName(QStringLiteral("chooseDirButton2"));

        horizontalLayout->addWidget(chooseDirButton2);

        allowedExt = new QLabel(groupBox_3);
        allowedExt->setObjectName(QStringLiteral("allowedExt"));

        horizontalLayout->addWidget(allowedExt);

        allowedExtension = new QLineEdit(groupBox_3);
        allowedExtension->setObjectName(QStringLiteral("allowedExtension"));

        horizontalLayout->addWidget(allowedExtension);


        gridLayout->addWidget(groupBox_3, 3, 0, 1, 5);

        groupBox_4 = new QGroupBox(tab2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableView = new QTableView(groupBox_4);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_2->addWidget(tableView);


        gridLayout->addWidget(groupBox_4, 4, 0, 1, 5);

        removeSimilarButton = new QPushButton(tab2);
        removeSimilarButton->setObjectName(QStringLiteral("removeSimilarButton"));

        gridLayout->addWidget(removeSimilarButton, 0, 4, 1, 1);

        redoButton2 = new QPushButton(tab2);
        redoButton2->setObjectName(QStringLiteral("redoButton2"));

        gridLayout->addWidget(redoButton2, 0, 1, 1, 1);

        undoButton2 = new QPushButton(tab2);
        undoButton2->setObjectName(QStringLiteral("undoButton2"));

        gridLayout->addWidget(undoButton2, 0, 0, 1, 1);

        runTestsButton2 = new QPushButton(tab2);
        runTestsButton2->setObjectName(QStringLiteral("runTestsButton2"));

        gridLayout->addWidget(runTestsButton2, 0, 3, 1, 1);

        tabWidget->addTab(tab2, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Unix Programming", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Select directory", Q_NULLPTR));
        chooseDirButton->setText(QApplication::translate("MainWindow", "Choose direcotry", Q_NULLPTR));
        redoButton1->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Search results", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Oldest dir:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Creation date:", Q_NULLPTR));
        undoButton1->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        runTestsButton1->setText(QApplication::translate("MainWindow", "Run tests", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("MainWindow", "Find oldest dir", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Select directory", Q_NULLPTR));
        chooseDirButton2->setText(QApplication::translate("MainWindow", "Choose", Q_NULLPTR));
        allowedExt->setText(QApplication::translate("MainWindow", "Allowed ext", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Direcotry files", Q_NULLPTR));
        removeSimilarButton->setText(QApplication::translate("MainWindow", "Remove similar", Q_NULLPTR));
        redoButton2->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
        undoButton2->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        runTestsButton2->setText(QApplication::translate("MainWindow", "Run tests", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("MainWindow", "Delete files with the same name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
