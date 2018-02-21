#include <bits/stdc++.h>

using namespace std;

int n, v[5], x, s;

int main(){
	
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> x;
		++v[x];
	}
	s += v[4];//4 must go alone
	s += v[2] / 2;//group 2 with 2
	v[2] -= v[2] / 2 * 2;
	//group 1 wiht 3
	if (v[3] >= v[1])
		s += v[3], v[3] = v[1] = 0;
	else
		s += v[3], v[1] -= v[3];
	//group 2 with 1
	if (2 * v[2] >= v[1])
		s += v[2], v[1] = 0;
	else if (v[2])
		s += v[2], v[1] -= 2;
	s += v[1] / 4;
	if (v[1] % 4 != 0)
		s += 1;
	cout << s << "\n";
	return 0;
}