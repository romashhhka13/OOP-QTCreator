#include "SportsmanWidget.h"

using namespace std;

QVector<int> get_min_column_widths(QPainter* painter, const vector<shared_ptr<Sportsman>>& sportsmans,
                        const QStringList& headers)
{

    QVector<int> widths(headers.size(), 0);
    for (int i = 0; i < headers.size(); ++i)
        widths[i] = painter->fontMetrics().horizontalAdvance(headers[i]);

    for (auto sportsman : sportsmans){
        QVector<int> w = sportsman->get_column_widths(painter);
        for (int i = 0; i < w.size(); i++)
            widths[i] = max(widths[i], w[i]);
    }

    return widths;
}


void SportsmanWidget::paintEvent(QPaintEvent *event)
{

    if (!SG.object_exist())
        return;

    // Создаём объект QPainter, устанавливаем цвет черным
    QPainter painter(this);
    painter.setPen(Qt::black);
    QStringList headers = {"Фамилия", "Имя", "Возраст", "Рост", "Номер игрока", "Позиция на поле"};
    vector<shared_ptr<Sportsman>> sportsmans = SG.get_group();
    QVector<int> column_widths = get_min_column_widths(&painter, sportsmans, headers);

    // Начальные координаты, отступ padding
    int x = 10;
    int y = 10;
    int height = painter.fontMetrics().height() + 5;
    int padding = 5;

    for (int i = 0; i < headers.size(); i++){
        QRect cell(x, y, column_widths[i] + padding * 4, height);
        painter.drawRect(cell);

        QRect padded_cell = cell.adjusted(padding, 0, 0, 0);
        painter.drawText(padded_cell, Qt::AlignLeft | Qt::AlignVCenter, headers[i]);

        x += column_widths[i] + padding * 4;
    }

    x = 10;
    y = y + height;
    SG.draw(&painter, x, y, column_widths, padding, height);

    int table_width = std::accumulate(column_widths.begin(), column_widths.end(), 0)
                      + column_widths.size() * padding * 4 + 20;
    int table_height = sportsmans.size() * (height + 5) + 20;
    this->resize(table_width, table_height);
}


void SportsmanWidget::load(const QString &path)
{
    std::ifstream fin(path.toStdString());
    if (fin)
        SG.load(fin);
}


void SportsmanWidget::save(const QString &path)
{
    std::ofstream fout(path.toStdString());
    if (fout)
        SG.save(fout);
}


void SportsmanWidget::clear(){
    SG.clear();
    // this->resize(0, 0);
    update();
}
