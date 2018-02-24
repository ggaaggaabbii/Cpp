#include <bits/stdc++.h>
#include <cstring>
#define MAXN 100010
#define MAXCHAR 27
#define pb push_back
using namespace std;

char sir[MAXN], solution[MAXN];
int n, k, viz[MAXCHAR], pos[MAXCHAR];
bool solved = false;
vector<char>Chars;
struct trie
{
	char c;
	trie *v[27];
	trie() {
		memset(v, 0, sizeof(v));
	}
}*q;

void add(char *s, trie *q) {

	n = strlen(s);
	for (int i = 0; i < n; ++i) {
		if (!viz[s[i] - 'a']) {
			viz[s[i] - 'a'] = 1;
		}
		trie *node = new trie();
		q->v[s[i] - 'a'] = node;
		q = q->v[s[i] - 'a'];
		q->c = s[i];
	}
}
void show(trie *q) {
	if (q->c)
		printf("%c\n", q->c);
	for (int i = 0; i < MAXCHAR; ++i)
		if (q->v[i])
			show(q->v[i]);
}

void solve(trie *q, int poz) {
	if (poz + 1 > n)
		return;
	//printf("%d\n", poz);
	solve(q->v[sir[poz + 1] - 'a'], poz + 1);

	if (poz == -1)
		return;
	if (pos[q->c - 'a'] == Chars.size() - 1 && !solved) {
		solution[poz] = Chars[0];
	} else if (!solved) {
		solution[poz] = Chars[pos[q->c - 'a'] + 1];
		//printf("%d\n", poz);
		if (poz < k)
			solved = true;
	} else {
		solution[poz] = Chars[pos[q->c - 'a']];
	}

}

int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", sir);
	q = new trie();
	trie *start = q;
	add(sir, q);


	for (int i = 0; i < MAXCHAR; ++i) {
		//printf("%d\n", i);
		if (viz[i]) {
			Chars.pb((char)('a' + i));
			viz[i] = 0;
		}
	}

	for (int i = 0; i < Chars.size(); ++i) {
		pos[Chars[i] - 'a'] = i;
	}

	if (k > n) {
		printf("%s", sir);
		for (int i = 0; i < k - n; ++i)
			printf("%c", Chars[0]);
		printf("\n");
	}
	else {
		solve(start, -1);
		for (int i = 0; i < k; ++i) {
			printf("%c", solution[i]);
		}
		printf("\n");
	}
	//show(start);



	//printf("%s\n", sir);
	return 0;
}
