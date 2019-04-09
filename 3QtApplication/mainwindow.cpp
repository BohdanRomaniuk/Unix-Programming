#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databaselogger.h"
#include "oldestfoldersearcher.h"
#include "repeatingfilesremover.h"
#include "searchresult.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QModelIndex>>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _logger = new DatabaseLogger("MyProgramLog.db");
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
        box.setText("Folder " + dirPath + " doesn't exist");
        box.exec();

        return;
    }

    OldesttFolderSearcher searcher(&dir, _logger);
    SearchResult result = searcher.findOldestDir();
    ui->oldestDirName->setText(result.getDirName());
    ui->oldestDirCreateDate->setText(result.getDirCreateDate().toString());
}

void MainWindow::on_chooseDirButton2_clicked()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->selectedDir2->setText(dirPath);

    showFilesInDirectory(dirPath);
}

void MainWindow::on_removeSimilarButton_clicked()
{
    QString dirPath = ui->selectedDir2->text();
    QDir dir(dirPath);
    if(!dir.exists())
    {
        QMessageBox box;
        box.setText("Folder " + dirPath + " doesn't exist");
        box.exec();

        return;
    }

    RepeatingFilesRemover remover(&dir, _logger);
    int removed = remover.removeSimilar(ui->allowedExtension->text());

    QMessageBox box;
    box.setText("Removed " + QString::number(removed) + " files");
    box.exec();

    showFilesInDirectory(dirPath);
}

void MainWindow::showFilesInDirectory(QString dirPath)
{
    QStandardItemModel* model = new QStandardItemModel();
    QStandardItem* item;
    QStringList cells;
    cells.append("Path");
    cells.append("Filename");
    cells.append("Ext");
    cells.append("Create date");

    model->setHorizontalHeaderLabels(cells);

    QDir dir(dirPath);
    QFileInfoList files = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
    int i=0;
    foreach(QFileInfo file, files)
    {
        item = new QStandardItem(QString(file.absoluteFilePath()));
        model->setItem(i,0,item);
        item = new QStandardItem(QString(file.fileName()));
        model->setItem(i,1,item);
        item = new QStandardItem(QString(file.suffix()));
        model->setItem(i,2,item);
        item = new QStandardItem(QString(file.lastModified().toString()));
        model->setItem(i,3,item);
        ++i;
    }

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}
