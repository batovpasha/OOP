using System;

namespace csharp_lab
{
    class Examination
    {
        public int semester;
        public string subject;
        
        public string teacher;

        public int mark { get; set; }

        public bool isDifferentiated;

        public DateTime date;

        public Examination()
        {
            semester = 1;
            subject = "programming";
            teacher = "Shemsedinov T. G.";
            mark = 98;
            isDifferentiated = true;
            date = new DateTime(2018, 1, 10);
        }

        public Examination(int _semester, string _subject, string _teacher, 
                           int _mark, bool _isDifferentiated, DateTime _date)
        {
            semester = _semester;
            subject = _subject;
            teacher = _teacher;
            mark = _mark;
            isDifferentiated = _isDifferentiated;
            date = _date;
        }

        public override string ToString()
        {
            return $"Subject: {subject}\n" +
                   $"Teacher: {teacher}\n" +
                   $"Mark: {mark}";
        }

        public object Clone()
        {
            return this.MemberwiseClone();
        }
    }
}