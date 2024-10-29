#include "SportsmansGroup.h"

BOOST_CLASS_VERSION(SportsmansGroup, 1)

using namespace std;
using namespace boost::archive;


void SportsmansGroup::load(ifstream& fin){
    clear();
    binary_iarchive ia(fin);
    ia >> *this;
}


void SportsmansGroup::save(std::ofstream &fout) const{
    binary_oarchive oa(fout);
    oa << *this;
}

void SportsmansGroup::clear(){
    Sportsman::reset_maxID();
    group.clear();
}

bool SportsmansGroup::object_exist() const{
    return !group.empty();
}

void SportsmansGroup::draw(QPainter *painter, int x, int& y,
                           QVector<int>& column_widths, int padding, int height) const
{
    std::for_each(group.begin(), group.end(),
                  std::bind(&Sportsman::draw, std::placeholders::_1,
                            painter, x, std::ref(y), column_widths,
                            padding, height));
}



