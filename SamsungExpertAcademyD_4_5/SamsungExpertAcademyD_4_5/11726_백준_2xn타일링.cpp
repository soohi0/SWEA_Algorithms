#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	//1�� 2�� Ȱ���ؼ� n�� ����� ����� �����غ���
	//���ͳ� �˻��غ��� �ٵ� DP�� Ǯ����. (���̳��� ���α׷���)
	//�� ������ n=1 �� �� 1����
	//n=2 �� �� 2����
	//n = 3�� �� 3����
	//n=4 �� �� 5����.. �ؼ� �Ǻ���ġó�� �����ϰ��ִ�
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