#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ok = 1;
        for(int i = 0; i < n; i++) {
            long long a;
            cin >> a;
            if(a % (n + 1) != 0) {
                ok = 0;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
