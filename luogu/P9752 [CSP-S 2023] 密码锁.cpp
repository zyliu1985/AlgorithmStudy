#include <iostream>
#include <algorithm>
using namespace std;

int cnt[10][10][10][10][10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		for (int x = 1; x <= 9; x++){
//			cnt[(a)%10][(b)%10][(c)%10][(d)%10][(e)%10]++;
			cnt[(a+x)%10][(b)%10][(c)%10][(d)%10][(e)%10]++;
			cnt[(a)%10][(b+x)%10][(c)%10][(d)%10][(e)%10]++;
			cnt[(a)%10][(b)%10][(c+x)%10][(d)%10][(e)%10]++;
			cnt[(a)%10][(b)%10][(c)%10][(d+x)%10][(e)%10]++;
			cnt[(a)%10][(b)%10][(c)%10][(d)%10][(e+x)%10]++;
			cnt[(a+x)%10][(b+x)%10][(c)%10][(d)%10][(e)%10]++;
			cnt[(a)%10][(b+x)%10][(c+x)%10][(d)%10][(e)%10]++;
			cnt[(a)%10][(b)%10][(c+x)%10][(d+x)%10][(e)%10]++;
			cnt[(a)%10][(b)%10][(c)%10][(d+x)%10][(e+x)%10]++;
		}
	}
	int ans = 0;
	for (int a = 0; a < 10; a++)
		for (int b = 0; b < 10; b++)
			for (int c = 0; c < 10; c++)
				for (int d = 0; d < 10; d++)
					for (int e = 0; e < 10; e++)
						if (cnt[a][b][c][d][e] == n) ans++;
	cout << ans << '\n';
	return 0;
}

