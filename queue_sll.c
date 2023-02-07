#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
typedef struct node {
  int data;
  struct node *next;
} NODE;

// Definition of the queue structure
typedef struct queue {
  NODE *front;
  NODE *rear;
};

// Function to get a new node
NODE *getnode() {
  NODE *temp = (NODE*)malloc(sizeof(NODE));
  return temp;
}

// Function to initialize the queue
void init(struct queue *q) {
  q->front = q->rear = NULL;
}

// Function to add a new element to the queue
void insert(struct queue *q, int x) {
  NODE *temp = getnode();
  temp->data = x;
  temp->next = NULL;
  if (q->rear == NULL) {
    q->front = q->rear = temp;
    return;
  }
  q->rear->next = temp;
  q->rear = temp;
}

// Function to remove an element from the queue
int delete(struct queue *q) {
  if (q->front == NULL) {
    printf("Error: queue is empty\n");
    return 0;
  }
  int x = q->front->data;
  NODE *temp = q->front;
  q->front = q->front->next;
  if (q->front == NULL) {
    q->rear = NULL;
  }
  free(temp);
  return x;
}

// Function to check if the queue is empty
int is_empty(struct queue *q) {
  return q->front == NULL;
}

// Function to display the queue
void display(struct queue *q) {
  NODE *temp = q->front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct queue q;
  init(&q);
  int choice, x;
  while (1) {
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the element to be inserted: ");
        scanf("%d", &x);
        insert(&q, x);
        break;
      case 2:
        x = delete(&q);
        printf("Deleted element is %d\n", x);
        break;
      case 3:
        printf("The queue is: ");
        display(&q);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}

