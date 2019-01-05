using System;

namespace csharp_lab
{
    class Person
    {
        public string name { get; set; }
        public string surname;
        public DateTime dateOfBirth;

        public int birthYear
        {
            get => dateOfBirth.Year;
            set => dateOfBirth = new DateTime(value, dateOfBirth.Month, dateOfBirth.Day);
        }

        public Person()
        {
            name = "Oddy";
            surname = "Nuff";
            dateOfBirth = new DateTime(1990, 4, 22);
        }

        public Person(string _name, string _surname, DateTime _dateOfBirth)
        {
            name = _name;
            surname = _surname;
            dateOfBirth = _dateOfBirth;
        }

        public virtual void PrintFullInfo()
        {
            Console.WriteLine($"Name: {name}\n" +
                              $"Surname: {surname}\n" +
                              $"Date of birth: {dateOfBirth.ToString()}");
        }
    }
}