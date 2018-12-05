package text;

import java.util.Scanner;

public class Text {
  String data;

  public Text() {}

  public Text(String data) {
    this.data = data;
  }

  public void userInput() {
    Scanner scanner = new Scanner(System.in);
      
    StringBuilder builder = new StringBuilder();
    
    System.out.println("Enter 'quit' for finishing input");

    while (true) {
      String line = scanner.nextLine();
        
      if (line.equals("quit"))
          break;
      
      builder.append(line).append('\n');
    }
    
    scanner.close();
    
    this.data = builder.toString();     
  }

  public void replaceLetters() {
    String[] words = data.split(" ");
      
    for (int i = 0; i < words.length; i++) {
      if (words[i].contains("ра")) {
        char[] letters = words[i].toCharArray();
        
        for (int j = 0; j < letters.length - 3; j++) {
          if (letters[j] == 'р' && letters[j + 1] == 'а') {
            letters[j + 1] = 'o';
          }
        }
                
        words[i] = new String(letters);
      }
    }
        
    data = String.join(" ", words);
  }
  
  public void print() {
    System.out.println(data);
  }
 
}