#include<bits/stdc++.h>
using namespace std;


bool dfs(int node,vector<int> adj[],vector<bool> &vis,vector<bool> &pathVis){

	vis[node]=true;
	pathVis[node]=true;


	for(auto it:adj[node]){

		if(!vis[it]){
			if(dfs(it,adj,vis,pathVis)) return true;
		}
		else if(pathVis[it]){
			return true;
		}
	}

	pathVis[node]=false;
	return false;

}


int main() {
    
    int n;cin>>n;
    // get the adjacent nodes

    vector<int> adj[n];

    vector<bool> vis(n);
    vector<bool> pathVis(n);

    for(int i=0;i<n;i++){

    	if(dfs(i,adj,vis,pathVis)){
    		cout<<"Cycle detected"<<endl;
    	}
    }

}
