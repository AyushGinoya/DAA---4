#include<bits/stdc++.h>
using namespace std;

int breakArr(int arr[],int s,int e)
{
    int pivot = arr[s];
    int i = s;
    int j = e;
    int ct=0;

    for(int k=s+1;k<=e;k++)
    {
        if(arr[k]<=pivot)
            ct++;
    }

    int pivotindex=ct+s;
    swap(arr[s] , arr[pivotindex]);

    while(i<pivotindex && j>pivotindex)
    {
        if(arr[i] <= pivot)
        {
            i++;
        }
        else if(arr[j] >= pivot)
        {
            j--;
        }

        if(i<pivotindex && j>pivotindex)
            swap(arr[i],arr[j]);

    }
    return pivotindex;
}
void quickSort(int arr[] , int s, int e)
{
    if(s>=e)
        return;
    int p = breakArr(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main()
{
    int arr[7]={33,54,64,775,3,22,2};

    quickSort(arr,0,6);

    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<"    ";
    }
}

