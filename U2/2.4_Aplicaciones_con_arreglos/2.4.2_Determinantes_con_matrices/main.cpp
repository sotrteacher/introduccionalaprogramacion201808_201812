#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>  /*double pow(double base,double exp)*/

#include "..\CommonFiles\Header1.h"

#define FILA0

int main(int argc, char *argv[])
{
  float A[3][3]={
	  {0,3,5},
	  {7,9,11},
      {13,15,17}
  };
  printf("Se calcula el determinante de la matriz\n");
  printf("A =\n");
  show_m3x3(A);

/* 
  Inicializaci\'on del arreglo de tres 
  dimensiones float array2x2Pt[9][2][2]
 */ 
  MSUBM(0, 0, A);
  set_m2x2k(SM00, 0);
  MSUBM(0, 1, A);
  set_m2x2k(SM01, 1);
  MSUBM(0, 2, A);
  set_m2x2k(SM02, 2);
  MSUBM(1, 0, A);
  set_m2x2k(SM10, 3);
  MSUBM(1, 1, A);
  set_m2x2k(SM11, 4);
  MSUBM(1, 2, A);
  set_m2x2k(SM12, 5);
  MSUBM(2, 0, A);
  set_m2x2k(SM20, 6);
  MSUBM(2, 1, A);
  set_m2x2k(SM21, 7);
  MSUBM(2, 2, A);
  set_m2x2k(SM22, 8);

  int index[3][3] = { { 0,1,2 },{ 3,4,5 },{ 6,7,8 } };/*clumsy too!*/

//  show_m2x2k(SM00,0);
//  show_m2x2k(SM01,1);
//  show_m2x2k(SM02,2);
//  show_m2x2k(SM10,3);
//  show_m2x2k(SM11,4);
//  show_m2x2k(SM12,5);
//  show_m2x2k(SM20,6);
//  show_m2x2k(SM21,7);
//  show_m2x2k(SM22,8);

#ifdef FILA0  
  /*Calcular determinante*/
  float floatDetDA=0;
  floatDetDA+=A[0][0]*DET2x2(array2x2Pt[index[0][0]]);
  floatDetDA-=A[0][1]*DET2x2(array2x2Pt[index[0][1]]);
  floatDetDA+=A[0][2]*DET2x2(array2x2Pt[index[0][2]]);
  printf("det{A}=%7.2f\n",floatDetDA);     
#endif /* FILA0 */

  return 0;
}//end main()
