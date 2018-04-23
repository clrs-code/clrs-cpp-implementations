/*  
Maximum Sum Subarray Problem - Recursive solution
 
Project :Algorithms in C++
Author  :Sharat Sachin
*/

#include <iostream>
#include <climits>
#include <vector>
#include <tuple>
using namespace std;
tuple<int, int, int> find_maximum_subarray(vector<int>, int, int);
tuple<int, int, int> find_maximum_crossing_subarray(vector<int>, int, int, int);
int main()
{
    vector<int> v;
    int size;
    tuple<int,int,int> t;
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
    t = find_maximum_subarray(v, 0, size-1);

    //Displaying Results
    cout << "\nSum of maximum subarray:" << get<2>(t);
    cout << "\nMaximum subarray:\n";
    for (int i = get<0>(t); i <= get<1>(t); i++)
        cout << v[i] << "\n";

    return 0;
}
tuple<int, int, int> find_maximum_subarray(vector<int> v, int low, int high)
{
    tuple<int, int, int> left, right, cross;
    if (high == low)
        return make_tuple(low, high, v[low]);
    else {
        int mid = (high + low) / 2;
        left = find_maximum_subarray(v, low, mid);
        right = find_maximum_subarray(v, mid + 1, high);
        cross = find_maximum_crossing_subarray(v, low, mid, high);
        if (get<2>(left) >= get<2>(right) && get<2>(left) >= get<2>(cross))
            return left;
        else if (get<2>(right) >= get<2>(left) && get<2>(right) >= get<2>(cross))
            return right;
        else
            return cross;
    }
}
tuple<int, int, int> find_maximum_crossing_subarray(vector<int> v, int low, int mid, int high)
{
    int left_sum = INT_MIN, sum = 0, max_left, right_sum = INT_MIN, max_right;
    for (int i = mid; i >= low; i--) {
        sum +=v[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += v[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    return make_tuple(max_left, max_right, left_sum + right_sum);
}
