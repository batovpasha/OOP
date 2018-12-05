import java.util.Scanner;

import matrix.Matrix;

public class Main {
  public static void main(String[] args) {
    System.out.println("Developer: Batov P. O. (IP-71)");
    
    Scanner in = new Scanner(System.in);

    while (true) {
      System.out.print("Please, enter the size of matrix: ");
      int n = in.nextInt();

      if (n == 0)
        break;

      Matrix matrix = new Matrix(n);
    
      matrix.generate(); // generating the matrix
    
      System.out.println("Matrix before swapping:");
      matrix.print();
    
      matrix.swap_columns(); // swapping columns in current matrix

      System.out.println("Matrix after swaping:");
      matrix.print();
    }
  }
}