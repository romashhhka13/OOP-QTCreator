#include "Addition.h"



void draw_table_row(QPainter* painter, QVector<int> column_widths,
                    QStringList& row, int x, int y, int padding, int height, bool for_headers)
{
    if (for_headers) {
        for (int i = 0; i < row.size(); i++){
            QRect cell(x, y, column_widths[i] + padding * 4, height);
            painter->drawRect(cell);

            QRect padded_cell = cell.adjusted(padding, 0, 0, 0);
            painter->drawText(padded_cell, Qt::AlignLeft | Qt::AlignVCenter, row[i]);

            x += column_widths[i] + padding * 4;
        }
    }

    else {
        for (int i = 0; i < column_widths.size(); i++){
            QRect cell(x, y, column_widths[i] + padding * 4, height);
            painter->drawRect(cell);

            QRect padded_cell = cell.adjusted(padding, 0, 0, 0);

            if (i < row.size())
                painter->drawText(padded_cell, Qt::AlignLeft | Qt::AlignVCenter, row[i]);
            else
                painter->drawText(padded_cell, Qt::AlignLeft | Qt::AlignVCenter, "-");

            x += column_widths[i] + padding * 4;
        }
    }
}
