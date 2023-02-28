#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *llink, *rlink;
};
typedef struct node * NODE;

NODE getnode(){
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL){
        printf("Memory not available.");
        exit(0);
    }
    return x;
}

NODE insert_BST(NODE root, int ele){
    NODE prev,cur,temp;
    temp=getnode();
    temp->llink=temp->rlink=NULL;
    temp->info=ele;
    if(root==NULL)
        return temp;
    cur=root;
    while(cur!=NULL){
        prev=cur;
        if(cur->info>ele)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    if(prev->info>ele)
        prev->llink=temp;
    else    
        prev->rlink=temp;
    
    return root;
}

NODE minValueNode(NODE node) {
    NODE current = node;
    while (current && current->llink != NULL) {
        current = current->llink;
    }
    return current;
}


void preorder(NODE root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

void postorder(NODE root){
    if(root==NULL){
        return;
    }
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ",root->info);
}

void inorder(NODE root){
    if(root==NULL){
        return;
    }
    inorder(root->llink);
    printf("%d ",root->info);
    inorder(root->rlink);
}

// void search(NODE root,int key){
//     if(root==NULL){
//         return;
//     }
//     if(root->info==key){
//         printf("Element is found.");
//         exit(0);
//     }
//     search(root->llink,key);
//     search(root->rlink,key);
//     printf("Element is not found.");
// }


NODE delete_BST(NODE root, int key) {
    if (root == NULL) {
        printf("Element not found.\n");
        return root;
    }
    if (key < root->info) {
        root->llink = delete_BST(root->llink, key);
    }
    else if (key > root->info) {
        root->rlink = delete_BST(root->rlink, key);
    }
    else {
        if (root->llink == NULL) {
            NODE temp = root->rlink;
            free(root);
            return temp;
        }
        else if (root->rlink == NULL) {
            NODE temp = root->llink;
            free(root);
            return temp;
        }
        NODE temp = minValueNode(root->rlink);
        root->info = temp->info;
        root->rlink = delete_BST(root->rlink, temp->info);
    }
    return root;
}


int main() {
    NODE root = NULL;
    int choice, ele, key;
    while(1){
        printf("\n\n");
        printf("1. Insert\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Delete\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);
                root = insert_BST(root, ele);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorder(root);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                break;
            case 5:
                printf("Enter key to be deleted: ");
                scanf("%d", &key);
                root = delete_BST(root, key);
                break;
            default:
                printf("Exiting...");
                exit(0);
        }
    }
}
