#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *llink, *rlink;
};

typedef struct node *NODE;

NODE getnode() {
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Memory not available.");
        exit(0);
    }
    x->llink = NULL;
    x->rlink = NULL;
    return x;
}

NODE insertFront(NODE head, int data) {
    NODE newNode = getnode();
    newNode->info = data;
    if (head == NULL) {
        head = newNode;
        return head;
    }
    newNode->rlink = head;
    head->llink = newNode;
    head = newNode;
    return head;
}

NODE insertRear(NODE head, int data) {
    NODE newNode = getnode();
    newNode->info = data;
    if (head == NULL) {
        head = newNode;
        return head;
    }
    NODE curr = head;
    while (curr->rlink != NULL) {
        curr = curr->rlink;
    }
    curr->rlink = newNode;
    newNode->llink = curr;
    return head;
}

NODE deleteFront(NODE head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    NODE curr = head;
    head = head->rlink;
    free(curr);
    if (head != NULL) {
        head->llink = NULL;
    }
    return head;
}

NODE deleteRear(NODE head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    NODE curr = head;
    while (curr->rlink != NULL) {
        curr = curr->rlink;
    }
    if (curr->llink == NULL) {
        head = NULL;
    } else {
        curr->llink->rlink = NULL;
    }
    free(curr);
    return head;
}

void display(NODE head) {
    NODE curr = head;
    if (curr == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (curr != NULL) {
        printf("%d ", curr->info);
        curr = curr->rlink;
    }
    printf("\n");
}

int main() {
    NODE head = NULL;
    int choice, data;
    while (1) {
        printf("\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                head = insertFront(head, data);
                break;
            case 2:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                head = insertRear(head, data);
                break;
            case 3:
                head = deleteFront(head);
                break;
            case 4:
                head = deleteRear(head);
                break;
            case 5:
                display(head);
                break;
            default:
                exit(0);
        }
    }
}

