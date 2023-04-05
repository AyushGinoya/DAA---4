#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=9;
    int arr[n] = {33,446,112,778,22,442,12,56,22};

    int x=12;

    for(int i=1;i<=n;i++)
    {
        if(x == arr[i])
        {
            cout<<"position = "<<i+1;
            break;
        }
    }
}
