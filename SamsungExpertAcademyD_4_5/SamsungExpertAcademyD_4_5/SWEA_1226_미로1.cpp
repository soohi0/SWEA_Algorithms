
#include <Windows.h>
#include<iostream>
#include <vector>
#include <string>
#include <stack>

#define N 16
using namespace std;
bool BFS(int i, int j, vector<string> vs);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int caseNum;
		cin >> caseNum;
		vector<string> vs;

		bool anw = false;
		for (int i = 0; i < 16; i++)
		{
			//for (int j = 0; j < 16; j++)
			//{
				string str = "";
				cin >> str;
				vs.push_back(str);
			//}
		}
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				if (vs[i][j] == '2')
				{
					anw = BFS(i, j, vs);
					Sleep(1000);
					break;
				}
			}
		}
		if (anw) {
			cout << "#" << test_case << " " << "1" << endl;
		}
		else {
			cout << "#" << test_case << " " << "0" << endl;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
bool BFS(int i, int j, vector<string> vs)
{
	stack<pair<int, int>> stk; //(x, y)
	stk.push(make_pair(j, i));

	int ny[4] = { 0, 0, -1, 1 };
	int nx[4] = { 1, -1, 0, 0 };

	int curI;
	int curJ;
	while (!stk.empty())
	{
		curJ = stk.top().first; //X
		curI = stk.top().second; //Y
		cout << "J ; "<<curJ << "I : "<<curI << endl;
		Sleep(1000);
		for (int k = 0; k < 4; k++)
		{
			int nextX = nx[k] + curJ;
			int nextY = ny[k] + curI;

			if (nextX > N - 1 || nextX < 0 || nextY > N - 1 || nextY < 0)
			{
				cout << " 1" << endl;
				continue;
			}
			else if (vs[nextY][nextX] == '1')
			{
				cout << " 2" << endl;

				continue;
			}
			else {
				if (vs[nextY][nextX] == '3')
				{
					cout << " 3" << endl;

					return true;
				}
				if (vs[nextY][nextX] == '0')
				{
					cout << "nextY : " << nextY << "X : " << nextX << endl;
					cout << vs[nextY][nextX] << endl;
					stk.push(make_pair(nextX, nextY));
					stk.pop();
				}
			}

		}
		

	}
	/*if (vs[curI][curJ] != '3') {
		return false;
	}
	else {
		return true;
	}*/
	return false;
}