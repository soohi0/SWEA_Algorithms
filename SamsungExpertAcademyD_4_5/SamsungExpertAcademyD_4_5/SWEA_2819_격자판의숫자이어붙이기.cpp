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
//#include <Windows.h>
//#include<iostream>
//#include <stdio.h>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <set>
//
//using namespace std;
//void DFS(vector<vector<string>> v, int i, int j, int dept, string str);
//void printV(vector < vector<string>> v);
//struct Dir {
//	int x;
//	int y;
//};
//Dir moveDir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
//set<string> vs;
//
//int main(int argc, char** argv)
//{
//	int test_case;
//	int T;
//	vector<vector <string> > cross;
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		//vs = new vector<string>;
//		vs.clear();
//		//�������� Ž���Ѵ�
//		//ó������ �����ؼ� 7���� �̾�ٿ� ���� �� �ִ� ������ ����Ǽ� ~ 16������ ���
//		for (int i = 0; i < 4; i++)
//		{
//			vector<string> v;
//			for (int j = 0; j < 4; j++)
//			{
//				string iput;
//				cin >> iput;
//				v.push_back(iput);
//			}
//			cross.push_back(v);
//		}//input
//		//printV(cross);
//		for (int i = 0; i < 4; i++)
//		{
//			for (int j = 0; j < 4; j++)
//			{
//				string s = cross[i][j];
//				DFS(cross, i, j, 1, s);
//				//vs.push_back(s);
//				cout << "=====================" << endl;
//				//Sleep(1000);
//
//			}
//		}
//		//sort(vs.begin(), vs.end());
//		//vs.erase(unique(vs.begin(), vs.end()), vs.end());
//
//		/*for (int i = 0; i < vs.size(); i++)
//		{
//			cout <<"vs : " <<vs. << endl;
//		}*/
//		cout << "#" << test_case<<" "<<  vs.size();
//
//		Sleep(10000);
//	}
//	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
//}
//void DFS(vector<vector<string>> v, int i ,int j, int dept, string str)
//{
//	//cout << "dept : " << dept << endl;
//
//	int nextX;
//	int nextY;
//	
//	for (int l = 0; l < 4; l++)
//	{
//		if (dept == 7)
//		{
//			vs.insert(str);
//			//cout << "string : " << str;
//			//str = "";
//			return;
//		}
//		
//		nextY = i + moveDir[l].y;
//		nextX = j + moveDir[l].x;
//		if (nextX > 3 || nextX < 0 || nextY > 3 || nextY < 0)
//		{
//			continue;
//		}
//		else {
//			dept++;
//			str += v[nextY][nextX];
//			DFS(v, nextY, nextX, dept, str);
//		}
//
//	}
//	
//	
//}
//void printV(vector < vector<string>> v)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			cout << v[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
/*
1
1 1 1 1
1 1 1 2
1 1 2 1
1 1 1 1

//*/

#include <string>
#include <math.h>
#include <iostream>
#include <set>
using namespace std;

int num = 0;
int arr[4][4];
set<int> setary;
void dfs(int x, int y, int val, int dept) {
	int nx[4] = { 0, 0, -1, 1 };
	int ny[4] = { -1, 1, 0, 0 };
	for (int i = 0; i < 4; i++) {
		if (dept == 7) {
			setary.insert(val);
			return;
		}
		int dx = x + nx[i];
		int dy = y + ny[i];

		if (dx < 0 || dx >= 4 || dy < 0 || dy >= 4) continue;
		else {
			dfs(dx, dy, val * 10 + arr[dy][dx], dept + 1);
		}
	}
}
int main()
{
	cin >> num;
	for (int i = 1; i <= num; i++) {
		setary.clear();
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> arr[j][k];
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				dfs(j, k, arr[j][k], 1);
			}
		}
		cout << "#" << i << " " << setary.size() << endl;
		//Sleep(10000);
	}
}