#include<bits/stdc++.h>
using namespace std;


void bfs(int node,vector<int> &adj[],vector<bool> &vis){

	queue<int> q;
	q.push(node);
	vis[node]=true;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int n:adj[cur]){
			if(!vis[n]){
				q.push(n);
				vis[n]=true;
			}
		}
	}

}



int main(){

	int n;
	vector<int> adj[n+1];

	vector<bool> vis(n+1,false);

	for(int i=1;i<=n;i++){
		if(!vis[i]){
			bfs(i,adj,vis);
		}
	}
	
	
	return 0;
}
