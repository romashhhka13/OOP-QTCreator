#pragma once

#include <numeric>
#include <memory>

#include <QWidget>
#include <QPainter>
#include "SportsmansGroup.h"

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


private:
    SportsmansGroup SG;

signals:
};

