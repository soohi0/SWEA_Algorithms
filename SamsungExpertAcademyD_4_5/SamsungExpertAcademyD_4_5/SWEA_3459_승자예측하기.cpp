#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
long long num;
//long long ���� �����ϴ� ���� �����ؾ��Ѵ�.
int checknum = 0;
void check() {
	checknum = 0;
	long long temp = 1;
	long long sum = 1;

	while (sum < num) {
		if (!checknum) {
			temp *= 4;
		}
		sum += temp;
		checknum = !checknum;
	}

}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);
	//cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%llu", &num);
		//cin >> num;
		check();

		printf("#%d %s\n", test_case, checknum ? "Alice" : "Bob");
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}