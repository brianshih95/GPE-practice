#include <bits/stdc++.h>
#define pci pair<char, int>
#define X first
#define Y second
using namespace std;

int h, w;

bool cmp(pci a, pci b){
    if(a.Y == b.Y)  // same times
        return a.X < b.X;
    return a.Y > b.Y;
}

void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid){
    vis[i][j] = 1;

    if(i+1<h && !vis[i+1][j] && grid[i][j] == grid[i+1][j])
        dfs(i+1, j, vis, grid);
    if(i-1>=0 && !vis[i-1][j] && grid[i][j] == grid[i-1][j])
        dfs(i-1, j, vis, grid);
    if(j+1<w && !vis[i][j+1] && grid[i][j] == grid[i][j+1])
        dfs(i, j+1, vis, grid);
    if(j-1>=0 && !vis[i][j-1] && grid[i][j] == grid[i][j-1])
        dfs(i, j-1, vis, grid);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int cases=1; cases<=n; cases++){
        cin >> h >> w;
        vector<vector<char>> grid(h, vector<char>(w));
        vector<vector<bool>> vis(h, vector<bool>(w, 0));
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
                cin >> grid[i][j];

        vector<pci> alphabet(26);   // X stands for state, Y stands for number of state
        for(int i=0; i<26; i++)
            alphabet[i] = {'a' + i, 0};

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(!vis[i][j]){
                    dfs(i, j, vis, grid);
                    alphabet[grid[i][j]-'a'].Y++;
                }
            }
        }

        sort(alphabet.begin(), alphabet.end(), cmp);

        cout << "World #" << cases << '\n';
        for(auto [x, y]: alphabet)
            if(y)
                cout << x << ": " << y << '\n';
    }
    return 0;
}
