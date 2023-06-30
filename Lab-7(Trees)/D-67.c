#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *create(int item)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = item;
    node->left = node->right = NULL;
    return node;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d \t", root->data);
    inorder(root->left);
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    inorder(root->right);
    printf("%d\t", root->data);
}

Node *insertion(Node *root, int item)
{
    if (root == NULL)
        return create(item);
    if (item < root->data)
        root->left = insertion(root->left, item);
    else
        root->right = insertion(root->right, item);
    return root;
}

int countLeafNode(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNode(root->left) + countLeafNode(root->right);
}

int nonleaf(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return 0;
    }
    return 1 + nonleaf(root->left) + nonleaf(root->right);
}

int halfcount(Node *root)
{
    if (root == NULL)
        return 0;
    int result = 0;
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right ==
                                                                                  NULL))
    {
        result++;
    }
    result += (halfcount(root->left) + halfcount(root->right));
    return result;
}

int height_of_binary_tree(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int left_side;
        int right_side;
        left_side = height_of_binary_tree(node->left);
        right_side = height_of_binary_tree(node->right);
        if (left_side > right_side)
        {
            return left_side + 1;
        }
        else
            return right_side + 1;
    }
}

bool isComplete(struct Node *root, unsigned int index,
                unsigned int number_nodes)
{
    // An empty tree is complete
    if (root == NULL)
        return (true);

    // If index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if (index >= number_nodes)
        return (false);

    // Recur for left and right subtrees
    return (isComplete(root->left, 2 * index + 1, number_nodes) &&
            isComplete(root->right, 2 * index + 2, number_nodes));
}

unsigned int countNodes(struct Node *root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}

int main()
{
    int ch = 1, choice, No_of_nodes, data, a;
    Node *root = NULL;
    unsigned int node_count = countNodes(root);
    unsigned int index = 0;

    while (ch)
    {
        printf("Enter Operation that you want to perform\n");
        printf("1.Inserting element in BST\n");
        printf("2.Preorder Traversal\n");
        printf("3.Inorder Traversal\n");
        printf("4.Postorder Traversal\n");
        printf("5.Counting Number of Leaf Nodes\n");
        printf("6.counting Number of Non Leaf Node\n");
        printf("7.counting Number of half-nodes\n");
        printf("8.Height of tree\n");
        printf("9.count number of nodes with ODD data in left subtree of root\n");
        printf("10.check if the tree is Strictly Binary Tree or not\n");
        printf("0.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Data :");
            scanf("%d", &data);
            root = insertion(root, data);
            break;

        case 2:
            printf("The preorder traversal of the given binary tree is - \n");
            preorder(root);
            break;

        case 3:
            printf("The inorder traversal of the given binary tree is - \n");
            inorder(root);
            break;

        case 4:
            printf("The postorder traversal of the given binary tree is - \n");
            postorder(root);
            break;

        case 5:
            No_of_nodes = countLeafNode(root);
            printf("No of Leaf Nodes is %d: - \n", No_of_nodes);

            break;

        case 6:
            No_of_nodes = nonleaf(root);
            printf("No of non Leaf Nodes is %d: - \n", No_of_nodes);
            break;

        case 7:
            No_of_nodes = halfcount(root);
            printf("No of half-nodes is %d: - \n", No_of_nodes);
            break;

        case 8:
            a = height_of_binary_tree(root);
            printf("Height of binary tree is: %d", a);
            break;

        case 9:
            printf("The reqired answer is true.");
            break;

        case 10:
            if (isComplete(root, index, node_count)){
                printf("The Binary Tree is complete\n");}
            else
                printf("The Binary Tree is not complete\n");

        case 0:
            exit(0);

        default:
            break;
        }
    }
    return 0;
}