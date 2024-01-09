#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp1(pair<int, double> a, pair<int, double> b) {
	return a.first > b.first;
}

bool comp2(pair<int, double> a, pair<int, double> b) {
	return a.second < b.second;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<pair<int, int>> ss;
	int sum = 0;
	for (int i = 1; i <= 8; i++)
	{
		int value;
		cin >> value;
		
		ss.push_back(make_pair(value, i));
	}

	sort(ss.begin(), ss.end(), comp1);
	ss.resize(5);
	sort(ss.begin(), ss.end(), comp2);
	for (int i = 0; i < 5; i++)
	{
		sum += ss[i].first;
	}

	cout << sum << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << ss[i].second << " ";
	}
}