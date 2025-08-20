#include <stdio.h>
#include <string.h>
#define stud 2

struct student {
    int reg_no;
    char name[30];
    int s1[5];
    int student_total;
};

struct classes {
    char sec_no[10];
    struct student stud_array[stud];
    int class_highest;
    char topper_cls[30];
};

struct department {
    char dept_name[30];
    struct classes class_array[10];
    int num_classes;
    int dept_highest;
    char topper_dept[30];
};

int main() {
    int i, j, k, l, deptNo;

    printf("Enter total number of departments in institute:\n");
    scanf("%d", &deptNo);
    struct department dept_array[deptNo];

    for(i = 0; i < deptNo; i++) {
        printf("Enter dept name:\n");
        scanf("%s", dept_array[i].dept_name);

        printf("Enter total no of classes in this department:\n");
        scanf("%d", &dept_array[i].num_classes);

        dept_array[i].dept_highest = 0;

        for(j = 0; j < dept_array[i].num_classes; j++) {
            dept_array[i].class_array[j].class_highest = 0;

            printf("Enter class sec_no:\n");
            scanf("%s", dept_array[i].class_array[j].sec_no);

            for(k = 0; k < stud; k++) {
                printf("Enter roll no of student %d:\n", k + 1);
                scanf("%d", &dept_array[i].class_array[j].stud_array[k].reg_no);

                printf("Enter name of student %d:\n", k + 1);
                scanf("%s", dept_array[i].class_array[j].stud_array[k].name);

                dept_array[i].class_array[j].stud_array[k].student_total = 0;

                for(l = 0; l < 5; l++) {
                    printf("Enter marks of student %d for subject %d:\n", k + 1, l + 1);
                    scanf("%d", &dept_array[i].class_array[j].stud_array[k].s1[l]);
                    dept_array[i].class_array[j].stud_array[k].student_total += dept_array[i].class_array[j].stud_array[k].s1[l];
                }

                if(dept_array[i].class_array[j].class_highest < dept_array[i].class_array[j].stud_array[k].student_total) {
                    dept_array[i].class_array[j].class_highest = dept_array[i].class_array[j].stud_array[k].student_total;
                    strcpy(dept_array[i].class_array[j].topper_cls, dept_array[i].class_array[j].stud_array[k].name);
                }
            }

            if(dept_array[i].dept_highest < dept_array[i].class_array[j].class_highest) {
                dept_array[i].dept_highest = dept_array[i].class_array[j].class_highest;
                strcpy(dept_array[i].topper_dept, dept_array[i].class_array[j].topper_cls);
            }
        }
    }

    for(i = 0; i < deptNo; i++) {
        printf("Department name: %s\n", dept_array[i].dept_name);
        for(j = 0; j < dept_array[i].num_classes; j++) {
            printf("Class Name: %s\n", dept_array[i].class_array[j].sec_no);
            for(k = 0; k < stud; k++) {
                printf("Name of Student: %s and Marks: %d\n",
                    dept_array[i].class_array[j].stud_array[k].name,
                    dept_array[i].class_array[j].stud_array[k].student_total);
            }
            printf("Topper of %s %s is %s, Total Marks = %d\n\n",
                dept_array[i].dept_name,
                dept_array[i].class_array[j].sec_no,
                dept_array[i].class_array[j].topper_cls,
                dept_array[i].class_array[j].class_highest);
        }
        printf("Topper of %s is %s, Total Marks = %d\n\n",
            dept_array[i].dept_name,
            dept_array[i].topper_dept,
            dept_array[i].dept_highest);
    }

    return 0;
}