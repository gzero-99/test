//장지영 [백준 ] #2293 동전1 c++ ♥
#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001]; // 전역변수로 하면 0으로 기본 초기화 되어있음.

int main() {
	int n, k;
	cin >> n >> k;
	int coin[101];
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	sort(coin, coin + n ); // 동전 크기순으로 나열

	if (k == 1) {
		cout << 1;
	}
	else {
		dp[0] = 1; // 기본 1
 
		for (int i = 0; i < n; i++) {
			for (int j = coin[i]; j <= k; j++) {
				dp[j] += dp[j - coin[i]]; // 다른 액수의 동전으로 바꿀수있으므로 빼줌
			}
		}
		cout << dp[k];
	}
	return 0;
}

//장지영 [백준 ] #2293 동전1 c++ ♡
/*
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int coin[101];
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}
	sort(coin, coin + n + 1); // 동전 크기순으로 나열

	if (k == 1) {
		cout << 1;
	}
	else {
		int  cnt = 1;
		for (int i = 1; i <= k; i++) { //k원 까지
			for (int j = 1; j < n; j++) { //1원 동전 빼고 .
				if (coin[j] > i) { //현재 \보다 크면 탈출
					break;
				}
				if (i % coin[j] == 0) {//배수인놈 만날때마다 +1해주기
					cout << i << "원이 " << coin[j] << "을 만나 " << cnt + 1 << ":cnt값 됨" << endl;
					cnt++;
				} //근데 이거만 하면 ..5원 만나고 또 다른 동전인 2원도 같이 사용가능한경우가 계산안됨 .. dp방식으로다시생각하기
			}
		}
		cout << cnt;
	}

	return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int coin[101];
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}
	sort(coin, coin + n+1); // 동전 크기순으로 나열

	if (k == 1) {
		cout << 1; 
	}
	else {
		int dp[10001];
		dp[0] = 1;
		dp[1] = 1;
		
		for (int i = 1; i <= n; i++) {
			for (int j = coin[i]; j <= k; j++) {
				dp[j] += dp[j - coin[i]]; // 다른 액수의 동전으로 바꿀수있으므로 빼줌
			}
		}
		cout << dp[k];
		
		for (int i = 1; i <= n; i++) {//1 ->2->5
			for (int j = 1; j <= k; j++) {//1 ~ 10  / 1 <= 1 / 2 <= 1, 2 / 5 <= 1~5  
				if (j-coin[i] >=0) {
					dp[j] = dp[j] + dp[j - coin[i]];
					cout << coin[i] << "동전일때 , " << dp[j] << " : dp[j]" << endl;
				}
			}
		}
		cout << dp[k];
		
		for (int i = 2; i <= n; i++) { // 2 -> 5
			for (int j = coin[i]; j             <= k; j++) { //  2~5(2) / 5~10 (5)
				if (j > coin[i]) {
					dp[j] = dp[j] + dp[j - coin[i]];
				}
			}
		}

		int  cnt = 1;
		for (int i = 1; i <= k; i++) { //k원 까지 
			for (int j = 1; j < n; j++) { //1원 동전 빼고 .
				if (coin[j] > i) { //현재 \보다 크면 탈출
					break;
				}
				if (i % coin[j] == 0) {//배수인놈 만날때마다 +1해주기
					cout << i << "원이 " << coin[j] << "을 만나 " << cnt + 1 << ":cnt값 됨" << endl;
					cnt++;
				}
			}
		}
		cout << cnt;
		
	}
	
	return 0;
}
*/