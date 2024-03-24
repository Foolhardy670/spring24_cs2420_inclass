#include <iostream>

using namespace std;

// print
void print(int a[], int n)
{
    int i;
    for(i =0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

// sorting
void bubble_sort(int a[], int n)
{
    int i, j, aux;
    for(i=1; i<n; i++)
    {
        for(j=n-1;j>=1;j--)
        {
            if(a[j-1] > a[j])
            {
                aux = a[j-1];
                a[j-1] = a[j];
                a[j] = aux;
            }
        }
    }
}

void insertion_sort(int a[], int n)
{
    int i, aux, k;
    for(i=1; i<n; i++)
    {
        aux = a[i];
        k = i -1;
        while(k>=0 && aux<a[k])
        {
            a[k+1] = a[k];
            k--;
        }
        a[k+1] = aux;
    }
}

void selection_sort(int a[], int n)
{
    int i, min, j, k;
    for(i=0; i<n; i++)
    {
        min = a[i];
        k = i;
        for(j=i+1; j<n; j++)
        {
            if(a[j] < min)
            {
                min = a[j];
                k = j;
            }
        }
        a[k] = a[i];
        a[i] = min;
    }
}

int partition_array(int a[], int begin, int end)
{
    int pos_pivot = (begin + end) / 2;
    int x = a[pos_pivot];
    int i = begin;
    int j = end;
    int aux;

    while(i<j)
    {
        // Find all smaller elements to left
        while(a[i] < x)
            i += 1;

        // Find all big elements to right
        while(a[j] > x)
            j -= 1;

        // Organize small elements to left and bigger elements to right [swapping]
        if(i<j)
        {
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            if(i == pos_pivot)
            {
                pos_pivot = j;
                j += 1;
            }
            else
            {
                if(j == pos_pivot)
                {
                    pos_pivot = i;
                    i -= 1;
                }
            }
            i += 1;
            j -= 1;
        }
    }
    if(j == end)
        j -= 1;
    return j;
}

void quick_sort(int a[], int begin, int end)
{
    int k;
    if(begin < end)
    {
        k = partition_array(a, begin, end);
        quick_sort(a, begin, k);
        quick_sort(a, k+1, end);
    }
}

void quick_sort(int a[], int n)
{
    quick_sort(a, 0, n-1);
}

void create_heap(int a[], int n)
{
    int i, k, aux, par_k;
    bool flag;

    for(i=1; i<n ; i++)
    {
        k = i;
        flag = true;
        while(k>0 && flag== true)
        {
            flag = false;
            par_k = (k-1)/2;
            if(a[k]>a[par_k])
            {
                aux = a[par_k];
                a[par_k] = a[k];
                a[k] = aux;
                k = (k-1) / 2;
                flag = true;
            }
        }
    }
}

void remove_heap(int a[], int n)
{
    int i, k, aux;
    int left, right, max, ap;
    bool flag;

    for(i=n-1; i>=1; i--)
    {
        aux = a[i];
        a[i] = a[0];
        left = 1;
        right = 2;
        k = 0;
        flag = true;
        while(left < i && flag == true)
        {
            max = a[left];
            ap = left;
            if(max < a[right] && right!=i)
            {
                max = a[right];
                ap = right;
            }
            if(aux <  max)
            {
                a[k] = a[ap];
                k = ap;
            }
            else
                flag = false;
            left = (k+1)*2-1;
            right = left+1;
        }
        a[k] = aux;
    }
}

void heap_sort(int a[], int n)
{
    create_heap(a, n);
    remove_heap(a, n);
}

// Merges two subarrays of a[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int a[], int left, int mid, int right)
{
    int i, j;
    int size_1 = mid - left + 1;
    int size_2 = right - mid;

    // Create temp arrays
    int *leftArray = new int[size_1];
    int *rightArray = new int[size_2];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (i = 0; i < size_1; i++)
        leftArray[i] = a[left + i];
    for (j = 0; j < size_2; j++)
        rightArray[j] = a[mid + 1 + j];

    int ix_1 = 0; // Initial index of first sub-a
    int ix_2 = 0; // Initial index of second sub-a
    int ix_merge = left; // Initial index of merged a

    // Merge the temp arrays back into a[left..right]
    while (ix_1 < size_1 && ix_2 < size_2)
    {
        if (leftArray[ix_1] <= rightArray[ix_2])
        {
            a[ix_merge] = leftArray[ix_1];
            ix_1++;
        }
        else
        {
            a[ix_merge] = rightArray[ix_2];
            ix_2++;
        }
        ix_merge++;
    }

    // Copy the remaining elements ofs left[], if there are any
    while (ix_1 < size_1)
    {
        a[ix_merge] = leftArray[ix_1];
        ix_1++;
        ix_merge++;
    }

    // Copy the remaining elements of right[], if there are any
    while (ix_2 < size_2)
    {
        a[ix_merge] = rightArray[ix_2];
        ix_2++;
        ix_merge++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-a
// of arr to be sorted */
// https://www.geeksforgeeks.org/merge-sort/
void merge_sort(int a[], int begin, int end)
{
    if(begin < end)
    {
        int mid = begin + (end - begin) / 2;
        merge_sort(a, begin, mid);
        merge_sort(a, mid + 1, end);
        merge(a, begin, mid, end);
    }
}

void merge_sort(int a[], int n)
{
    merge_sort(a, 0, n-1);
}

// Main function
int main(void)
{
    // Example
    int a[] = {15, 67, 8, 16, 44, 27, 12, 35};
    int n = 8;
    cout<<"Initial Array"<<endl;
    print(a, n);

    // Sorting
    bubble_sort(a, n);
    cout<<"[Bubble Sort]"<<endl;

//    insertion_sort(a, n);
//    cout<<"[Insertion Sort]"<<endl;

//    selection_sort(a, n);
//    cout<<"[Selection Sort]"<<endl;

//    quick_sort(a, n);
//    cout<<"[Quick Sort]"<<endl;

//    heap_sort(a, n);
//    cout<<"[Heap Sort]"<<endl;

//    merge_sort(a, n);
//    cout<<"[Merge Sort]"<<endl;

    // result print
    print(a, n);

    return 0;
}