#include "Sportsman.h"

BOOST_CLASS_VERSION(Sportsman, 1)

using namespace std;


int Sportsman::max_id = 1;


void Sportsman::reset_maxID()
{
    max_id = 1;
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

    for (int i = 0; i < column_widths.size(); i++){
        QRect cell(x, y, column_widths[i] + padding * 4, height);
        painter->drawRect(cell);

        QRect padded_cell = cell.adjusted(padding, 0, 0, 0);

        if (i < data.size())
            painter->drawText(padded_cell, Qt::AlignLeft | Qt::AlignVCenter, data[i]);
        else
            painter->drawText(padded_cell, Qt::AlignLeft | Qt::AlignVCenter, "-");

        x += column_widths[i] + padding * 4;
    }

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


Sportsman::Sportsman()
{
    surname = "";
    name = "";
    age = 0;
    height = 0;
    id = max_id++;
}
