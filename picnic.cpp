#pragma warning (disable:4996)

// 6.3 ��ǳ (PICNIC)
#include <stdio.h>

int n, m;
bool arr[10][10];
bool taken[10];

void input(void) {
	int a, b;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		arr[a][b] = true;
		arr[b][a] = true;
	}
}

void init(void) {
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			arr[i][j] = false;
		}
	}
	for (int i = 0; i <= 9; i++) {
		taken[i] = false;
	}
}

int calc(void) {
	int idx = -1;
	// ���� ¦�� ���� �л� �� ���� ���� ��ȣ : idx
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			idx = i;
			break;
		}
	}
	// ��� ¦�� ���������� �� +1
	if (idx == -1) return 1;
	int ret = 0;
	for (int i = idx + 1; i < n; i++) {
		if (!taken[i] && arr[idx][i]) {
			taken[i] = taken[idx] = true;
			ret += calc();
			taken[i] = taken[idx] = false;
		}
	}
	return ret;
}

int main(void) {

	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		init();
		input();
		printf("%d\n", calc());
	}

}