#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

const int ARRAY_SIZE = 500000;

int partition(int start, int end)
{
    //has test the pivot = end version
    int pivot = (start + end) / 2;
    return pivot;
}
//void swap(int * a, int b, int c)
//{
    //assert(b < ARRAY_SIZE && c < ARRAY_SIZE && b >= 0 && c >= 0);
    //int temp = a[b];
    //a[b] = a[c];
    //a[c] = temp;
//}
void swap(int &a, int &b)
{
    a ^= b;
    b = a^b;
    a = a^b;
}

void quicksort(int *a, int start, int end)
{
    assert(start < ARRAY_SIZE && end < ARRAY_SIZE && start >= 0 && end >= 0);
    if(start == end)
        return;
    //if(start == end - 1)
    //{
        //if(a[start]> a[end])
            //swap(a, start, end);
        //return;
    //}
    assert(start < end);
    int p = partition(start, end);
    //swap(a, p, end);
    //put the pivot on the end of the array
    swap(a[p], a[end]);
    int iter_small = start, iter_big = end - 1;
    while(a[iter_small] < a[end] && iter_small < end - 1)iter_small++;
    while(a[iter_big] > a[end] && iter_big > start) iter_big--;
    while(iter_small < iter_big)
    {
        //swap(a, iter_small, iter_big);
        swap(a[iter_small], a[iter_big]);
        while(a[iter_small] < a[end] && iter_small < end - 1)iter_small++;
        while(a[iter_big] > a[end] && iter_big > start) iter_big--;
    }
    //cause the last swap is not expected
    //swap(a, iter_small, iter_big);
    //iter_small = iter_small > 0 ? ++iter_small : 0;
    //iter_big = iter_big < end ? --iter_big : 0;
    //iter_small--; iter_big++;
    
    //The choose one is the smallest
    /*if(iter_big < start) 
    {
        swap(a, iter_small, end);
        quicksort(a, iter_small, end);
    }
    //Thec choose one is the biggest
    else if(iter_small > end) 
    {
        quicksort(a, start, iter_big);
    }
    else
    {
        iter_big++;
        iter_small--;
        swap(a, iter_big, end);
        //we should not compare the partitioner again
        iter_big++;
        quicksort(a, start, iter_small);
        quicksort(a, iter_big, end);
    }*/

    //This swap is very talent!!
    //int temp_swap = iter_big;
    //iter_big = iter_small;
    //iter_small = temp_swap;
    swap(iter_big, iter_small);
    //In case a[end] is the biggest number, in this case we should not exchange a[end] and a[iter_big]
    if(a[end] < a[iter_big])
    {
        //swap(a, iter_big, end);
        swap(a[iter_big], a[end]);
    }
    //we should not compare the partitioner again
    //iter_big++;
    quicksort(a, start, iter_small);
    quicksort(a, iter_big + 1, end);
}

int main()
{
    //int a[ARRAY_SIZE] = {3, 1, 2, 4, 5, 7, 9, 8, 10, 20};
#if 0
    int a[ARRAY_SIZE] = {3, 4, 7, 1, 8, 9, 0, 5, 2, 6};
#else
    int a[ARRAY_SIZE] = {0};
    srand((unsigned)time(NULL));
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        a[i] = i;
    }
    for(int i = ARRAY_SIZE - 1; i > 0; i--)
    {
        int rand_temp = rand()%i;
        //swap(a, i, rand_temp);
        swap(a[i], a[rand_temp]);
    }
#endif
    //for(int i = 0; i < ARRAY_SIZE; i++)
    //{
        //cout<<a[i]<<", ";
    //}
    //cout<<endl;

    quicksort(a, 0, ARRAY_SIZE - 1);

    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        //cout<<a[i]<<" ";
        if(a[i] != i)
        {
            cout<<"Error!"<<endl;
            return 1;
        }
    }
    cout<<endl;
    return 0;
}
