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
    QFont font("Times New Roman", 14, -1, false);
    painter.setPen(Qt::black);
    font.setBold(true);
    painter.setFont(font);

    // Создаем вектор заголовков таблицы, получаем ссылку на вектор спортсменов, получаем размеры каждого столбца
    QStringList headers = {"Фамилия", "Имя", "Возраст", "Рост", "Номер игрока", "Позиция на поле"};
    vector<shared_ptr<Sportsman>> sportsmans = SG.get_group();
    QVector<int> column_widths = get_min_column_widths(&painter, sportsmans, headers);

    // Задаём начальные координаты, отступ padding
    // Рисуем заголовки
    int x = 10;
    int y = 10;
    int height = painter.fontMetrics().height() + 5;
    int padding = 5;
    draw_table_row(&painter, column_widths, headers, x, y, padding, height, true);

    // Рисуем следующие строки таблицы с информацией о спортменах
    x = 10;
    y = y + height;
    font.setPointSize(12);
    font.setBold(false);
    painter.setFont(font);
    SG.draw(&painter, x, y, column_widths, padding, height);

    // Изменяем размеры виджета
    int table_width = std::accumulate(column_widths.begin(), column_widths.end(), 0)
                      + column_widths.size() * padding * 4 + 40;
    int table_height = sportsmans.size() * (height + 5) + 40;
    this->resize(table_width, table_height);
}


void SportsmanWidget::load(const QString &path)
{
    std::ifstream fin(path.toStdString());
    if (fin)
        SG.load(fin);
    update();
}


void SportsmanWidget::save(const QString &path)
{
    std::ofstream fout(path.toStdString());
    if (fout)
        SG.save(fout);
}


void SportsmanWidget::clear(){
    SG.clear();
    update();
}
