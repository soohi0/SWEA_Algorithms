/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
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
//		//격자판을 탐색한다
//		//처음부터 시작해서 7개를 이어붙여 만들 수 있는 숫자의 경우의수 ~ 16개까지 모두
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
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
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