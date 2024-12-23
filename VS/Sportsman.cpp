#include "Sportsman.h"


using namespace std;


int Sportsman::max_id = 1;



void Sportsman::ResetMaxID() {
    max_id = 1;
}

int Sportsman::GetID() const{
    return id;
}

void Sportsman::Input()
{
    cout << "�������: ";
    getline(cin >> ws, surname);

    cout << "���: ";
    getline(cin >> ws, name);

    cout << "�������: ";
    age = GetCorrectNumber(1, 100);

    cout << "����: ";
    height = GetCorrectNumber(1, 300);
}

void Sportsman::Output() const
{
    char symbol = 149; // marker
    cout << "���������� � ��������� #" << id << endl
        << symbol << "�������: " << surname << endl
        << symbol << "���: " << name << endl
        << symbol << "�������: " << age << endl
        << symbol << "���� ���������: " << height << endl;
}

Sportsman::Sportsman(){
    surname = "";
    name = "";
    age = 0;
    height = 0;
    id = max_id++;
}
