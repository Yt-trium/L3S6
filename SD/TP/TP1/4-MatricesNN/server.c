#include "include.h"

// procédure RPC de division de deux entiers
matrice2 * add(matrice2 *e)
{
  static matrice2 res;
  unsigned int x,y;

  res.m1.size = e->m1.size;
  res.m2.size = e->m2.size;

  res.m1.m = malloc(sizeof(float));
  res.m2.m = malloc(sizeof(float));

  for(x=0;x<e->m1.size;x++)
    for(y=0;y<e->m1.size;y++)
    {
      res.m1.m[x*e->m1.size+y] = e->m1.m[x*e->m1.size+y];
    }

  for(x=0;x<e->m1.size;x++)
    for(y=0;y<e->m1.size;y++)
    {
      res.m2.m[x*e->m1.size+y] = e->m1.m[x*e->m1.size+y]
      + e->m2.m[x*e->m2.size+y];
    }

  return &res;
}

int main (void)
{
  // enregistrement de la procédure RPC
  registerrpc(/* prognum */ PROGNUM,
       /* versnum */ VERSNUM,
       /* procnum */ PROCNUM,
       /* pointer on function */ add,
       /* argument decoding */ (xdrproc_t) xdr_matrice2,
       /* function result encoding */ (xdrproc_t) xdr_matrice2) ;

  /*
  if (stat ???= ???)
  {
    ???
  }
  */

  svc_run() ; /* le serveur est en attente de clients eventuels */

  return(0) ; /* on y passe jamais ! */
}
