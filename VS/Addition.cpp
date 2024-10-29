#include "Addition.h"


using namespace std;


int ChooseActionMenu(std::vector<std::string>& menu, bool with_exit, string action_text)
{
	if (menu.size() < 1)
		return -1;

	int i = 1;
	for (auto& s : menu)
		cout << std::format("{}. {}", i++, s) << "\n";
	if (with_exit)
		cout << "0. Выход\n";

	cout << action_text;
	return with_exit ? GetCorrectNumber<int>(0, menu.size()) : GetCorrectNumber<int>(1, menu.size());
}
