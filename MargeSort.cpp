#include<bits/stdc++.h>
using namespace std;

const int n=100;

void marg(int arr[],int s,int e)
{
    int mid = s + (e-s)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k=s;

    for(int i=0;i<len1;i++)
    {
        first[i] = arr[k];
        k++;
    }

    k=mid+1;
    for(int i=0;i<len2;i++)
    {
        second[i] = arr[k];
        k++;
    }
    k=s;
    int i=0,j=0;

    while(i<len1 && j<len2)
    {
        if(first[i] >= second[j])
        {
            arr[k] = second[j];
            j++;
            k++;
        }
        else
        {
            arr[k] = first[i];
            k++;
            i++;
        }
    }

    while(i<len1)
    {
        arr[k]=first[i];
        k++;
        i++;
    }

    while(j<len2)
    {
        arr[k]=second[j];
        k++;
        j++;
    }
}

void margsort(int arr[],int s,int e)
{
    if(s>=e)
        return;

    int mid=(s+e)/2;
    margsort(arr,s,mid);
    margsort(arr,mid+1,e);
    marg(arr,s,e);
}


int main()
{

    int arr[5]={44,23,55,3,77};
    margsort(arr,0,4);

    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<"     ";
    }

    return 0;
}
