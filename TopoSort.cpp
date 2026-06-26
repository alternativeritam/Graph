#include<bits/stdc++.h>
using namespace std;


void dfs(int node,vector<int> adj[],stack<int> &st,vector<bool> &vis){

	vis[node]=true;

	for(auto it:adj[node]){
		if(!vis[it]){
			dfs(it,adj,st,vis);
		}
	}
	st.push(node);
}


int main() {
    
    int n;cin>>n;
    // get the adjacent nodes

    vector<int> adj[n];
    stack<int> st;
    vector<bool> vis(n,false);
    for (int i = 0; i <n; ++i)
    {
    	if(!vis[i]){
    		dfs(i,adj,st,vis);
    	}
    }
   	
   	vector<int> ans;

   	while(!st.empty()){
   		ans.push_back(st.top());
   		st.pop();
   	}

}
