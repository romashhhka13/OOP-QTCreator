#include "AddDialog.h"
#include "ui_AddDialog.h"


AddDialog::AddDialog(QWidget *parent, bool is_added)
    : QDialog(parent)
    , is_added(is_added)
    , ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    ui->lineEdit3->setValidator(new QIntValidator(0, 100, this));
    ui->lineEdit4->setValidator(new QIntValidator(0, 100, this));
    ui->lineEdit5->setValidator(new QIntValidator(0, 100, this));
    ui->radioButton1->setChecked(true);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::fill_in_fields(std::shared_ptr<Sportsman> s)
{
    QStringList data = s->get_data();

    ui->lineEdit1->setText(data[0]);
    ui->lineEdit2->setText(data[1]);
    ui->lineEdit3->setText(data[2]);
    ui->lineEdit4->setText(data[3]);

    if (std::shared_ptr<Footballer> f = std::dynamic_pointer_cast<Footballer>(s)) {
        ui->lineEdit5->setText(data[4]);
        ui->lineEdit6->setText(data[5]);
        ui->radioButton1->setEnabled(false);
        ui->radioButton2->toggled(true);
        ui->radioButton2->setChecked(true);
    }
    else {
        ui->lineEdit5->setText("");
        ui->lineEdit6->setText("");
        ui->radioButton2->setEnabled(false);
        ui->radioButton1->toggled(true);
        ui->radioButton1->setChecked(true);
    }
}

void AddDialog::on_addButton_clicked()
{

    if (!check_is_empty())
        return;

    QString surname = ui->lineEdit1->text();
    QString name = ui->lineEdit2->text();
    QString age = ui->lineEdit3->text();
    QString height = ui->lineEdit4->text();

    if (ui->radioButton1->isChecked()) {
        if (is_added) {
            std::shared_ptr<Sportsman> s = std::make_shared<Sportsman>();
            s->set_surname(surname);
            s->set_name(name);
            s->set_age(age.toInt());
            s->set_height(height.toInt());
            emit element_added(s);
        }
        else {
            QStringList data = {surname, name, age, height};
            emit element_edited(data);
        }
    }
    else {
        QString number = ui->lineEdit5->text();
        QString position = ui->lineEdit6->text();
        if (is_added) {
            std::shared_ptr<Footballer> f = std::make_shared<Footballer>();
            f->set_surname(surname);
            f->set_name(name);
            f->set_age(age.toInt());
            f->set_height(height.toInt());
            f->set_number(number.toInt());
            f->set_position(position);
            emit element_added(f);
        } else {
            QStringList data = {surname, name, age, height, number, position};
            emit element_edited(data);
        }
    }
    this->accept();
}



void AddDialog::on_radioButton1_toggled(bool checked)
{
    if (checked) {
        ui->lineEdit5->hide();
        ui->lineEdit6->hide();
        ui->number->hide();
        ui->position->hide();
    }
}


void AddDialog::on_radioButton2_toggled(bool checked)
{
    if (checked) {
        ui->lineEdit5->show();
        ui->lineEdit6->show();
        ui->number->show();
        ui->position->show();
    }
}

bool AddDialog::check_is_empty()
{
    if (ui->lineEdit1->text().isEmpty() ||
        ui->lineEdit2->text().isEmpty() ||
        ui->lineEdit3->text().isEmpty() ||
        ui->lineEdit4->text().isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Не все поля заполнены!");
        return false;
    }

    if (ui->radioButton1->isChecked())
        return true;

    if (ui->lineEdit5->text().isEmpty() ||
        ui->lineEdit6->text().isEmpty()) {
            QMessageBox::critical(this, "Ошибка", "Не все поля заполнены!");
            return false;
        }

    return true;
}

