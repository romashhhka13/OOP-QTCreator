#pragma once

#include <QMainWindow>
#include <QFileDialog>

#include "SportsmansGroup.h"
#include "DialogIlichev.h"
#include "Addition.h"
#include "Serialize.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowIlichev;
}
QT_END_NAMESPACE

class MainWindowIlichev : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowIlichev(QWidget *parent = nullptr);
    ~MainWindowIlichev();


private slots:
    void on_actionOpen_triggered();

    void on_actionSaveAs_triggered();

    void on_actionClear_triggered();

    void on_actionEdit_triggered();

private:
    Ui::MainWindowIlichev *ui;
};

