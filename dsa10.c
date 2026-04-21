#include <stdio.h>
#include <stdlib.h>
/*NAME: TARIQ KHALIL BHATKAR
UIN: 251P032
ROLL NO: 31*/ 

// ADT Node (BST)
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Create Node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Find Minimum (for delete case 3)
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete (3 cases)
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Display (Modified to show TWO NULLs like DLL style)
void display(Node* root) {
    if (root != NULL) {
        display(root->left);

        // Left side
        if (root->left == NULL)
            printf("NULL <- ");
        else
            printf("%d <- ", root->left->data);

        // Current node
        printf("%d", root->data);

        // Right side
        if (root->right == NULL)
            printf(" -> NULL\n");
        else
            printf(" -> %d\n", root->right->data);

        display(root->right);
    }
}

// Main Menu
int main() {
    Node* root = NULL;
    int choice, value;
    printf("code: Tariq Bhatkar");


    while (1) {
        printf("\n--- BST MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;

        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value))
                printf("Value FOUND\n");
            else
                printf("Value NOT FOUND\n");
            break;

        case 4:
            printf("\nBST Display (with NULLs):\n");
            display(root);
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}