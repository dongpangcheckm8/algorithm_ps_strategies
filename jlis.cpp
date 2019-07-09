#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int A[101], B[101];
int dp[101][101];

int JLIS(int prev, int curA, int curB){
	int& ret = dp[curA][curB];
	if(ret != -1) return ret;
	ret = 1;
	for(int nextA = curA; nextA < n; nextA++){
		if(prev < A[nextA]) ret = max(ret, 1 + JLIS(A[nextA], nextA + 1, curB));
	}
	for(int nextB = curB; nextB < m; nextB++){
		if(prev < B[nextB]) ret = max(ret, 1 + JLIS(B[nextB], curA, nextB + 1));
	}
	return ret;
}

int main(void){
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++){
		cin >> n >> m;
		for(int i = 0; i < n; i++) cin >> A[i];
		for(int i = 0; i < m; i++) cin >> B[i];
		memset(dp, -1, sizeof(dp));
		int res = 1;
		for(int i = 0; i < n; i++) res = max(res, JLIS(A[i], i + 1, 0));
		for(int i = 0; i < m; i++) res = max(res, JLIS(B[i], 0, i + 1));
		cout << res << endl;
	}
	return 0;
}
