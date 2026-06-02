#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &grid,vector<vector<bool>> &vis,int row,int col){

	int n=grid.size();
	int m=grid[0].size();

	queue<pair<int,int>> q;
	q.push({row,col});
	vis[row][col]=true;
	while(!q.empty()){

		int i=q.front().first;
		int j=q.front().second;

		for(int drow=-1;drow<=1;drow++){
			for(int dcol=-1;dcol<=1;dcol++){
				int nrow = i+drow;
				int ncol = j+dcol;

				if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
					vis[nrow][ncol]=true;
					q.push({nrow,ncol});
				}
			}
		}
	}
}



int main(){

	int n,m;
	cin>>n>>m;
	// given a 2-D array
	vector<vector<int>> grid(n,vector<int>(m));
	vector<vector<bool>> grid(n,vector<int>(m,false));
	int cnt=0;
	for(int i=0;i<n;i++){

		for(int j=0;j<m;j++){

			if(!vis[i][j]){
				bfs(grid,vis,i,j);
				cnt++
			}
		}
	}

	cout<<cnt<<endl;

	return 0;
}
