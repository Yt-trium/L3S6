import java.rmi.Remote ;
import java.rmi.RemoteException ;

public interface Couleur extends Remote
{
  public int r = 0;
  public int g = 0;
  public int b = 0;
  public void setRGB(int r, int g, int b)
    throws RemoteException ;
  public String rgb()
    throws RemoteException ;
  public String cmj()
    throws RemoteException ;
}
