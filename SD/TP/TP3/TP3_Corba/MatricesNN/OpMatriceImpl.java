import org.omg.CORBA.* ;

public class OpMatriceImpl
  extends OpMatricePOA
{
  public int[][] multiplicationMatrice (int[][] a, int[][] b)
  {
    /*
    int[][] x = new int[1][1];
    return x;
    */

    int aRows = a.length;
    int aColumns = a[0].length;
    int bRows = b.length;
    int bColumns = b[0].length;

    if (aColumns != bRows)
    {
      throw new IllegalArgumentException("A:Rows: " + aColumns + " did not match B:Columns " + bRows + ".");
    }

    int[][] C = new int[aRows][bColumns];

    for (int i = 0; i < aRows; i++) { // aRow
      for (int j = 0; j < bColumns; j++) { // bColumn
        for (int k = 0; k < aColumns; k++) { // aColumn
          C[i][j] += a[i][k] * b[k][j];
        }
      }
    }

    return C;
  }
}
