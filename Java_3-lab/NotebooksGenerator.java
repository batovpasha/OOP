import notebook.Notebook;

public class NotebooksGenerator {
  Notebook[] notebooks;

  public NotebooksGenerator() {
    notebooks = new Notebook[10];
  }

  public void generate() {
    String[] names = { "Александр", "Вадим", "Михаил", "Ярослав", "Ян", "Олег", 
                       "Константин", "Максим", "Дмитрий", "Евгений" };
    
    String[] surnames = { "Смирнов", "Соколов", "Зайцев", "Морозов", "Волков",
                          "Лебедев", "Тарасов", "Попов", "Петров", "Васильев" };
    
    String[] patronymics = { "Данилович", "Юрьевич", "Львович", "Натанович",
                             "Матвеевич", "Кириллович", "Ефимович", "Юрьевич",
                             "Ильич", "Александрович" };
    
    String[] addresses = { "наб. реки Мойки, 12", "Литейный проспект, 53" , 
                           "Литейный проспект, 24", "ул. Садовая, 61",
                           "ул. Декабристов, 57", "ул. Малая Конюшенная, 4/2", 
                           "ул. Жуковского, 7", "набережная Крюкова канала, 23",
                           "Литейный проспект, 36", "Кузнечный переулок, 5/2" };

    for (int i = 0; i < notebooks.length; i++) {
      notebooks[i] = new Notebook(names[i], surnames[i], patronymics[i]);
     
      notebooks[i].setAddress(addresses[i]);

      int randomNumber = (int) (Math.random() * 9); // random number from 0 to 9

      if (randomNumber % 2 == 0)
        notebooks[i].setAdditionalInformation("мобильный телефон");
      else
        notebooks[i].setAdditionalInformation("стационарный телефон");
      
      randomNumber =  (int) (Math.random() * 9);

      if (randomNumber % 2 == 0) {
        Integer number = (int) (Math.random() * 900000 + 100000);
        notebooks[i].setPhoneNumber(number.toString());
      }
    }
  }

  public Notebook[] getNotebooks() {
    return this.notebooks;
  }
}