#pragma warning (disable:4996)

// #2. 게임판 덮기 (BOARDCOVER)
#include <stdio.h>
#include <vector>
using namespace std;

int h, w, res, whites, max_count;
vector<vector<int>> map(22, vector<int>(22, 0));
const int coverType[4][3][2] = {
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
};

void input(void) {
	scanf("%d %d", &h, &w);
	char in;
	whites = 0;
	for (int i = 0; i < h; i++) {
		map.push_back(vector<int>());
		for (int j = 0; j < w; j++) {
			scanf(" %c", &in);
			if (in == '.') whites++;
			if (in == '.') map.at(i).push_back(0);
			else map.at(i).push_back(1);
		}
	}
	max_count = whites / 3;
}

// 'cover' or 'remove' blocks
// if delta is 1, it will cover block on map
// if delta is -1, it will remove block from map
// it will return 'false' when constraints were violated
bool set(vector<vector<int>>& map, int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= map.size() || nx < 0 || nx >= map[0].size()) ok = false;
		else if ((map[ny][nx] += delta) > 1) ok = false;
	}
	return ok;
}

// return all cases
// map[i][j] = 1 means it is 'alredy coverd' or '#'
// map[i][j] = 0 means it is 'not yet coverd', so you can cover block on map
int cover(vector<vector<int>>& map) {
	// find spot to start covering block on map
	int y = -1, x = -1;
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	// if full map is filled with blocks, return 1
	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		// if you can cover block, it goes recursive
		if (set(map, y, x, type, 1)) ret += cover(map);
		// remove block
		set(map, y, x, type, -1);
	}
	return ret;
}

int main(void) {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		map.clear();
		input();
		if (whites % 3) printf("0\n");
		else {
			printf("%d\n", cover(map));
		}
	}
}