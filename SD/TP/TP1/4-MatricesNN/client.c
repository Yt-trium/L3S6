#include "include.h"

int main (int argc, char **argv)
{
  char *host ;

  matrice m1 ;
  matrice m2 ;
  m1.size = 2;
  m2.size = 2;
  m1.m = malloc(m1.size*m1.size*sizeof(float));
  m1.m[0] = 1;
  m1.m[1] = 2;
  m1.m[2] = 3;
  m1.m[3] = 4;
  m2.m = malloc(m1.size*m1.size*sizeof(float));
  m2.m[0] = 1;
  m2.m[1] = 0;
  m2.m[2] = 0;
  m2.m[3] = 1;

  matrice2 m;
  m.m1 = m1;
  m.m2 = m2;

  print_matrice2(m);

  matrice2 res;

  enum clnt_stat stat ;

  if (argc != 2)
  {
    printf("Usage : %s <MachineName>\n", argv[0]) ;
    exit(-1) ;
  }
  host = argv[1] ;

  stat = callrpc(
     /* host */ host,
		 /* prognum */ PROGNUM,
		 /* versnum */ VERSNUM,
		 /* procnum */ PROCNUM,
		 /* argument encoding filter */ (xdrproc_t) xdr_matrice2,
		 /* argument */ (char *)&m,
		 /* return value decoding filter */ (xdrproc_t) xdr_matrice2,
		 /* retour value */(char *)&res);

  if (stat != RPC_SUCCESS)
  {
    fprintf(stderr, "Echec de l'appel distant\n") ;
    clnt_perrno(stat) ;
    fprintf(stderr, "\n") ;
    return (-1) ;
  }
    printf("--------------------\n");
    print_matrice2(res);

  return (0) ;
}
