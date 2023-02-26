#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} Node;

Node *create_node(int key)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return create_node(key);
    }
    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder_traversal(Node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
    printf("\n");
}

void preorder_traversal(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
    printf("\n");
}

void postorder_traversal(Node *root)
{
    if (root != NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->key);
    }
    printf("\n");
}

Node *search(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->key == key)
    {
        return root;
    }

    if (key < root->key)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

Node *find_min_node(Node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

Node *delete(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key < root->key)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->key)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = find_min_node(root->right);
        root->key = temp->key;
        root->right = delete (root->right, temp->key);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    int choice, key;
    while (1)
    {
        printf("Binary Search Tree Operations\n");
        printf("1. Insert a node\n");
        printf("2. Inorder traversal\n");
        printf("3. Preorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Search and delete a node by key\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            printf("Node inserted successfully!\n");
            break;
        case 2:
            printf("Inorder traversal: ");
            inorder_traversal(root);
            break;
        case 3:
            printf("Preorder traversal: ");
            preorder_traversal(root);
            break;
        case 4:
            printf("Postorder traversal: ");
            postorder_traversal(root);
            break;
        case 5:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            if (search(root, key) == NULL)
            {
                printf("Key not found. Nothing deleted.\n");
            }
            else
            {
                delete (root, key);
                printf("Key found and deleted.\n");
            }
            break;
        default:
            exit(0);
        }
    }
}
