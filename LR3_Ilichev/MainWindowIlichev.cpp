#include "MainWindowIlichev.h"
#include "./ui_MainWindowIlichev.h"


MainWindowIlichev::MainWindowIlichev(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowIlichev)
{
    ui->setupUi(this);
}


MainWindowIlichev::~MainWindowIlichev()
{
    delete ui;
}


void MainWindowIlichev::on_actionOpen_triggered()
{
    QString path = QDir::currentPath() + "/../../.data";
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть"), path, tr("Файл (*.txt)"));
    if (!fileName.isEmpty())
        ui->my_widget->load(fileName);
}


void MainWindowIlichev::on_actionSaveAs_triggered()
{
    QString path = QDir::currentPath() + "/../../.data";
    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить как"), path, tr("Файл (*.txt)"));
    ui->my_widget->save(fileName);
}


void MainWindowIlichev::on_actionClear_triggered()
{
    ui->my_widget->clear();
}


