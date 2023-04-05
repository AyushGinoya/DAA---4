#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num_val=4;
    int num_wt=4;
    int max_wt=10;

    int wt[num_wt];
    int value[num_val];

    cout<<"Ent wt : ";
    for(int i=0;i<num_wt;i++)
        cin>>wt[i];

    cout<<"Ent val : ";
    for(int i=0;i<num_val;i++)
        cin>>value[i];

    int table[num_val + 1][max_wt + 1];

    for(int i=0;i<num_val+1;i++)
        table[i][0]=0;

    for(int i=0;i<max_wt+1;i++)
        table[0][i]=0;

    for(int i=1;i<num_val + 1;i++)
    {
        for(int j=1;j<max_wt + 1;j++)
        {
            if(wt[i-1]>j)
                table[i][j] = table[i-1][j];
            else
                table[i][j] = max(table[i-1][j],table[i-1][j - wt[i - 1]]+value[i - 1]);
        }
    }

    for(int i=0;i<num_val + 1;i++)
    {
        for(int j=0;j<max_wt + 1;j++)
            cout << table[i][j] << " ";
        cout << endl;
    }

    cout << endl;
    cout<<endl<<table[4][10]<<endl;
}
