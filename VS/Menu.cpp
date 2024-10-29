#include "Menu.h"


using namespace std;


void MenuAddSportsman(SportsmansGroup& group)
{
	cout << endl << "***Введите информацию о спортсмене***" << endl;
	group.AddSportsman();
}


void MenuAddFootballer(SportsmansGroup& group)
{
	cout << endl << "***Введите информацию о футболисте***" << endl;
	group.AddFootballer();
}


void MenuShowSportsmans(const SportsmansGroup& group)
{
	cout << endl << "***Спортсмены***" << endl;
	if (group.ObjectExist())
		group.ShowSportsmans();
	else
		cout << "Спортсмены не найдены!" << endl;
}


void MenuSave(const SportsmansGroup& group)
{
	string file_name;
	cout << endl << "Введите название файла: ";
	getline(cin >> ws, file_name);

	ofstream fout(".data/" + file_name + ".txt");

	if (fout) {
		group.Save(fout);
		cout << "Данные успешно сохранены!" << endl;
	}
	else
		cout << "Не удалось открыть файл!" << endl;
}


void MenuLoad(SportsmansGroup& group)
{
	string file_name;
	cout << endl << "Введите название файла: ";
	getline(cin >> ws, file_name);

	ifstream fin(".data/" + file_name + ".txt");
	if (fin) {
		group.Load(fin);
		cout << "Данные успешно считаны!" << endl;
	}
	else
		cout << "Не удалось открыть файл!" << endl;
}


void MenuClear(SportsmansGroup& group)
{
	cout << "Очистить данные (Да - 1, Нет - 0): ";
	if (GetCorrectNumber(0, 1)) {
		group.Clear();
		cout << "Данные успешно очищены!" << endl;
	}
}



