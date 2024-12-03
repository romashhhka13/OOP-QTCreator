using System;
using System.Xml.Serialization;


namespace MyAppIlichev
{
    public class Footballer : Sportsman
    {
        public string position;
        public int number;

        public Footballer()
        {
            position = string.Empty;
            number = 0;
        }

        // Переопределение метода Input
        public override void Input()
        {
            // Вызов базового метода
            base.Input();

            Console.Write("Позиция: ");
            position = Console.ReadLine() ?? string.Empty;

            Console.Write("Номер на поле: ");
            number = Utils.GetCorrectNumber(1, 100);
        }

        public override string CreateTableRow()
        {
            return base.CreateTableRow() + $" | {position,-12} | {number,-5} |";
        }

        // Переопределение метода Output
        public override void Output()
        {
            Console.WriteLine(CreateTableRow());
        }
    }
}
