#include<bits/stdc++.h>
using namespace std;


bool dfs(int node,vector<int> adj[],vector<int> &color,int col){
	color[node]=col;

	for(auto it:adj[node]){
		if(color[it]==-1){
			if(!dfs(it,adj,color,!col)) return false;
		}
		else if(color[it]==color[node]) return false;
	}

	return true;
}


int main() {
    
    int n;cin>>n;
    // get the adjacent nodes

    vector<int> adj[n];

    vector<int> color(n,-1);

    for(int i=0;i<n;i++){

    	if(color[i]==-1){
    		if(!dfs(i,adj,color,0)){
    			cout<<"No Bipartite graph"<<endl;
    	}
    }

}
