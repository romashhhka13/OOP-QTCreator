#include "DialogIlichev.h"
#include "ui_DialogIlichev.h"


QString sportsman_to_string(std::shared_ptr<Sportsman> sportsman)
{
    QStringList data = sportsman->get_data();
    return QString("%1 %2").arg(data[0]).arg(data[1]);
}


DialogIlichev::DialogIlichev(QWidget *parent, std::shared_ptr<SportsmansGroup> group)
    : QDialog(parent)
    , SG(group)
    , ui(new Ui::DialogIlichev)
{
    ui->setupUi(this);

    for (auto sportsman : SG->get_group())
        ui->listWidget->addItem(sportsman_to_string(sportsman));

    ui->listWidget->setCurrentRow(0);
    update_controls();
}


DialogIlichev::~DialogIlichev()
{
    delete ui;
}

void DialogIlichev::on_addButton_clicked()
{
    AddDialog dlg(this);
    connect(&dlg, &AddDialog::element_added, this, &DialogIlichev::add_element_to_list);
    dlg.exec();
}

void DialogIlichev::add_element_to_list(std::shared_ptr<Sportsman> s){
    SG->add_sportsman(s);
    ui->listWidget->addItem(sportsman_to_string(s));
    ui->listWidget->setCurrentRow(SG->get_size() - 1);
}

void DialogIlichev::edit_element(QStringList& data) {
    int currentRow = ui->listWidget->currentRow();
    std::shared_ptr<Sportsman> current_s = SG->get_sportsman(currentRow);
    current_s->update(data);
    ui->listWidget->item(currentRow)->setText(sportsman_to_string(current_s));
    on_listWidget_currentRowChanged(currentRow);


}

void DialogIlichev::on_deleteButton_clicked()
{
    int currentRow = ui->listWidget->currentRow();
    if(currentRow < 0)
        return;
    int nextRow = currentRow == (SG->get_size() - 1) ? currentRow - 1 : currentRow;
    delete ui->listWidget->takeItem(currentRow);
    SG->delete_sportsman(currentRow);
    ui->listWidget->setCurrentRow(nextRow);
    update_controls();
}

void DialogIlichev::on_editButton_clicked()
{
    int currentRow = ui->listWidget->currentRow();

    if (currentRow < 0 or currentRow >= SG->get_size()) {
        QMessageBox::critical(this, "Ошибка", "Спортмен не выбран");
        return;
    }

    AddDialog dlg(this, false);

    connect(this, &DialogIlichev::get_element, &dlg, &AddDialog::fill_in_fields);
    connect(&dlg, &AddDialog::element_edited, this, &DialogIlichev::edit_element);

    std::shared_ptr<Sportsman> s = SG->get_sportsman(currentRow);
    emit get_element(s);

    dlg.exec();
}

void DialogIlichev::on_listWidget_currentRowChanged(int currentRow)
{
    if(currentRow < 0 || currentRow >= SG->get_size())
        return;

    QStringList data = SG->get_sportsman(currentRow)->get_data();

    ui->lineEdit1->setText(data[0]);
    ui->lineEdit2->setText(data[1]);
    ui->lineEdit3->setText(data[2]);
    ui->lineEdit4->setText(data[3]);

    if (std::shared_ptr<Footballer> s = std::dynamic_pointer_cast<Footballer>(SG->get_sportsman(currentRow))) {
        ui->lineEdit5->show();
        ui->lineEdit6->show();
        ui->number->show();
        ui->position->show();
        ui->lineEdit5->setText(data[4]);
        ui->lineEdit6->setText(data[5]);
    }
    else {
        ui->lineEdit5->hide();
        ui->lineEdit6->hide();
        ui->number->hide();
        ui->position->hide();
        ui->lineEdit5->setText("");
        ui->lineEdit6->setText("");
    }
}

void DialogIlichev::update_controls() {
    bool show = SG->object_exist();
    ui->deleteButton->setEnabled(show);
    if (!show){
        ui->lineEdit1->setText("");
        ui->lineEdit2->setText("");
        ui->lineEdit3->setText("");
        ui->lineEdit4->setText("");
        ui->lineEdit5->setText("");
        ui->lineEdit6->setText("");
        ui->lineEdit5->hide();
        ui->lineEdit6->hide();
        ui->position->hide();
        ui->number->hide();
    }
    update();
}



