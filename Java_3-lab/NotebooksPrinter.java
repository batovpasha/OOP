import notebook.Notebook;

public class NotebooksPrinter {
  public void print(Notebook[] collection) {
    if (collection.length == 0) {
      System.out.println("Sorry, there are no subscribers that match your request");
      return;
    }

    StringBuilder header = new StringBuilder();
    
    header.append(String.format("%-30s", "Surname"))
          .append(String.format("%-30s", "Name"))
          .append(String.format("%-30s", "Patronymic"))
          .append(String.format("%-30s", "Address"))
          .append(String.format("%-30s", "Additional info"))
          .append(String.format("%-30s", "Phone number"));
        
    System.out.println(header.toString());
    
    for (Notebook notebook:collection) {
      if (notebook != null)
        System.out.println(notebook);
    }
  }
}