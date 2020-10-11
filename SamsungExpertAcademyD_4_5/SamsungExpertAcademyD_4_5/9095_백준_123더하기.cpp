#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

//int main()
//{
//	int T;
//	scanf("%d", &T);
//
//	
//
//	for (int i = 0; i < T; i++)
//	{
//		vector<int> dp;
//		dp.push_back(1);
//		dp.push_back(2);
//		dp.push_back(4);
//
//		int num;
//		scanf("%d", &num);
//
//		for (int j = 3; j < num; j++)
//		{
//			dp.push_back(dp[j - 3] + dp[j - 2] + dp[j - 1]);
//			//printf("\ndp : %d\n", dp[j - 3] + dp[j - 2] + dp[j - 1]);
//		}
//
//		printf("%d", dp[dp.size() - 1]);
//	}
//}
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
	int T;
	int n;
	int dp[11];

	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 4; j <= n; j++)
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		cout << dp[n] << '\n';
	}
	return 0;
}