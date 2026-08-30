#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

int guide[maxn];
bool g[maxn];

int main(){
	int G, P;
	std::cin >> G >> P;
	for(int i = 1; i <= G; ++i) guide[i] = i;
	for(int i = 1; i <= P; ++i){
		int gi;
		std::cin >> gi;
		if(guide[gi] == 0){
			std::cout << i - 1;
			return 0;
		}
		for(int j = gi; j >= guide[gi]; --j)
			guide[j] = guide[guide[gi] - 1];	
	}
	std::cout << P;
}
