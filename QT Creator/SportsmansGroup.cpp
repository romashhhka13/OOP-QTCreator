#include "SportsmansGroup.h"

BOOST_CLASS_VERSION(SportsmansGroup, 1)

using namespace std;

void SportsmansGroup::load(ifstream& fin){
    clear();
    boost::archive::binary_iarchive ia(fin);
    ia >> *this;
}


void SportsmansGroup::save(std::ofstream &fout) const{
    boost::archive::binary_oarchive oa(fout);
    oa << *this;
}

void SportsmansGroup::clear(){
    Sportsman::reset_maxID();
    group.clear();
}

bool SportsmansGroup::object_exist() const{
    return !group.empty();
}

int SportsmansGroup::get_size() const {
    return group.size();
}

void SportsmansGroup::delete_sportsman(int index) {
    group.erase(group.begin() + index);
}

std::shared_ptr<Sportsman> SportsmansGroup::get_sportsman(int num) {
    return group[num];
}

void SportsmansGroup::draw(QPainter *painter, int x, int& y,
                           QVector<int>& column_widths, int padding, int height) const
{
    std::for_each(group.begin(), group.end(), [&](const std::shared_ptr<Sportsman> sportsman) {
        sportsman->draw(painter, x, y, column_widths, padding, height);
    });
}

SportsmansGroup::SportsmansGroup(const SportsmansGroup &SG)
{
    for (const auto& sportsman : SG.group)
        group.push_back(sportsman->clone());
}

SportsmansGroup &SportsmansGroup::operator=(const SportsmansGroup &other)
{
    if (this != &other) {
        clear();
        for (const auto& sportsman : other.group)
            group.push_back(sportsman->clone());
    }
    return *this;
}

