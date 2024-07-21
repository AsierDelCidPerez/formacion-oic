#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int despAdy[2][8] = {
    {1, 1, 0, -1, -1, -1, 0, 1},
    {0, -1, -1, -1, 0, 1, 1, 1}
};

const int desp[2][4] = {
    {1, 0, -1, 0},
    {0, -1, 0, 1}
};

vector<vector<bool>> visited;

int dfs(vector<string> const & bitmap, int x, int y){
    visited[x][y] = true;
    int acumulado = 0;
    for(int i=0;i<4;i++){
        int nX = x + desp[0][i];
        int nY = y + desp[1][i];

        if(nX >= 0 && nY >= 0 && nX < bitmap.size() && nY < bitmap[0].length()){
            if(bitmap[nX][nY] == '#' && !visited[nX][nY]) {
                acumulado += dfs(bitmap, nX, nY);
            }
        }
    }
    return acumulado+1;
}

int maxMancha(vector<string> const & bitmap){
    int max = 0;
    for(int i=0;i<bitmap.size();i++){
        for(int j=0;j<bitmap[0].length();j++){
            if(bitmap[i][j] == '#' && !visited[i][j]) {
                int res = dfs(bitmap, i, j);
                max = res > max ? res : max;
            }
        }
    }
    return max;
}

int main(){
    int N, C;
    while(cin >> N >> C){
        vector<string> bitmap(N, "");
        visited.assign(N, vector<bool>(C, false));
        cin.ignore();
        for(int i=0;i<N;i++){
            getline(cin, bitmap[i]);
        }

        cout << maxMancha(bitmap) << "\n";
    }
}
