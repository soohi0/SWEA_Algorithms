#include <stdio.h>
int main(void)
{
	int test_case;
	int T;

	// freopen("input.txt", "r", stdin);
	
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int probNum = 0;
		scanf("%d", &probNum);
		for (int i = 0; i < probNum; i++)
		{
			int score;
			scanf("%d", &score);



		}
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}