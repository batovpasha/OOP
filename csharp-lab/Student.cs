using System;
using System.Collections.Generic;
using System.Linq;

namespace csharp_lab
{
    class Student: Person, ICloneable
    {
        public Education qualificationLevel;
        private string group;

        public int gradebookNumber;
        public int GradebookNumber
        {
            get => gradebookNumber;
            set
            {
                if (value <= 99999 || value > 99999999)
                    throw new Exception("Gradebook number must be in range from 99999 to 99999999");
                gradebookNumber = value;
            }
        }
        public List<Examination> passedExams = new List<Examination>();

        public float avarageMark => passedExams.Sum(exam => exam.mark) / passedExams.Count;

        public void AddExams(Examination[] examList) => passedExams.AddRange(examList);

        public override string ToString()
        {
            return $"Name: {name}\n" +
                   $"Surname: {surname}\n" +
                   $"Group number: {group}";
        } 

        public override void PrintFullInfo()
        {
            base.PrintFullInfo();
            Console.WriteLine($"Qualification level: {qualificationLevel}\n" +
                              $"Group: {group}\n" +
                              $"Gradebook number: {gradebookNumber}\n" +
                              $"Avarage mark: {avarageMark}\n" +
                              $"Passed exams:\n");
            passedExams.ForEach(exam => Console.WriteLine(exam.ToString() + '\n'));
        }

        public Student(string name, string surname, DateTime dateOfBirth, 
                       Education _qualificationLevel, string _group, 
                       int _gradebookNumber) : base(name, surname, dateOfBirth)
        {
            qualificationLevel = _qualificationLevel;
            group = _group;
            gradebookNumber = _gradebookNumber;
        }
        public object Clone()
        {   
            Student cloned = new Student(this.name, this.surname, this.dateOfBirth,
                                         this.qualificationLevel, this.group, 
                                         this.gradebookNumber);
            
            cloned.passedExams = this.passedExams.Select(exam => (Examination)exam.Clone()).ToList(); 
            return cloned;
        }

        public IEnumerable<Examination> getCredits()
        {
            foreach (Examination exam in passedExams)
            {
                if (!exam.isDifferentiated)
                    yield return exam;
            }
        }

        public Examination[] getArraySortedBySubjectName()
        {
            return passedExams.OrderBy(exam => exam.subject).ToArray();
        }
        public enum Education
        {
            Master,
            Bachelor,
            SecondEducation,
            PhD
        }
    }
}