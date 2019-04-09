#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databaselogger.h"

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

private:
    Ui::MainWindow *ui;
    DatabaseLogger* _logger;
};

#endif // MAINWINDOW_H
