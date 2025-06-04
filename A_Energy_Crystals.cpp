#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;  

    while (t--) {
        int x;
        cin >> x;

       
        int ans = (int)ceil(log2(x)) + 2;

        cout << ans << endl;
    }

    return 0;
}
