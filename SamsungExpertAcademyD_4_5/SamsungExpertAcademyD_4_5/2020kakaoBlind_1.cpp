
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
	string answer = "";

	for (int i = 0; i < new_id.length(); i++)
	{
		if (new_id[i] >= 'A' &&new_id[i] <= 'Z')
		{
			int idnum = new_id[i];
			idnum += 32;
			char new_id2 = idnum;
			new_id[i] = new_id2;
		}
	}

	for (int i = 0; i < new_id.length(); i++)
	{
		int idnum = new_id[i];
		if ((idnum >= 97 && idnum <= 122) || (idnum >= 48 && idnum <= 57)
			|| (idnum == 45) || (idnum == 95) || (idnum == 46))
		{
			;
		}
		else {
			new_id.erase(i, 1);
			i--;
		}
	}
	bool isExist = false;
	for (int i = 0; i < new_id.length(); i++)
	{
		int idnum = new_id[i];
		if (idnum == 46)
		{
			if (!isExist)
			{
				isExist = true;
			}
			else {
				new_id.erase(i, 1);
				i--;
			}
		}
		else {
			isExist = false;
		}
	}
	for (int i = 0; i < new_id.length(); i++)
	{
		int idnum = new_id[i];
		if (idnum == 46 && i == 0) {
			new_id.erase(i, 1);
		}
	}
	for (int i = 0; i < new_id.length(); i++)
	{
		int idnum = new_id[i];

		if (idnum == 46 && i == new_id.length() - 1) {
			new_id.erase(i, 1);
		}
	}

	if (new_id.empty())
	{
		new_id = "a";
	}
	if (new_id.length() >= 16)
	{
		new_id.erase(15);
		char id = new_id[new_id.length() - 1];
		if (id == '.')
		{
			new_id.erase(new_id.length() - 1, 1);
		}
	}
	if (new_id.length() <= 2)
	{
		char id = new_id[new_id.length() - 1];//마지막 문자
		while (new_id.length() < 3)
		{
			new_id += id;
		}
	}
	answer = new_id;

	return answer;
}
int main()
{
	cout << solution("...!@BaT#*..y.abcdefghijklm") << endl;
	cout << solution("z-+.^.") << endl;

	cout << solution("=.=") << endl;

	cout << solution("123_.def") << endl;

	cout << solution(".abcdefghijklmn.p") << endl;

	//solution("...!@BaT#*..y.abcdefghijklm");
}