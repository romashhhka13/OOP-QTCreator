using System.Runtime.InteropServices;


namespace MyAppIlichev
{
    internal class Sportsman
    {
        private static int MaxId;
        public int Id { get; set; }
        public string Surname { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }
        public int Height { get; set; }

        public Sportsman()
        {
            Id = ++MaxId;
            Name = "";
            Surname = "";
            Age = 0;
            Height = 0;
        }

        public virtual SportsmanDataStruct GetStruct()
        {
            SportsmanDataStruct SD = new SportsmanDataStruct
            {
                id = Id,
                surname = Surname,
                name = Name,
                age = Age,
                height = Height
            };

            return SD;
        }

        public virtual List<string> GetData()
        {
            List<string> data = new List<string>
            {
                Surname,
                Name,
                Age.ToString(),
                Height.ToString()
            };

            return data;
        }


        public static void ResetMaxId() { MaxId = 0; }
    }
}
