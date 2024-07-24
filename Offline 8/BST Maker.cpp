#include <bits/stdc++.h>
using namespace std;

#define paragraph cout << endl

/*
Sanity Check:
#1.
9
55
33
44
11
88
77
66
99
22

In-order traversal of the tree:
11 22 33 44 55 66 77 88 99

2
33
88

In-order traversal of the new tree:
11 22 44 55 66 77 99
*/

struct node // Nodes of thee tree
{
    int data;
    node *left;
    node *right;
};

node *root = NULL;

void BSTprint(node *temp) // In-Order printing of the BST
{
    if (temp != NULL)
    {
        BSTprint(temp->left);
        cout << temp->data << " ";
        BSTprint(temp->right);
    }
}
void BSTdelete(int val)
{
    node *curr_node = root;
    node *prev_node = root;

    while (curr_node != NULL) // Traversing to find the appropriate location
    {
        if (curr_node->data == val)
        {
            break;
        }
        prev_node = curr_node;
        if (curr_node->data > val)
        {
            curr_node = curr_node->left;
        }
        else
        {
            curr_node = curr_node->right;
        }
    }

    if (curr_node == NULL)
    {
        return;
    }
    else
    {
        // Case 1: Leaf Node
        if (curr_node->right == NULL && curr_node->left == NULL) // To check if leaf
        {
            if (prev_node->right == curr_node) // Checks which leaf
            {
                prev_node->right = NULL; // Removes leaf
            }
            else
            {
                prev_node->left = NULL;
            }
        }

        // Case 2: Node with one child
        else if (curr_node->right == NULL || curr_node->left == NULL) // To check if there is a child
        {
            node *child;                  // To keep the data of the child
            if (curr_node->right == NULL) // Node has left child
            {
                child = curr_node->left; // Saving the data of the left child
            }
            else // Node has right child
            {
                child = curr_node->right; // Saving the data of the right child
            }
            if (prev_node->right == curr_node) // Finding the location of where to delete
            {
                prev_node->right = child; // Replaces the node with the child
            }
            else
            {
                prev_node->left = child;
            }
        }

        // Case 3: Node with two children
        else
        {
            node *temp = curr_node;
            prev_node = curr_node;
            curr_node = curr_node->right;
            while (curr_node->left != NULL) // To find the smallest value
            {
                prev_node = curr_node;
                curr_node = curr_node->left;
            }
            temp->data = curr_node->data;
            if (prev_node->left == curr_node->right) // Replaces the data with the smallest one
            {
                prev_node->left = curr_node->right;
            }
            else
            {
                prev_node->right = curr_node->right;
            }
        }

        // Case 4: Root -> Missing
    }
}

void BSTinsert(int val) // Inserts a value in the tree
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL; // Temp node for value insertion

    if (root == NULL) // For no data in the tree
    {
        root = temp;
    }

    else // For new data
    {
        node *curr_node = root;
        node *prev_node = root;
        while (curr_node != NULL) // Traversing to find the appropriate location
        {
            prev_node = curr_node;
            if (curr_node->data > val)
            {
                curr_node = curr_node->left;
            }
            else
            {
                curr_node = curr_node->right;
            }
        }

        if (prev_node->data > val) // Inserting in the appropriate location
        {
            prev_node->left = temp;
        }
        else
        {
            prev_node->right = temp;
        }
    }
}

int main()
{
    int node_no, val;

    cout << "Enter Number of Nodes: ";
    cin >> node_no;
    for (int i = 0; i < node_no; i++)
    {
        cout << "Enter Node no. " << i + 1 << ": ";
        cin >> val;
        BSTinsert(val);
    }
    paragraph;

    cout << "In-order traversal of the tree: " << endl; // In-order printing of BST gives ascending value
    BSTprint(root);                                     // To verify if BST was made successfully
    paragraph;
    paragraph;

    cout << "Enter how many nodes you would like to delete: ";
    cin >> node_no;
    for (int i = 0; i < node_no; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> val;
        BSTdelete(val);
    }
    paragraph;

    cout << "In-order traversal of the new tree: " << endl;
    BSTprint(root);
    paragraph;
}
