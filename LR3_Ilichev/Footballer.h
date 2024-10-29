#pragma once

#include <string>

#include "Sportsman.h"
#include "Serialize.h"


class Footballer : public Sportsman
{
public:

    Footballer();


    //Методы для отрисовки и вычисления размеров текстового блока
    QStringList get_data() const override;


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


