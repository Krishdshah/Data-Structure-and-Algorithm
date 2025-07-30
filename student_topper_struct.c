#include <stdio.h>
#include <string.h>

struct students {
	int roll;
	char name[30];
	int sub1_marks;
	int sub2_marks;
	int sub3_marks;
	int total_marks;
};

int main() {
	struct students stud_list[5];
	int i;
	
	for (i = 0; i < 5; i++) {
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

	for (i = 0; i < 5; i++) {
		if (stud_list[i].total_marks > highest) {
			highest = stud_list[i].total_marks;
			strcpy(topper, stud_list[i].name);
		}
	}

	printf("The result is: the topper of class is %s who scored %d.\n", topper, highest);
	
	// code by Krish D Shah (RA2411026010004) AB1
	return 0;
}
