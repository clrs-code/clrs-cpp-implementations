/*  
Program :Insertion Sort  
 
Project :Algorithms in C++
Author  :Sharat Sachin
*/
 
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long a, i, j, key;
    vector<int> v1;
    for (i = 0; i < 100; i++) {
        cin >> a;
        v1.push_back(a);
    }
    for (j = 1; j < v1.size(); j++) {
        key = v1[j];
        i = j - 1;
        while (i >= 0 && v1[i] > key) {
            v1[i + 1] = v1[i];
            i--;
        }
        v1[i + 1] = key;
    }
    for (auto& i : v1)
        cout << i << "\t";
    return 0;
}
