#pragma once

#include <QPainter>

void draw_table_row(QPainter* painter, QVector<int> column_widths,
                    QStringList& row, int x, int y, int padding, int height, bool for_headers = false);
