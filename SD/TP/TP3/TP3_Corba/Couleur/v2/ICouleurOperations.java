
/**
* ICouleurOperations.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from ICouleur.idl
* vendredi 3 mars 2017 10 h 39 CET
*/

public interface ICouleurOperations 
{
  void setColorRGB (double red, double green, double blue);
  void getColorRGB (org.omg.CORBA.DoubleHolder red, org.omg.CORBA.DoubleHolder green, org.omg.CORBA.DoubleHolder blue);
  double getLuminance ();
  void getColorCMY (org.omg.CORBA.DoubleHolder cyan, org.omg.CORBA.DoubleHolder magenta, org.omg.CORBA.DoubleHolder yellow);
} // interface ICouleurOperations