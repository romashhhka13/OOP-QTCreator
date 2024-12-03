using System;

namespace MyAppIlichev
{
    public static class Menu
    {
        public static void MenuAddSportsman(SportsmansGroup group)
        {
            Console.WriteLine("<<<Введите информацию о спортсмене>>>");
            group.AddSportsman();
        }

        public static void MenuAddFootballer(SportsmansGroup group)
        {
            Console.WriteLine("<<<Введите информацию о футболисте>>>");
            group.AddFootballer();
        }

        public static void MenuShowSportsmans(SportsmansGroup group)
        {
            Console.WriteLine("<<<Все спортсмены>>>");
            if (group.ObjectExist())
            {
                group.ShowSportsmans();
            }
            else
            {
                Console.WriteLine("В системе нет спортсменов!");
            }
        }

        public static void MenuSave(SportsmansGroup group)
        {
            Console.Write("Введите название файла: ");
            string filePath = Console.ReadLine() ?? string.Empty;
            group.Save("../../../.data/" + filePath);
            Console.WriteLine("Данные сохранены!");
        }

        public static void MenuLoad(SportsmansGroup group)
        {
            Console.Write("Введите название файла: ");
            string filePath = Console.ReadLine() ?? string.Empty;
            group.Load("../../../.data/" + filePath);
            Console.WriteLine("Данные загружены!");
        }

        public static void MenuClear(SportsmansGroup group)
        {
            group.Clear();
            Console.WriteLine("Данные очищены!");
        }


    }
}
