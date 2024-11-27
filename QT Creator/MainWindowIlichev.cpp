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
    if (!fileName.isEmpty()) {
        ui->my_widget->load(fileName);
    }
}


void MainWindowIlichev::on_actionSaveAs_triggered()
{
    QString path = QDir::currentPath() + "/../../.data";
    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить как"), path, tr("Файл (*.txt)"));
    ui->my_widget->save(fileName);
}


void MainWindowIlichev::on_actionClear_triggered(){
    ui->my_widget->clear();
}


void MainWindowIlichev::on_actionEdit_triggered()
{
    SportsmansGroup SG(ui->my_widget->get_SG());
    // clone(ui->my_widget->get_SG(), SG);
    std::shared_ptr<SportsmansGroup> SG_ptr = std::make_shared<SportsmansGroup>(SG);
    // std::shared_ptr<SportsmansGroup> SG = std::make_shared<SportsmansGroup>(ui->my_widget->get_SG());


    DialogIlichev dlg(this, SG_ptr);
    auto launch = dlg.exec();

    if (launch == QDialog::Accepted) {
        ui->my_widget->set_SG(dlg.get_SG());
        ui->my_widget->update();
        std::cout << "Accepted" << std::endl;
    }
    // else if (launch == QDialog::Rejected) {
    //     std::cout << "Rejected" << std::endl;
    // }
}

