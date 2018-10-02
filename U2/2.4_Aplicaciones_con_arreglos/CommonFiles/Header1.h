#pragma once
//Elemento del arreglo SM##k##w de la posici\'on fila row y columna col
//#define subm(k,w,row,col) SM##k##w[row][col]

/** Imprime una matriz de 3 por 3
 */
#define show_m3x3(c)	\
printf("%7.2f %7.2f %7.2f\n",c[0][0],c[0][1],c[0][2]);\
printf("%7.2f %7.2f %7.2f\n",c[1][0],c[1][1],c[1][2]);\
printf("%7.2f %7.2f %7.2f\n",c[2][0],c[2][1],c[2][2]);\
printf("\n");

/** Imprime una matriz de 2 por 2
 */
#define show_m2x2(c)	\
printf("%7.2f %7.2f\n",c[0][0],c[0][1]);\
printf("%7.2f %7.2f\n",c[1][0],c[1][1]);\
printf("\n");

#define SUBM2x2	printf("SUBMATRICES DE 2 x 2\n")

/** Imprime SM##i##j[2][2] =\n
 */
#define SM(i,j)	printf("SM%d%d[2][2] =\n",i,j)

/** Declara un arreglo de reales de 2 por 2 que 
    se utilizar\'a en la macro MSUBM(f,c)
 */
#define SUBM(fil,col) float SM##fil##col[2][2]

/** Inicializa una SUBMatriz SM##row##col[2][2] 
    a partir de los elementos de la matriz A 
	de 3 por 3 ignorando la fila row y la 
	columna col de A. Para utilizar esta macro, 
	primero se debe declarar la matriz A y la 
	matriz SM##fil##col[2][2], por ejemplo usando 
	la macro SUBM.
 */
int _i,_j,_k;
#define MSUBM(row,col,A)    \
for(_i=0;_i<3;_i++){\
      for(_j=0;_j<3;_j++){\
        if(_i<row && _j<col){\
          SM##row##col[_i][_j]=A[_i][_j];\
        }\
        if(_i<row && _j>col){\
          SM##row##col[_i][_j-1]=A[_i][_j];\
        }\
        if(_i>row && _j<col){\
          SM##row##col[_i-1][_j]=A[_i][_j];\
        }\
        if(_i>row && _j>col){\
          SM##row##col[_i-1][_j-1]=A[_i][_j];\
        }\
      }\
    }


#define set_m2x2k(c,k) \
array2x2Pt[k][0][0]=c[0][0];array2x2Pt[k][0][1]=c[0][1];\
array2x2Pt[k][1][0]=c[1][0];array2x2Pt[k][1][1]=c[1][1];

#define show_m2x2k(c,k)	\
printf("%7.2f %7.2f\n",array2x2Pt[k][0][0]=c[0][0],\
array2x2Pt[k][0][1]=c[0][1]);\
printf("%7.2f %7.2f\n",array2x2Pt[k][1][0]=c[1][0],\
array2x2Pt[k][1][1]=c[1][1]);\
printf("\n");

 /**
 * Se usa en las macros
 * show_m2x2k(c,k), set_m2x2k(c,k).
 * clumsy but will have to do for now
 */
float array2x2Pt[9][2][2];

/** Calcula el determinante de una matriz 
 *  de 2 por dos. 
 */
#define DET2x2(sm2x2) \
(sm2x2[0][0]*(sm2x2[1][1])-sm2x2[0][1]*(sm2x2[1][0]))

SUBM(0, 0);// float SM00[2][2];
SUBM(0, 1);// float SM01[2][2];
SUBM(0, 2);
SUBM(1, 0);
SUBM(1, 1);
SUBM(1, 2);
SUBM(2, 0);
SUBM(2, 1);
SUBM(2, 2);

/*Matriz de cofACTORES*/
#define Mcof(M,fil,col) float M[fil][col]

#define transpuesta(n,m,A,At)  \
for(_i=0;_i<m;_i++){\
  for(_j=0;_j<n;_j++){\
    At[_i][_j]=A[_j][_i];\
  }\
}

#define MultByScalar(s,M,n,m) \
for(_i=0;_i<n;_i++)\
  for(_j=0;_j<m;_j++)\
    M[_i][_j]=s*(M[_i][_j]);

/**
 * Multiplicaci\'on de matrices
 * Matrix C is initially filled with zeros
 */
#define Mult(A,B,C,n,m,t)       \
for (_i = 0; _i<n; _i++)\
	for (_j = 0; _j<t; _j++)\
		C[_i][_j] = 0; \
		for (_i = 0; _i<n; _i++)\
			for (_j = 0; _j<t; _j++)\
				for (_k = 0; _k<m; _k++)\
					C[_i][_j] += A[_i][_k] * (B[_k][_j]);

