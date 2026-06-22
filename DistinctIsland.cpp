#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int n, int m, vector<vector<int>> &grid,
         vector<vector<bool>> &vis, vector<pair<int,int>> &pos, int row0, int col0) {
    vis[row][col] = true;
    pos.push_back({row - row0, col - col0}); // insert the position after sub tracting the base row and col

    int drow[] = {0, +1, 0, -1};
    int dcol[] = {+1, 0, -1, 0};

    for (int k = 0; k < 4; k++) {
        int nrow = row + drow[k];
        int ncol = col + dcol[k];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
            && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
            dfs(nrow, ncol, n, m, grid, vis, pos, row0, col0);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    set<vector<pair<int,int>>> st;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == 1) {
                vector<pair<int,int>> pos;
                dfs(i, j, n, m, grid, vis, pos, i, j);
                st.insert(pos);
            }
        }
    }

    cout << st.size() << endl;
    return 0;
}
