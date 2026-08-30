#include <iostream>
#include <algorithm>
using namespace std;

//         2   3   5   7   0
long long dp[20][35][25][20][15][2][2][2];
long long rev(long long x){
	long long re = 0;
	while (x > 0){
		re = re * 10 + (x % 10);
		x /= 10;
	}
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	long long n, k;
	cin >> n >> k;
	int len = 0;
	long long t = n;
	while (t > 0){
		t /= 10;
		len++;
	}
	n = rev(n);
	for (int d = 0; d <= n % 10; d++){
		switch (d){
		    //            2  3  5  7  0
			case 0: dp[1][0][0][0][0][0][(d == n % 10)][1] = 1; break;
			case 1: dp[1][0][0][0][0][0][(d == n % 10)][0] = 1; break;
			case 2: dp[1][1][0][0][0][0][(d == n % 10)][0] = 1; break;
			case 3: dp[1][0][1][0][0][0][(d == n % 10)][0] = 1; break;
			case 4: dp[1][2][0][0][0][0][(d == n % 10)][0] = 1; break;
			case 5: dp[1][0][0][1][0][0][(d == n % 10)][0] = 1; break;
			case 6: dp[1][1][1][0][0][0][(d == n % 10)][0] = 1; break;
			case 7: dp[1][0][0][0][1][0][(d == n % 10)][0] = 1; break;
			case 8: dp[1][3][0][0][0][0][(d == n % 10)][0] = 1; break;
			case 9: dp[1][0][2][0][0][0][(d == n % 10)][0] = 1; break;
		}
	}
	n /= 10;
	for (int i = 1; i < len; i++){
		int now = n % 10;
		long long prd = 1;
		for (long long p0 = 0, prd0 = prd; p0 <= 1; p0++, prd *= 0){
			if (prd > k){
				prd = prd0;
				break;
			}
			for (long long p2 = 0, prd2 = prd; p2 <= 30; p2++, prd *= 2){
				if (prd > k){
					prd = prd2;
					break;
				}
				for (long long p3 = 0, prd3 = prd; p3 <= 19; p3++, prd *= 3){
					if (prd > k){
						prd = prd3;
						break;
					}
					for (long long p5 = 0, prd5 = prd; p5 <= 13; p5++, prd *= 5){
						if (prd > k){
							prd = prd5;
							break;
						}
						for (long long p7 = 0, prd7 = prd; p7 <= 11; p7++, prd *= 7){
							if (prd > k){
								prd = prd7;
								break;
							}
							for (int d = 0; d <= 9; d++){
								if (prd * d > k) break;
								switch (d){
								    case 0: dp[i+1][p2][p3][p5][p7][1][0][0] += dp[i][p2][p3][p5][p7][p0][0][0]; break;
								    case 1: dp[i+1][p2][p3][p5][p7][p0][0][0] += dp[i][p2][p3][p5][p7][p0][0][0]; break;
								    case 2: dp[i+1][p2+1][p3][p5][p7][p0][0][0] += dp[i][p2][p3][p5][p7][p0][0][0]; break;
								    case 3: dp[i+1][p2][p3+1][p5][p7][p0][0][0] += dp[i][p2][p3][p5][p7][p0][0][0]; break;
								    case 4: dp[i+1][p2+2][p3][p5][p7][p0][0][0] += dp[i][p2][p3][p5][p7][p0][0][0]; break;
								    case 5: dp[i+1][p2][p3][p5+1][p7][p0][0][0] += dp[i][p2][p3][p5][p7][p0][0][0]; break;
								    case 6: dp[i+1][p2+1][p3+1][p5][p7][p0][0][0] += dp[i][p2][p3][p5][p7][p0][0][0]; break;
								    case 7: dp[i+1][p2][p3][p5][p7+1][p0][0][0] += dp[i][p2][p3][p5][p7][p0][0][0]; break;
								    case 8: dp[i+1][p2+3][p3][p5][p7][p0][0][0] += dp[i][p2][p3][p5][p7][p0][0][0]; break;
								    case 9: dp[i+1][p2][p3+2][p5][p7][p0][0][0] += dp[i][p2][p3][p5][p7][p0][0][0]; break;
								}
								if (d <= now){
									switch (d){
									    case 0: dp[i+1][p2][p3][p5][p7][1][(d==now)][0] += dp[i][p2][p3][p5][p7][p0][1][0]; break;
									    case 1: dp[i+1][p2][p3][p5][p7][p0][(d==now)][0] += dp[i][p2][p3][p5][p7][p0][1][0]; break;
									    case 2: dp[i+1][p2+1][p3][p5][p7][p0][(d==now)][0] += dp[i][p2][p3][p5][p7][p0][1][0]; break;
									    case 3: dp[i+1][p2][p3+1][p5][p7][p0][(d==now)][0] += dp[i][p2][p3][p5][p7][p0][1][0]; break;
									    case 4: dp[i+1][p2+2][p3][p5][p7][p0][(d==now)][0] += dp[i][p2][p3][p5][p7][p0][1][0]; break;
									    case 5: dp[i+1][p2][p3][p5+1][p7][p0][(d==now)][0] += dp[i][p2][p3][p5][p7][p0][1][0]; break;
									    case 6: dp[i+1][p2+1][p3+1][p5][p7][p0][(d==now)][0] += dp[i][p2][p3][p5][p7][p0][1][0]; break;
									    case 7: dp[i+1][p2][p3][p5][p7+1][p0][(d==now)][0] += dp[i][p2][p3][p5][p7][p0][1][0]; break;
									    case 8: dp[i+1][p2+3][p3][p5][p7][p0][(d==now)][0] += dp[i][p2][p3][p5][p7][p0][1][0]; break;
									    case 9: dp[i+1][p2][p3+2][p5][p7][p0][(d==now)][0] += dp[i][p2][p3][p5][p7][p0][1][0]; break;
									}
								}
								if (p0 == 0 && p2 == 0 && p3 == 0 && p5 == 0 && p7 == 0){
									// lead
									switch (d){
										case 0: dp[i+1][0][0][0][0][0][0][1] += dp[i][0][0][0][0][0][0][1]; break;
										case 1: dp[i+1][0][0][0][0][0][0][0] += dp[i][0][0][0][0][0][0][1]; break;
										case 2: dp[i+1][1][0][0][0][0][0][0] += dp[i][0][0][0][0][0][0][1]; break;
										case 3: dp[i+1][0][1][0][0][0][0][0] += dp[i][0][0][0][0][0][0][1]; break;
										case 4: dp[i+1][2][0][0][0][0][0][0] += dp[i][0][0][0][0][0][0][1]; break;
										case 5: dp[i+1][0][0][1][0][0][0][0] += dp[i][0][0][0][0][0][0][1]; break;
										case 6: dp[i+1][1][1][0][0][0][0][0] += dp[i][0][0][0][0][0][0][1]; break;
										case 7: dp[i+1][0][0][0][1][0][0][0] += dp[i][0][0][0][0][0][0][1]; break;
										case 8: dp[i+1][3][0][0][0][0][0][0] += dp[i][0][0][0][0][0][0][1]; break;
										case 9: dp[i+1][0][2][0][0][0][0][0] += dp[i][0][0][0][0][0][0][1]; break;
									}
								}
							}
						}
					}
				}
			}
		}
//		long long ans = 0;
//		prd = 1;
//		for (long long p0 = 0, prd0 = prd; p0 <= 1; p0++, prd *= 0){
//			if (prd > k){
//				prd = prd0;
//				break;
//			}
//			for (long long p2 = 0, prd2 = prd; p2 <= 30; p2++, prd *= 2){
//				if (prd > k){
//					prd = prd2;
//					break;
//				}
//				for (long long p3 = 0, prd3 = prd; p3 <= 19; p3++, prd *= 3){
//					if (prd > k){
//						prd = prd3;
//						break;
//					}
//					for (long long p5 = 0, prd5 = prd; p5 <= 13; p5++, prd *= 5){
//						if (prd > k){
//							prd = prd5;
//							break;
//						}
//						for (long long p7 = 0, prd7 = prd; p7 <= 11; p7++, prd *= 7){
//							if (prd > k){
//								prd = prd7;
//								break;
//							}
//	//						if (dp[len][p2][p3][p5][p7][p0][0][0] + dp[len][p2][p3][p5][p7][p0][1][0] > 0) cout << p2 << ',' << p3 << ',' << p5 << ',' << p7 << ',' << p0 << ':' << dp[len][p2][p3][p5][p7][p0][0][0] << ',' << dp[len][p2][p3][p5][p7][p0][1][0] << '\n';
//							ans += dp[i][p2][p3][p5][p7][p0][0][0] + dp[i][p2][p3][p5][p7][p0][1][0];
//						}
//					}
//				}
//			}
//		}
//		cout << ans << '\n';
		n /= 10;
	}
	long long ans = 0;
	long long prd = 1;
	for (long long p0 = 0, prd0 = prd; p0 <= 1; p0++, prd *= 0){
		if (prd > k){
			prd = prd0;
			break;
		}
		for (long long p2 = 0, prd2 = prd; p2 <= 30; p2++, prd *= 2){
			if (prd > k){
				prd = prd2;
				break;
			}
			for (long long p3 = 0, prd3 = prd; p3 <= 19; p3++, prd *= 3){
				if (prd > k){
					prd = prd3;
					break;
				}
				for (long long p5 = 0, prd5 = prd; p5 <= 13; p5++, prd *= 5){
					if (prd > k){
						prd = prd5;
						break;
					}
					for (long long p7 = 0, prd7 = prd; p7 <= 11; p7++, prd *= 7){
						if (prd > k){
							prd = prd7;
							break;
						}
//						if (dp[len][p2][p3][p5][p7][p0][0][0] + dp[len][p2][p3][p5][p7][p0][1][0] > 0) cout << p2 << ',' << p3 << ',' << p5 << ',' << p7 << ',' << p0 << ':' << dp[len][p2][p3][p5][p7][p0][0][0] << ',' << dp[len][p2][p3][p5][p7][p0][1][0] << '\n';
						ans += dp[len][p2][p3][p5][p7][p0][0][0] + dp[len][p2][p3][p5][p7][p0][1][0];
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

