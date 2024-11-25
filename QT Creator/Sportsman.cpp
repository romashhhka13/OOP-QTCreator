#include "Sportsman.h"

BOOST_CLASS_VERSION(Sportsman, 1)

using namespace std;

int Sportsman::max_id = 1;

void Sportsman::reset_maxID()
{
    max_id = 1;
}

std::shared_ptr<Sportsman> Sportsman::clone() const{
    return std::make_shared<Sportsman>(*this);
}

void Sportsman::update(QStringList& data){
    surname = data[0].toLocal8Bit();
    name = data[1].toLocal8Bit();
    age = data[2].toInt();
    height = data[3].toInt();
}

QStringList Sportsman::get_data() const
{
    return QStringList({QString::fromLocal8Bit(surname.c_str()),
                        QString::fromLocal8Bit(name.c_str()),
                        QString::number(age),
                        QString::number(height)});
}

void Sportsman::draw(QPainter *painter, int x, int& y, QVector<int>& column_widths, int padding, int height) const {

    QStringList data = get_data();
    draw_table_row(painter, column_widths, data, x, y, padding, height);
    y += height;
}

QVector<int> Sportsman::get_column_widths(QPainter* painter) const
{
    QStringList data = get_data();
    QVector<int> widths(data.size(), 0);

    for (int i = 0; i < data.size(); i++)
        widths[i] = painter->fontMetrics().horizontalAdvance(data[i]);

    return widths;
}
