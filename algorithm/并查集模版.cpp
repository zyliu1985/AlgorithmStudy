#include <iostream>
using namespace std;

int f[10005];
int find(int x){
	if (f[x] == x) return x;
	int y = find(f[x]);
	f[x] = y;
	return y;
}
void merge(int x, int y){
	int zx = find(x);
	int zy = find(y);
	if (zx != zy)
		f[zx] = zy;
}
int main(){
	for (int i = 1; i <= 10000; i++) f[i] = i;
	return 0;
}