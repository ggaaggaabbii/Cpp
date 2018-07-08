#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;

    vector<int> v;
    int nr;

    for (int i = 0; i < n; ++i) {
        cin >> nr;
        v.push_back(nr);
    }

    int count = 0;

    for (int i = 1; i < v.size(); ++i) {
        int last_pos = v[i - 1] + d;
        bool ok = false;

        if (v[i] - last_pos >= d) {
            ++count;
            ok = true;
        }

        if (v[i] - d != last_pos && v[i] - d > v[i - 1] + d && ok) {
            ++count;
        }
    }

    cout << count + 2 << "\n";

    return 0;
}
