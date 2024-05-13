#include <bits/stdc++.h>
using namespace std;

#define paragraph cout << endl;

struct node
{
    int data;
    node *next;
};

node *root = NULL;

// 1. Insert First
void insertFirst(int val)
{
    cout << val << " is inserted as first node" << endl;
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->next = root;
        root = temp;
    }
}

// 2. Insert Last
void insertLast(int val)
{
    cout << val << " is inserted as last node" << endl;
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        node *curr_node = root;
        while (curr_node->next != NULL)
        {
            curr_node = curr_node->next;
        }
        curr_node = curr_node->next = temp;
    }
}

// 3. Insert Anywhere (Position)
void insertAnywhere(int val, int pos)
{
    cout << val << " is inserted as node " << pos << endl;
    node *temp, *curr_node = root;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    if (pos == 1)
    {
        node *temp2;
        temp2 = new node();
        temp2->data = val;
        temp2->next = NULL;
        if (root == NULL)
        {
            root = temp2;
        }
        else
        {
            temp2->next = root;
            root = temp2;
        }
    }
    else
    {
        int i = 1;
        while (i < pos - 1)
        {
            curr_node = curr_node->next;
            i++;
        }
        temp->next = curr_node->next;
        curr_node->next = temp;
    }
}

// 4. Delete First
void deleteFirst()
{
    cout << "First node is deleted" << endl;
    root = root->next;
}

// 5. Delete Last
void deleteLast()
{
    cout << "Last node is deleted" << endl;
    node *curr_node = root;
    while (curr_node->next->next != NULL)
    {
        curr_node = curr_node->next;
    }
    curr_node->next = NULL;
}

// 6. Delete Anywhere
void deleteAnywhere(int pos)
{
    cout << "Node " << pos << " is deleted" << endl;
    node *curr_node = root;
    if (pos == 1)
    {
        root = root->next;
    }
    else
    {
        int i = 1;
        while (i < pos - 2)
        {
            curr_node = curr_node->next;
            i++;
        }
        curr_node->next = curr_node->next->next;
    }
}

// 7. Print List
void printing()
{
    paragraph
    cout << "List So far: " << endl;
    node *curr_node = root;
    while (curr_node != NULL)
    {
        cout << curr_node->data << endl;
        curr_node = curr_node->next;
    }
    paragraph
}

// 8. Search in List (Value)
void searching(int val)
{
    cout << val << " will be searched in the list" << endl;
    node *curr_node = root;
    while (curr_node != NULL)
    {
        if (val == curr_node->data)
        {
            cout << val << " is present in the list" << endl;
            paragraph 
            return;
        }
        curr_node = curr_node->next;
    }
    cout << val << " is not present in the list" << endl;
    paragraph
}

// 9. Last Node
void last_node() // Function to print the linked list
{
    cout << "Last Node: ";
    node *curr_node = root;
    while (curr_node->next != NULL)
    {
        curr_node = curr_node->next;
    }
    cout << curr_node->data << endl;
    paragraph
}

// 10. Previous node value of last node
void previous_last_node()
{
    cout << "Second last Node: ";
    node *curr_node = root;
    while (curr_node->next->next != NULL)
    {
        curr_node = curr_node->next;
    }
    cout << curr_node->data << endl;
    paragraph
}

// 11. List Size
void list_size()
{
    cout << "List size so far: ";
    int count = 0;
    node *curr_node = root;
    while (curr_node != NULL)
    {
        curr_node = curr_node->next;
        count++;
    }
    cout << count << endl;
    paragraph
}

int main()
{
    // Function 1
    insertFirst(10);
    insertFirst(20);
    insertFirst(30);
    printing();

    // Function 2
    insertLast(40);
    insertLast(50);
    insertLast(60);
    printing();

    // Function 3
    insertAnywhere(70, 1);
    insertAnywhere(80, 3);
    insertAnywhere(90, 5);
    printing();

    // Function 4
    deleteFirst();
    deleteFirst();
    printing();

    // Function 5
    deleteLast();
    deleteLast();
    printing();

    // Function 6
    deleteAnywhere(1);
    deleteAnywhere(3);
    printing();

    // Function 7
    printing();

    // Function 8
    searching(20);
    searching(30);

    // Function 9
    last_node();

    // Function 10
    previous_last_node();

    // Function 11
    list_size();
}
