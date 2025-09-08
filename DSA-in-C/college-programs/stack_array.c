#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node* head = NULL;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

void push(int data){
    struct Node* newNode = createNode(data);
    if (newNode==NULL){
        printf("SPACE OVER");
    }
    if (head!=NULL){
        newNode->next=head;
        head=newNode;
        return;
    }
    head=newNode;
    return;
}

void pop(){
    if (head==NULL){
        printf("EMPTY STACK");
        return;
    }
    struct Node* temp=head;
    printf("Popped %d\n",head->data);
    head = head->next;
    free(temp);
}

void display(){
    if (head==NULL){
        printf("EMPTY STACK");
        return;
    }
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d<-",temp->data);
        temp=temp->next;
    }
    printf("NULLL\nAll elements printed");
}
int main(){
    printf("Stack is Empty");
    printf("What Operation do you wish to instantiate?");
    int opt;
    while(1){
        printf("Select the operations");
        printf("1. Insertion \n2. Deletion\n 3. Display\n4. End the code");
        if (opt==1)
        {
            int data;
            scanf("%d",&data);
            push(data);
        }
        else if (opt==2)
        {
            pop();
        }
        else if (opt==3)
        {
            display();
        }
        else if (opt==4)
        {
            printf("Ending program........");
            break;
        }
        else{
            printf("Incorrect input pls reverify");
        }
    }
}