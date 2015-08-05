#include<iostream>
#include<cstdlib>
#include<cassert>

using namespace std;

const int ARRAY_SIZE = 10;

int partition(int start, int end)
{
    return end;
}
void swap(int * a, int b, int c)
{
    assert(b < ARRAY_SIZE && c < ARRAY_SIZE && b >= 0 && c >= 0);
    int temp = a[b];
    a[b] = a[c];
    a[c] = temp;
}

void quicksort(int *a, int start, int end)
{
    assert(start < ARRAY_SIZE && end < ARRAY_SIZE && start >= 0 && end >= 0);
    if(start == end)
        return;
    if(start == end - 1)
    {
        if(a[start]> a[end])
            swap(a, start, end);
        return;
    }
    assert(start < end);
    int p = partition(start, end);
    swap(a, p, end);
    int iter_small = start, iter_big = end - 1;
    while(a[iter_small] < a[end] && iter_small < end)iter_small++;
    while(a[iter_big] > a[end] && iter_big >= 0) iter_big--;
    while(iter_small < iter_big)
    {
        swap(a, iter_small, iter_big);
        while(a[iter_small] < a[end])iter_small++;
        while(a[iter_big] > a[end]) iter_big--;
    }
    //cause the last swap is not expected
    //swap(a, iter_small, iter_big);
    //iter_small = iter_small > 0 ? ++iter_small : 0;
    //iter_big = iter_big < end ? --iter_big : 0;
    //iter_small--; iter_big++;
    
    //The choose one is the smallest
    if(a[iter_big] > a[end]) 
    {
        swap(a, iter_big, end);
        cout<<"a[iter_big] > a[end]: "<<iter_small<<" "<iter_big<<endl;
    }
    //Thec choose one is the biggest
    else if(a[iter_small] < a[end]) 
    {
        cout<<"a[iter_small] < a[end]: "<<iter_small<<" "<iter_big<<endl;
    }
    else
    {
        iter_big++;
        iter_small--;
        swap(a, iter_big, end);
    }
    quicksort(a, start, iter_small);
    quicksort(a, iter_big, end);

}

int main()
{
    int a[ARRAY_SIZE] = {3, 1, 2, 4, 5, 7, 9, 8, 10, 20};
    quicksort(a, 0, 9);

    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
