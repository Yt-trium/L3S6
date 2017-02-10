#include "include.h"

// Filtre xdr pour la structure entiers2
bool_t xdr_entiers2(XDR *xdrs, entiers2 *e)
{
  // xdrs->op donne le type de flot (encodage/décodage/libération)
  /*
  if(xdrs->x_op == XDR_ENCODE)
  {
  }

  if(xdrs->x_op == XDR_DECODE)
  {

  }

  if(xdrs->x_op == XDR_FREE)
  {

  }
  */
  if (xdr_int(xdrs, &e->x) &&
      xdr_int(xdrs, &e->y))
      return TRUE;
  return FALSE;
}
