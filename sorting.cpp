/********************************************************
 * Written By:-     Jenil Gandhi
 * Sem:-            CE 4
 * Date:-           10/12/2020
 * Roll no:-        CE038
 * Subject:-        DAA(Design and Analysis of Algorithm)
 * Guidance by:-    Prof Jigar Pandya
 * Objective:-      Implentation of different sorting algorithms
********************************************************/

#include<bits/stdc++.h>
using namespace std;
class sorting_algos{
    private:
    int len;
    int *arr;
    /***********************************
    Helper Functions
    --> Below listed are the helper functions to perform
        sorting operations effectievely
    --> These are declared privately so that only class
        methods can access them
    ************************************/
    
    
    
    /*****************************************
     * This helper function takes two pointer arguments
       and swaps it
    ******************************************/
    void swap(int *a,int *b)
    {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    
    
    /************************************************
    The method create heap creates the heap
    arguments to provide length n
    this will create a heap of n integers in an array
    Used by "Heapsort"
    *************************************************/
    void create_heap(int n)
    {
        int heap[n];
        for(int i=0;i<n;i++)
        {
            if(i==0)heap[0]=arr[0];
            else
            {
                int parent;
                heap[i]=arr[i];
                int cur_pos=i;
                while(true)
                {
                    parent=floor(float(cur_pos-1)/float(2));
                    if(heap[parent]<heap[cur_pos] && parent>=0)
                    {
                        swap(&heap[parent],&heap[cur_pos]);
                        cur_pos=parent;
                    }
                    else
                    {
                        break;
                    }
                    
                }
            }
            
        }
        for(int i=0;i<n;i++)
        {
            arr[i]=heap[i];
        }
        
    }

    
    /**********************************************
     This function merge takes 4 arguments
     lowerbound1 upperbound1 lowerbound2 upperbound2
     this will merge two sorted arrays
     Used by "Mergesort"
    **********************************************/
    void merge(int l1,int r1,int l2,int r2)
    {
        int low1=l1;
        int high=r2;
        int len1=r1-l1+1;
        int len2=r2-l2+1;
        vector<int> v1;
        while(l1<=r1 && l2<=r2)
        {
            if(arr[l1]<arr[l2])
            {
                v1.push_back(arr[l1]);
                l1++;
            }
            else
            {
                v1.push_back(arr[l2]);
                l2++;
            }
        }
        while(l1<=r1)
        {
            v1.push_back(arr[l1]);
            l1++;
        }
        while(l2<=r2)
        {
            v1.push_back(arr[l2]);
            l2++;
        }
        int cntr=0;
        for(int i=low1;i<=high;i++)
        {
            arr[i]=v1[cntr];
            cntr++;
        }

    }

    /******************************************
    This function takes low and high as arguments 
    This function is used by "Quick Sort"
    returns the sorted index
    ******************************************/
    int partition(int low,int high)
    {
        int start=low;
        int end=high;
        int pivot=arr[low];
        while(start<end)
        {
            while(arr[start]<=pivot){
                start++;
            }
            while(arr[end]>pivot){
                end--;
            }
            if(start<end)
            {
                swap(&arr[start],&arr[end]);
            }
            
        }
        swap(&arr[low],&arr[end]);//swapping with pivot
        return end;
    }

    /****************************************************
    End of helper functions
    ****************************************************/
    
    
    public:

    //This constructor takes an array and its length as arguments
    sorting_algos(int length,int array[])
    {
        len=length;
        arr=array;
    }

    //default constructor to notify that provide arguments
    sorting_algos()
    {
        cout<<"Please call parameterized constructor";
    }

    //Code for bubble sort
    void bubble_sort()
    {
        for(int i=0;i<len-1;i++)
        {
            for(int j=0;j<len-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(&arr[j],&arr[j+1]);
                }
            }
        }
    }

    //code for selection sort
    void selection_sort()
    {
        int min;
        for(int i=0;i<len-1;i++)
        {
            min=i;
            for(int j=i+1;j<len;j++)
            {
                if(arr[j]<arr[min])
                {
                    min=j;
                }
            }
            swap(&arr[i],&arr[min]);
        }
    }

    //code for insertion sort
    void insertion_sort()
    {
        for(int i=0;i<len;i++)
        {
            int key=arr[i];
            int j;
            for(j=i-1;j>=0;j--)
            {
                if(arr[j]>key)
                {
                    arr[j+1]=arr[j];
                }
                else
                {
                    break;
                }
                
            }
            arr[j+1]=key;
        }
        
    }

    //code for heap sort
    void heap_sort()
    {
        //this uses a helper function create heap for creating heap
        create_heap(len-3);
        for(int i=0;i<len-1;i++)
        {
            swap(&arr[0],&arr[len-i-1]);
            create_heap(len-i-1);
        }
        
    }

    //code for mergesort
    void merge_sort(int l,int r)
    {
        if(l>=r)
        {
            // cout<<"return";
            return;
        }
        else
        {
            int mid=(l+r-1)/2;
            merge_sort(l,mid);
            merge_sort(mid+1,r);
            merge(l,mid,mid+1,r);
            //implement merge function
        }
        
    }

    //code for quicksort
    void quick_sort(int low,int high)
    {
        if(low<high)
        {
            int part=partition(low,high);
            quick_sort(low,part-1);
            quick_sort(part+1,high);
        }
    }

    //print_arr method used to print the array
    //this will print the array space seperated 
    void print_arr()
    {
        for(int i=0;i<len;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sorting_algos s1(n,arr);
    // s1.bubble_sort();
    // s1.selection_sort();
    // s1.insertion_sort();
    // s1.heap_sort();
    // s1.merge_sort(0,n-1);
    // s1.quick_sort(0,n);
    // s1.print_arr();
}