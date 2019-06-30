// #8. 최대 증가 부분 수열 (LIS)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 501;
int n;
int S[MAX];
int cache[MAX];

int getLis(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (S[start] < S[next]) {
			ret = max(ret, getLis(next) + 1);
		}
	}
	return ret;
}

int main(void) {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++) {
			cin >> S[i];
		}
		int maxLen = 0;
		for (int i = 0; i < n; i++){
			maxLen = max(maxLen, getLis(i));
		}
		cout << maxLen << endl;
	}
	return 0;
}
