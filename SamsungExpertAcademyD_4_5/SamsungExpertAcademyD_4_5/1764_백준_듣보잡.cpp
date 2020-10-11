#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> v;
	vector<string> result;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end());

	int cnt = 0;

	for (int i = 0; i < m; ++i)
	{
		string s;
		cin >> s;
		if (binary_search(v.begin(), v.end(), s)) {
			result.push_back(s);
			cnt++;
		}

	}
	cout << cnt << '\n';
	sort(result.begin(), result.end());
	for (string s : result)
		cout << s << '\n';

	return 0;
}