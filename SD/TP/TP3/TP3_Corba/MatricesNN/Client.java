import java.io.* ;
import org.omg.CORBA.* ;

public class Client
{
  public static void main(String args[])
  {
    String ior = "";
    try
    {
    FileReader file = new FileReader(iorfile.value) ;
    BufferedReader in = new BufferedReader(file) ;
    ior = in.readLine() ;
    file.close() ;
    }
    catch( FileNotFoundException ex ) { ex.printStackTrace();}
    catch( IOException ex ) { ex.printStackTrace();}

    int[][] A = { {1, 0, 0, 0}, {0, 3, 0, 0}, {0, 1, 3, 0}, {0, 4, 0, 7} } ;
    int[][] B = { {1, 4}, {1, 8}, {2, 3}, {1, 0} } ;
    int[][] X;

    // initialiser l'ORB.
    try
    {
      ORB orb = ORB.init( args, null ) ;
      System.out.println( "0) ORB initialise'") ;
      System.out.println( "1) IOR lue : " + ior ) ;

      org.omg.CORBA.Object obj = orb.string_to_object(ior) ;
      OpMatrice service = OpMatriceHelper.narrow(obj) ;
      System.out.println("2) Reference obtenue a partir de l'IOR") ;

      X = service.multiplicationMatrice(A,B) ;
      System.out.println("4) Le serveur a trouve :") ;


      for (int i = 0; i < X.length; i++) {
        for (int j = 0; j < X[0].length; j++) {
          System.out.print(X[i][j]);
          System.out.print("\t");
        }
        System.out.println("------------------------------------------------");
      }
    }
    catch( org.omg.CORBA.SystemException ex )
    {
      System.err.println( "Erreur !!" ) ;
      ex.printStackTrace() ;
    }
  }
}
