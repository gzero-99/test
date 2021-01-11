/*
#include <iostream>
#include <vector>
#include <stdbool.h>
#include <string>
#define MIN(a,b) a<b?a:b
#define MAX 1002
using namespace std;

int map[MAX][MAX];
bool checked[MAX][MAX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
vector <pair <int, int>> v;
vector <pair<int, int>> land;
int cnt;

void lookforw(int x, int y) {
	int xx, yy;
	int mxy;
	bool p = false;
	int c = 0;
	for (int i = 0; i < 4; i++) {
		xx = x + dx[i];
		yy = y + dy[i];

		if (xx < 0 || xx >= n || yy < 0 || yy >= m)continue;
		if (checked[xx][yy] == 1)continue; //true�̸� ����

		mxy = map[xx][yy];
		if (mxy == 1003) {
			map[x][y] = 1;
			//p = true;
			v.pop_back();
			checked[x][y] = false;
			return;
		}
		else if (mxy == 0) {
			v.push_back(make_pair(xx, yy));
			checked[xx][yy] = true;
			lookforw(xx, yy);
		}
		else if (mxy > 0 && mxy < 1003) {
			if (c == 1) //�ٸ� ���⿡���� ���ڰ� �־�����.
			{
				map[x][y] = MIN(mxy + 1, map[x][y]);
			}
			else {
				map[x][y] = mxy + 1;
				c += 1;
				p = true;
			}

		}

		if (i == 3 && p == true) {
			v.pop_back();
			checked[x][y] = false;
			return;
		}
	}
}
int main() {
	int TC;
	string str;
	int sum=0;

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> str;
			for (int j = 0; j < m; j++) {
				if (str[j] == 'L') {
					map[i][j] = 0;
					land.push_back(make_pair(i, j));
				}
				else if (str[j] == 'W') 
					map[i][j] = 1003;
			}
		}
		//Ȯ���� ���
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}

		vector < pair<int, int> >::iterator iter;
		int x, y;
		for (iter = land.begin(); iter != land.end(); iter++) {
			x = iter->first;
			y = iter->second;
			int xx, yy;
			int mxy;
			bool p = false;
			int c = 0;
			for (int i = 0; i < 4; i++) {
				xx = x + dx[i];
				yy = y + dy[i];

				if (xx < 0 || xx >= n || yy < 0 || yy >= m)continue;
				if (checked[xx][yy] == 1)continue; //true�̸� ����

				mxy = map[xx][yy];
				if (mxy == 1003) {
					map[x][y] = 1;
					//p = true;
					v.pop_back();
					checked[x][y] = false;
					break;
					//return;
				}
				else if (mxy == 0) {
					v.push_back(make_pair(xx, yy));
					checked[xx][yy] = true;
					vector < pair<int, int> >::iterator iter2;
					for (iter2 = v.begin(); iter2 != v.end(); iter2++) {
						x = iter2->first;
						y = iter2->second;
						//??
					}

					break;
				
				}
				else if (mxy > 0 && mxy < 1003) {
					if (c == 1) //�ٸ� ���⿡���� ���ڰ� �־�����.
					{
						map[x][y] = MIN(mxy + 1, map[x][y]);
					}
					else {
						map[x][y] = mxy + 1;
						c += 1;
						p = true;
					}

				}

				if (i == 3 && p == true) {
					v.pop_back();
					checked[x][y] = false;
					break;
				}
			}
		}
		cnt = 0;
		

		//��� ���
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) 
				if (map[i][j] != 1003)
					sum += map[i][j];

		cout << "#" << t << " " << sum << endl;

	}
	return 0;
}
*/

/*
//�ϴ��� 
#include <iostream>
#include <vector>
#include <stdbool.h>
#define MAX 1002
using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int sum = 0; int lmc = 0; //��� �̵�Ƚ���� �� , �ּ��̵�Ƚ�� 
//int cnt = 0;
//vector <pair<pair <int, int>, int>> map; // ��ǥ , �̵�Ƚ��
int map[MAX][MAX];
int move[MAX][MAX];
char str[MAX][MAX]; //W�� L�� ����� 

void lookfor(int x, int y ,int cnt) {
	int xx, yy;
	char mxy;
	for (int i = 0; i < 4; i++) {
		xx = x + dx[i];
		yy = y + dy[i];
		if (xx < 0 || xx >= n || yy < 0 || yy >= m)continue;
		mxy = map[xx][yy];
		cnt += 1;
		if (mxy == 1003) //���� ������ 
		{
			
			break;
		}
		else if (mxy > 0 && mxy < 1003) {//�̹������� ������Ʈ �� ��
			//if()
		}
		//else if ((map.front().first.first==xx)&& (map.front().first.second== yy)) 
	}

}
int main() {
	int TC;

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> n;
		cin >> m;
		for (int i = 0; i < n; i++) {
			cin >> str[i];
			for (int j = 0; j < m; j++) {
				if (str[i][j] == 'L') {
					//map.push_back(make_pair(make_pair(i, j), 0));
					map[i][j] = 0;
				}
				else {
					map[i][j] = 1003;
				}
			}
		}

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (str[i][j] =='L')//���̸� ?
			{
				lmc = 2000;
				
				cout << "LMC: " << lmc << "\n";
				sum += lmc;
			}
		}
	}
	return 0;
}
*/
/*

vector < pair<pair<int, int>, int >>::iterator iter;
for (iter = map.begin(); iter != map.end(); iter++) {


	//a = abs(i - (iter->first));
	//b = abs(j - (iter->second));
	//add = a + b;
	//cout << "a: " << a << " b: " << b << "\n";
	//if (lmc > add) lmc = add;
	//if (lmc == 1)break;

}
*/
//�ù�


/*
// ������ sw #10966 �����̸� ���� c++ [1] ����� �����ϴ� ���ѽð� �ʰ�.=> ��
// w�� ������ ���� vector�� pair�� �����ؼ� L���� ��� w������ �̵�Ƚ������ ���ؼ� �ּҸ� ã�Ƴ���
// �翬�� �����ɸ��� �ǰ� ,,
// ���ѽð� �ʰ� .. �ƹ������� ��� ����, L�� �������� �����¿� �̵��ؼ� Wã�Ƴ��� ��������ؾ��ҵ�
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <stdbool.h>
#define MAX 1002
using namespace std;
vector <pair<int, int>> v;
int sum = 0;//��� �̵�Ƚ���� ��
int lmc = 0;//�ּ��̵�Ƚ��
bool map[MAX][MAX];

int main() {
	int TC;
	int n, m;
	int add;
	char str[MAX];

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		int a, b;
		cin >> n;
		cin >> m;
		//n���� �ٿ� mĭ ���� ���ڿ� �Է¹ޱ�.
		for (int i = 0; i < n; i++) {
			cin >> str;
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) map[i][j] = false;
				if (str[j] == 'W') {
					map[i][j] = true;
					v.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}

		sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != 1)//���̸� ?
				{
					lmc = 2000; 
					vector < pair<int, int> >::iterator iter;
					for (iter = v.begin(); iter != v.end(); iter++) {
						a = abs(i - (iter->first) );
						b = abs(j - (iter->second));
						add = a + b;
						cout << "a: " << a<<" b: " << b << "\n";
						if (lmc > add) lmc = add;
						if (lmc == 1)break;
					}
					cout <<"LMC: "<< lmc << "\n";
					sum += lmc;
				}
			}
		}
		//��� ���
		cout << "#" << t << " " << sum << endl;
		v.clear();

	}
	return 0;
}
*/


//������ sw #10966 �����̸� ���� c++ [2]
//L�� ��ġ�� �������� �����¿� �̵��ؼ� W�� ã�Ƴ��� ( �̵�Ƚ����cnt�����ֱ� )
//BFS �� �ٲ㺸�� - �ʺ�켱 Ž�� ! 
/*
	#include <iostream>
	#include <stdbool.h>
	#include <queue>
	#define MAX 1002
	using namespace std;
	bool map[MAX][MAX];
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	int n, m;
	int sum = 0;//��� �̵�Ƚ���� ��
	int lmc = 0;//�ּ��̵�Ƚ��
	int visit[MAX][MAX];
	queue <pair<int, int>> que;

	int main() {
		int TC;
		char str[1002];
		cin >> TC;
		for (int t = 1; t <= TC; t++) {
			cin >> n;
			cin >> m;
			//n���� �ٿ� mĭ ���� ���ڿ� �Է¹ޱ�.
			for (int i = 0; i < n; i++) {
				cin >> str;
				for (int j = 0; j < m; j++) {
					if (str[j] == 'W') {
						map[i][j] = 1;

					}
				}
			}
			//Ȯ���� ���
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << map[i][j] << " ";
				}
				cout << "\n";
			}
			//���� ���༭ �ּ��̵�Ƚ���� ��� �̵�Ƚ���� ���� ������.
			sum = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (map[i][j] != 1)//���̸� ?
					{//���� ĭ���� �̵��ϱ� ���� �ּ� �̵�Ƚ���� ���Ѵ�.
						lmc = 0;
						//visit[i][j] = lmc;
						que.push(make_pair(i, j));
						cout << "i j ����:" << i<<j << endl;
						{
							bool empty = false;
							while (!que.empty()) {
								if (empty == true) break;
								int x = que.front().first;
								int y = que.front().second;
								cout << "X Y: " << x<<","<<y<< endl;
								que.pop();
								if (visit[x][y] > 0) continue; //�̹� Ž����
								lmc++;
								visit[x][y] = lmc;
								for (int k = 0;k < 4; k++) {
									int xx = i + dx[k];
									int yy = j + dy[k];
									if (xx<0 || xx>=n || yy<0 || yy>=m || visit[xx][yy] > 0)continue;
									cout << "visit xx,yy "<<" "<<xx<<yy<<  endl;
									if (map[xx][yy] == 1)//���� ������ ..
									{
										for (int a = 0; a < n; a++) //visit�迭 �ʱ�ȭ
											for (int b = 0; b < m; b++)
												if (visit[a][b] > 0)
													visit[a][b] = 0;
					
										while (!que.empty()) que.pop(); //ť �ʱ�ȭ
										empty = true;
										break;
									}
									else {
										que.push(make_pair(xx, yy));
									}
								}
							
							}
							cout << "LMC :"<<lmc << endl;

						}

						sum += lmc;
					
					}
				}
			}

			//��� ���
			cout << "#" << t << " " << sum << endl;
		}
		return 0;
	}
*/

/*
#include <iostream>
#include <stdbool.h>
using namespace std;
int map[1002][1002];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int sum = 0;//��� �̵�Ƚ���� ��
int lmc = 0;//�ּ��̵�Ƚ��
bool checked[1002][1002];
void check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (checked[i][j] == true)
				checked[i][j] = false;
		}
	}
}
void move(int x, int y, int cnt) {
	int xx, yy;
	int mxy;
	for (int i = 0; i < 4; i++) {
		xx = x + dx[i];
		yy = y + dy[i];
		if (xx<0 || xx>n - 1 || yy<0 || yy>m - 1) continue;
		if (checked[xx][yy] == true) continue;
		mxy = map[xx][yy];
		checked[xx][yy] = true;
		if (mxy == 1) {
			cout << "������ cnt :" << cnt + 1 << "\n";
			lmc = cnt + 1;
			return;
		}
		if (mxy == 0 )//���� ������ ?
		{
			cout << "������ cnt :"<<cnt+1<<"\n";
			 move(xx, yy, cnt+1); 
		}
	}
	return;
}
int main() {
	int TC;
	char str[1002];
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> n;
		cin >> m;
		//n���� �ٿ� mĭ ���� ���ڿ� �Է¹ޱ�.
		for (int i = 0; i < n; i++) {
			cin >> str;
			for (int j = 0; j < m; j++) {
				if (str[j] == 'L') {
					map[i][j] = 0;
				}
				else if (str[j] == 'W') {
					map[i][j] = 1;
				}
			}
		}
		//Ȯ���� ���
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		//���� ���༭ �ּ��̵�Ƚ���� ��� �̵�Ƚ���� ���� ������.
		sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0)//���̸� ?
				{//���� ĭ���� �̵��ϱ� ���� �ּ� �̵�Ƚ���� ���Ѵ�.
					lmc = 0;
					move(i, j, 0);
					cout << "lmc: " << lmc;
					sum += lmc;
					cout << ", sum: " << sum << endl;
					check();
				}
			}
		}
		
		//��� ���
		cout << "#" << t << " " << sum << endl;
	}
	return 0;
}
*/

/*

// ������ sw #10966 �����̸� ���� c++ [1] ����� �����ϴ� ���ѽð� �ʰ�.
// w�� ������ ���� vector�� pair�� �����ؼ� L���� ��� w������ �̵�Ƚ������ ���ؼ� �ּҸ� ã�Ƴ���
// �翬�� �����ɸ��� �ǰ� ,,
// ���ѽð� �ʰ� .. �ƹ������� ��� ����, L�� �������� �����¿� �̵��ؼ� Wã�Ƴ��� ��������ؾ��ҵ�
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
using namespace std;
vector <pair<int, int>> v;
int sum = 0;//��� �̵�Ƚ���� ��
int lmc = 0;//�ּ��̵�Ƚ��
int map[1002][1002];

int main() {
	int TC;
	int n, m;
	int x, y;
	char str[1002];
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> n;
		cin >> m;
		//n���� �ٿ� mĭ ���� ���ڿ� �Է¹ޱ�.
		for (int i = 0; i < n; i++) {
			cin >> str;
			for (int j = 0; j < m; j++) {
				if (str[j] == 'L') {
					map[i + 1][j + 1] = 0;
				}
				else if (str[j] == 'W') {
					map[i + 1][j + 1] = 1;
					v.push_back(make_pair(i + 1, j + 1));
				}
			}
		}

		//���� ���༭ �ּ��̵�Ƚ���� ��� �̵�Ƚ���� ���� ������.
		sum = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == 0)//���̸� ?
				{//���� ĭ���� �̵��ϱ� ���� �ּ� �̵�Ƚ���� ���Ѵ�.
					lmc = 2000; //���� ���� �̵�
					vector < pair<int, int> >::iterator iter;
					for (iter = v.begin(); iter != v.end(); iter++) {
						// ���� x,y�� ���� �� Ƚ���� �� ! 1�� �߸� for��break;
						// �� �ܴ� ���� �� ���� �� ������ �����صα� .
						x = iter->first;
						y = iter->second;
						x = abs(i - x);
						y = abs(j - y);
						if (lmc > x + y) {
							lmc = x + y;
						}
						if (lmc == 1)break;
					}
					sum += lmc;
				}
				else if (map[i][j] == 1)//���̸�?
					continue;
			}
		}
		//��� ���
		cout << "#" << t << " " << sum << endl;
		v.clear();
	}
	return 0;
}
*/

/*
//Ȯ���� ���
for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= m; j++) {
		cout << map[i][j] << " ";
	}
	cout << "\n";
}
*/
//cout << "a:" <<x<< " b:" << y << ",�̵�: "<<lmc<<endl;

/*
//vector �����̳� Ÿ������ pair �� ����ϴ� ���
vector < pair<int, int> >::iterator iter;
for (iter = v.begin(); iter != v.end(); iter++) {
cout << "(" <<iter->first << "," << iter->second << ")"<<endl;
}
*/

/*
#include <iostream>
#include <string.h>
#include <stdlib.h>
#define MIN(a,b) a<=b?a:b
using namespace std;
int main() {
	int T, N, M;
	char map[1002][1002];
	//int water[1000002][2];
	int water[250000][2]; //100�������� int�� �迭 �ִ�ũ�� �Ұ����ϴ뼭..
	int cnt;
	scanf_s("%d", &T);
	for (int t = 1; t <= T; t++) {
		int move, leastM;
		int sum = 0;
		cnt = 0;
		scanf_s("%d %d", &N, &M);
		for (int i = 1; i <= N; i++) {
			scanf_s("%s", map[i]);
			for (int j = 1; j <= M; j++) {
				//cin >> map[i][j];
				if (map[i][j] == 'W') {
					water[cnt][0] = i;
					water[cnt][1] = j;
					cnt++;
				}
			}
		}
		if (cnt < 1) {
			break;
		}
		int x, y;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] == 'L'){
					leastM = (N + M - 2);
					for (int k = 0; k < cnt-1; k++) {
						x = i - water[k][0];
						y = j - water[k][1];
						move = abs(x + y);
						if (move == 1) {
							leastM = 1;
							break;
						}
						else if(move>1){
							leastM= MIN(move, leastM);
						}
					}
					sum += leastM;
				}
				else { //W�� ��� �׳� �Ѿ��
					continue;
				}
			}
		}

		printf("#%d %d", t, sum);
	}
	return 0;
}
*/




































