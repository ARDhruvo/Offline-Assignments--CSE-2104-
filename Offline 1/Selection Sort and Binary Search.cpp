#include <bits/stdc++.h>
using namespace std;

void printVect(vector<int> A)
{
    int s = A.size();
    for(int i = 0; i < s; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
}


int binarySearch(vector<int> A, int k)
{
    int n = A.size();
    for(int j = 0; j <= n-2; j++)
    {
        int mini = A[j], pos = j;
        for(int i = j+1; i <= n-1; i++)
        {
            if(A[i] < mini)
            {
                mini = A[i];
                pos = i;
            }

        }
        swap(A[pos], A[j]);
    } //sorted again because functions dont store memories
    int lo = 0, hi = A.size() - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (A[mid] == k)
        {
            return 1;
        }
        else if (A[mid] >= k)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return 0;
}

int selectionSort(vector<int> A)
{
    int n = A.size();
    for(int j = 0; j <= n-2; j++)
    {
        int mini = A[j], pos = j;
        for(int i = j+1; i <= n-1; i++)
        {
            if(A[i] < mini)
            {
                mini = A[i];
                pos = i;
            }

        }
        swap(A[pos], A[j]);
    }
    printVect(A);
}

int main()
{
    vector<int> A;
    int x;
    cout << "Please enter 10 elements:\n";
    for(int i = 0; i < 10; i++) //for taking input
    {
        cin>> x;
        A.push_back(x);
    }
    cout << "Entered elements:\n";
    printVect(A); //printing the elements
    cout << "\n";
    cout << "Selection Sorted elements:\n";
    selectionSort(A); //sorting the elements
    cout << "\n";
    cout << "Enter element for searching:\n";
    int k; //variable to search
    cin >> k;
    cout << "\n";
    int ans = binarySearch(A, k);
    if(ans)
    {
        cout << k << " is present in the given set of elements\n";
    }
    else
    {
        cout << k << " is absent in the given set of elements\n";
    }
}
