#include <stdio.h> // Include stdio
#include <stdlib.h> // Include stdlib
/*NAME: TARIQ KHALIL BHATKAR
UIN: 251P032
ROLL NO: 31*/ // Author
// ADT Node (BST) // Node struct
typedef struct Node {
    int data; // Data
    struct Node *left, *right; // Left right
} Node;

// Create Node // Create node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate
    newNode->data = value; // Assign
    newNode->left = newNode->right = NULL; // Set null
    return newNode; // Return
}

// Insert // Insert
Node* insert(Node* root, int value) {
    if (root == NULL) // If null
        return createNode(value); // Create
    if (value < root->data) // If less
        root->left = insert(root->left, value); // Insert left
    else if (value > root->data) // If greater
        root->right = insert(root->right, value); // Insert right
    return root; // Return root
}

// Search // Search
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) // If null or found
        return root; // Return
    if (key < root->data) // If less
        return search(root->left, key); // Search left
    return search(root->right, key); // Search right
}

// Find Minimum (for delete case 3) // Find min
Node* findMin(Node* root) {
    while (root->left != NULL) // While left
        root = root->left; // Go left
    return root; // Return
}

// Delete (3 cases) // Delete
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root; // If null return
    if (key < root->data) // If less
        root->left = deleteNode(root->left, key); // Delete left
    else if (key > root->data) // If greater
        root->right = deleteNode(root->right, key); // Delete right
    else { // Found
        // Case 1: No child // No child
        if (root->left == NULL && root->right == NULL) {
            free(root); // Free
            return NULL; // Return null
        }
        // Case 2: One child // One child
        else if (root->left == NULL) {
            Node* temp = root->right; // Temp right
            free(root); // Free
            return temp; // Return temp
        }
        else if (root->right == NULL) {
            Node* temp = root->left; // Temp left
            free(root); // Free
            return temp; // Return temp
        }
        // Case 3: Two children // Two children
        Node* temp = findMin(root->right); // Find min right
        root->data = temp->data; // Replace
        root->right = deleteNode(root->right, temp->data); // Delete min
    }
    return root; // Return root
}

// Display (Modified to show TWO NULLs like DLL style) // Display
void display(Node* root) {
    if (root != NULL) { // If not null
        display(root->left); // Display left
        // Left side // Left
        if (root->left == NULL) // If no left
            printf("NULL <- "); // Print null
        else
            printf("%d <- ", root->left->data); // Print left data
        // Current node // Current
        printf("%d", root->data); // Print data
        // Right side // Right
        if (root->right == NULL) // If no right
            printf(" -> NULL\n"); // Print null
        else
            printf(" -> %d\n", root->right->data); // Print right data
        display(root->right); // Display right
    }
}

// Main Menu // Main
int main() {
    Node* root = NULL; // Root null
    int choice, value; // Choice value
    printf("code: Tariq Bhatkar"); // Coder
    while (1) { // Loop
        printf("\n--- BST MENU ---\n"); // Menu
        printf("1. Insert\n"); // 1
        printf("2. Delete\n"); // 2
        printf("3. Search\n"); // 3
        printf("4. Display\n"); // 4
        printf("5. Exit\n"); // 5
        printf("Enter choice: "); // Prompt
        scanf("%d", &choice); // Read
        switch (choice) { // Switch
        case 1:
            printf("Enter value to insert: "); // Prompt
            scanf("%d", &value); // Read
            root = insert(root, value); // Insert
            break;
        case 2:
            printf("Enter value to delete: "); // Prompt
            scanf("%d", &value); // Read
            root = deleteNode(root, value); // Delete
            break;
        case 3:
            printf("Enter value to search: "); // Prompt
            scanf("%d", &value); // Read
            if (search(root, value)) // If found
                printf("Value FOUND\n"); // Found
            else
                printf("Value NOT FOUND\n"); // Not found
            break;
        case 4:
            printf("\nBST Display (with NULLs):\n"); // Label
            display(root); // Display
            break;
        case 5:
            printf("Exiting...\n"); // Exit
            exit(0); // Exit
        default:
            printf("Invalid choice!\n"); // Invalid
        }
    }
    return 0; // Return
}
