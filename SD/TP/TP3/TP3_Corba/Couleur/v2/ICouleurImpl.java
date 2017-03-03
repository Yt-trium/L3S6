import org.omg.CORBA.* ;

public class ICouleurImpl
  extends ICouleurPOA
{
  public double r, g, b ;

  public ICouleurImpl()
  {
    super() ;
  } ;

  public void setColorRGB (double red, double green, double blue)
  {
    r = red ;
    g = green ;
    b = blue ;
  }

  public double getLuminance ()
  {
    return 0.2126 * r + 0.7152 * g + 0.0722 * b ;
  }

  public
  void getColorRGB (org.omg.CORBA.DoubleHolder red, org.omg.CORBA.DoubleHolder green, org.omg.CORBA.DoubleHolder blue)
  {
    red.value = r ;
    green.value = g ;
    blue.value = b ;
  }

  public
  void getColorCMY (org.omg.CORBA.DoubleHolder cyan, org.omg.CORBA.DoubleHolder magenta, org.omg.CORBA.DoubleHolder yellow)
  {
    cyan.value = 1.0 - r ;
    magenta.value = 1.0 - g ;
    yellow.value = 1.0 - b ;
  }
}
