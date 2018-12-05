import java.util.Scanner;

import text.Text;

public class Main {
  public static void main(String[] args) {
    System.out.println("Please, choose the way to initialize text:");
    System.out.println("  Enter '1' for using finished text");
    System.out.println("  Enter '2' for user input");
    
    Scanner scanner = new Scanner(System.in);
    
    System.out.print("Your choice: ");
    int choice = scanner.nextInt();

    if (choice == 1) {
      Text text = new Text("Мова значно запозичила синтаксис із C і C++.\n" 
                         + "Зокрема, взято за основу об'єктну модель С++, проте її модифіковано.\n" 
                         + "Усунуто можливість появи деяких конфліктних ситуацій, що могли виникнути через помилки програміста та полегшено сам процес розробки об'єктно-орієнтованих програм.\n" 
                         + "Ряд дій, які в С/C++ повинні здійснювати програмісти, доручено віртуальній машині.\n" 
                         + "Передусім Java розроблялась як платформо-незалежна мова, тому вона має менше низькорівневих можливостей для роботи з апаратним забезпеченням, що в порівнянні, наприклад, з C++ зменшує швидкість роботи програм.\n" 
                         + "За необхідності таких дій Java дозволяє викликати підпрограми, написані іншими мовами програмування.\n");
      
      System.out.println("Text before replacing 'ра' on 'ро':");
      text.print();

      text.replaceLetters(); // replacing 'ра' on 'ро'
    
      System.out.println("Text after replacing 'ра' on 'ро':");
      text.print();
    }

    if (choice == 2) {
      Text text = new Text();
      
      text.userInput();

      System.out.println("Text before replacing 'ра' on 'ро':");
      text.print();

      text.replaceLetters(); // replacing 'ра' on 'ро'

      System.out.println("Text after replacing 'ра' on 'ро':");
      text.print();
    }
    
    scanner.close();
  }
}