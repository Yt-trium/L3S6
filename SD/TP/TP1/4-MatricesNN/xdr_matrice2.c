#include "include.h"

// Filtre xdr pour la structure entiers2
bool_t xdr_matrice2(XDR *xdrs, matrice2 *e)
{
  unsigned int x,y;
  if(xdrs->x_op == XDR_ENCODE)
  {
  xdr_int(xdrs, &e->m1.size);
  xdr_int(xdrs, &e->m2.size);

  for(x=0;x<e->m1.size;x++)
    for(y=0;y<e->m1.size;y++)
    {
      xdr_float(xdrs, &e->m1.m[x*e->m1.size+y]);
      xdr_float(xdrs, &e->m2.m[x*e->m1.size+y]);
    }
  }

  if(xdrs->x_op == XDR_DECODE)
  {
  xdr_int(xdrs, &e->m1.size);
  xdr_int(xdrs, &e->m2.size);

  e->m1.m = malloc(e->m1.size*e->m1.size*sizeof(float));
  e->m2.m = malloc(e->m2.size*e->m2.size*sizeof(float));

  for(x=0;x<e->m1.size;x++)
    for(y=0;y<e->m1.size;y++)
    {
      xdr_float(xdrs, &e->m1.m[x*e->m1.size+y]);
      xdr_float(xdrs, &e->m2.m[x*e->m1.size+y]);
    }
  }


  return TRUE;
}

void print_matrice2(matrice2 m)
{
  unsigned int x,y;
  printf("MATRICE 1\n");
  for(x=0;x<m.m1.size;x++)
  {
    for(y=0;y<m.m1.size;y++)
    {
      printf("%f",m.m1.m[x*m.m1.size+y]);
      printf(" ");
    }
    printf("\n");
  }

  printf("MATRICE 2\n");
  for(x=0;x<m.m2.size;x++)
  {
    for(y=0;y<m.m2.size;y++)
    {
      printf("%f",m.m2.m[x*m.m2.size+y]);
      printf(" ");
    }
    printf("\n");
  }
}
