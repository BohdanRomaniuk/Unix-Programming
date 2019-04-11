#include <QFileDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QPainter>
#include <QCheckBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databaselogger.h"
#include "oldestfoldersearcher.h"
#include "repeatingfilesremover.h"
#include "searchresult.h"
#include "oldestsearchcommand.h"
#include "repeatingremovecommand.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _logger = new DatabaseLogger("MyProgramLog.db");
    _tests = new Tests(_logger);
    _undoStack1 = new QUndoStack();
    _undoStack2 = new QUndoStack();

    QStyleOptionButton opt;
    opt.state = QStyle::State_Active | QStyle::State_Enabled;
    opt.rect = QRect(50, 25, 100, 50);
    QPainter painter(ui->removeSimilarButton);
    ui->tab1->style()->drawControl(QStyle::CE_PushButton, &opt, &painter, ui->removeSimilarButton);
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
    oldDirPath1 = newDirPath1;
    newDirPath1 = ui->selectedDir->text();
    auto command = new SearchOldestFolderCommand(oldDirPath1, newDirPath1, ui->selectedDir, ui->oldestDirName, ui->oldestDirCreateDate, _logger);
    _undoStack1->push(command);
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
    auto command = new RepeatingRemoveCommand(ui->selectedDir2->text(), ui->allowedExtension->text(), ui->tableView, _logger);
    _undoStack2->push(command);
}

void MainWindow::on_runTestsButton1_clicked()
{
    _tests->runFirstTaskTests();
}


void MainWindow::on_runTestsButton2_clicked()
{
    _tests->runSecondTaskTests();
}

void MainWindow::paintEvent(QPaintEvent * event)
{
    QStyleOptionButton opt;
    opt.state = QStyle::State_Active | QStyle::State_Enabled;
    opt.rect = QRect(0, 0, 10, 10);
    QPainter painter(this);
    style()->drawControl(QStyle::CE_PushButton, &opt, &painter, this);

    QPalette pal1 = ui->pushButton_4->palette();
    pal1.setColor(QPalette::Button, QColor(Qt::green));
    ui->pushButton_4->setAutoFillBackground(true);
    ui->pushButton_4->setPalette(pal1);
    ui->pushButton_4->update();

    QPalette pal2 = ui->removeSimilarButton->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::red));
    ui->removeSimilarButton->setAutoFillBackground(true);
    ui->removeSimilarButton->setPalette(pal2);
    ui->removeSimilarButton->update();
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

void MainWindow::on_undoButton1_clicked()
{
    _undoStack1->undo();
}

void MainWindow::on_redoButton1_clicked()
{
    _undoStack1->redo();
}

void MainWindow::on_undoButton2_clicked()
{
    _undoStack2->undo();
}

void MainWindow::on_redoButton2_clicked()
{
    _undoStack2->redo();
}
