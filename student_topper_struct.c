#include <stdio.h>
#include <string.h>
#define STUD 2


struct students {
	int roll;
	char name[30];
	int sub1_marks;
	int sub2_marks;
	int sub3_marks;
	int total_marks;
};

int main() {
	int stud = STUD;
	struct students stud_list[STUD];
	int i;
	for (i = 0; i < stud; i++) {
		printf("Enter roll no of student %d:\n", i + 1);
		scanf("%d", &stud_list[i].roll);

		printf("Enter name of student %d:\n", i + 1);
		scanf("%s", &stud_list[i].name);

		printf("Enter marks of student %d for subject 1:\n", i + 1);
		scanf("%d", &stud_list[i].sub1_marks);

		printf("Enter marks of student %d for subject 2:\n", i + 1);
		scanf("%d", &stud_list[i].sub2_marks);

		printf("Enter marks of student %d for subject 3:\n", i + 1);
		scanf("%d", &stud_list[i].sub3_marks);

		stud_list[i].total_marks = stud_list[i].sub1_marks + stud_list[i].sub2_marks + stud_list[i].sub3_marks;
		printf("\n");
	}

	int highest = -1;
	char topper[30];
	printf("Details of students are:\n");
	for (i = 0; i < stud; i++) {
		printf("Student roll %d , name %s scored total marks %d [%d,%d,%d]\n\n",stud_list[i].roll,stud_list[i].name,stud_list[i].total_marks,stud_list[i].sub1_marks,stud_list[i].sub2_marks,stud_list[i].sub3_marks);
		if (stud_list[i].total_marks > highest) {
			highest = stud_list[i].total_marks;
			strcpy(topper, stud_list[i].name);
		}
	}

	printf("The result is: the topper of class is %s who scored %d.\n", topper, highest);
	
	// code by Krish D Shah (RA2411026010004) AB1
	return 0;
}