#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
#define MAXN 52
#define INF 60000

using namespace std;

FILE *f = fopen("lanterna.in","r");
FILE *g = fopen("lanterna.out", "w");

struct Entry {
    int d, n, r;
    bool operator <(const Entry& e) const
    {
        return d > e.d;
    }
};

vector <pair<int, pair<int, int> > > G[MAXN];
int friendly[MAXN], m, k, n;
int dp[MAXN][1010];
priority_queue <Entry> H;

#define DIM 100000
char buff[DIM];
int poz=0;
 
void citeste(int &numar){
     numar = 0;    
     while (buff[poz] < '0' || buff[poz] > '9')     
          if (++poz == DIM) 
               fread(buff,1,DIM,f),poz=0;        
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM) 
               fread(buff,1,DIM,f),poz=0;               
     }     
}

void readData(){
	int x, y, c, wat;
	citeste(n);
	citeste(k);
	for (int i = 1; i <= n; ++i)
		citeste(friendly[i]);
	citeste(m);
	while (m--){
		citeste(x);
		citeste(y);
		citeste(c);
		citeste(wat);
		G[x].push_back(make_pair(y, make_pair(c, wat)));
		G[y].push_back(make_pair(x, make_pair(c, wat)));
	}
}

int getMinDistForGivenW(int w){
	int node, dist, remain, remain2;
	Entry top;

	memset(dp, 0x3f3f3f3f, sizeof(dp));

	dp[1][w] = 0;
	H.push({0, 1, w});

	while (!H.empty()){
		top = H.top();
		H.pop();
		dist = top.d;
		node = top.n;
		remain = top.r;

		if (friendly[node] == 1)
			remain2 = w;
		else
			remain2 = remain;

		for (auto it:G[node]){
			if (it.second.second > remain2)
				continue;

			int ind = remain2 - it.second.second;

			if (dp[it.first][ind] > dp[node][remain] + it.second.first){
				dp[it.first][ind] = dp[node][remain] + it.second.first;
				H.push({dp[it.first][ind], it.first, ind});
			}
		}
	}
	int Min = INF;
	for (int i = 0; i <= w; ++i){
		Min = min(Min, dp[n][i]);
	}

	return Min;
}

int main(){
	int low, high, mid, minDist, last = k;

	readData();
	minDist = getMinDistForGivenW(k);

	low = -1;
	high = k;

	while (high - low >= 0){
		mid = (high + low) / 2;
		//cout << high << " " << low <<" "<< mid;
		if (getMinDistForGivenW(mid) == minDist)
			high = mid - 1;
		else
			low = mid + 1;
	}

	fprintf(g, "%d %d\n", minDist, high + 1);

	return 0;
}