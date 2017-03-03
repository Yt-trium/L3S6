import java.net.* ;
import java.rmi.* ;

public class Serveur
{
  public static void main(String [] args)
  {
    if (args.length != 1)
    {
      System.out.println("Usage : java Serveur <port du rmiregistry>") ;
      System.exit(0) ;
    }
    try
    {
      CouleurImpl objLocal = new CouleurImpl () ;
      System.out.println(objLocal.rgb());
      System.out.println("rmi://localhost:"+args[0]+"/Couleur") ;
      Naming.rebind("rmi://localhost:"+args[0]+"/Couleur",objLocal) ;
      System.out.println("Serveur pret") ;
    }
    catch (RemoteException re) { System.out.println(re) ; }
    catch (MalformedURLException e) { System.out.println(e) ; }
  }
}