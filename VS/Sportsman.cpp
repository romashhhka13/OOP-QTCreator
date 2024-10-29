#include "Sportsman.h"


using namespace std;


int Sportsman::max_id = 1;


BOOST_CLASS_VERSION(Sportsman, 1)


void Sportsman::ResetMaxID() {
    max_id = 1;
}

int Sportsman::GetID() const{
    return id;
}

void Sportsman::Input()
{
    cout << "Фамилия: ";
    getline(cin >> ws, surname);

    cout << "Имя: ";
    getline(cin >> ws, name);

    cout << "Возраст: ";
    age = GetCorrectNumber(1, 100);

    cout << "Рост: ";
    height = GetCorrectNumber(1, 300);
}

void Sportsman::Output() const
{
    char symbol = 149; // marker
    cout << "Информация о спортмене #" << id << endl
        << symbol << "Фамилия: " << surname << endl
        << symbol << "Имя: " << name << endl
        << symbol << "Возраст: " << age << endl
        << symbol << "Рост спортмена: " << height << endl;
}

Sportsman::Sportsman(){
    surname = "";
    name = "";
    age = 0;
    height = 0;
    id = max_id++;
}
