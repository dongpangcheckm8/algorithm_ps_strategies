// #4. 쿼드 트리 뒤집기 (QUAD TREE)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string str;

void input(void) {
	cin >> str;
}

// reverse quad tree without decompressing
string reverse(string::iterator & it) {
	char head = *it;
	it++;
	if (head == 'b' || head == 'w') return string(1, head);
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(void) {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		str.clear();
		input();
		string::iterator base_it = str.begin();
		cout << reverse(base_it) << endl;
	}
	return 0;
}
