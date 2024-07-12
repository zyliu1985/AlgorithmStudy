#include <iostream>
using namespace std;

long long f[25][25];
int dx[9] = {-1, 1, 2, 2, 1, -1, -2, -2, 0};
int dy[9] = {-2, -2, -1, 1, 2, 2, 1, -1, 0};
int n, m, a, b;
bool check(int x, int y){
    for (int i = 0; i < 9; i++){
        int nx = a + dx[i];
        int ny = b + dy[i];
        if (nx == x && ny == y) return false;
    }
    return true;
}
int main(){
    cin >> n >> m >> a >> b;
    f[0][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (i == 0 && j == 0) continue;
            else{
                if (!check(i, j)) continue;
                if (i > 0) f[i][j] += f[i-1][j];
                if (j > 0) f[i][j] += f[i][j-1];
            }
    cout << f[n][m] << endl;
    return 0;
}