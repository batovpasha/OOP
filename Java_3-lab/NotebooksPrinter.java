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
    
    for (int i = 0; i < collection.length; i++) {
      if (collection[i] != null) {
        StringBuilder builder = new StringBuilder();
    
        builder.append(String.format("%-30s", collection[i].getSurname()))
               .append(String.format("%-30s", collection[i].getName()))
               .append(String.format("%-30s", collection[i].getPatronymic()))
               .append(String.format("%-30s", collection[i].getAddress()))
               .append(String.format("%-30s", collection[i].getAdditionalInformation()))
               .append(String.format("%-30s", collection[i].getPhoneNumber()));
     
        System.out.println(builder.toString());
      }
    }
  }
}