using System;


namespace MyAppIlichev
{
    class Program
    {
        static void Main()
        { 
            // Меню
            List<string> menu = new List<string>
        {
            "Добавить спортсмена",
            "Добавить футболиста",
            "Показать всех спортсменов",
            "Сохранить в файл",
            "Загрузить из файла",
            "Очистить"
        };



            SportsmansGroup SG = new SportsmansGroup();

            while (true)
            {
                switch (Utils.ChooseActionMenu(menu))
                {
                    case 1:
                        Menu.MenuAddSportsman(SG);
                        break;
                    case 2:
                        Menu.MenuAddFootballer(SG);
                        break;
                    case 3:
                        Menu.MenuShowSportsmans(SG);
                        break;
                    case 4:
                        Menu.MenuSave(SG);
                        break;
                    case 5:
                        Menu.MenuLoad(SG);
                        break;
                    case 6:
                        Menu.MenuClear(SG);
                        break;
                    case 0:
                        return;
                }
            }

        }

    }
}