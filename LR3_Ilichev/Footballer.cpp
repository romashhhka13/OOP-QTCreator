#include "Footballer.h"

using namespace std;

BOOST_CLASS_VERSION(Footballer, 1)
BOOST_CLASS_EXPORT(Footballer)


QStringList Footballer::get_data() const
{
    return Sportsman::get_data() + QStringList{QString::number(number),
                                               QString::fromLocal8Bit(position.c_str())};
}


Footballer::Footballer()
{
    number = 0;
    position = "";
}

