#include <iostream>

using namespace std;

int N;
char map[101][101];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isInside(int i, int j) {
    return ((i<N && i>=0) && (j<N && j>=0));
}

void dfs(int a, int b, char cur) {
    if (cur == 'R' || cur == 'G') map[a][b] = '0';
    else if (cur == 'B') map[a][b] = '1';
    else if (cur == '0') map[a][b] = 'X';
    else if (cur == '1') map[a][b] = 'X';
    
    for (int i=0; i<4; i++){
        int dy = a + dir[i][0];
        int dx = b + dir[i][1];

        if (isInside(dy, dx) && map[dy][dx] == cur) {
            dfs(dy, dx, cur);
        }
    }
}

int main() {
    int rgb = 0, rb = 0;
    cin >> N;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j] == 'R') {
                rgb++;
                dfs(i, j, 'R');
            }
            else if (map[i][j] == 'G') {
                rgb++;
                dfs(i, j, 'G');
            }
            else if (map[i][j] == 'B') {
                rgb++;
                dfs(i, j, 'B');
            }
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j] == '0') {
                rb++;
                dfs(i, j, '0');
            }
            else if (map[i][j] == '1') {
                rb++;
                dfs(i, j, '1');
            }
        }
    }
    cout << rgb << " " << rb << endl;
}
