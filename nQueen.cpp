#include<bits/stdc++.h>
using namespace std;

const int n=8;

bool isSafe(vector<vector<int>> &v,int x,int y,int n)
{

    //check column attack
    for(int row = 0; row < n; row++)
    {
        if(v[row][y])
        {
            return false;
        }
    }

    int row = x;
    int col = y;

    // check left upper diagonal
    while(row >= 0 && col >=0)
    {
        if(v[row][col])
        {
            return false;
        }
        row--;
        col--;
    }

    row = x;
    col = y;

    // check right upper diagonal

    while(row >= 0 && col <n)
    {
        if(v[row][col])
        {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool nQueen(vector<vector<int>> &v, int x, int n)
{
    if(x>=n)
        return true;

    for(int col=0;col<n;col++)
    {
        if(isSafe(v,x,col,n))
        {
            v[x][col]=1;

            if(nQueen(v,x+1,n))
            {
                return true;
            }

            v[x][col]=0;
        }
    }

    return false;
}

int main()
{

    vector<vector<int>> v(n, vector<int>(n, 0));

    if(nQueen(v,0,n))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<v[i][j]<<"    ";
            }
            cout<<endl;
        }
    }

    return 0;
}
