#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<long long> v;
long long sum;
int count, val, op, m;

int main()
{
	scanf("%d", &m);

	while (m--){
		scanf("%d", &op);
		if (op == 1)
			scanf("%d", &val), v.push_back(val);
		else{
			while (count < v.size() - 1 && (count == 0 || sum + v.back() > v[count] * (count + 1)))
				sum += v[count++];
			printf("%.10f\n", v.back() - (double)(sum + v.back()) / (count + 1));
		}
	}
	
	return 0;
}