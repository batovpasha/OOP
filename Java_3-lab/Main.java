import notebook.Notebook;

import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    NotebooksGenerator notebooksGenerator = new NotebooksGenerator();
    notebooksGenerator.generate();
    
    NotebooksCollection collection = new NotebooksCollection(notebooksGenerator.getNotebooks());
    NotebooksPrinter notebooksPrinter = new NotebooksPrinter();
    
    notebooksPrinter.print(collection.getCollection());

    Scanner scanner = new Scanner(System.in);

    System.out.println("Enter 1 for searching by first letter in surname");
    System.out.println("Enter 2 for searching by having phone number");
    System.out.print("Your choice: ");

    int choice = scanner.nextInt();

    if (choice == 1) {
      System.out.print("Enter the letter: ");

      char letter = scanner.next().charAt(0);

      notebooksPrinter.print(collection.findByFirstLetterInSurname(letter));
    }

    if (choice == 2) {
      notebooksPrinter.print(collection.findByHavingPhoneNumber());
    }

    else {
      scanner.close();
      return;
    }
  }
}