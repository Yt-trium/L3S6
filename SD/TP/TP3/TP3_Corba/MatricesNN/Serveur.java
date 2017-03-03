import org.omg.CORBA.* ;
import org.omg.PortableServer.* ;
import java.io.* ;

public class Serveur
{
  public static void main(String[] args)
  {
    try
    {
      //init ORB
      ORB orb = ORB.init(args, null ) ;

      OpMatriceImpl myobj = new OpMatriceImpl() ;

      // Init POA
      POA poa = POAHelper.narrow( orb.resolve_initial_references("RootPOA")) ;
      // Activer POA
      poa.the_POAManager().activate() ;

      // Déduire l'objet CORBA
      org.omg.CORBA.Object poaobj = poa.servant_to_reference( myobj ) ;
      // Déduire l'IOR
      String ior = orb.object_to_string( poaobj ) ;

      // String ior = orb.object_to_string( myobj ) ;
      System.out.println( ior ) ;
      FileOutputStream file = new FileOutputStream(iorfile.value) ;
    PrintWriter out = new PrintWriter(file) ;
    out.println(ior) ; out.flush() ;
    file.close() ;

      orb.run() ;
    }

    catch( org.omg.CORBA.SystemException ex ) { ex.printStackTrace() ; }
    catch( org.omg.CORBA.UserException ex ) { ex.printStackTrace();}
    catch( FileNotFoundException ex ) { ex.printStackTrace();}
    catch( IOException ex ) { ex.printStackTrace();}
  }
}
