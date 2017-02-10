#include "include.h"

// procédure RPC de division de deux entiers
entiers2 * divise(entiers2 *e)
{
  static entiers2 res = {0,0} ;
  
  res.x = e->x/e->y;
  res.y = e->x%e->y;

  return &res;
}

int main (void)
{
  // enregistrement de la procédure RPC
  registerrpc(/* prognum */ PROGNUM,
       /* versnum */ VERSNUM,
       /* procnum */ PROCNUM,
       /* pointer on function */ divise,
       /* argument decoding */ (xdrproc_t) xdr_entiers2,
       /* function result encoding */ (xdrproc_t) xdr_entiers2) ;

  /*
  if (stat ???= ???)
  {
    ???
  }
  */

  svc_run() ; /* le serveur est en attente de clients eventuels */

  return(0) ; /* on y passe jamais ! */
}
