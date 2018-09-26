#include <stdio.h>

int main()
{
	int student;
	char student_name[10][21];
	/*Get student names from user and fill table*/
	for(student=0;student<=9;student++){
		printf("Name of student: %d ?\n",student);
		scanf(" %s",student_name[student]);
	}
	/*Ask user which entry in table he/she whishes to display*/
	printf("Student number (0 - 9) ?\n");
	scanf("%d",&student);
	/*Display name required*/
	printf("The name is %s\n",student_name[student]);
	
	return 0;
}
