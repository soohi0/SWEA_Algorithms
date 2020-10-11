#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	//1과 2를 활용해서 n을 만드는 방법을 생각해보자
	//인터넷 검색해보니 다들 DP로 풀었다. (다이나믹 프로그래밍)
	//그 이유는 n=1 일 때 1가지
	//n=2 일 때 2가지
	//n = 3일 때 3가지
	//n=4 일 때 5가지.. 해서 피보나치처럼 구성하고있다
	vector<int> dp;

	dp.push_back(1);
	dp.push_back(2);

	for (int i = 2; i < n; i++)
	{
		//printf("%d %d\n", (dp[i - 1]), ( dp[i - 2]) );

		dp.push_back((dp[i - 1] + dp[i - 2]) % 10007);
	}
	printf("%d", dp[n - 1]);

}