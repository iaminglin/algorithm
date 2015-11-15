#include "head.h"
void printArr(int arr[],int length);
int main(int argc, char const *argv[])
{
    int num = 20;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        arr[i] = rand()%1000;
    }
    printArr(arr,num);
    // BubbleSort(arr,0,num-1);
    // QuickSort(arr,0,num -1);
    // SelectionSort(arr,0,num-1);
    // HeapSort(arr,num);
    // InsertSort(arr,0,num-1);
    // ShellSort(arr,0,num-1);
    // MergeSort(arr,0,num-1);

    int temp[] = {1,10,100,1000,10000};
    // RadixSort_LSD(arr,0,num-1,4,temp);
    // RadixSort_MSD(arr,0,num-1,4,temp);
    printArr(arr,num);
    return 0;
}


void BubbleSort(int arr[],int begin,int end)
{
    for (int i = begin,num=0; i < end; ++i,++num)
    {
        for(int j = begin;j<end-num;++j)
        {
            if(arr[j]>arr[j+1])
            {
                Swap(arr,j,j+1);
            }
        }
    }
}
void QuickSort(int arr[],int begin,int end)
{
    if(end-begin+1<10)
    {
        BubbleSort(arr,begin,end);
        return;
    }
    PatitionMedianOfThree(arr,begin,end);
    int left = begin;
    int first = begin;
    int right = end;
    int last = end;
    int leftNum = 0;
    int rightNum = 0;
    int key = arr[begin];
    while(first<last)
    {
        while(first<last && arr[last]>=key)
        {
            if(arr[last] == key)
            {
                Swap(arr,last,right);
                right--;
                rightNum++;
            }
            last--;
        }
        arr[first] = arr[last];
        while(first<last && arr[first] <= key)
        {
            if(arr[first] == key)
            {
                Swap(arr,left,first);
                left++;
                leftNum++;
            }
            first++;
        }
        arr[last] = arr[first];
    }
    arr[first] = key;
    int i = begin;
    int j = first-1;
    while(i<left && arr[j]!=key)
    {
        Swap(arr,i,j);
        i++;
        j--;
    }
    i= end;
    j = last+1;
    while(i>right && arr[j]!=key)
    {
        Swap(arr,i,j);
        i--;
        j++;
    }
    QuickSort(arr,begin,first-1-leftNum);
    QuickSort(arr,last+1+rightNum,end);
}
void SelectionSort(int arr[],int begin,int end)
{
    int minIndex=0;
    int maxIndex=0;
    for(int i = begin,num =0;i<begin+(end-begin+1)/2;i++,num++)
    {
        minIndex = i;
        maxIndex = i;
        for(int j = i+1;j<=end-num;j++)
        {
            if(arr[minIndex]>arr[j])
            {
                minIndex = j;
                continue;
            }
            if(arr[maxIndex]<arr[j])
            {
                maxIndex = j;
            }
        }
        if(minIndex!=i)
        {
            Swap(arr,minIndex,i);
        }
        if(maxIndex!=i)
        {
            Swap(arr,maxIndex,end-num);
        }
    }
}
void HeapSort(int arr[],int length)
{
    for(int i = length/2-1;i>=0;i--)
    {
        HeapAdjust(arr,i,length-1);
    }
    for(int i = length-1;i>=1;i--)
    {
        Swap(arr,0,i);
        HeapAdjust(arr,0,i-1);
    }
}
void InsertSort(int arr[],int begin,int end)
{
    for(int i = begin+1;i<=end;i++)
    {
        for(int j = i-1;j>=0 && arr[j]>arr[j+1];j--)
        {
            Swap(arr,j,j+1);
        }
    }
}
void ShellSort(int arr[],int begin,int end)
{
    int shell[3] = {5,3,1};
    for(int k = 0;k<3;k++)
    {
        for(int i = begin+shell[k];i<=end;i++)
        {
            for(int j = i-shell[k];j>=0 && arr[j]>arr[j+1];j-=shell[k])
            {
                Swap(arr,j,j+1);
            }
        }
    }
}
void MergeSort(int arr[],int begin,int end)
{
    if(begin!=end)
    {
        int mid = (end+begin)/2;
        MergeSort(arr,begin,mid);
        MergeSort(arr,mid+1,end);
        Merger(arr,begin,mid,end);
    }
}
void RadixSort_MSD(int arr[],int begin,int end,int d,int temp[])
{
    int radix = 10;
    int count[radix];
    int bucket[end-begin+1];
    int i;
    int j;
    for(i = 0;i<radix;i++)
    {
        count[i] = 0;
    }
    for(i=begin;i<=end;i++)
    {
        count[getdigit(arr[i],temp[d-1])]++;
    }
    for(i = 1;i<radix;i++)
    {
        count[i] = count[i]+count[i-1];
    }
    int maxIndex = count[radix-1];
    for(i=end;i>=begin;i--)
    {
        j = getdigit(arr[i],temp[d-1]);
        bucket[count[j]-1] = arr[i];
        count[j]--;
    }
    for(i = begin,j=0;i<=end;i++,j++)
    {
        arr[i] = bucket[j];
    }
    for(i = 0;i<radix;i++)
    {
        int p1 = count[i];
        int p2 = i==radix-1?maxIndex-1:count[i+1]-1;
        if(p1<p2 && d>1)
        {
            RadixSort_MSD(arr,p1,p2,d-1,temp);
        }
    }
}
void RadixSort_LSD(int arr[],int begin,int end,int d,int temp[])
{
    int radix = 10;
    int count[radix];
    int bucket[end-begin+1];
    int i;
    int j;
    for(int k = 0;k<d;k++)
    {
        for(i = 0;i<radix;i++)
        {
            count[i] = 0;
        }
        for(i=begin;i<=end;i++)
        {
            count[getdigit(arr[i],temp[k])]++;
        }
        for(i = 1;i<radix;i++)
        {
            count[i] = count[i]+count[i-1];
        }
        for(i=end;i>=begin;i--)
        {
            j = getdigit(arr[i],temp[k]);
            bucket[count[j]-1] = arr[i];
            count[j]--;
        }
        for(i = begin,j=0;i<=end;i++,j++)
        {
            arr[i] = bucket[j];
        }
    }
}
void PatitionMedianOfThree(int arr[],int begin,int end)
{
    int mid = begin+(end-begin)/2;
    if(arr[mid]>arr[end])
    {
        Swap(arr,mid,end);
    }
    if(arr[begin]>arr[end])
    {
        Swap(arr,begin,end);
    }
    if(arr[mid]>arr[begin])
    {
        Swap(arr,mid,begin);
    }
}
void HeapAdjust(int arr[],int begin,int end)
{
    int key = arr[begin];
    for(int i = 2*begin+1;i<=end;i=2*i+1)
    {
        if(i<end && arr[i]<arr[i+1])
        {
            i++;
        }
        if(key<arr[i])
        {
            arr[begin] = arr[i];
            begin = i;
        }
        else
        {
            break;
        }
    }
    arr[begin] = key;
}
void Merger(int arr[],int begin,int mid,int end)
{
    int temp[end-begin+1];
    int index = 0;
    int i = begin;
    int j = mid+1;
    while(i<=mid && j<=end)
    {
        if(arr[i]>arr[j])
        {
            temp[index] = arr[j];
            j++;
        }
        else
        {
            temp[index] = arr[i];
            i++;
        }
        index++;
    }
    while(i<=mid)
    {
        temp[index] = arr[i];
        i++;
        index++;
    }
    while(j<=end)
    {
        temp[index] = arr[j];
        j++;
        index++;
    }
    for(i = begin,j=0;i<=end;i++,j++)
    {
        arr[i] = temp[j];
    }
}
int getdigit(int i,int j)
{

    return i/j%10;
}
void Swap(int arr[],int a,int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void printArr(int arr[],int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
