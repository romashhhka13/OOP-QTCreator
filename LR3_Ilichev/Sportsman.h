#pragma once

#include <string>
#include <numeric>
#include <iostream>

#include <QPainter>
#include <QString>
#include <QSize>
#include <QVector>

#include "Serialize.h"


class Sportsman
{
public:

    Sportsman();
    static void reset_maxID();

    //Методы для отрисовки и вычисления размеров текстового блока
    virtual QStringList get_data() const;
    void draw(QPainter* painter, int x, int& y, QVector<int>& column_widths, int padding, int height) const;
    QVector<int> get_column_widths(QPainter* painter) const;

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& id;
        ar& surname;
        ar& name;
        ar& age;
        ar& height;
    }

// protected:
    std::string surname;
    std::string name;
    int id;
    int age;
    int height;
    static int max_id;
};


