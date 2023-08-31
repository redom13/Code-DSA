/*           1 BASED INDEXING             */

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Priority_Queue
{
    T *arr;
    int heapEnd, maxSize;
    int parent(int i)
    {
        return floor(i / 2);
    }
    int lchild(int i)
    {
        return 2 * i;
    }
    int rchild(int i)
    {
        return 2 * i + 1;
    }
    void Priority_Queueify(int i) // Assumes that the left & r8 subtrees r already heaps.
    {
        int l = lchild(i);
        int r = rchild(i);
        int largest = i;
        if (l < heapEnd && arr[l] > arr[i])
        {
            largest = l;
        }
        if (r < heapEnd && arr[r] > arr[largest])
            largest = r;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            Priority_Queueify(largest);
        }
    }

public:
    Priority_Queue(int maxSize = 10)
    {
        heapEnd = 1;
        this->maxSize = maxSize;
        if (maxSize < 2)
        {
            cout << "The size must at least be 2" << endl;
            exit(1);
        }
        arr = new T[maxSize];
    }
    void Insert(T key)
    {
        if (heapEnd == maxSize)
        {
            // cout << "Overflow" << endl;
            // return;
            maxSize *= 2;
            T *tmp = new T[maxSize];
            for (int i = 1; i < heapEnd; i++)
            {
                tmp[i] = arr[i];
            }
            delete[] arr;
            arr = tmp;
        }
        arr[heapEnd++] = key;
        int
            i = heapEnd - 1;
        while (i != 1 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    T ExtractMax()
    {
        if (heapEnd <= 1)
            return INT_MIN;
        if (heapEnd == 2)
        {
            heapEnd--;
            return arr[1];
        }
        T ans = arr[1];
        arr[1] = arr[--heapEnd];
        Priority_Queueify(1);
        return ans;
    }
    void IncreaseKey(int i, T newVal)
    {
        if (newVal <= arr[i])
        {
            cout << "New key is not larger than the previous key" << endl;
            return;
        }
        arr[i] = newVal;
        while (i != 1 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
        cout << "Key increased!" << endl;
    }
    T FindMax()
    {
        return arr[1];
    }
    void DecreaseKey(int i, T newKey)
    {
        if (newKey >= arr[i])
        {
            cout << "New key is not smaller than the previous key" << endl;
            return;
        }
        arr[i] = newKey;
        Priority_Queueify(i);
        cout << "Key decreased!" << endl;
    }
    void Print()
    {
        cout << "No of elements: " << heapEnd - 1 << endl;
        int h = log2(heapEnd - 1);
        // cout<<"Height: "<<h<<endl;
        int n = 1, indx = 1;
        for (int i = 0; i <= h; i++)
        {
            for (int j = 0; j < n && indx < heapEnd; j++)
            {
                cout << arr[indx++] << "    ";
            }
            n *= 2;
            cout << endl;
        }
        cout << endl;
    }
    void Sort()
    {
        int prev = heapEnd;
        for (int i = heapEnd; i > 2; i--)
        {
            swap(arr[1], arr[--heapEnd]);
            Priority_Queueify(1);
        }
        heapEnd = prev;
    }
    // int curSize()
    // {
    //     return heapEnd-1;
    // }
};