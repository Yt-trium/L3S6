import java.io.* ;
import org.omg.CORBA.* ;

public class Client
{
  public static void main(String args[])
  {
    double rouge, vert, bleu ;
    double luminance ;

    if( args.length < 4 )
    {
      System.out.println( "Usage: java Client <ior> <r> <g> <b>" ) ;
      System.exit( 1 ) ;
    }

    try
    {
      // initialiser l'ORB.
      ORB orb = ORB.init( args, null ) ;
      System.out.println( "0) ORB initialise'") ;

      // Lire l'IOR
      String ior = args[0] ;
      System.out.println( "1) IOR lue : " + ior ) ;

      // Traduire IOR en objet CORBA
      org.omg.CORBA.Object obj = orb.string_to_object(args[0]) ;
      // Traduire l'objet CORBA en Objet ICouleur grace au Helper
      ICouleur service = ICouleurHelper.narrow(obj) ;
      System.out.println("2) Reference obtenue a partir de l'IOR") ;

      // Lire les arguments
      rouge = Double.parseDouble(args[1]) ;
      vert = Double.parseDouble(args[2]) ;
      bleu = Double.parseDouble(args[3]) ;
      System.out.println("3) Couleur lue sur la ligne de commande : " + rouge + ", " + vert + ", " + bleu);

      service.setColorRGB(rouge, vert, bleu) ;
      luminance = service.getLuminance() ;
      System.out.println("4) La luminance est  : " + luminance) ;
      double C = service.getC() ;
      System.out.println("5) C : " + C) ;
    }
    catch( org.omg.CORBA.SystemException ex )
    {
      System.err.println( "Erreur !!" ) ;
      ex.printStackTrace() ;
    }
  }
}
