#include <bits/stdc++.h>

using namespace std;

int heapSize=0;
int parent(int i)
{
    return (i-1)/2;
}
int lchild(int i)
{
    return 2*i+1;
}
int rchild(int i)
{
    return 2*i+2;
}

void Maxheapify(int*a,int i)
{
    int l=lchild(i);
    int r=rchild(i);
    int largest=i;
    if (l<heapSize && a[l]>a[i])
    {
        largest=l;
    }
    if (r<heapSize && a[r]>a[largest])
    {
        largest=r;
    }
    if (largest!=i)
    {
        swap(a[i],a[largest]);
        Maxheapify(a,largest);
    }
}

void BuildHeap(int *a)
{
    for (int i=floor(heapSize/2);i>=0;i--)
    {
        Maxheapify(a,i);
    }
}

void HeapSort(int *a)
{
    BuildHeap(a);
    for (int i=heapSize;i>0;i--)
    {
        swap(a[0],a[--heapSize]);
        Maxheapify(a,0);
    }
}

int main()
{
    int n;
    cin>>n;
    int* a=new int[n];
    heapSize=n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    HeapSort(a);
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}