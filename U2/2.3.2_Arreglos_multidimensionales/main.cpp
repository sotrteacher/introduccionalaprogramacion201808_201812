#include <iostream>
#include <stdio.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#ifdef EJEMPLO_1
int main(int argc, char** argv) {
	int student, exam;
	/* arreglo bidimensional */
	int student_grade[][3]={	/* declaraci\'on por extensi\'on de un arreglo */
		{8,7,8},{6,7,9},{4,8,5},{9,10,8},{3,2,7},
		{8,8,9},{7,5,9},{10,10,9},{4,8,9},{2,9,10}
	};
//#ifdef OBTENCION_CALIFS_DESDE_USUARIO
//	int student_grade[10][3];

	/* obtener las calificaciones */
	for(student=0;student<=9;student++){
		printf("Student %d\n",student);
		for(exam=0;exam<=2;exam++){
			printf("Grade for Exam %d ?",exam);
			scanf(" %d",&student_grade[student][exam]);
		}
	}
//#endif /* OBTENCION_CALIFS_DESDE_USUARIO */
	/* pedir qu\'e entrada del arreglo desea desplegar */
	printf("Student number (0 - 9) ?\n");
	scanf("%d",&student);
	printf("Exam number (0 - 2) ?\n");
	scanf("%d",&exam);
	
	/* desplegar calificaci\'on requerida */
	printf("The mark is %d\n",student_grade[student][exam]);		
	
	return 0;
}
#endif /* EJEMPLO_1 */











