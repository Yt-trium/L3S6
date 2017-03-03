import org.omg.CORBA.* ;
import org.omg.PortableServer.* ;

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

      // Init POA
      POA poa = POAHelper.narrow( orb.resolve_initial_references("RootPOA")) ;

      // Activer POA
      poa.the_POAManager().activate() ;

      // Déduire l'objet CORBA
      org.omg.CORBA.Object poaobj = poa.servant_to_reference( myobj ) ;

      // Déduire l'IOR
      String ior = orb.object_to_string( poaobj ) ;

      // Afficher l'IOR
      System.out.println( ior ) ;

      orb.run() ;
    }

    catch( org.omg.CORBA.SystemException ex ) { ex.printStackTrace() ; }
    catch( org.omg.CORBA.UserException ex ) { ex.printStackTrace();}
  }
}
