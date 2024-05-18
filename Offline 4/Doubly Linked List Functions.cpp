#include <bits/stdc++.h>
using namespace std;

#define paragraph cout << endl;

struct node
{
    int data;
    node *next;
    node *prev;
};

node *root = NULL;
node *tail = NULL;

// 1. Insert First
void insertFirst(int val)
{
    cout << val << " is inserted as first node" << endl;
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    if (root == NULL)
    {
        root = temp;
        tail = temp;
    }
    else
    {
        temp->next = root;
        root->prev = temp;
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
    temp->prev = NULL;
    if (root == NULL)
    {
        root = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
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
        insertFirst(val);
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
        temp->prev = curr_node;
        curr_node->next->prev = temp;
        curr_node->next = temp;
    }
}

// 4. Delete First
void deleteFirst()
{
    cout << "First node is deleted" << endl;
    if (root != NULL)
    {
        root = root->next;
        root->prev = NULL;
    }
}

// 5. Delete Last
void deleteLast()
{
    cout << "Last node is deleted" << endl;
    if (tail != NULL)
    {
        tail = tail->prev;
        tail->next = NULL;
    }
}

// 6. Delete Anywhere
void deleteAnywhere(int pos)
{
    cout << "Node " << pos << " is deleted" << endl;
    node *curr_node = root;
    if (pos == 1)
    {
        root = root->next;
        root->prev = NULL;
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
        curr_node->next->prev = curr_node;
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

void reversePrinting()
{
    cout << "List Reversed: " << endl;
    node *curr_node = tail;
    while (curr_node != NULL)
    {
        cout << curr_node->data << endl;
        curr_node = curr_node->prev;
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
    cout << "Last Node: " << endl;
    cout << tail->data << endl;
    paragraph
}

// 10. Previous node value of last node
void previous_last_node()
{
    cout << "Second last Node: " << endl;
    cout << tail->prev->data << endl;
    paragraph
}

// 11. List Size
int list_size()
{
    int count = 0;
    node *curr_node = root;
    while (curr_node != NULL)
    {
        curr_node = curr_node->next;
        count++;
    }
    return count;
    paragraph
}

// Binary Search
void binarySearching(int k)
{
    cout << k << " will be binary searched in the list" << endl;
    int lo = 0, hi = list_size();
    while(lo <= hi)
    {
        node *curr_node = root;
        int mid = (lo + hi) / 2;
        for(int i = 0; i <= (lo + hi) / 2; i++)
        {
            curr_node = curr_node->next;
        }
        int data= curr_node->data;
        if (data == k)
        {
            cout << k << " is present in the list" << endl;
            paragraph
            return;
        }
        else if (data >= k)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << k << " is not present in the list" << endl;
    paragraph
}


int main()
{
    // Function 1
    insertFirst(20);
    insertFirst(10);
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
    reversePrinting();

    // Function 8
    searching(20);
    searching(30);

    // Binary Search
    binarySearching(20);
    binarySearching(30);

    // Function 9
    last_node();

    // Function 10
    previous_last_node();

    // Function 11
    int siz = list_size();
    cout << "List size so far: " << siz << endl;
}
