using System;
using System.Xml.Serialization;

namespace MyAppIlichev
{
    public class Sportsman
    {
        // Поля класса
        public string surname;
        public string name;
        public int age;
        public int height;
        public int id;

        // Статическое поле
        private static int maxId = 1;

        // Конструктор
        public Sportsman()
        {
            surname = string.Empty;
            name = string.Empty;
            age = 0;
            height = 0;
            id = maxId++;
        }

        // Метод сброса статического ID
        public static void ResetMaxID()
        {
            maxId = 1;
        }

        // Геттер для ID
        public int GetID()
        {
            return id;
        }

        // Метод для ввода данных
        public virtual void Input()
        {
            Console.Write("Фамилия: ");
            surname = Console.ReadLine() ?? string.Empty;

            Console.Write("Имя: ");
            name = Console.ReadLine() ?? string.Empty;

            Console.Write("Возраст: ");
            age = Utils.GetCorrectNumber(1, 100);

            Console.Write("Рост: ");
            height = Utils.GetCorrectNumber(1, 300);
        }

        public virtual string CreateTableRow()
        {
            return $"| {id,-2} | {surname,-12} | {name,-12} | {age,-8} | {height,-5}";
        }

        // Метод для вывода данных
        public virtual void Output()
        {
            Console.WriteLine(CreateTableRow() + $" | {"-",-12} | {"-",-5} |");
        }
    }
}
