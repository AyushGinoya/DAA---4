#include<bits/stdc++.h>
using namespace std;

const int n=10;
vector< pair <int,int> > g[n];
vector<int> dis(n,INT_MAX);
vector<bool> vis(n,false);
vector<int> parent(n);
int cost=0;

void primsMst(int source)
{
     set < pair < int , int > > st;     //wt,vtx

    st.insert({0,source});
    dis[source]=0;

    while(st.size() > 0)
    {
        auto node = *st.begin();
        st.erase(st.begin());

        int curr_node = node.second;       //u
        int curr_node_dis = node.first;        //wt
        int v = parent[curr_node];

         vis[curr_node] = true;

       cost = cost + curr_node_dis;

        for(auto child : g[curr_node])
        {
            int child_node_dis = child.second;   //1
            int child_node = child.first;       //0

            if(vis[child_node ])
            continue;

            if(dis[child_node] > child_node_dis)
            {
                st.erase({dis[child_node] , child_node});
                dis[child_node] = child_node_dis;
                st.insert({dis[child_node],child_node});
                parent[child_node] = curr_node;
            }
        }
    }
    cout<<cost<<endl;
}

int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }

    primsMst(0);

    return 0;
}
