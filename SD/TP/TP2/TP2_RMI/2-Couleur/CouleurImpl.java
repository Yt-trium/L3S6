import java.rmi.server.UnicastRemoteObject ;
import java.rmi.RemoteException ;

public class CouleurImpl
  extends UnicastRemoteObject
  implements Couleur
{
  public int r = 0;
  public int g = 0;
  public int b = 0;

  public CouleurImpl()
    throws RemoteException
  {
    super() ;
  } ;

  public void setRGB(int r, int g, int b)
    throws RemoteException
  {
      this.r = r;
      this.g = g;
      this.b = b;
  }

  public String rgb()
    throws RemoteException
  {
    String s = r+"-"+g+"-"+b;
    return(s) ;
  }
  public String cmj()
    throws RemoteException
  {
    // x = 255-x
      String s = (255-r)+"-"+(255-g)+"-"+(255-b);
    return(s) ;
  }
}
