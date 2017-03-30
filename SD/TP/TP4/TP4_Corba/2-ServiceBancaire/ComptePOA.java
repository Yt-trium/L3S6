
/**
* ComptePOA.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from Compte.idl
* mardi 14 mars 2017 08 h 36 CET
*/

public abstract class ComptePOA extends org.omg.PortableServer.Servant
 implements CompteOperations, org.omg.CORBA.portable.InvokeHandler
{

  // Constructors

  private static java.util.Hashtable _methods = new java.util.Hashtable ();
  static
  {
    _methods.put ("deposeLiquide", new java.lang.Integer (0));
    _methods.put ("retireLiquide", new java.lang.Integer (1));
    _methods.put ("afficheMontant", new java.lang.Integer (2));
    _methods.put ("virementCompteaCompte", new java.lang.Integer (3));
  }

  public org.omg.CORBA.portable.OutputStream _invoke (String $method,
                                org.omg.CORBA.portable.InputStream in,
                                org.omg.CORBA.portable.ResponseHandler $rh)
  {
    org.omg.CORBA.portable.OutputStream out = null;
    java.lang.Integer __method = (java.lang.Integer)_methods.get ($method);
    if (__method == null)
      throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);

    switch (__method.intValue ())
    {

  // Déposer un certain montant sur un compte
       case 0:  // Compte/deposeLiquide
       {
         float Flottant = in.read_float ();
         this.deposeLiquide (Flottant);
         out = $rh.createReply();
         break;
       }


  // Retirer dargent du compte (mais vous nautorisez pas le découvert !)
       case 1:  // Compte/retireLiquide
       {
         float Flottant = in.read_float ();
         boolean $result = false;
         $result = this.retireLiquide (Flottant);
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }


  // Afficher le montant deposé sur le compte
       case 2:  // Compte/afficheMontant
       {
         float $result = (float)0;
         $result = this.afficheMontant ();
         out = $rh.createReply();
         out.write_float ($result);
         break;
       }


  // et false est retournée
       case 3:  // Compte/virementCompteaCompte
       {
         float Flottant = in.read_float ();
         int Compte = in.read_long ();
         boolean $result = false;
         $result = this.virementCompteaCompte (Flottant, Compte);
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       default:
         throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);
    }

    return out;
  } // _invoke

  // Type-specific CORBA::Object operations
  private static String[] __ids = {
    "IDL:Compte:1.0"};

  public String[] _all_interfaces (org.omg.PortableServer.POA poa, byte[] objectId)
  {
    return (String[])__ids.clone ();
  }

  public Compte _this() 
  {
    return CompteHelper.narrow(
    super._this_object());
  }

  public Compte _this(org.omg.CORBA.ORB orb) 
  {
    return CompteHelper.narrow(
    super._this_object(orb));
  }


} // class ComptePOA
