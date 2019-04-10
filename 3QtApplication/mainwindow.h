#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUndoStack>
#include <QUndoCommand>
#include <QLineEdit>
#include "databaselogger.h"
#include "tests.h"
#include "oldestfoldersearcher.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_chooseDirButton_clicked();

    void on_pushButton_4_clicked();

    void on_chooseDirButton2_clicked();

    void showFilesInDirectory(QString dirPath);

    void on_removeSimilarButton_clicked();

    void on_runTestsButton1_clicked();

    void on_runTestsButton2_clicked();

    void on_redoButton1_clicked();

    void on_undoButton1_clicked();

    void on_undoButton2_clicked();

    void on_redoButton2_clicked();

private:
    Ui::MainWindow *ui;
    DatabaseLogger* _logger;
    Tests* _tests;
    QUndoStack* _undoStack1;
    QUndoStack* _undoStack2;

    //First task undo
    QString oldDirPath1;
    QString newDirPath1;

    //Second task undo
    QFileInfoList oldFiles;
    QFileInfoList newFiles;
};

#endif // MAINWINDOW_H
