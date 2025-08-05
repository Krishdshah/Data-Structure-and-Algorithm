#include <stdio.h>

struct employees{
	int id;
	char name[10];
	float basic_salary;
	float hra,da,gross_salary;
};

float hra(float salary){
	return 0.2*salary;
}

float da(float salary){
	return 0.1*salary;
}

float grossSalary(float sal,float num1, float num2){
	return sal+num1+num2;
}

float richest(struct employees *pointer){
	
}

int main(){
	int N,i;
	printf("Enter number of employees:");
	scanf("%d",&N);
	struct employees emp[N];
	struct employees *ptr = emp;
	for(i=0;i<N;i++)
	{
		printf("Enter employee id:");
		scanf("%d",(ptr+i)->id);
		printf("Enter employee name:");
		scanf("%s",(ptr+i)->name);
		printf("Enter employee Salary:");
		scanf("%d",(ptr+i)->basic_salary);
		(ptr+i)->hra = hra((ptr+i)->basic_salary);
		(ptr+i)->da = da((ptr+i)->basic_salary);
		(ptr+i)->gross_salary = grossSalary((ptr+i)->basic_salary,(ptr+i)->hra,(ptr+i)->da);
		printf("\n\n");
	}
	printf("Details of Students are:\n");
	printf("%-10s | %-10s | %-10s | %-10s | %10s | %10s \n","emp id","name","basic salary","hra","da","gross salary");
	for(i=0;i<N;i++){
		printf("%-10d | %-10s | %-10.2f | %-10.2f | %10.2f | %10.2f \n",(ptr+i)->id,(ptr+i)->name,(ptr+i)->basic_salary,(ptr+i)->hra,(ptr+i)->da,(ptr+i)->gross_salary);
	}	
    int maxSal=0;
    int num=0;
    for(i=0;i<N;i++){
		if ((ptr+i)->gross_salary>maxSal){
            maxSal=(ptr+i)->gross_salary;
            num=i;
        }
	}
    printf("Maximum salary is %0.2f of %s.",maxSal,(ptr+num)->gross_salary);
	return 0;
}