#include<bits/stdc++.h>
using namespace std;



int main() {

    int v,s;
    cin>>v>>s; // v -> number of vertex and s -> start node
  // give adjacency list {wt,node}
    vector<vector<int>> adj[];
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});
    vector<int> dist(v,INT_MAX);
    while(!pq.empty()){

        int dis = pq.front().first;
        int node = pq.front().second;
        pq.pop();
        for(auto it:adj[node]){

            int wt = it[0];
            int cur = it[1];

            if(wt+dis<dist[cur]){
                dist[cur]=wt+dis;
                pq.push({dist[cur],cur});
            }
        }

    }

    // print dist array
}
