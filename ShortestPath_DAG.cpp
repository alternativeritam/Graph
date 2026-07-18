#include<bits/stdc++.h>
using namespace std;

void TopoSort(vector<pair<int,int>> adj[],vector<bool> &vis,int node,stack<int> &st){

    vis[node]=true;

    for(auto it:adj[node]){
        int cur = it.first;
        if(!vis[cur]){
            TopoSort(adj,vis,cur);
        }
    }

    st.push(node);
}


int main() {
    
   int n,;
   cin>>n;
   // given adjacency list with weight
   vector<pair<int,int>> adj[n];
   stack<int> st;
   for (int i = 0; i < n; ++i)
   {
       if(!vis[i]){
            TopoSort(adj,vis,i,st);
       }
   }
   
   vector<int> dis(n,INT_MAX);

   while(!st.empty()){

        int node = st.top();
        st.pop();

        for(auto it:adj[node]){

            int cur = it.first;
            int wt = it.second;

            dis[cur] = min(dis[cur],dis[node]+wt);
        }

   }

   // print dis array

}
