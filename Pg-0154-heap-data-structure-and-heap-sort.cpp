/*
Heap Data Structure and Heapsort algorithm
Project :Algorithms in C++
Author  :Sharat Sachin
*/

#include <iostream>
#include <climits>
#include <vector>
#include <tuple>
using namespace std;

class heapDS_heapsort {
    vector<int> A;
    int size;

public:
    heapDS_heapsort(vector<int> data)
    {
        A.insert(A.end(), data.begin(), data.end());
    }

    void max_heapify(int i, int size)
    {
        int l = 2 * i + 1, r = 2 * i + 2, largest;
        if (l < size && A[l] > A[i])
            largest = l;
        else
            largest = i;
        if (r < size && A[r] > A[largest])
            largest = r;
        if (i != largest) {
            swap(A[largest], A[i]);
            max_heapify(largest, size);
        }
    }
 
    void build_max_heap(int size)
    {
        for (int i = size / 2 - 1; i >= 0; --i) {
            max_heapify(i, size);
        }
    }

    void heap_sort()
    {
        int size = A.size();
        int heap_size = size;
        build_max_heap(size);
        for (int i = size - 1; i > 0; --i) {
            swap(A[0], A[i]);
            --heap_size;
            max_heapify(0, heap_size);
        }
    }

    void display()
    {
        cout << "Contents of A after sorting:\n";
        for (auto a : A)
            cout << a << " ";
    }
};

int main()
{
    vector<int> data = { 5, 1, 8, 3, 4, 9, 10, 2, -2, -4, -6, -1, 0 };
    heapDS_heapsort heap(data);
    heap.heap_sort();
    heap.display();
    return 0;
}

/*
OUTPUT:
Contents of A after sorting:
-6 -4 -2 -1 0 1 2 3 4 5 8 9 10 

Run and see at: http://rextester.com/GGA26490
*/
