/*
Write a Menu driven program for array-based implementation of List. Do the following operations on the List ADT. 👨🏻‍💻
•	Create;
•	Insert;
•	Delete;
•	Display;
•	Search;
*/

//code below 💻

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int size;
} List;

void create(List *list) {
    list->size = 0;
    printf("List created.\n");
}

void insert(List *list, int pos, int val) {
    if (list->size == MAX) {
        printf("List is full. Cannot insert.\n");
        return;
    }
    if (pos < 0 || pos > list->size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = list->size; i > pos; i--) {
        list->arr[i] = list->arr[i - 1];
    }
    list->arr[pos] = val;
    list->size++;
    printf("Inserted %d at position %d.\n", val, pos);
}

void delete(List *list, int pos) {
    if (list->size == 0) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (pos < 0 || pos >= list->size) {
        printf("Invalid position.\n");
        return;
    }
    int deleted = list->arr[pos];
    for (int i = pos; i < list->size - 1; i++) {
        list->arr[i] = list->arr[i + 1];
    }
    list->size--;
    printf("✅ Deleted %d from position %d.\n", deleted, pos);
}

void display(List *list) {
    if (list->size == 0) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

void search(List *list, int val) {
    for (int i = 0; i < list->size; i++) {
        if (list->arr[i] == val) {
            printf("🔍 Element %d found at position %d.\n", val, i);
            return;
        }
    }
    printf("Element %d not found.\n", val);
}

int main() {
    List list;
    int choice, val, pos;
    create(&list);

    while (1) {
        printf("\n------ Menu ------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &val);
                insert(&list, pos, val);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete(&list, pos);
                break;
            case 3:
                display(&list);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(&list, val);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
                
        }
    }
    return 0;
}
