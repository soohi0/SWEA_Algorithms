#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//������ �̿��ؼ� Ǯ���� ��..������ Ȯ���� �ؾ��ϴ� �ð��ʰ��� �߻��ߴ�.
//greedy�� �̿��ؼ� sort�� ���� ������ �ϰ� dp�̿��ߴµ� �ƴ�
int main()
{
	int inputNum;
	scanf("%d", &inputNum);
	vector<int> arr(inputNum);

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < inputNum; i++) {
		int num;
		scanf("%d", &num);
		arr[i] = num;
	}
	sort(arr.begin(), arr.end());

	vector<int> dp;
	dp.push_back(arr[0]);
	//dp.push_back(arr2[1] + arr2[0]);
	int sum = 0;
	for (int i = 1; i < inputNum; i++)
	{
		dp.push_back(dp[i - 1] + arr[i]);
	}


	for (int i = 0; i < dp.size(); i++)
	{
		sum += dp[i];
	}
	//printf("\n%d\n", sum);
	pq.push(sum);
	////3 1 4 3 2

	//������ �̿��� ����
	//do {

	//	for (int i = 0; i < inputNum; i++) {
	//		arr2[i] = arr[i];
	//	}
	//	/*for (int i = 0; i < inputNum; i++) {
	//		printf("%d ", arr2[i]);
	//	}*/
	//	

	//} while (next_permutation(arr.begin(), arr.end()));

	printf("%d", pq.top());
}