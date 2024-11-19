#pragma once

#include <string>
#include <numeric>
#include <iostream>

#include <QPainter>
#include <QString>
#include <QVector>

#include "Serialize.h"
#include "Addition.h"


class Sportsman
{
public:

    // Методы класса
    static void reset_maxID();
    virtual QStringList get_data() const;
    virtual std::shared_ptr<Sportsman> clone() const;
    virtual void update(QStringList& data);

    // Сеттеры
    void set_surname(QString surn) { surname = surn.toLocal8Bit(); };
    void set_name(QString n) { name = n.toLocal8Bit(); };
    void set_age(int a) { age = a; };
    void set_height(int h) { height = h; };

    //Методы для отрисовки и вычисления размеров ширины столюцов
    void draw(QPainter* painter, int x, int& y, QVector<int>& column_widths, int padding, int height) const;
    QVector<int> get_column_widths(QPainter* painter) const;

    // Конуструктор
    Sportsman() { id = max_id++; };

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

    std::string surname;
    std::string name;
    int id;
    int age;
    int height;
    static int max_id;
};


