#include<bits/stdc++.h>
using namespace std;

const int n=1e5+7;
int parent[n];
int sz[n];

void make(int v)
{
    parent[v]=v;
    sz[v]=1;
}

int find(int v)
{
    if(v == parent[v])
        return v;
    else
        return parent[v]=find(parent[v]);

    /*
        while (parent[v] != v)
        v = parent[v];

        return v;
    */
}

int Union(int a,int b)
{
    a=find(a);
    b=find(b);

    if(a != b)
    {
        if(sz[a] < sz[b])
            swap(a,b);

        parent[b]=a;
        sz[a] += sz[b];
    }
}

int main()
{
    vector< pair<int, pair<int,int> > >edges;

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a,b,wt;
        cin>>a>>b>>wt;
        edges.push_back({wt,{a,b}});
    }

    sort(edges.begin(), edges.end());

    for(int i=0;i<n;i++)
    {
        make(i);
    }

    int cost=0;
    for(auto &edge : edges)
    {
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;

        if(find(u)==find(v))
            continue;
        Union(u,v);
        cost = cost + wt;
        cout<<u<<"   "<<v<<endl;
    }

    cout<<endl<<cost<<endl;
}
