//[SW] 10966. 물놀이를 가자, c++, ♥
//조수희
//두개의 벡터를 만들어서 풀었음
//탐색하는 부분은 함수로 만들었으면 코드 길이가 더 줄을수 있을거 같음

/*
#include <stdio.h>
#include <string.h>
#include <vector>
#define MIN(a,b) a<b?a:b
using namespace std;

char map[4000][4000];
int arr[2000][2000];
int visit[2000][2000];
int N, M;

//출력확인용 함수

void printArr() {
printf("\n");
for (int i = 0; i < N; i++) {
for (int j = 0; j < M; j++)
printf("%d ", arr[i][j]);
printf("\n");
}
printf("\n");
}


int main() {
	int T, sum;
	//두개의 벡터
	vector<pair<int, int>> v1;
	vector<pair<int, int>> v2;

	scanf("%d", &T);

	//T개의 테스트케이스
	for (int test_case = 1; test_case <= T; test_case++) {
		//0으로 초기화하기
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		sum = 0;

		scanf("%d %d", &N, &M);

		//지도 입력받기
		//L이면 큰수를, M이면 벡터에 삽입+방문기록
		for (int i = 0; i < N; i++) {
			scanf("%s", map[i]);
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 'L') arr[i][j] = 2000;
				else {
					v1.push_back(make_pair(i, j));
					visit[i][j] = 1;
				}
			}
		}
		
		//num : 이동거리
		//cnt : 방문한 지역 개수
		//v : 벡터 구분
		
		int num = 1;
		int cnt = 0, v = 1;
		//방문한 지역의 개수가 전체
		while (cnt != N * M) {
			//v가 1이면 v1벡터 사용
			if (v == 1) {
				cnt += v1.size();
				//if (cnt == N * M) break;
				//저장한 좌표만큼만 반복문
				for (int i = 0; i < v1.size(); i++) {
					int x = v1[i].first;
					int y = v1[i].second;

					//좌표에서 상하좌우로+방문하지 않은곳만
					if (x + 1 < N && !visit[x + 1][y]) {
						//적은 이동거리 저장
						arr[x + 1][y] = MIN(num, arr[x + 1][y]);
						//v2벡터에 새로운 이동좌표 저장
						v2.push_back(make_pair(x + 1, y));
						//방문기록하기
						visit[x + 1][y] = 1;
					}
					if (x - 1 >= 0 && !visit[x - 1][y]) {
						arr[x - 1][y] = MIN(num, arr[x - 1][y]);
						v2.push_back(make_pair(x - 1, y));
						visit[x - 1][y] = 1;
					}
					if (y + 1 < M && !visit[x][y + 1]) {
						arr[x][y + 1] = MIN(num, arr[x][y + 1]);
						v2.push_back(make_pair(x, y + 1));
						visit[x][y + 1] = 1;
					}
					if (y - 1 >= 0 && !visit[x][y - 1]) {
						arr[x][y - 1] = MIN(num, arr[x][y - 1]);
						v2.push_back(make_pair(x, y - 1));
						visit[x][y - 1] = 1;
					}
				}
				//모든 좌표를 사용하고 v1벡터 초기화하기
				v1.clear();
				num++;
				v = 0;
			}
			else {
				//v가 0이면 실행
				//이하 내용 같음
				cnt += v2.size();
				//if (cnt == N * M) break;
				for (int i = 0; i < v2.size(); i++) {
					int x = v2[i].first;
					int y = v2[i].second;

					if (x + 1 < N && !visit[x + 1][y]) {
						arr[x + 1][y] = MIN(num, arr[x + 1][y]);
						v1.push_back(make_pair(x + 1, y));
						visit[x + 1][y] = 1;
					}
					if (x - 1 >= 0 && !visit[x - 1][y]) {
						arr[x - 1][y] = MIN(num, arr[x - 1][y]);
						v1.push_back(make_pair(x - 1, y));
						visit[x - 1][y] = 1;
					}
					if (y + 1 < M && !visit[x][y + 1]) {
						arr[x][y + 1] = MIN(num, arr[x][y + 1]);
						v1.push_back(make_pair(x, y + 1));
						visit[x][y + 1] = 1;
					}
					if (y - 1 >= 0 && !visit[x][y - 1]) {
						arr[x][y - 1] = MIN(num, arr[x][y - 1]);
						v1.push_back(make_pair(x, y - 1));
						visit[x][y - 1] = 1;
					}
				}
				v2.clear();
				num++;
				v = 1;
			}
			printArr();
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				sum += arr[i][j];
		printf("#%d %d\n", test_case, sum);
		v1.clear();
		v2.clear();
	}
	return 0;
}
*/