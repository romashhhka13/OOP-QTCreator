using System;

namespace MyAppIlichev
{
    public static class Utils
    {
        public static int GetCorrectNumber(int min, int max)
        {
            int x;
            while (true)
            {
                if (int.TryParse(Console.ReadLine(), out x) && x >= min && x <= max)
                    return x;

                Console.WriteLine($"Введите корректное число ({min} - {max}):");
            }
        }

        public static int ChooseActionMenu(List<string> menu, bool withExit = true, string actionText = "Выберете действие: ")
        {
            if (menu.Count < 1)
                return -1;

            int i = 1;

            foreach (var s in menu)
            {
                Console.WriteLine($"{i++}. {s}");
            }

            if (withExit)
                Console.WriteLine("0. Выход");

            Console.Write(actionText);

            return withExit ? GetCorrectNumber(0, menu.Count) : GetCorrectNumber(1, menu.Count);
        }
    }
}
