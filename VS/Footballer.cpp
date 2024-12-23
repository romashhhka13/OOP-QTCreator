#include "Footballer.h"


using namespace std;


BOOST_CLASS_EXPORT(Footballer)


void Footballer::Input()
{
	Sportsman::Input();
	cout << "Введите номер игрока: ";
	number = GetCorrectNumber(1, 99);

	vector<string> positions = { "Вратарь", "Левый защитник",
		"Правый защитник", "Центральный защитник", "Правый полузащитник",
		"Левый полузащитник", "Опорный полузащитник", "Левый нападающий",
		"Правый нападающий", "Центральный нападающий" };
	position = positions[ChooseActionMenu(positions, false, "Позиция игрока на поле: ") - 1];
}


void Footballer::Output() const
{
	Sportsman::Output();
	char symbol = 149;
	cout << symbol << "Номер игрока: " << number << endl
		<< symbol << "Позиция на поле: " << position << endl;
}

Footballer::Footballer()
{
	number = 0;
	position = "";
}
