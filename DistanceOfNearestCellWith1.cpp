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

	// given M x N matrix

	int n,m;
	cin>>nm>>m;
	vector<vector<int>> grid(n,vector<int>(m)); // it is given
	vector<vector<int>> dist(n,vector<int>(m));
	vector<vector<bool>> vis(n,vector<bool>(m));
	queue<pair<pair<int,int>,int>> q;
	for(int i=0;i<n;i++){

		for(int j=0;j<m;j++){
			if(grid[i][j]==1){
				q.push({{0,0},0});
				vis[i][j]=true;
				dist[i][j]=0;
			}
		}

	}

	vector<int> drow = {0,+1,0,-1};
	vector<int> dcol = {1,0,-1,0};

	while(!q.empty()){

		int row = q.front().first.first;
		int col = q.front().first.second;
		int step = q.front().second;
		q.pop();
		dist[row][col]=std;
		for(int i=0;i<4;i++){

			int nrow = row+drow[i];
			int ncol = col+dcol[i];
			if(nrow>=0 && nrow<n && ncol>=0 && ncol<m !vis[nrow][ncol]){

				vis[nrow][ncol]=true;
				q.push({{nrow,ncol},step+1});

			}
		}
	}
}
