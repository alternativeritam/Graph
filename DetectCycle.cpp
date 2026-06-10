#include<bits/stdc++.h>
using namespace std;



bool dfs(vector<int> adj[],vector<bool> vis,int pre,int cur){

	for(auto node:adj[cur]){
		if(!vis[node]){
			vis[node]=true;
			dfs(adj,vis,cur,node);
		}
		else if(vis[node] && pre!=node) return true;
	}

	return false;
}


int main(){

	// given adjacent list of the graph
	int n;
	cin>>n;
	vector<int> adj[n];
	vector<bool> vis(n);
	for(int i=0;i<n;i++){

		if(!vis[i]){
			vis[i]=true;
			if(dfs(adj,vis,-1,i)) cout<<"Yes cycle is there"
		}

	}
	return 0;
}
