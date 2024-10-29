#pragma once

#include <memory>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <QPainter>

#include "Sportsman.h"
#include "Serialize.h"

class SportsmansGroup
{
public:
    const std::vector<std::shared_ptr<Sportsman>>& get_group() const { return group; }

    void load(std::ifstream& fin);
    void save(std::ofstream& fout) const;
    void clear();
    bool object_exist() const;

    // Функция для отрисовки
    void draw(QPainter* painter, int x, int& y,
              QVector<int>& column_widths, int padding, int height) const;

private:
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version){
        ar& group;
    }

    std::vector<std::shared_ptr<Sportsman>> group;
};


