#pragma once

#include <string>

#include "Sportsman.h"
#include "Serialize.h"


class Footballer : public Sportsman
{
public:

    //Методы класса
    QStringList get_data() const override;
    std::shared_ptr<Sportsman> clone() const override;
    void update(QStringList& data) override;

    // Сеттеры
    void set_number(int num) { number = num; };
    void set_position(QString pos) { position = pos.toLocal8Bit(); };

    // Конструктор
    Footballer() = default;

private:
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<Sportsman>(*this);
        ar& number;
        ar& position;
    }

    std::string position;
    int number;
};


