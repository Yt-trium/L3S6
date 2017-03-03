import java.rmi.server.UnicastRemoteObject ;
import java.rmi.RemoteException ;

public class OpMatriceImpl
  extends UnicastRemoteObject
  implements OpMatrice
{
  public int r = 0;
  public int g = 0;
  public int b = 0;

  public OpMatriceImpl()
    throws RemoteException
  {
    super() ;
  } ;

  public int[][] multiplicationMatrice (int [][] a, int [][] b)
    throws RemoteException
  {
    int [][] x = new int[a.length][a.length];

    for(int i = 0; i< a.length; i++)
    {
      for (int j = 0; j < a[i].length; j++)
      {
        x[i][j] = a[i][j]+b[i][j];
      }
    }

    return x;
  }
}
