#pragma once

#include <QDialog>
#include <QStringList>
#include <QMessageBox>
#include <vector>
#include <memory>

#include "Sportsman.h"
#include "Footballer.h"
#include "SportsmansGroup.h"
#include "AddDialog.h"


namespace Ui {
class DialogIlichev;
}

class DialogIlichev : public QDialog
{
    Q_OBJECT

public:
    explicit DialogIlichev(QWidget *parent, std::shared_ptr<SportsmansGroup> group);
    ~DialogIlichev();

    std::shared_ptr<SportsmansGroup> get_SG() { return SG; };

private slots:

    void on_addButton_clicked();

    void add_element_to_list(std::shared_ptr<Sportsman> s);

    void edit_element(QStringList& data);

    void on_deleteButton_clicked();

    void on_editButton_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

signals:
    void get_element(std::shared_ptr<Sportsman> s);

private:
    void update_controls();

    Ui::DialogIlichev *ui;
    std::shared_ptr<SportsmansGroup> SG;
};


