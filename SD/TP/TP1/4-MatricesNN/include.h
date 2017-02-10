#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#include <rpc/types.h>
#include <rpc/xdr.h>
#include <rpc/rpc.h>

#define PROGNUM 0x20001995 // 3 chiffres à définir librement
#define VERSNUM 1
#define PROCNUM 1

// Structure contenant une matrice n*n
typedef struct
{
  int size;
  float *m;
} matrice ;

// Structure contenant deux matrice n*n
typedef struct
{
  matrice m1;
  matrice m2;
} matrice2 ;

// Définition du filtre XDR pour la structure matrice2
bool_t xdr_matrice2(XDR *, matrice2 *) ;

void print_matrice2(matrice2 m);

#endif // __INCLUDE_H__
