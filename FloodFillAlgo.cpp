#include<bits/stdc++.h>
using namespace std;



void dfs(vector<vector<int>> &ans,int row,int col,int initCol,int newCol,vector<int> &drow,vector<int> &dcol){

	int n=ans.size();
	int m=ans[0].size();

	for(int i=0;i<4;i++){

		int nrow = row+drow[i];
		int ncol = col+dcol[i];

		if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==initCol){
			ans[nrow][ncol]=newCol;
			dfs(ans,nrow,ncol,initCol,newCol,drow,dcol);
		}

	}

}


int main(){

	int n,m;
	cin>>n>>m;
	// given a 2-D array
	vector<vector<int>> grid(n,vector<int>(m));
	vector<vector<int>> ans = grid; //copy it
	int row,col;
	cin>>row>>col;
	int initCol = grid[row][col];
	int newCol;
	cin>>newCol;
	vector<int> drow = {0,+1,0,-1};
	vector<int> dcol = {1,0,-1,0};
	dfs(ans,row,col,initCol,newCol,drow,dcol);
	// print ans

	return 0;
}
