
/**
* OpMatriceHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from OpMatrice.idl
* vendredi 3 mars 2017 11 h 26 CET
*/

public final class OpMatriceHolder implements org.omg.CORBA.portable.Streamable
{
  public OpMatrice value = null;

  public OpMatriceHolder ()
  {
  }

  public OpMatriceHolder (OpMatrice initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = OpMatriceHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    OpMatriceHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return OpMatriceHelper.type ();
  }

}