//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string>
//#include <vector>
//
//using namespace std;
//bool isExist(int n, vector<int> v);
//int main()
//{
//	//입출력속도 향상
//	ios_base::sync_with_stdio(0);
//	//printf("%s", str);
//	vector<int> set;
//	//switch 문은 string 못해서 hashcode 로 하등가 해야하는데 귀찮아서 그냥 if else로 구현
//	int num;
//	scanf("%d", &num);
//	for (int j = 0; j < num; j++)
//	{
//		char strr[100];
//		scanf("%s", strr);
//
//		string str = strr;
//
//		if (str == "add")
//		{
//			int inputNum;
//			scanf("%d", &inputNum);
//
//			set.push_back(inputNum);
//		}
//		else if (str == "remove")
//		{
//			int inputNum;
//			scanf("%d", &inputNum);
//
//			
//			if (isExist(inputNum, set))
//			{
//				int removeidx = -1;
//				for (int i = 0; i < set.size(); i++)
//				{
//					if (set[i] == inputNum)
//					{
//						removeidx = i;
//					}
//				}
//				for (int i = removeidx; i < set.size()-1; i++)
//				{
//					set[i] = set[i + 1];
//				}
//				int size = set.size();
//				set.resize(size - 1);
//			}
//		}
//		else if (str == "check")
//		{
//			int inputNum;
//			scanf("%d", &inputNum);
//			if (isExist(inputNum, set))
//			{
//				printf("%d", 1);
//			}
//			else {
//				printf("%d", 0);
//			}
//		}
//		else if (str == "toggle")
//		{
//			int inputNum;
//			scanf("%d", &inputNum);
//
//			int removeidx = -1;
//			if (isExist(inputNum, set))
//			{
//				for (int i = 0; i < set.size(); i++)
//				{
//					if (set[i] == inputNum)
//					{
//						removeidx = i;
//					}
//				}
//				for (int i = removeidx; i < set.size()-1; i++)
//				{
//					set[i] = set[i + 1];
//				}
//				set.resize(set.size() - 1);
//			}
//			else {
//				set.push_back(inputNum);
//			}
//		}
//		else if (str == "all")
//		{
//			set.clear();
//			vector <int >().swap(set);
//
//			for (int i = 0; i < 20; i++)
//			{
//				set.push_back(i + 1);
//			}
//		}
//		else if (str == "empty")
//		{
//			set.clear();
//			vector <int >().swap(set);
//		}
//		for (int i = 0; i < set.size(); i++)
//		{
//			printf("%d ", set[i]);
//		}
//		printf("\n");
//	}
//	
//}
//bool isExist(int n, vector<int> v)
//{
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i] == n)
//		{
//			return true;
//		}
//	}
//	return false;
//}
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int M;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> M;

	vector<bool> idx(21, false);

	string method;
	int a;

	for (int i = 0; i < M; i++) {
		cin >> method;
		if (method == "add") {
			cin >> a;
			idx[a] = true;
		}
		else if (method == "remove") {
			cin >> a;
			idx[a] = false;
		}
		else if (method == "check") {
			cin >> a;
			if (idx[a])
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (method == "toggle") {
			cin >> a;
			if (idx[a])
				idx[a] = false;
			else
				idx[a] = true;
		}
		else if (method == "all") {
			for (int j = 1; j <= 20; j++)
				idx[j] = true;
		}
		else if (method == "empty") {
			for (int j = 1; j <= 20; j++)
				idx[j] = false;
		}
	}

	return 0;
}
