#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;

multiset<int> st;
vector<pair<string, int> > v;
/** Credit xena */
int main()
{
	// ios::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n--)
	{
		string s;
		int a;
		cin >> s;
		if (s[0] == 'i')
		{
			cin >> a;
			st.insert(a);
		}
		if (s[0] == 'r')
		{
			if (st.empty())
				v.push_back({"insert", -INF});
			else
				st.erase(st.begin());
		}
		if (s[0] == 'g')
		{
			cin >> a;
			while (st.size() && *st.begin() < a)
			{
				v.push_back({"removeMin", 0});
				st.erase(st.begin());
			}
			if (st.empty() || *st.begin() > a)
			{
				v.push_back({"insert", a});
				st.insert(a);
			}
		}
		v.push_back({s, a});
	}
	cout << v.size() << "\n";
	for (auto x:v)
	{
		cout << x.first;
		if (x.first[0] != 'r')
			cout << " " << x.second;
		cout << "\n";
	}
	return 0;
}
