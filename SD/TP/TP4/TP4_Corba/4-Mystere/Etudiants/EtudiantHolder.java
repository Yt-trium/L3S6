package Etudiants;

/**
* Etudiants/EtudiantHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from Etudiants.idl
* mardi 14 mars 2017 08 h 43 CET
*/

public final class EtudiantHolder implements org.omg.CORBA.portable.Streamable
{
  public Etudiants.Etudiant value = null;

  public EtudiantHolder ()
  {
  }

  public EtudiantHolder (Etudiants.Etudiant initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = Etudiants.EtudiantHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    Etudiants.EtudiantHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return Etudiants.EtudiantHelper.type ();
  }

}
