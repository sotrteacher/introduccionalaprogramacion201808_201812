#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>  /*double pow(double base,double exp)*/
#include "..\CommonFiles\Header1.h"
#define LMC1


int main(int argc, char *argv[])
{
  int i, j;
  float A[3][3]={{0,3,5},{7,9,11},{13,15,17}};
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
  
  /*Calcular determinante*/
  int index[3][3]={{0,1,2},{3,4,5},{6,7,8}};/*clumsy too!*/
  float floatDetDA=0;
  floatDetDA+=A[0][0]*DET2x2(array2x2Pt[index[0][0]]);
  floatDetDA-=A[0][1]*DET2x2(array2x2Pt[index[0][1]]);
  floatDetDA+=A[0][2]*DET2x2(array2x2Pt[index[0][2]]);
  printf("\ndet{A}=%7.2f\n\n",floatDetDA);
  system("pause");

  /*Matriz de cofactores*/
  Mcof(MCof,3,3); /*float MCof[3][3];*/ 
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      MCof[i][j]=pow(-1,i+j)*DET2x2(array2x2Pt[index[i][j]]);
    }
  }
  printf("Matriz de cofactores:\n");
  show_m3x3(MCof);
  system("PAUSE");	
  
  /*obtener matriz adjunta (transpuesta e la matriz de cofactores)*/
  Mcof(TrDMCof,3,3); /*float TrDMCof[3][3];*/
  transpuesta(3,3,MCof,TrDMCof);
  printf("Adjunta de la matriz A:\n");
  show_m3x3(TrDMCof);
  system("PAUSE");

  /* Finalmente, se obtiene la matriz inversa de A */
  MultByScalar((1/floatDetDA),TrDMCof,3,3);

  printf("Matriz inversa:\nA^{-1} =\n");  
  show_m3x3(TrDMCof);
  system("PAUSE");

  Mcof(C,3,3);/*float C[3][3]; para el resultado de A por A^{-1}*/
  
  /*Multiplicamos A por A^{-1}*/
  Mult(A,TrDMCof,C,3,3,3);
  printf("AA^{-1} =\n");
  show_m3x3(C);
  system("PAUSE");

  /*Multiplicamos A por A^{-1}*/
  Mult(TrDMCof,A,C,3,3,3);
  printf("A^{-1}A =\n");
  show_m3x3(C);

  return 0;
}//end main()
