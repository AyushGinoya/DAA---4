#include<bits/stdc++.h>
using namespace std;

int main()
{
    string boy="ayush";
    string girl="ayushi";

    int b=boy.length();
    int g=girl.length();

    int t[b+1][g+1];

    for(int i=0;i<=b;i++)
    {
        for(int j=0;j<=g;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j]=0;
            }
            else if(boy[i-1]==girl[j-1])
            {
                t[i][j]=t[i-1][j-1]+1;
            }
            else
            {
                t[i][j] = max(t[i][j-1] , t[i-1][j]);
            }
        }
    }


    for(int i=0;i<=b;i++)
    {
        for(int j=0;j<=g;j++)
        {
            cout<<t[i][j]<<"    ";
        }
        cout<<endl;
    }

    cout<<endl<< t[b][g]<<endl;
}
