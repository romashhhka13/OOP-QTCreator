#pragma once

#include <numeric>
#include <memory>
#include <iostream>
#include <vector>
#include <fstream>

#include <QWidget>
#include <QPainter>

#include "SportsmansGroup.h"
#include "Sportsman.h"

class SportsmanWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SportsmanWidget(QWidget *parent = nullptr):
        QWidget(parent) {};

    void paintEvent(QPaintEvent* event) override;
    void load(const QString& path);
    void save(const QString& path);
    void clear();

    SportsmansGroup& get_SG() { return SG; }
    void set_SG(std::shared_ptr<SportsmansGroup> group) { SG = *group; };

private:
    SportsmansGroup SG;

signals:
};

