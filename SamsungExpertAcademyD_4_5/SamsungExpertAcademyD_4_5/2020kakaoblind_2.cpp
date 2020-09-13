#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int ctrlX(int dir, int curPosX, int curPosY, vector<vector<int>> board)
{
	if (dir == 1)//오른쪽
	{
		for (int j = curPosX; j < 4; j++)
		{
			if (board[curPosY][j] != 0)
			{
				return j;
			}
			if (j == 3 && board[curPosY][j] == 0)
			{
				return j; //마지막칸
			}
		}
	}
	if (dir == -1)//왼쪽
	{
		for (int j = curPosX; j >= 0; j--)
		{
			if (board[curPosY][j] != 0)
			{
				return j;
			}
			if (j == 0 && board[curPosY][j] == 0)
			{
				return j; //마지막칸
			}
		}
	}
}
int ctrlY(int dir, int curPosX, int curPosY, vector<vector<int>> board)
{
	if (dir == 1)//아래
	{
		for (int i = curPosY; i < 4; i++)
		{
			if (board[i][curPosX] != 0)
			{
				return i;
			}
			if (i == 3 && board[i][curPosX] == 0)
			{
				return i; //마지막칸
			}
		}
	}
	if (dir == -1)//위
	{
		for (int i = curPosX; i >= 0; i--)
		{
			if (board[i][curPosX] != 0)
			{
				return i;
			}
			if (i == 0 && board[i][curPosX] == 0)
			{
				return i; //마지막칸
			}
		}
	}
}
int solution(vector<vector<int>> board, int r, int c) {
	int answer = 0;
	int sero = r;
	int garo = c;
	int largestNum = 0;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			if (largestNum < board[i][j])
			{
				largestNum = board[i][j];
			}
		}
	}
	cout << largestNum << endl;
	//for (int i = 0; i < largestNum; i++)
	//{

	int cardNum = board[sero][garo];
	//while (board[sero][garo] != cardNum || (sero == r && garo == c))
	//{
	queue<pair<pair<int, int>, int> > q;
	priority_queue<int>pq;

	int length = 0;
	q.push(make_pair(make_pair(garo, sero), length)); //x, y
	cout << "length" << length << endl;
	while (!q.empty())
	{

		garo = q.front().first.first;//x
		sero = q.front().first.second;//y
		//cout << "X : " << ctrlX(1, garo, sero, board);
		//cout << "X : " << ctrlX(-1, garo, sero, board);


		int nX[8] = { 1, -1, 0, 0,ctrlX(1, garo, sero, board), ctrlX(-1, garo, sero, board), 0, 0 };//j
		int nY[8] = { 0, 0, 1, -1,0, 0, ctrlY(1, garo, sero, board), ctrlY(-1, garo, sero, board) };//i 오 왼 아래 위

		for (int k = 0; k < 8; k++)
		{
			int nextX = nX[k] + garo;
			int nextY = nY[k] + sero;
			int curlength = q.front().second;

			//cout << "X : " << nextX << endl;
			//cout << "Y : " << nextY << endl;
			//Sleep(1000);
			if (nextX >= 4 || nextX < 0 || nextY >= 4 || nextY < 0)
			{
				//cout << 1 << endl;
				//Sleep(1000);

				continue;
			}
			else if (board[nextY][nextX] == 0)
			{
				//cout << 2 << endl;

				//garo = nextX;
				//sero = nextY;

				//cout << "length1 " << curlength << endl;
				curlength++;

				//Sleep(1000);
				//q.pop();
				//continue;
			}
			else if (board[nextY][nextX] == cardNum)
			{
				cout << 3 << endl;

				//cout << "length2 " << curlength << endl;
				q.push(make_pair(make_pair(nextX, nextY), curlength));

				pq.push(curlength);
				//q.pop();
				//curlength = 0;
				//Sleep(1000);

				//goto DIR;
			}
			else if (board[nextY][nextX] != 0 && board[nextY][nextX] != cardNum)
			{
				curlength++;

				//q.push(make_pair(make_pair(nextX, nextY), curlength));
			}

		}
		q.pop();
		//cout <<"se:" <<q.front().second << endl;
	}
	//DIR:
	answer += pq.top();
	cout << "asw : " << answer << endl;

	//	}

	//}
	//if (board[sero][garo] != 0)//존재하면
	//{

	//}
	//else {

	//}


	return answer;
}
void printArr(vector<vector<int>> board)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{

	vector<vector<int>> board;
	for (int i = 0; i < 4; i++)
	{
		vector<int >v;
		for (int j = 0; j < 4; j++)
		{
			int input;
			cin >> input;
			v.push_back(input);
		}
		board.push_back(v);
	}
	cout << "aw ; " << solution(board, 1, 0);
	//printArr(board);
}



/*
1 0 0 3
2 0 0 0
0 0 0 2
3 0 1 0
*/