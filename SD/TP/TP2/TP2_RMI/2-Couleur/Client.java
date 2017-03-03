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
      Couleur c = (Couleur) Naming.lookup("rmi://" + args[0] + ":" + args[1] + "/Couleur");
      c.setRGB(255,255,255);
      System.out.println("Couleur : " + c.rgb()) ;
      System.out.println("Couleur : " + c.cmj()) ;
      c.setRGB(120,230,20);
      System.out.println("Couleur : " + c.rgb()) ;
      System.out.println("Couleur : " + c.cmj()) ;
    }
    catch (NotBoundException re) { System.out.println(re) ; }
    catch (RemoteException re) { System.out.println(re) ; }
    catch (MalformedURLException e) { System.out.println(e) ; }
  }
}
