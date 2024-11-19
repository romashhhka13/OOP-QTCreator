#include "Footballer.h"

using namespace std;

BOOST_CLASS_VERSION(Footballer, 1)
BOOST_CLASS_EXPORT(Footballer)


QStringList Footballer::get_data() const
{
    return Sportsman::get_data() + QStringList{QString::number(number),
                                               QString::fromLocal8Bit(position.c_str())};
}

std::shared_ptr<Sportsman> Footballer::clone() const{
    return std::make_shared<Footballer>(*this);
}

void Footballer::update(QStringList &data)
{
    Sportsman::update(data);
    number = data[4].toInt();
    position = data[5].toLocal8Bit();
}



