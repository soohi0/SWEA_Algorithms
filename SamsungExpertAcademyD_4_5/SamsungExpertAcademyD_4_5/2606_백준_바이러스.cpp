#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int main()
{
	int computer;
	scanf("%d", &computer);
	//printf("%d", computer);

	int web;
	scanf("%d", &web);
	//printf("%d", web);
	int** graph = new int *[computer + 1];
	for (int i = 0; i < computer + 1; i++)
	{
		graph[i] = new int[computer + 1];
		memset(graph[i], 0, sizeof(int)*(computer+1));

	}
	for(int i = 1; i < web + 1; i++)
	{
		int first;
		int second;

		scanf("%d %d", &first, &second);

		graph[first][second] = 1;
		graph[second][first] = 1;
		
	}
	//바이러스걸리면 그대로 1
	int * birus = new int[computer + 1];
	memset(birus, 0, sizeof(int)*(computer + 1));
	queue<int> q;
	graph[1][1] = 1;
	if (graph[1][1] == 1)
	{
		q.push(1);
	}
	while (!q.empty())
	{
		//q에 입력된 수와 연결된 컴퓨터를 큐에 넣고 연결된 컴퓨터를 바이러스 배열 안에 표시한다.
		int num = q.front();	
		//printf("%d\n", num);
		for (int i = 1; i < computer + 1; i++)
		{
			if (graph[num][i] == 1)
			{
				if (birus[i] != 1)
				{
					q.push(i);
					birus[i] = 1;
				}
			}
		}
		q.pop();
	}
	int count = 0;
	for (int i = 0; i < computer + 1; i++)
	{
		if (birus[i] == 1)
		{
			count++;
		}
	}

	printf("%d", count - 1);

	//print
	//for (int i = 0; i < computer + 1; i++)
	//{
	//	for (int j = 0; j < computer + 1; j++)
	//	{
	//		printf("%d ", graph[i][j]);
	//	}
	//	printf("\n");
	//}
}