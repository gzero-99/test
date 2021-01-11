//������ [���� ] #2293 ����1 c++ ��
#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001]; // ���������� �ϸ� 0���� �⺻ �ʱ�ȭ �Ǿ�����.

int main() {
	int n, k;
	cin >> n >> k;
	int coin[101];
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	sort(coin, coin + n ); // ���� ũ������� ����

	if (k == 1) {
		cout << 1;
	}
	else {
		dp[0] = 1; // �⺻ 1
 
		for (int i = 0; i < n; i++) {
			for (int j = coin[i]; j <= k; j++) {
				dp[j] += dp[j - coin[i]]; // �ٸ� �׼��� �������� �ٲܼ������Ƿ� ����
			}
		}
		cout << dp[k];
	}
	return 0;
}

//������ [���� ] #2293 ����1 c++ ��
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
	sort(coin, coin + n + 1); // ���� ũ������� ����

	if (k == 1) {
		cout << 1;
	}
	else {
		int  cnt = 1;
		for (int i = 1; i <= k; i++) { //k�� ����
			for (int j = 1; j < n; j++) { //1�� ���� ���� .
				if (coin[j] > i) { //���� \���� ũ�� Ż��
					break;
				}
				if (i % coin[j] == 0) {//����γ� ���������� +1���ֱ�
					cout << i << "���� " << coin[j] << "�� ���� " << cnt + 1 << ":cnt�� ��" << endl;
					cnt++;
				} //�ٵ� �̰Ÿ� �ϸ� ..5�� ������ �� �ٸ� ������ 2���� ���� ��밡���Ѱ�찡 ���ȵ� .. dp������δٽû����ϱ�
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
	sort(coin, coin + n+1); // ���� ũ������� ����

	if (k == 1) {
		cout << 1; 
	}
	else {
		int dp[10001];
		dp[0] = 1;
		dp[1] = 1;
		
		for (int i = 1; i <= n; i++) {
			for (int j = coin[i]; j <= k; j++) {
				dp[j] += dp[j - coin[i]]; // �ٸ� �׼��� �������� �ٲܼ������Ƿ� ����
			}
		}
		cout << dp[k];
		
		for (int i = 1; i <= n; i++) {//1 ->2->5
			for (int j = 1; j <= k; j++) {//1 ~ 10  / 1 <= 1 / 2 <= 1, 2 / 5 <= 1~5  
				if (j-coin[i] >=0) {
					dp[j] = dp[j] + dp[j - coin[i]];
					cout << coin[i] << "�����϶� , " << dp[j] << " : dp[j]" << endl;
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
		for (int i = 1; i <= k; i++) { //k�� ���� 
			for (int j = 1; j < n; j++) { //1�� ���� ���� .
				if (coin[j] > i) { //���� \���� ũ�� Ż��
					break;
				}
				if (i % coin[j] == 0) {//����γ� ���������� +1���ֱ�
					cout << i << "���� " << coin[j] << "�� ���� " << cnt + 1 << ":cnt�� ��" << endl;
					cnt++;
				}
			}
		}
		cout << cnt;
		
	}
	
	return 0;
}
*/