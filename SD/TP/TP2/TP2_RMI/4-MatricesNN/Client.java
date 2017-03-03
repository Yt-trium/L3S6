import java.rmi.* ;

import java.net.MalformedURLException ;

public class Client
{
  public static void main(String [] args)
  {
    if (args.length != 2)
    {
      System.out.println("Usage : java Client <machine du Serveur> <port du rmiregistry>") ;
      System.exit(0) ;
    }
    try
    {
      int [][] a = new int[][]{{1,2},{3,4}};
      int [][] b = new int[][]{{7,7},{10,10}};

      OpMatrice opm = (OpMatrice) Naming.lookup("rmi://" + args[0] + ":" + args[1] + "/OpMatrice");

      int [][] x = opm.multiplicationMatrice(a,b);

      System.out.println("OpMatrice : " + x) ;
      for(int i = 0; i< x.length; i++)
      {
        for (int j = 0; j < x[i].length; j++)
        {
          System.out.print(x[i][j]);
          System.out.print(" ");
        }
        System.out.print("\n");
      }
    }
    catch (NotBoundException re) { System.out.println(re) ; }
    catch (RemoteException re) { System.out.println(re) ; }
    catch (MalformedURLException e) { System.out.println(e) ; }
  }
}
