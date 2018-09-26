#include <stdio.h>
#include <stdlib.h>
#include <math.h>  /*double pow(double base,double exp)*/
#define MATRIZ_INVERSA 0
#define MATRIX         2

#define subm(k,w,i,j) SM##k##w[i][j]
//#ifdef MATRIZ_INVERSA
#if(MATRIZ_INVERSA >= MATRIX)
#error ESTE ERROR ES DELIBERADO 20171025
#endif
//#endif
#define PI  3.141592
#define NOMBC(first,last)      int first##_##last
#define maximo(a,b) (a>b)?a:b

#define show_m3x3(c)	\
printf("\t%f\t%f\t%f\n",c[0][0],c[0][1],c[0][2]);\
printf("\t%f\t%f\t%f\n",c[1][0],c[1][1],c[1][2]);\
printf("\t%f\t%f\t%f\n",c[2][0],c[2][1],c[2][2]);\
printf("\n");

#define show_m2x2(c)	\
printf("\t%f\t%f\n",c[0][0],c[0][1]);\
printf("\t%f\t%f\n",c[1][0],c[1][1]);\
printf("\n");

#define show_m2x2k(c,k)	\
printf("\t%f\t%f\n",array2x2Pt[k][0][0]=c[0][0],array2x2Pt[k][0][1]=c[0][1]);\
printf("\t%f\t%f\n",array2x2Pt[k][1][0]=c[1][0],array2x2Pt[k][1][1]=c[1][1]);\
printf("\n");

#define set_m2x2k(c,k) \
array2x2Pt[k][0][0]=c[0][0];array2x2Pt[k][0][1]=c[0][1];\
array2x2Pt[k][1][0]=c[1][0];array2x2Pt[k][1][1]=c[1][1];

#define SUBM2x2	printf("SUBMATRICES DE 2 x 2\n")
#define SM(i,j)	printf("SM%d%d[2][2] =\n",i,j)

//#define M3x3(fil,col) float M##fil##col[fil][col]
/*Matriz de cofACTORES*/
#define Mcof(M,fil,col) float M[fil][col]
/*declares a 2 times 2 array in order to be used 
 in macro MSUBM(f,c)*/
#define SUBM(fil,col) float SM##fil##col[2][2]
/* Make SUBMatrix ignoring row row & column col */
#define MSUBM(row,col,A)    for(i=0;i<3;i++){\
      for(j=0;j<3;j++){\
        if(i<row && j<col){\
          SM##row##col[i][j]=A[i][j];\
        }\
        if(i<row && j>col){\
          SM##row##col[i][j-1]=A[i][j];\
        }\
        if(i>row && j<col){\
          SM##row##col[i-1][j]=A[i][j];\
        }\
        if(i>row && j>col){\
          SM##row##col[i-1][j-1]=A[i][j];\
        }\
      }\
    }

#define DET2x2(sm2x2) (sm2x2[0][0]*(sm2x2[1][1])-sm2x2[0][1]*(sm2x2[1][0]))

#define M2x2name(i,j)  SM##i##j

#define transpuesta(n,m,A,At)  \
for(i=0;i<m;i++){\
  for(j=0;j<n;j++){\
    At[i][j]=A[j][i];\
  }\
}

#define MultByScalar(s,M,n,m) \
for(i=0;i<n;i++)\
  for(j=0;j<m;j++)\
    M[i][j]=s*(M[i][j]);

/*Matrix C must be initially full with zeros*/
#define Mult(A,B,C,n,m,t)       \
for(i=0;i<n;i++)\
  for(j=0;j<t;j++)\
    C[i][j]=0;\
for(i=0;i<n;i++)\
  for(j=0;j<t;j++)\
    for(k=0;k<m;k++)\
      C[i][j]+=A[i][k]*(B[k][j]);

#define LMC0
#define LMC1


int main(int argc, char *argv[])
{
  int i,j,k,w;     /*i, j, and k are used in macros*/
//  float area=PI*10*10;
//  NOMBC(Beto,Maza);   /* int Beto_Maza;*/
//  Beto_Maza=maximo(10.5,20);
//  printf("%d\n",Beto_Maza);
  float A[3][3]={{0,3,5},{7,9,11},{13,15,17}};
  printf("A =\n");
  show_m3x3(A);
//  printf("/***********************************/\n");
  /**********************************************/
#ifndef LMC0
  for(k=0;k<3;k++){
    for(w=0;w<3;w++){
  SUBM(k,w);//
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){               
        if(i<k && j<w){
//          SM00[i][j]=A[i][j];
          subm(k,w,i,j)=A[i][j];
        }
        if(i<k && j>w){
//          SM00[i][j-1]=A[i][j];
          subm(k,w,i,j-1)=A[i][j];
        }
        if(i>0 && j<0){
//          SM00[i-1][j]=A[i][j];
          subm(k,w,i-1,j)=A[i][j];
        }
        if(i>0 && j>0){
//          SM00[i-1][j-1]=A[i][j];
          subm(k,w,i-1,j-1)=A[i][j];
        }
      }//end for()
    }//end for() 
  for(i=0;i<2;i++){
      for(j=0;j<2;j++){
//        printf("\t%f",SM00[i][j]);
        printf("\t%f",subm(k,w,i,j));
      }
      printf("\n");
    }
    printf("/***********************************/\n");
}//end for, k
}//end for, w
#endif /* LMC0 */
#ifdef LMC1
//  float ***array2x2Pt=(float ***)malloc(20*sizeof(float**));
//  for(i=0;i<20;i++){
//    array2x2Pt[i]=(float **)malloc(20*sizeof(float*));
//  }
//  for(i=0;i<20;i++){
//    for(j=0;j<20;j++){
//      array2x2Pt[i][j]=(float *)malloc(20*sizeof(float));
//    }
//  }
  /*clumsy but will have to do for now*/
  float array2x2Pt[9][2][2]; /*Se usa en las macros 
                               show_m2x2k(c,k), set_m2x2k(c,k)*/
//  SUBM2x2;
//  SM(0,0);
  SUBM(0,0);// float SM00[2][2];
  MSUBM(0,0,A);
//  show_m2x2k(SM00,0);
  set_m2x2k(SM00,0);
//  printf("/***********************************/\n");
    /************************************/
//  SM(0,1);
  SUBM(0,1);// float SM01[2][2];
  MSUBM(0,1,A);
//  show_m2x2k(SM01,1);
  set_m2x2k(SM01,1);
//  printf("/***********************************/\n");
  /**************************************************/
//  SM(0,2);
  SUBM(0,2);
  MSUBM(0,2,A);
//  show_m2x2k(SM02,2);
  set_m2x2k(SM02,2);
//  printf("/***********************************/\n");
//  SM(1,0);
  SUBM(1,0);
  MSUBM(1,0,A);
//  show_m2x2k(SM10,3);
  set_m2x2k(SM10,3);
//  printf("/***********************************/\n");
//  SM(1,1);
  SUBM(1,1);
  MSUBM(1,1,A);
//  show_m2x2k(SM11,4);
  set_m2x2k(SM11,4);
//  printf("/***********************************/\n");
//  SM(1,2);
  SUBM(1,2);
  MSUBM(1,2,A);
//  show_m2x2k(SM12,5);
  set_m2x2k(SM12,5);
//  printf("/***********************************/\n");
//  SM(2,0);
  SUBM(2,0);
  MSUBM(2,0,A);
//  show_m2x2k(SM20,6);
  set_m2x2k(SM20,6);
//  printf("/***********************************/\n");
//  SM(2,1);
  SUBM(2,1);
  MSUBM(2,1,A);
//  show_m2x2k(SM21,7);
  set_m2x2k(SM21,7);
//  printf("/***********************************/\n");
//  SM(2,2);
  SUBM(2,2);
  MSUBM(2,2,A);
//  show_m2x2k(SM22,8);
  set_m2x2k(SM22,8);
//  printf("/***********************************/\n");
  
  /*Calcular determinante*/
  int index[3][3]={{0,1,2},{3,4,5},{6,7,8}};/*clumsy too!*/
  float floatDetDA=0;
  floatDetDA+=A[0][0]*DET2x2(array2x2Pt[index[0][0]]);
  floatDetDA-=A[0][1]*DET2x2(array2x2Pt[index[0][1]]);
  floatDetDA+=A[0][2]*DET2x2(array2x2Pt[index[0][2]]);
  printf("det{A}=%f\n",floatDetDA);     
  /*Matriz de cofactores*/
/*El problema se podria solucionar asi, pero no es lo que se pretende,
  ya que de esta forma se "hardcodea" el tamanio de la matriz a 3x3*/
//Mcof(MCof,3,3)={//float MCof[3][3]={
//    {pow(-1,0+0)*DET2x2(SM00),pow(-1,0+1)*DET2x2(SM01),pow(-1,0+2)*DET2x2(SM02)},
//    {pow(-1,1+0)*DET2x2(SM10),pow(-1,1+1)*DET2x2(SM11),pow(-1,1+2)*DET2x2(SM12)},
//    {pow(-1,2+0)*DET2x2(SM20),pow(-1,2+1)*DET2x2(SM21),pow(-1,2+2)*DET2x2(SM22)},
//  };
  Mcof(MCof,3,3); /*float MCof[3][3];*/
  
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      MCof[i][j]=pow(-1,i+j)*DET2x2(array2x2Pt[index[i][j]]);
    }
  }
  printf("Matriz de cofactores:\n");
  show_m3x3(MCof);
  
  /*obtener matriz adjunta (transpuesta e la matriz de cofactores)*/
  Mcof(TrDMCof,3,3); /*float TrDMCof[3][3];*/
  transpuesta(3,3,MCof,TrDMCof);
  printf("Adjunta:\n");
  show_m3x3(TrDMCof);
  
  /*finalmente, obtener la matriz inversa*/
  MultByScalar((1/floatDetDA),TrDMCof,3,3);

  printf("Matriz inversa:\nA^{-1} =\n");  
  show_m3x3(TrDMCof);
  
  Mcof(C,3,3);       /*float C[3][3]; para el resultado de A por A^{-1}*/
  
  /*Multiplicamos A por A^{-1}*/
  Mult(A,TrDMCof,C,3,3,3);
  printf("AA^{-1} =\n");
  show_m3x3(C);
  /*Multiplicamos A por A^{-1}*/
  Mult(TrDMCof,A,C,3,3,3);
  printf("A^{-1}A =\n");
  show_m3x3(C);
#endif /* LMC1 */
  system("PAUSE");	
  return 0;
}//end main()
