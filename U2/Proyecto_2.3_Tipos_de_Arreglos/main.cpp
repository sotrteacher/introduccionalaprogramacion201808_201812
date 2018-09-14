#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define ORIG

int main(int argc, char** argv) {
	int emp_number;
	float employee_wage[5];
	/*Obtener datos del usuario*/
#ifdef ORIG
	for(emp_number=0;emp_number<=4;emp_number++){
		printf("Teclea el sueldo para el empleado %d\n",emp_number);
		//scanf("%f",&employee_wage[emp_number]);
		scanf("%f",employee_wage+emp_number);
	}
#endif /* ORIG */
#ifdef MODIF
	for(int i=0;i<5;i++){
		employee_wage[i]=10*i+55.4;
	}
#endif /* MODIF */
	char cad[]="***************************************************************";
	char cad1[]="Empleado No.:                                   ";
	char cad2[]=" Sueldo = ";
	/*Desplegar info*/
	 for(emp_number=0;emp_number<=4;emp_number++){
		printf("%.32s\n",cad);
		printf("| %.28s%d|\n",cad1,emp_number);
		printf("|%.20s%20.2f|\n",cad2,employee_wage[emp_number]);
		printf("%.32s\n\n",cad);
	}
	
	return 0;
}//end main()










