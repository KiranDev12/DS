#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;

    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = NULL;

void insert(int data)
{
    struct node *tempNode = (struct node *)malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;

    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    // if tree is empty
    if (root == NULL)
    {
        root = tempNode;
    }
    else
    {
        current = root;
        parent = NULL;

        while (1)
        {
            parent = current;

            // go to left of the tree
            if (data < parent->data)
            {
                current = current->leftChild;

                // insert to the left
                if (current == NULL)
                {
                    parent->leftChild = tempNode;
                    return;
                }
            } // go to right of the tree
            else
            {
                current = current->rightChild;

                // insert to the right
                if (current == NULL)
                {
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}

struct node *search(int data)
{
    struct node *current = root;

    while (current->data != data)
    {

        // go to left tree
        if (current->data > data)
        {
            current = current->leftChild;
        }
        // else go to right tree
        else
        {
            current = current->rightChild;
        }

        // not found
        if (current == NULL)
        {
            return NULL;
        }
    }

    return current;
}

void pre_order_traversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        pre_order_traversal(root->leftChild);
        pre_order_traversal(root->rightChild);
    }
}

void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->leftChild);
        printf("%d ", root->data);
        inorder_traversal(root->rightChild);
    }
}

void post_order_traversal(struct node *root)
{
    if (root != NULL)
    {
        post_order_traversal(root->leftChild);
        post_order_traversal(root->rightChild);
        printf("%d ", root->data);
    }
}

int main()
{
    int data;
    int ch;
    int size;

    while (1)
    {
        printf("\n1.Create a BST\n2.Insert an element\n3.PreOrder Traversal\n4.Inorder Traversal\n5.Postorder Traversal\n6.Search an element\n\n");
        printf("Enter your choice: \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number of elements in the BST: \n");
            scanf("%d", &size);
            printf("Enter the elements of the BST: \n");
            for (int i = 0; i < size; i++)
            {
                scanf("%d", &data);
                insert(data);
            }
            break;
        case 2:
            printf("Enter the data to be inserted: \n");
            scanf("%d", &data);
            insert(data);
            break;
        case 3:
            printf("PreOrder Traversal is: \n");
            pre_order_traversal(root);
            break;
        case 4:
            printf("Inorder Traversal is: \n");
            inorder_traversal(root);
            break;
        case 5:
            printf("PostOrder Traversal is: \n");
            post_order_traversal(root);
            break;
        case 6:
            printf("Enter the data to be searched: \n");
            scanf("%d", &data);
            struct node *temp = search(data);
            if (temp == NULL)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Element found\n");
            }

        default:
            break;
        }
    }
}
