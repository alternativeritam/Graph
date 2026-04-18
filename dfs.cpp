#include<bits/stdc++.h>
using namespace std;


void dfs(int node,vector<int> adj[],vector<bool> &vis){

	vis[node]=true;
	cout<<node<<" ";
	for(int n:adj[node]){
		if(!vis[n]){
			dfs(n,adj,vis);
		}
	}

}



int main(){

	int n;
	cin>>n;
	vector<int> adj[n+1];
	for(int i = 0; i < n; i++){
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);  // for undirected graph
	}
	vector<bool> vis(n+1,false);

	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,adj,vis);
		}
	}
	
	
	return 0;
}
