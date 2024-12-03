using System;
using System.Xml.Serialization;


namespace MyAppIlichev
{
    [XmlRoot("SportsmansGroup")]
    public class SportsmansGroup
    {
        [XmlArray("group")]
        [XmlArrayItem("Sportsman", typeof(Sportsman))]
        [XmlArrayItem("Footballer", typeof(Footballer))]
        public List<Sportsman> group = new List<Sportsman>();

        public void AddSportsman()
        {
            Sportsman sportsman = new Sportsman();
            sportsman.Input();
            group.Add(sportsman);
        }

        public void AddFootballer()
        {
            Footballer footballer = new Footballer();
            footballer.Input();
            group.Add(footballer);
        }

        public void ShowSportsmans()
        {
            Console.WriteLine(new string('-', 78));
            Console.WriteLine("| {0,-2} | {1,-12} | {2,-12} | {3,-8} | {4,-5} | {5,-12} | {6, -5} |",
                "id", "Фамилия", "Имя", "Возраст", "Рост", "Позиция", "Номер");
            Console.WriteLine(new string('-', 78));
            foreach (var sportsman in group)
            {
                sportsman.Output();
            }
            Console.WriteLine(new string('-', 78));
        }

        public void Save(string filePath)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(SportsmansGroup));
            using (FileStream fs = new FileStream(filePath, FileMode.Create))
            {
                serializer.Serialize(fs, this);
            }
        }

        public void Load(string filePath)
        {
            Clear();
            XmlSerializer serializer = new XmlSerializer(typeof(SportsmansGroup));
            using (FileStream fs = new FileStream(filePath, FileMode.Open))
            {
                var deserialized = (SportsmansGroup)serializer.Deserialize(fs);
                this.group = deserialized.group;
            }
        }

        public void Clear()
        {
            Sportsman.ResetMaxID();
            group.Clear();
        }

        public bool ObjectExist()
        {
            return group.Count > 0;
        }
    }
}
