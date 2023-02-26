#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *createNode(int key)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
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

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root;
    }
    if (root->key < key)
    {
        return search(root->right, key);
    }
    return search(root->left, key);
}

void findParent(struct node *root, struct node *current, struct node *parent)
{
    if (root == current)
    {
        printf("No parent\n");
        return;
    }
    
    if (root != NULL)
    {
        if (root->key == current->key)
        {
            printf("%d ", parent->key);
        }
        else if (root->key > current->key)
        {
            findParent(root->left, current, root);
        }
        else
        {
            findParent(root->right, current, root);
        }
    }
}

int countNodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return (countNodes(root->left) + 1 + countNodes(root->right));
    }
}

int findHeight(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        if (leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}

int main()
{
    struct node *root = NULL;
    int choice, key, height, nodeCount;
    struct node *searchedNode, *parent;

    while (1)
    {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert by key\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search Node\n");
        printf("6. Count Nodes\n");
        printf("7. Find height\n");
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the key you want to insert\n");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Inorder traversal: ");
            inorderTraversal(root);
            break;
        case 3:
            printf("Preorder traversal: ");
            preorderTraversal(root);
            break;
        case 4:
            printf("Postorder traversal: ");
            postorderTraversal(root);
            break;
        case 5:
            printf("Enter the element to be searched: ");
            scanf("%d", &key);
            if (search(root, key) == NULL)
            {
                printf("Element not found\n");
                break;
            }
            printf("Element found\n");
            searchedNode = search(root, key);
            findParent(root, searchedNode, parent);
            break;
        case 6:
            printf("%d", countNodes(root));
            break;
        case 7:
            printf("%d", findHeight(root));
            break;
        default:
            break;
        }
    }
}