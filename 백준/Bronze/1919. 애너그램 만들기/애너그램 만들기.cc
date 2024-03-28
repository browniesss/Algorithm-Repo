#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

#define N 26

int main(int argc, char**argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> v1(N);
	vector<int> v2(N);
	string str1, str2;
	int res=0;
	
	cin >> str1 >> str2;
	
	for(int i=0; i<str1.size(); i++)
		v1[str1.at(i)-'a']++;
	
	for(int i=0; i<str2.size(); i++)
		v2[str2.at(i)-'a']++;
	
	
	for(int i=0; i<N; i++)
		res+=abs(v1[i]-v2[i]);
		

	cout << res;
	 
	return 0;
}