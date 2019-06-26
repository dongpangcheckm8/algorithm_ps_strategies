// #6. 외발 뛰기 (JUMP GAME)
#include <stdio.h>

const int MAX = 101;
int n;
int map[MAX][MAX];
int cache[MAX][MAX];

int solve(int y, int x) {
	// return base case
	if (y >= n || x >= n) return 0;
	if (y == n - 1 && x == n - 1) return 1;
	
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	int dis = map[y][x];
	return ret = (solve(y, x + dis) || solve(y + dis, x));
}

int main(void) {
	int t;
	scanf("%d\n", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
				cache[i][j] = -1;
			}
		}
		int res = solve(0, 0);
		if (res) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
