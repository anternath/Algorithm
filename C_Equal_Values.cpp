#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n+1];
        unordered_map<int, int> min_idx, max_idx;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (min_idx.find(a[i]) == min_idx.end())
                min_idx[a[i]] = i;
            max_idx[a[i]] = i;
        }

        long long res = LLONG_MAX;
        for (auto [val, l] : min_idx) {
            int r = max_idx[val];
            long long cost = 1LL * (l - 1) * val + 1LL * (n - r) * val;
            res = min(res, cost);
        }

        cout << res << endl;
    }
    return 0;
}
