package matrix;

import java.lang.Math;

public class Matrix {  
  int[][] matrix;
  int size;

  public Matrix(int n) {
    matrix = new int[n][n];
    size = n;
  }

  public void swap_columns() {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (size % 2 != 0 && i == ((size - 1) - i))
          return;
        
        if (size % 2 == 0 && i - ((size - 1) - i) == 1)
          return;
        
        int temp = matrix[j][i];

        matrix[j][i] = matrix[j][(size - 1) - i];
        matrix[j][(size - 1) - i] = temp;
      }
    }
  }

  public void generate() {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        matrix[i][j] = (int) (Math.random() * 100) - 50;
      }
    }
  }

  public void print() {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        System.out.printf("%4d", matrix[i][j]);
      }
      System.out.println();
    }
    System.out.println();
  }
}