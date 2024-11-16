#include <iostream>
using namespace std;

struct node{
	long long x, y;
} tmp[50005];
int main(){
	freopen("area.in", "r", stdin);
	freopen("area.out", "w", stdout); 
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> tmp[i].x >> tmp[i].y;
	tmp[0] = {0, 0};
	tmp[n+1] = {1000000000, 1000000000};
	int maxxid = 0, maxx2id = 0, minxid = n+1, minx2id = n+1, maxyid = 0, maxy2id = 0, minyid = n+1, miny2id = n+1;
	for (int i = 1; i <= n; i++){
		if (tmp[i].x > tmp[maxxid].x){
			maxx2id = maxxid;
			maxxid = i;
		} else if (tmp[i].x > tmp[maxx2id].x){
			maxx2id = i;
		}
		if (tmp[i].x < tmp[minxid].x){
			minx2id = minxid;
			minxid = i;
		} else if (tmp[i].x < tmp[minx2id].x){
			minx2id = i;
		}
		
		if (tmp[i].y > tmp[maxyid].y){
			maxy2id = maxyid;
			maxyid = i;
		} else if (tmp[i].y > tmp[maxy2id].y){
			maxy2id = i;
		}
		if (tmp[i].y < tmp[minyid].y){
			miny2id = minyid;
			minyid = i;
		} else if (tmp[i].y < tmp[miny2id].y){
			miny2id = i;
		}
	}
	long long ans = 1e18;
	// ɾ maxx
	if (maxxid == maxyid)
		ans = min(ans, (tmp[maxx2id].x - tmp[minxid].x) * (tmp[maxy2id].y - tmp[minyid].y));
	else if (maxxid == minyid)
		ans = min(ans, (tmp[maxx2id].x - tmp[minxid].x) * (tmp[maxyid].y - tmp[miny2id].y));
	else
		ans = min(ans, (tmp[maxx2id].x - tmp[minxid].x) * (tmp[maxyid].y - tmp[minyid].y));
	// ɾ minx
	if (minxid == maxyid)
		ans = min(ans, (tmp[maxxid].x - tmp[minx2id].x) * (tmp[maxy2id].y - tmp[minyid].y));
	else if (minxid == minyid)
		ans = min(ans, (tmp[maxxid].x - tmp[minx2id].x) * (tmp[maxyid].y - tmp[miny2id].y));
	else
		ans = min(ans, (tmp[maxxid].x - tmp[minx2id].x) * (tmp[maxyid].y - tmp[minyid].y));
	// ɾ maxy
	if (maxxid == maxyid)
		ans = min(ans, (tmp[maxx2id].x - tmp[minxid].x) * (tmp[maxy2id].y - tmp[minyid].y));
	else if (minxid == maxyid)
		ans = min(ans, (tmp[maxxid].x - tmp[minx2id].x) * (tmp[maxy2id].y - tmp[minyid].y));
	else
		ans = min(ans, (tmp[maxxid].x - tmp[minxid].x) * (tmp[maxy2id].y - tmp[minyid].y)); 
	// ɾ miny
	if (maxxid == minyid)
		ans = min(ans, (tmp[maxx2id].x - tmp[minxid].x) * (tmp[maxyid].y - tmp[miny2id].y));
	else if (minxid == minyid)
		ans = min(ans, (tmp[maxxid].x - tmp[minx2id].x) * (tmp[maxyid].y - tmp[miny2id].y));
	else
		ans = min(ans, (tmp[maxxid].x - tmp[minxid].x) * (tmp[maxyid].y - tmp[miny2id].y)); 
	cout << ans << endl;
	return 0;
}
