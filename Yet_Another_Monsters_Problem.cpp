#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<long long> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        // Sort descending
        sort(v.rbegin(), v.rend());

        long long ans = LLONG_MAX;
        for(int k = 0; k <= n; k++) {
            long long damage_time = 0;
            if(k < n) {
                damage_time = v[k];
            } 
            ans = min(ans, damage_time + k);
        }
        cout << ans << "\n";
    }

    return 0;
}
