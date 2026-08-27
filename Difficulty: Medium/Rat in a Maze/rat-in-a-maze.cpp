class Solution {
  public:
  
    bool valid(int i, int j, int n){
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    
    void total(vector<vector<int>>& maze, int i, int j, int n, string path, 
    vector<string>& ans, vector<vector<bool>>& visited){
        if(i == n - 1 && j == n - 1){
            ans.push_back(path);
            return;
        }
        
        visited[i][j] = 1;
        
        //UP
        if(valid(i - 1, j, n) && visited[i - 1][j] != 1 && maze[i-1][j]){
            path.push_back('U');
            total(maze, i - 1, j, n, path, ans, visited);
            path.pop_back();
        }
        
        //DOWN
        if(valid(i + 1, j, n) && visited[i + 1][j] != 1 && maze[i + 1][j]){
            path.push_back('D');
            total(maze, i + 1, j, n, path, ans, visited);
            path.pop_back();
        }
        
        //LEFT
        if(valid(i, j - 1, n) && visited[i][j - 1] != 1 && maze[i][j - 1]){
            path.push_back('L');
            total(maze, i, j - 1, n, path, ans, visited);
            path.pop_back();
        }
        
        //RIGHT
        if(valid(i, j + 1, n) && visited[i][j + 1] != 1 && maze[i][j + 1]){
            path.push_back('R');
            total(maze, i, j + 1, n, path, ans, visited);
            path.pop_back();
        }
        
        visited[i][j] = 0;
        
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        int n = maze.size();
        vector<string> ans;

        if (n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
            return ans;
        }

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        total(maze, 0, 0, n, "", ans, visited);

        sort(ans.begin(), ans.end());

        return ans;
    }
};