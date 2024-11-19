#pragma once

#include <QDialog>
#include <QMessageBox>
#include <QIntValidator>
#include <memory>
#include <format>

#include "SportsmansGroup.h"
#include "Sportsman.h"
#include "Footballer.h"
#include "Addition.h"

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr, bool is_added = true);
    ~AddDialog();

public slots:
    void fill_in_fields(std::shared_ptr<Sportsman> s);

private slots:
    void on_addButton_clicked();

    void on_radioButton1_toggled(bool checked);

    void on_radioButton2_toggled(bool checked);

signals:
    void element_added(std::shared_ptr<Sportsman> s);
    void element_edited(QStringList& data);

private:
    bool check_is_empty();
    bool is_added;
    Ui::AddDialog *ui;
};

