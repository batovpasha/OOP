using System;
using System.Collections.Generic;

namespace csharp_lab
{
    class Program
    {
        static void Main(string[] args)
        {   
            Examination[] passedExams = {
                new Examination(1, "Math", "Orlovskiy", 88, true, new DateTime(2018, 1, 8)),
                new Examination(1, "Programming", "Shemsedinov", 78, false, new DateTime(2018, 1, 8)),
                new Examination(1, "English", "Tereshchenko", 98, true, new DateTime(2018, 1, 8))
            };

            Student student1 = new Student("Pavlo", "Batov", new DateTime(1999, 12, 6),
                                          Student.Education.Bachelor, "IP71", 11113);
            
            Console.WriteLine("Info about current student:");
            Console.WriteLine(student1.ToString());
            Console.WriteLine();

            student1.AddExams(passedExams);

            Console.WriteLine("Info about current student:");
            Console.WriteLine(student1.ToString());
            Console.WriteLine();
            
            Console.WriteLine("Full info:");
            student1.PrintFullInfo();

            // 1-task cloning student
            Student student2 = (Student)student1.Clone();
            // 2-task throw exception
            student2.GradebookNumber = 12;
            // 3-task
            foreach (Examination credit in student2.getCredits())
                Console.WriteLine(credit.ToString());
            
            Console.WriteLine();
            // 4-task
            Examination[] arraySortedBySubjectName = student2.getArraySortedBySubjectName();

            foreach (Examination exam in arraySortedBySubjectName)
            {
                Console.WriteLine(exam);
            }
        }
    }
}
