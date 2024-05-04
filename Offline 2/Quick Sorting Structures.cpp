#include <bits/stdc++.h>
using namespace std;

typedef struct student stud;

struct student{
    int id;
    char name[2000];
    double cgpa;
};

stud lis[5];

void printStud(stud info[], int len){ //Prints student info
    for(int i = 0; i <= len; i++){
        cout << "Information of Student No. " << i + 1 << endl;
        cout << "ID: " << info[i].id << endl;
        cout << "Name: " << info[i].name << endl;
        cout << "CGPA: " << info[i].cgpa << endl;
        cout << endl;
    }
}

void swapInfo(stud info[], int i, int j){ //Swaps student details
    swap(lis[i].id, lis[j].id);
    swap(lis[i].name, lis[j].name);
    swap(lis[i].cgpa, lis[j].cgpa);
}

int partition(int lo, int hi){ //Partition function
    double pivot = lis[lo].cgpa;
    int i = lo, j = hi;
    while(i < j){
        while(lis[i].cgpa <= pivot){
            i++;
        }
        while(lis[j].cgpa > pivot){
            j--;
        }
        if(i < j){
            swapInfo(lis, i, j);
        }
    }
    swapInfo(lis, lo, j);
    return j;
}

void quickSort(int lo, int hi){ //Quick Sort function
    if(lo < hi){
        int p = partition(lo, hi);
        quickSort(lo, p-1);
        quickSort(p+1, hi);
    }
}

int main(){
    cout << "Enter student infos:" << endl;
    for(int i = 0; i <= 4; i++){ //Takes input
        cout << "Info of Student no. " << i + 1 << endl;
        cout << "Enter ID: ";
        cin >> lis[i].id;
        cout << "Enter Name: ";
        cin >> lis[i].name;
        cout << "Enter CGPA: ";
        cin >> lis[i].cgpa;
        cout << endl;
    }
    cout << endl;
    quickSort(0, 5 - 1); //Sorting the list of structures
    cout << "Sorted Student Details:" << endl;
    printStud(lis, 5 - 1); //Printing the sorted structure
}
