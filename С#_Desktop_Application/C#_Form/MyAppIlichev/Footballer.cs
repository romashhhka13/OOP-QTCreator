using System;

namespace MyAppIlichev
{
    internal class Footballer : Sportsman
    {
        public string Position { get; set; }
        public int Number { get; set; }

        public Footballer()
            : base()
        {
            Position = "";
            Number = 0;
        }

        public override SportsmanDataStruct GetStruct() 
        {
            SportsmanDataStruct SD = base.GetStruct();
            SD.number = Number;
            SD.position = Position;

            return SD;
        }

        public override List<string> GetData()
        {
            List<string> data = base.GetData();
            data.Add(Number.ToString());
            data.Add(Position);

            return data;
        }

    }
}
