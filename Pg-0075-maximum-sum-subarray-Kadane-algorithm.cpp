/*  
Maximum Sum Subarray Problem - Kadane O(n) algorithm

Project :Algorithms in C++
Author  :Sharat Sachin
*/

#include <iostream>
#include <climits>
#include <vector>
#include <tuple>
using namespace std;
tuple<int, int, int> find_maximum_subarray(vector<int>, int, int);
int main()
{
    vector<int> v;
    int size;
    tuple<int, int, int> t;
    cout << "Enter the size of the array:";
    cin >> size;

    //Input of numbers into vector
    cout << "Enter the array to find the maximum subarray of: \n";
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        v.push_back(element);
    }

    //Calculating the solution
    t = find_maximum_subarray(v, 0, size - 1);

    //Displaying Results
    cout << "\nSum of maximum subarray:" << get<2>(t);
    cout << "\nMaximum subarray:\n";
    for (int i = get<0>(t); i <= get<1>(t); i++)
        cout << v[i] << "\n";

    return 0;
}
tuple<int, int, int> find_maximum_subarray(vector<int> v, int low, int high)
{
    int max_so_far = v[low], max_ending_here = 0, ss = 0, ee = 0;
    for (int i = low; i <= high; i++) {
        int s;
        max_ending_here += v[i];
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
            ss = s;
            ee = i;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    return make_tuple(ss, ee, max_so_far);
}
