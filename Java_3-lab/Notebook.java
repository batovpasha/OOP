package notebook;

public class Notebook {
  String name;
  String surname;
  String patronymic;

  String address;
  String phoneNumber;
  String additionalInformation;

  public Notebook(String name, String surname, String patronymic) {
    this.name = name;
    this.surname = surname;
    this.patronymic = patronymic;
  }

  public void setName(String name) {
    this.name = name;
  }

  public void setSurname(String surname) {
    this.surname = surname;
  }

  public void setPatronymic(String patronymic) {
    this.patronymic = patronymic;
  }

  public void setAddress(String address) {
    this.address = address;
  }
    
  public void setPhoneNumber(String phoneNumber) {
    this.phoneNumber = phoneNumber;
  }
  
  public void setAdditionalInformation(String additionalInformation) {
    this.additionalInformation = additionalInformation;
  }

  public String getName() {
    return this.name;
  }

  public String getSurname() {
    return this.surname;
  }

  public String getPatronymic() {
    return this.patronymic;
  }

  public String getAddress() {
    return this.address;
  }
    
  public String getPhoneNumber() {
    return this.phoneNumber;
  }
  
  public String getAdditionalInformation() {
    return this.additionalInformation;
  }

  public String toString() {
    StringBuilder builder = new StringBuilder();
    
    builder.append(String.format("%-30s", getSurname()))
           .append(String.format("%-30s", getName()))
           .append(String.format("%-30s", getPatronymic()))
           .append(String.format("%-30s", getAddress()))
           .append(String.format("%-30s", getAdditionalInformation()))
           .append(String.format("%-30s", getPhoneNumber()));

    return builder.toString();
  }
}