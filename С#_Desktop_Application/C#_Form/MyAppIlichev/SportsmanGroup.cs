using System;


namespace MyAppIlichev
{
    internal class SportsmanGroup
    {
        public SportsmanGroup() { }

        public void AddStruct(SportsmanDataStruct SD)
        {
            if (!SD.is_footballer)
            {
                Sportsman s = new Sportsman();
                s.Id = SD.id;
                s.Surname = SD.surname;
                s.Name = SD.name;
                s.Age = SD.age;
                s.Height = SD.height;
                group.Add(s);
            }
            else
            {
                Footballer f = new Footballer();
                f.Id = SD.id;
                f.Surname = SD.surname;
                f.Name = SD.name;
                f.Age = SD.age;
                f.Height = SD.height;
                f.Number = SD.number;
                f.Position = SD.position;
                group.Add(f);
            }
        }


        public SportsmanDataStruct[] GetStructs()
        {
            SportsmanDataStruct[] sportsmans = new SportsmanDataStruct[group.Count()];
            
            for (int i = 0; i < group.Count; i++)
            {
                sportsmans[i] = group[i].GetStruct();
            }

            return sportsmans;
        }

        public List<string> GetData(int index_sportsman)
        {
            List<string> data = group[index_sportsman].GetData();
            return data;
        }

        public bool isFootballer(int index_sportsman)
        {
            return (group[index_sportsman] is Footballer footballer);
        }

        public int AddSportsman()
        {
            Sportsman s = new Sportsman();
            group.Add(s);
            return group.Count - 1;
        }

        public int AddFootballer()
        {
            Footballer f = new Footballer();
            group.Add(f);
            return group.Count - 1;
        }

        public void DeleteSportsman(int index_sportsman)
        {
            group.RemoveAt(index_sportsman);
        }

        public void Clear()
        {
            Sportsman.ResetMaxId();
            group.Clear();
        }

        public bool ObjectExist()
        {
            return group.Count > 0;
        }

        public List<Sportsman> group = new List<Sportsman>();
    }
}
