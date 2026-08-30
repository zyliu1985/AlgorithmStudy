#include <bits/stdc++.h>

int day [10];

int main() {
	int n;
	std::cin >> n;

	for(int i =1; i<= n; ++i) {
		for(int j = 1; j <= 5; ++j) {
			char c;
			std::cin >> c;
			if(c == 'Y')
				day[j]++;
		}
	}


	int ans = 1;
	for(int i = 2; i <= 5; ++i)
		if(day[i] >= day[ans])
			ans = i;

	int cnt = 0;
	for(int i = 1; i <= 5; ++i) {
		if(day[i] == day[ans]) {
			if(cnt >= 1)
				std::cout << ",";
			std::cout << i;
			cnt++;
		}
	}
}
