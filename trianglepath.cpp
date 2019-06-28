// #7. 삼각형 위의 최대 경로 (TRIANGLE PATH)
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 101;
int n;
int triangle[MAX][MAX];
int cache[MAX][MAX];

int getPath(int y, int x) {
	// return base case
	if (y == n - 1) return triangle[y][x];

	int& ret = cache[y][x];
	if (ret != -1) return ret;
	return ret = max(getPath(y + 1, x), getPath(y + 1, x + 1)) + triangle[y][x];
}

int main(void) {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				cin >> triangle[i][j];
			}
		}
		cout << getPath(0, 0) << endl;
	}
	return 0;
}
