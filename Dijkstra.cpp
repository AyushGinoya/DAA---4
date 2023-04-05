#include<bits/stdc++.h>
using namespace std;

const int n=100;
vector<pair<int,int>> g[n];
vector<bool> vis(n,false);
vector<int> dist(n,INT_MAX);


void dijkstra(int source)
{
    set < pair < int , int > > st;

    st.insert({0,source});
    dist[source]=0;

    while(st.size() > 0)
    {
       auto node1 = *st.begin();
        st.erase(st.begin());

        int curr_node = node1.second;
        int curr_node_dis = node1.first;

       if(vis[curr_node])
            continue;

        vis[curr_node] = true;
        for(auto child : g[curr_node])
        {
            int child_node = child.second;
            int child_node_dis = child.first;

            if(dist[curr_node] + child_node_dis < dist[child_node])
            {
                dist[child_node] = dist[curr_node] + child_node_dis;
                st.insert({dist[child_node] , child_node});
            }
        }
    }
}
int main()
{
    cout<<"Enter Node and Edg : ";
    int m,n;
    cin>>m>>n;

    cout<<"Enter x,y,wt :";
    for(int i=0;i<n;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
        g[y].push_back({x,wt});
    }


    for(auto m : g)
    {
        for(auto n :m)
        {
            cout<<n.first<<"    "<<n.second<<endl;
        }
        cout<<endl;
    }

    cout<<"Enter Source node :";
    int s;
    cin>>s;
    dijkstra(s);

    int ans=0;
    for(int i=0;i<n;i++)
    {

       cout<<dist[i]<<"     ";
    }
}
