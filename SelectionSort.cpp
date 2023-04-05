#include<bits/stdc++.h>
using namespace std;

void myFun(int arr[] , int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIdx = i;
        int j;
        for(j=i+1;j<n;j++)
        {
            if(arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(arr[i],arr[minIdx]);
    }
}
int main()
{
    int n=6;
    int arr[n] = {3,35,77,4,22,8};

    myFun(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"     ";
    }
}
