// #5. 울타리 잘라내기 (FENCE)
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20001;
int n;

int calc(vector <int>& fences, int left, int right) {
	// if there is one fence left, return its height
	if (left == right) return fences[left];
	int mid = (left + right) / 2;
	int res = max(calc(fences, left, mid), calc(fences, mid + 1, right));
	int low = mid, high = mid + 1;
	int hgt = min(fences[low], fences[high]);
	res = max(res, hgt * 2);
	while (left < low || high < right) {
		// stretch to more higher side
		if (high < right && (low == left || fences[low - 1] < fences[high + 1])) {
			high++;
			hgt = min(hgt, fences[high]);
		}
		else {
			low--;
			hgt = min(hgt, fences[low]);
		}
		res = max(res, hgt * (high - low + 1));
	}
	return res;
}

int main(void) {
	int t;
	scanf("%d\n", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d\n", &n);
		vector <int> fences(n, 0);
		for (int i = 0; i < n; i++) {
			scanf("%d\n", &fences[i]);
		}
		printf("%d\n", calc(fences, 0, n - 1));
	}
	return 0;
}
