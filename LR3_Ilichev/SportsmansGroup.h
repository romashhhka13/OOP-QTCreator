#pragma once

#include <memory>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <QPainter>

#include "Sportsman.h"
#include "Footballer.h"
#include "Serialize.h"


class SportsmansGroup
{
public:
    // Методы класса-контейнера
    std::vector<std::shared_ptr<Sportsman>>& get_group() { return group; };
    void add_sportsman(std::shared_ptr<Sportsman> s) { group.push_back(s); };
    void load(std::ifstream& fin);
    void save(std::ofstream& fout) const;
    void clear();
    bool object_exist() const;
    int get_size() const;
    std::shared_ptr<Sportsman> get_sportsman(int num);
    void delete_sportsman(int index);

    // Функция для отрисовки
    void draw(QPainter* painter, int x, int& y,
              QVector<int>& column_widths, int padding, int height) const;

    // Конструкторы
    SportsmansGroup() = default;

    // Переопределение операторов
    SportsmansGroup& operator=(const SportsmansGroup& other);

private:
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version){
        ar& group;
    }

    std::vector<std::shared_ptr<Sportsman>> group;
};


