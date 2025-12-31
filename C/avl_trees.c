#include<stdio.h>
#include<stdlib.h>

struct AVL {
    int data;
    struct AVL *left;
    struct AVL *right;
    int height;
};

typedef struct AVL *node;

/* Utility functions */
int get_height(node n) {
    if (n == NULL) return 0;
    return n->height;
}

int get_max(int a, int b) {
    return (a > b) ? a : b;
}

int get_balance(node n) {
    if (n == NULL) return 0;
    return get_height(n->left) - get_height(n->right);
}

node new_node(int key) {
    node n = (node)malloc(sizeof(struct AVL));
    n->data = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

/* Rotations */
node right_rotate(node y) {
    node x = y->left;
    node T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = get_max(get_height(y->left), get_height(y->right)) + 1;
    x->height = get_max(get_height(x->left), get_height(x->right)) + 1;

    return x;
}

node left_rotate(node x) {
    node y = x->right;
    node T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = get_max(get_height(x->left), get_height(x->right)) + 1;
    y->height = get_max(get_height(y->left), get_height(y->right)) + 1;

    return y;
}

/* Insert */
node insert(node root, int key) {
    if (root == NULL)
        return new_node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;   // no duplicates

    root->height = 1 + get_max(get_height(root->left),
                               get_height(root->right));

    int balance = get_balance(root);

    // LL
    if (balance > 1 && key < root->left->data)
        return right_rotate(root);

    // RR
    if (balance < -1 && key > root->right->data)
        return left_rotate(root);

    // LR
    if (balance > 1 && key > root->left->data) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // RL
    if (balance < -1 && key < root->right->data) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

/* Minimum value node */
node min_value_node(node n) {
    while (n->left != NULL)
        n = n->left;
    return n;
}

/* Delete */
node deleteNode(node root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            node temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            node temp = min_value_node(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + get_max(get_height(root->left),
                               get_height(root->right));

    int balance = get_balance(root);

    // LL
    if (balance > 1 && get_balance(root->left) >= 0)
        return right_rotate(root);

    // LR
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // RR
    if (balance < -1 && get_balance(root->right) <= 0)
        return left_rotate(root);

    // RL
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

/* Print tree */
void printTree(node root, int space, int indent) {
    int i;
    if (root == NULL) return;

    space += indent;

    printTree(root->right, space, indent);

    printf("\n");
    for (i = 0; i < space; i++)
        printf(" ");
    printf("(%d)\n", root->data);

    printTree(root->left, space, indent);
}

/* Main */
int main() {
    node root = NULL;
    int n, i, key;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter key: ");
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("\nAVL Tree after insertion:\n");
    printTree(root, 0, 5);

    printf("\nEnter a key to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);

    printf("\nAVL Tree after deletion:\n");
    printTree(root, 0, 5);

    return 0;
}
