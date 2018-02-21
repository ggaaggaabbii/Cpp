#include <bits/stdc++.h>

using namespace std;

int n, k;

void query(int l, int r){
	cout << "1 " << l << " " << r << "\n";
	fflush(stdout);
}

int findForRange(int l, int r){
	int pos1, pos2, mid;
	string response;
	do{
		pos2 = pos1 = (l + r) / 2;
		if (pos1 + 1 <= r)
			++pos2;
		query(pos1, pos2);
		cin >> response;
		mid = (l + r) / 2;
		if (response == "TAK")
			r = mid;
		else
			l = mid;

	}while (r - l > 1);
	query(l, r);
	cin >> response;
	if (response == "TAK")
		return l;
	return r;
}

int main(){
	string response;
	cin >> n >> k;
	int initialPos = findForRange(1, n);
	int secondPos = initialPos, tirdPos = initialPos;
	if (initialPos != 1){
		secondPos = findForRange(1, initialPos - 1);
		//cout << "2 " << initialPos << " " << secondPos << "\n";
	}
	if (initialPos != n){
		tirdPos = findForRange(initialPos + 1, n);
		//cout << "2 " << initialPos << " " << tirdPos << "\n";
	}
	query(secondPos, initialPos);
	cin >> response;
	if (response == "TAK" && initialPos != secondPos)
		cout << "2 " << initialPos << " " << secondPos << "\n";
	else
		cout << "2 " << initialPos << " " << tirdPos << "\n";
	return 0;
}