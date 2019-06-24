#pragma warning (disable:4996)

// #3. 시계 맞추기 (CLOCK SYNC)
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int SWITCHES = 10, CLOCKS = 16, INF = 9999;
// shows linked information between switches and clocks
// x : linked
// . : not linked
const char link[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};
vector<int> clocks;

// check whether every clock are pointing upperside or not
bool isFinished(const vector<int>& clocks) {
	for (int i = 0; i < CLOCKS; i++) {
		if (clocks[i] != 12) {
			return false;
		}
	}
	return true;
}

// press specific switch to rotate clocks
void pressButton(vector <int>& clocks, int switchnum) {
	for (int clock = 0; clock < CLOCKS; clock++) {
		if (link[switchnum][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}

void input(void) {
	int time;
	for (int i = 0; i < CLOCKS; i++) {
		scanf("%d", &time);
		clocks.push_back(time);
	}
}

int calc(vector <int>& clocks, int switchnum) {
	// if you pressed all swithes, check whether it is finished
	if (switchnum == SWITCHES) return isFinished(clocks) ? 0 : INF;
	int ret = INF;
	// if you press same button for 4 times, it would be rotated 360
	// so, you don't need to press swtich more than 3 times
	for (int i = 0; i < 4; i++) {
		ret = min(ret, i + calc(clocks, switchnum + 1));
		pressButton(clocks, switchnum);
	}
	return ret;
}

int main(void) {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		clocks.clear();
		input();
		int res = calc(clocks, 0);
		if (res == INF) {
			printf("%d\n", -1);
		}
		else printf("%d\n", res);
	}
}