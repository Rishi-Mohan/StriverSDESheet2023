void solve(int i, int j, int n, int m, vector<vector<int>> &mat,vector<vector<int>> &vis, string path, vector<string> &ans){
    if(i == n-1 && j == m-1){
        ans.push_back(path);
        return;
    }

    if(i + 1 < n && vis[i + 1][j] == 0 && mat[i+1][j] == 1){
        vis[i][j] = 1;
        solve(i+1, j, n, m, mat, vis, path + 'D', ans);
        vis[i][j] = 0;
    }

    if(i - 1 >= 0 && vis[i - 1][j] == 0 && mat[i-1][j] == 1){
        vis[i][j] = 1;
        solve(i-1, j, n, m, mat, vis, path + 'U', ans);
        vis[i][j] = 0;
    }

    if(j + 1 < m && vis[i][j+1] == 0 && mat[i][j+1] == 1){
        vis[i][j] = 1;
        solve(i, j+1, n, m, mat, vis, path + 'R', ans);
        vis[i][j] = 0;
    }


    if(j - 1 >= 0&& vis[i][j-1] == 0 && mat[i][j-1] == 1){
        vis[i][j] = 1;
        solve(i, j-1, n, m, mat, vis, path + 'L', ans);
        vis[i][j] = 0;
    }
    
}
vector<string> ratMaze(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<string> ans;

    if(mat[0][0] == 0){
        return ans;
    }

    string path;
    vector<vector<int>> vis(n, vector<int>(m));
    solve(0, 0, n, m, mat, vis, path, ans);
    return ans;
}
