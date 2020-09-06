/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<queue>
#include<algorithm>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;
#define INF 2147483647;
int d[100][100];
void dajikstra(vector<string> graph, int n);


int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/

	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				d[i][j] = INF;
			}
		}
		int n;
		cin >> n;
		/*int ** arr = new int *[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}*/
		vector<string> vs;
		for (int i = 0; i < n; i++)
		{
			string str = "";
			cin >> str;
			vs.push_back(str);
		}

		dajikstra(vs, n);

		cout << "#" << test_case << " " << d[n - 1][n - 1] << endl;
 	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
void dajikstra(vector<string> graph, int n)
{
	int ny[4] = { 0, 0, -1, 1 };
	int nx[4] = { 1, -1, 0, 0 };

	//graph[0][0] = 0;

	priority_queue<pair< pair<int, int>, int> > pq;
	pq.push(make_pair(make_pair(0,0), 0));

	while (!pq.empty())
	{
		pair<int, int> current = pq.top().first;
		int distance = pq.top().second;

		pq.pop();
		if (d[current.second][current.first] < distance) continue;
		for (int i = 0; i < 4; i++)
		{
			int nextX = nx[i] + current.first;
			int nextY = ny[i] + current.second;

			if (nextX > n-1 || nextX < 0 || nextY > n-1 || nextY < 0)
			{
				continue;
			}
			else {
				char ch = graph[nextY][nextX];
				int gnum = ch - '0';
				int nextDistance = distance + gnum;

				if (nextDistance < d[nextY][nextX])
				{
					d[nextY][nextX] = nextDistance;
					pq.push(make_pair(make_pair(nextX, nextY), nextDistance));
				}
			}
			
		}

	}
	/*for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << d[i][j] << " ";
		}
		cout << endl;
	}*/

	
}
/*
2
4
0 1 0 0
1 1 1 0
1 0 1 1
1 0 1 0
6
0 1 1 0 0 1
0 1 0 1 0 0
0 1 0 0 1 1
1 0 1 0 0 1
0 1 0 1 0 1
1 1 1 0 1 0
*/