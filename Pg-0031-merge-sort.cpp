/*  
Merge Sort Algorithm
 
Project :Algorithms in C++
Author  :Sharat Sachin
*/

#include <iostream>
#include <vector>
using namespace ::std;
void merge(vector<int>& M, int l, int m, int r)
{
    int i, j, k;
    vector<int> L,R;
    for (i = l; i <= m; i++)        L.push_back(M[i]);
    for (j = m + 1; j <= r; j++)    R.push_back(M[j]);
    i = 0;
    j = 0;
    k = l;
    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j])
            M[k] = L[i++];
        else
            M[k] = R[j++];
        k++;
    }
    while (i < L.size())
        M[k++] = L[i++];
    while (j < R.size())
        M[k++] = R[j++];
}
void mergeSort(vector<int>& MS, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2; //prevents overflow for large l,r
        mergeSort(MS, l, m);
        mergeSort(MS, m + 1, r);
        merge(MS, l, m, r);
    }
}
void printV(vector<int>& PV)
{
    for (auto& i : PV)
        cout << i << " ";
    cout << "\n";
}
int main()
{
    vector<int> V;
    int i, a;
    for (i = 0; i < 100; i++) {
        cin >> a;
        V.push_back(a);
    }
    cout << "Given array is \n";
    printV(V);
    mergeSort(V, 0, V.size() - 1);
    cout << "\nSorted array is \n";
    printV(V);
    return 0;
}
