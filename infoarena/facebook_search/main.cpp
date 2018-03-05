#include <bits/stdc++.h>
#define MAXN 100002
using namespace std;

ifstream f("fbsearch.in");
ofstream g("fbsearch.out");

int n, m, T, Value;
string Word;
char op;
unsigned short Relevance[MAXN];
unordered_map<string, int> Index;
unordered_map<int, string> V;

struct trie {
	int maxInd;
	trie* v[26];
	trie() {
		maxInd = 0;
		memset(v, 0, sizeof(v));
	}
}*root;

int findPos(char x) {
	if (x >= 'a' && x <= 'z') {
		return x - 'a';
	}
	if (x >= 'A' && x <= 'Z') {
		return x - 'A';
	}
	return -1;
}

void update(trie *q, string word, int pos, int wordIndex) {
	if (!q->maxInd || Relevance[wordIndex] > Relevance[q->maxInd] ||
	        (Relevance[wordIndex] == Relevance[q->maxInd] && word < V[q->maxInd])) {
		q->maxInd = wordIndex;
	}
	if (pos >= word.length()) return;

	int poz = findPos(word[pos]);

	if (poz == -1) return;

	if (q->v[poz] == 0) {
		q->v[poz] = new trie();
	}

	update(q->v[poz], word, pos + 1, wordIndex);

}


void query(trie *q, string word, int pos) {
	if (pos >= word.length()) {
		if (q->maxInd != 0)
			g << V[q->maxInd] << '\n';
		else
			g << "Search Bing for " << word << '\n';
		return;
	}
	int poz = findPos(word[pos]);
	if (poz == -1 || q->v[poz] == 0 || q->maxInd == 0) {
		g << "Search Bing for " << word << '\n';
		return;
	}

	query(q->v[findPos(word[pos])], word, pos + 1);
}
/*
void afis(trie *q) {
	for (int i = 0; i < 28; ++i) {
		if (q->v[i] != 0) {
			cout << (char)(i + 'a') << " " << q->maxInd << '\n';
			afis(q->v[i]);
		}
	}
}
*/
void resetTrie(trie *q) {
	for (int i = 0; i < 26; ++i) {
		if (q->v[i])
			resetTrie(q->v[i]);
	}
	free(q);
	//delete(q);
}

int main() {
	f >> T;
	int ind;
	while (T--) {
		root = new trie();
		memset(Relevance, 0, sizeof(Relevance));
		Index.clear();
		V.clear();
		f >> n >> m;
		f.get();
		for (int i = 1; i <= n; ++i) {
			f >> Word;
			Index[Word] = i;
			V[i] = Word;
			update(root, Word, 0, i);
		}
		//afis(root);
		//cout << "\n";
		for (int i = 1; i <= m; ++i) {
			op = 0;
			Word.clear();
			f >> op;
			f >> Word;
			if (op != 'Q') {
				f >> Value;
				ind = Index[Word];
				Relevance[ind] += Value;
				update(root, Word, 0, ind);
			}
			else
				query(root, Word, 0);
		}
		resetTrie(root);
	}
	//cout << (float)sizeof(Index) / 1024;
	return 0;
}
