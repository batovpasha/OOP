import notebook.Notebook;

public class NotebooksCollection {
  Notebook[] collection;

  NotebooksCollection(Notebook[] collection) {
    this.collection = collection;
  }

  public Notebook[] getCollection() {
    return this.collection;
  }

  public Notebook[] findByFirstLetterInSurname(char letter) {
    Notebook[] result = new Notebook[collection.length];
    int index = 0;

    for (int i = 0; i < collection.length; i++) {
      if (collection[i].getSurname().charAt(0) == letter) {
        result[index] = collection[i];
        index++;
      }
    }

    if (index == 0)
      return new Notebook[0];
    
    return result;
  }

  public Notebook[] findByHavingPhoneNumber() {
    Notebook[] result = new Notebook[collection.length];
    int index = 0;

    for (int i = 0; i < collection.length; i++) {
      if (collection[i].getPhoneNumber() != null) {
        result[index] = collection[i];
        index++;
      }
    }

    if (index == 0)
      return new Notebook[0];

    return result;
  }
}