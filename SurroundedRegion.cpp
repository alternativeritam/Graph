#include<bits/stdc++.h>
using namespace std;



void dfs(vector<vector<char>> &mat,int row,int col,vector<vector<bool>> &vis){

	vis[row][col]=true;
	vector<int> drow={+1,0,-1,0};
	vector<int> dcol={0,+1,0,-1};

	for(int i=0;i<4;i++){

		int nrow=row+drow[i];
		int ncol=col+dcol[i];

		if(nrow>=0 && nrow<n && ncol>=0 && ncol<m !vis[nrow][ncol] && mat[nrow][ncol]=='0' && !vis[nrow][ncol]){
			dfs(mat,nrow,ncol,vis);
		}

	}
}


int main(){

	// given M x N matrix

	int n,m;
	cin>>n>>m;
	// give the matrix as input
	vector<vector<char>> mat(n,vector<char>(m));

	vector<vector<bool>> vis(n,vector<bool>(m));

	// first column
	for(int i=0;i<n;i++){

		if(mat[i][0]=='0' && !vis[i][0]){
			vis[i][0]=true;
			dfs(mat,i,0,vis);
		}

	}

	// last column
	for(in i=0;i<n;i++){

		if(mat[i][m-1]=='0' && !vis[i][m-1]){
			vis[i][m-1]=true;
			dfs(mat,i,m-1,vis);
		}
	}

	// first row
	for(int i=0;i<m;i++){
		if(mat[0][i]=='0' && !vis[0][i]){
			vis[0][i]=true;
			dfs(mat,0,i,vis);
		}
	}

	// last row
	for(int i=0;i<m;i++){
		if(mat[n-1][i]=='0'&& !vis[n-1][i]){
			vis[n-1][i]=true;
			dfs(mat,0=n-1,i,vis);
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j] && mat[i][j]=='0'){
				mat[i][j]='X';
			}
		}
	}


	
}
