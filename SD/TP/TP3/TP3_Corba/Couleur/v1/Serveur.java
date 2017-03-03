import org.omg.CORBA.* ;

public class Serveur
{
  public static void main(String[] args)
  {
    try
    {
      //init ORB
      ORB orb = ORB.init(args, null ) ;
      
      // Déclarer l'objet
      ICouleurImpl myobj = new ICouleurImpl() ;
      // Déduire l'IOR
      String ior = orb.object_to_string( myobj ) ;
      // Afficher l'IOR
      System.out.println( ior ) ;
	   
      orb.run() ;
    }

    catch( org.omg.CORBA.SystemException ex ) { ex.printStackTrace() ; }
  }
}
