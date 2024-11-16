struct node{
	int64 id, maxe, t;
	friend operator < (const node x, const node y){
		return x.t < y.t;
	}
} bus[1005][1005];
int64 idt[1005][1005];
void init(int L, int N, int64[] T, int[] W, int X, int M, int[] S){
	for (int i = 0; i < N; i++){
		bus[0][i] = {i, T[i], T[i]};
		idt[0][i] = T[i];
	}
	sort(bus[0], bus[0] + N);
	for (int i = 0; i < N; i++){
		bus[0][i].maxe = max(bus[0][i].maxe, bus[0][i-1].maxe);
	}
	for (int i = 1; i <= M; i++){
		for (int j = 0; j < N; j++){
			int id = bus[i-1][j].id;
			bus[i][j].id = id;
			bus[i][j].maxe = idt[i-1][id] + W[id] * (S[i] - s[i-1]);
		}
	}
}