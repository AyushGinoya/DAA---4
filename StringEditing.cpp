#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";

    int len1 = str1.length();
    int len2 = str2.length();

    int t[len1+1][len2+1];

    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            if(i==0)
            {
                t[i][j] = j;
            }
            else if(j==0)
            {
                t[i][j] = i;
            }
            else if(str1[i] == str2[j])
            {
                t[i][j] = t[i-1][j-1];
            }
            else
            {
                t[i][j] =1 + min(min(t[i-1][j] , t[i][j-1]) , t[i-1][j-1]);
            }
        }
    }

    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            cout<<t[i][j]<<"    ";
        }
        cout<<endl;
    }

    cout<<endl<<t[len1][len2];

    return 0;
}
