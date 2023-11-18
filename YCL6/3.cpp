#include <iostream>
using namespace std;

int a[10] = {0,5,4,3,2,1}, b[10], c[10], mins = 1e9;

void dfs(int ha, int hb, int hc, int step){
	if (hc == 5){
		mins = min(mins, step);
		return;
	}
	int t;
	if (ha > 0){
		t = a[ha];
		a[ha] = 0;
		if (b[hb] > t || hb == 0){
			hb++;
			b[hb] = t;
			dfs(ha-1, hb+1, hc, step+1);
			b[hb] = 0;
		}
		if (c[hc] > t || hc == 0){
			hc++;
			c[hc] = t;
			dfs(ha-1, hb, hc+1, step+1);
			c[hc] = 0;
		}
		a[ha] = t;
	}
	if (hb > 0){
		t = b[hb];
		b[hb] = 0;
		if (a[ha] > t || ha == 0){
			ha++;
			a[ha] = t;
			dfs(ha+1, hb-1, hc, step+1);
			a[ha] = 0;
		}
		if (c[hc] > t || hc == 0){
			hc++;
			c[hc] = t;
			dfs(ha, hb-1, hc+1, step+1);
			c[hc] = 0;
		}
		b[hb] = t;
	}
	if (hc > 0){
		t = c[hc];
		c[hc] = 0;
		if (b[hb] > t || hb == 0){
			hb++;
			b[hb] = t;
			dfs(ha, hb+1, hc-1, step+1);
			b[hb] = 0;
		}
		if (a[ha] > t || ha == 0){
			ha++;
			a[ha] = t;
			dfs(ha+1, hb, hc-1, step+1);
			a[ha] = 0;
		}
		c[hc] = t;
	}
}

int main(){
	dfs(5, 0, 0, 0);
	cout << mins << endl;
	return 0;
}