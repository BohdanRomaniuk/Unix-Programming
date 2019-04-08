#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databaselogger.h"
#include "oldestfoldersearcher.h"
#include "searchresult.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_chooseDirButton_clicked()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->selectedDir->setText(dirPath);
}

void MainWindow::on_pushButton_4_clicked()
{
    QString dirPath = ui->selectedDir->text();
    QDir dir(dirPath);
    if(!dir.exists())
    {
        QMessageBox box;
        box.setText("Folder doesn't exist");
        box.exec();

        return;
    }

    OldesttFolderSearcher searcher(&dir, new DatabaseLogger("MyProgramLog.db"));
    SearchResult result = searcher.findOldestDir();
    ui->oldestDirName->setText(result.getDirName());
    ui->oldestDirCreateDate->setText(result.getDirCreateDate().toString());
}
