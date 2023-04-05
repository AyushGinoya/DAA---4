#include<iostream>
using namespace std;

void insertionSort(int arr[],int n)
{
    int j,x;
    for(int i=1;i<n;i++)c
    {
        x = arr[i];
        j=i-1;
        while(j>-1 && arr[j] > x)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}
int main()
{
    int arr[7]={33,54,64,775,3,22,2};

    insertionSort(arr,7);

    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<"    ";
    }
}
