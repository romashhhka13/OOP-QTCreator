#pragma once

#include <QMainWindow>
#include <QFileDialog>
#include <fstream>


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

private:
    Ui::MainWindowIlichev *ui;
};

