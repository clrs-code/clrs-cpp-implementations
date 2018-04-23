/*  
Maximum Sum Subarray Problem - Naive brute force solution
 
Project :Algorithms in C++
Author  :Sharat Sachin
*/

#include <iostream>
#include <climits>
 #include <vector>
using namespace ::std;
int main()
{
    vector<int> v;

    int size, m;
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
    int curr_max_sum = INT_MIN, curr_start_index = 0, curr_end_index = 0;
    for (int start = 0; start < size; start++) {
        for (int end = start + 1; end < size; end++) {
            int sum = 0;
            //Calculating sum of elements from start to end inclusive
            for (int j = start; j <= end; j++) {
                sum += v[j];
            }
            //Checking if latest value of sum is more than current max value
            if (sum > curr_max_sum) {
                curr_max_sum = sum; 
                curr_start_index = start;
                curr_end_index = end;
            }
        }
    }

    //Displaying Results 
    cout << "\nSum of maximum subarray:" << curr_max_sum;
    cout << "\nMaximum subarray:\n";
    for (int i = curr_start_index; i <= curr_end_index; i++)
        cout << v[i] << "\n";

    return 0;
}
