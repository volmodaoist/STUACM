#include  "bits/stdc++.h"
using namespace std;
typedef long long LL;


//四舍五入
int getRound(double x) {
	return int(x + 0.5);
}


int main() {
	#ifdef _OJ_ONLINE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif

	#ifndef _OJ_ONLINE
	std::ios::sync_with_stdio(false);
	#endif
	
	string s, ss;
	cin >> s;
	LL ans = 0;
	for (int i = 0;i < s.size();i++) {
		ans += (s[i] - '0');
	}
	ss = to_string(ans);
	for (int i = 0;i < ss.size()-1;i++) {
		switch (ss[i]) {
			case '1':cout << "yi" << " ";break;
			case '2':cout << "er" << " ";break;
			case '3':cout << "san" << " ";break;
			case '4':cout << "si" << " ";break;
			case '5':cout << "wu" << " ";break;
			case '6':cout << "liu" << " ";break;
			case '7':cout << "qi" << " ";break;
			case '8':cout << "ba" << " ";break;
			case '9':cout << "jiu" << " ";break;
			case '0':cout << "ling" << " ";break;
		}
	}
	switch (ss[ss.size() - 1]) {
		case '1':cout << "yi" ;break;
		case '2':cout << "er" ;break;
		case '3':cout << "san";break;
		case '4':cout << "si" ;break;
		case '5':cout << "wu" ;break;
		case '6':cout << "liu";break;
		case '7':cout << "qi" ;break;
		case '8':cout << "ba" ;break;
		case '9':cout << "jiu";break;
		case '0':cout << "ling";break;
	}
	return 0;
}