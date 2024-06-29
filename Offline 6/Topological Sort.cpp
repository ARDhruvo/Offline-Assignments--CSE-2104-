#include <bits/stdc++.h>
using namespace std;

#define paragraph cout << endl
#define WHITE -1 // Node not visited yet
#define GRAY 0 // Currently visiting but all the child nodes are not visited yet
#define BLACK 1 // Node visit complete

/* Sanity Check:
6
6
6 1
6 3
3 4
4 2
5 1
5 2

Result: 6 5 3 4 2 1

4
4
1 2
2 3
4 2
4 3

Result: 4 1 2 3
 */

vector<int> Node_Vec[100]; // To make the graph
int color[12]; // To set the condition (color)
stack<int> sorted; // Sorts the nodes in (reverse) order

void printing() // Prints the sorted nodes
{
    cout << "Sorted Nodes:" << endl;
    while (!sorted.empty())
    {
        int index = sorted.top();
        cout << index << " ";
        sorted.pop();
    }
    paragraph;
}

void topologicalSort(int u)
{
    color[u] = GRAY; // Sets the visited node to GRAY
    for (int i = 0; i < Node_Vec[u].size(); i++)
    {
        int v = Node_Vec[u][i]; // Adjacent node
        if (color[v] == WHITE)
        {
            topologicalSort(v); // Recursion into the child node/adjacent node
        }
    }
    color[u] = BLACK; // Sets the currently visiting node to BLACK
    sorted.push(u); // Sets the sorted location in the stack
}

int main()
{
    int node_no, edge_no, src, dst;
    cout << "Enter the number of nodes: ";
    cin >> node_no;
    cout << "Enter the number of edges: ";
    cin >> edge_no;
    cout << "Enter connections:" << endl;
    for (int i = 1; i <= edge_no; i++)
    {
        int nodeA, nodeB;
        scanf("%d %d", &nodeA, &nodeB);
        Node_Vec[nodeA].push_back(nodeB); // Since it will be a directed graph
    }
    paragraph;

    // Print Node Adjacency List by traversing the list
    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= node_no; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < Node_Vec[i].size(); j++)
        {
            cout << Node_Vec[i][j] << " ";
        }
        paragraph;
    }

    for (int i = 0; i <= node_no; i++) // Sets all the nodes to WHITE
    {
        color[i] = WHITE;
    }
    paragraph;

    // For Sorting
    for (int i = 1; i <= node_no; i++)
    {
        if (color[i] == WHITE)
        {
            topologicalSort(i);
        }
    }
    paragraph;

    printing(); // For printing the sorted nodes
}
