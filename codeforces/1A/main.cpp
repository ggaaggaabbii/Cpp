#include <iostream>
#include <fstream>

using namespace std;

int main(){
	long long n, m, a;
	long long s = 0;
	cin >> n;
	cin >> m;
	cin >> a;
	s = (n / a) * (m / a);
	if (n % a != 0)
		s += m / a;
	if (m % a != 0)
		s += n / a;
	if (n % a != 0 && m % a != 0)
		++s;
	cout << s << "\n";
	return 0;
}