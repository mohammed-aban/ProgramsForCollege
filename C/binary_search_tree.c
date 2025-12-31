#include<stdio.h>
#include<stdlib.h>

struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST *node;

node insert(node root, int key) {
    if (root == NULL) {
        root = (node)malloc(sizeof(struct BST));
        root->data = key;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    
    if (key < root->data) 
        root->left = insert(root->left, key);

    if (key > root->data)  
        root->right = insert(root->right, key);
    
    return root;
}

void preorder(node root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(node root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void search(node root, int key) {
    if (root == NULL) {
        printf("Key not found\n");
        return;
    }


    if (key == root->data) {
        printf("Key found.\n");
        return;
    }
    if (key < root->data) {
        search(root->left, key);
    }
    if (key > root->data) {
        search(root->right, key);
    }
}

int main() {
    int n, i, key, choice;
    node root = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &key);
        root = insert(root, key);
    }

    

    while (1) {
        printf("\n1. Preorder\n2. Inorder\n3. Postorder\n4. Search an element\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Preorder: ");
            preorder(root);
            break;
    
        case 2: 
            printf("Inorder: ");
            inorder(root);
            break;

        case 3:
            printf("Postorder: ");
            postorder(root);
            break;
        
        case 4:
            printf("Enter the element to be searched: ");
            scanf("%d", &key);
            search(root, key);
            break;

        case 5: exit(0);
            
        default:
            printf("Invalid choice.\n");
        }
    }
}