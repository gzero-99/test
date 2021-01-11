/*
// 장지영 [sw] 물놀이 c++ ♡ [ 실패 ]
// 이거는 그 w까지의 최소 이동횟수를 저장저장해서 
// 그 저장된 값 만났을때 상하좌우에서 만난것들이랑 비교하는 방법 
//-> 으로하려하는데 iterator 문제 발생 
#include <iostream>
#include <vector>
#include <stdbool.h>
#include <string>
#define MIN(a,b) a<b?a:b
#define MAX 1002
using namespace std;

int map[MAX][MAX];
//bool checked[MAX][MAX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
vector <pair <int, int>> v1;
vector <pair <int, int>> v2;

void lookfor() {
	vector < pair<int, int> >::reverse_iterator r_iter;
	int x, y;
	for (r_iter = v1.rbegin(); r_iter != v1.rend(); r_iter++) {
		x = r_iter->first;
		y = r_iter->second;
		int xx, yy;
		int mxy;
		bool p = false;
		bool p2 = false;
		int c = 0;
		for (int i = 0; i < 4; i++) {
			xx = x + dx[i];
			yy = y + dy[i];

			if (xx < 0 || xx >= n || yy < 0 || yy >= m)continue;

			mxy = map[xx][yy];
			if (mxy == 1003) {
				map[x][y] = 1;
				v1.pop_back();
				break;
			}
			else if (mxy == 0) {
				p2 = true;
			}
			else if (mxy > 0 && mxy < 1003) {
				if (c == 1) //다른 방향에서도 숫자가 있었으면.
					map[x][y] = MIN(mxy + 1, map[x][y]);
				else {
					map[x][y] = mxy + 1;
					c += 1;
					p = true;
				}
			}

			if (i == 3 && p == true) {
				v1.pop_back();
				break;
			}
			if (i == 3 && p2 == true) {
				v1.pop_back();
				v2.push_back(make_pair(x, y));
			}
		}
	}
}
void  lookfor2() {
	vector < pair<int, int> >::reverse_iterator r_iter;
	int x, y;
	for (r_iter = v2.rbegin(); r_iter != v2.rend(); r_iter++) {
		x = r_iter->first;
		y = r_iter->second;
		int xx, yy;
		int mxy;
		bool p = false;
		bool p2 = false;
		int c = 0;
		for (int i = 0; i < 4; i++) {
			xx = x + dx[i];
			yy = y + dy[i];

			if (xx < 0 || xx >= n || yy < 0 || yy >= m)continue;

			mxy = map[xx][yy];
			if (mxy == 1003) {
				map[x][y] = 1;
				v2.pop_back();
				break;
			}
			else if (mxy == 0) {
				p2 = true;
			}
			else if (mxy > 0 && mxy < 1003) {
				if (c == 1) //다른 방향에서도 숫자가 있었으면.
					map[x][y] = MIN(mxy + 1, map[x][y]);
				else {
					map[x][y] = mxy + 1;
					c += 1;
					p = true;
				}
			}

			if (i == 3 && p == true) {
				v2.pop_back();
				break;
			}
			if (i == 3 && p2 == true) {
				v2.pop_back();
				v1.push_back(make_pair(x, y));
			}
		}
	}
}
int main() {
	int TC;
	string str;
	int sum = 0;

	cin >> TC;
	for (int t = 1; t <= TC; t++) {

		cin >> n >> m;

		//0으로 초기화하기 <string.h>
		//memset(arr, 0, sizeof(arr));
		//memset(visit, 0, sizeof(visit));

		for (int i = 0; i < n; i++) {
			cin >> str;
			for (int j = 0; j < m; j++) {
				if (str[j] == 'L') {
					map[i][j] = 0;
					v1.push_back(make_pair(i, j));
				}
				else if (str[j] == 'W')
					map[i][j] = 1003;
			}
		}
		//확인차 출력
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}

		while (!(v1.empty() && v2.empty())) {
			lookfor();
			lookfor2();
			
			
			if (!v1.empty()) {
				lookfor();
				if(!v2.empty())
					lookfor2();
			}
			else if (v1.empty()) {
				lookfor2();
			}
			else if (v2.empty()) {
				lookfor();
				if (!v2.empty())
					lookfor2();
			}
			
			
		}


			//결과 출력
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (map[i][j] != 1003)
						sum += map[i][j];

			cout << "#" << t << " " << sum << endl;
		
	}
	return 0;
}
*/