#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
typedef struct node {
  int data;
  struct node *next;
} NODE;


// Definition of the stack structure
typedef struct stack {
  NODE *top;
};

// Function to get a new node
NODE *getnode() {
  NODE *temp = (NODE*)malloc(sizeof(NODE));
  return temp;
}

// Function to initialize the stack
void init(struct stack *s) {
  s->top = NULL;
}

// Function to push a new element onto the stack
void push(struct stack *s, int x) {
  NODE *temp = getnode();
  temp->data = x;
  temp->next = s->top;
  s->top = temp;
}

// Function to pop an element from the stack
int pop(struct stack *s) {
  if (s->top == NULL) {
    printf("Error: stack is empty\n");
    return 0;
  }
  int x = s->top->data;
  NODE *temp = s->top;
  s->top = s->top->next;
  free(temp);
  return x;
}

// Function to check if the stack is empty
int is_empty(struct stack *s) {
  return s->top == NULL;
}

// Function to display the stack
void display(struct stack *s) {
  NODE *temp = s->top;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct stack s;
  init(&s);
  int choice, x;
  while (1) {
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the element to be pushed: ");
        scanf("%d", &x);
        push(&s, x);
        break;
      case 2:
        x = pop(&s);
        printf("Popped element is %d\n", x);
        break;
      case 3:
        printf("The stack is: ");
        display(&s);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}

