#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int steps = 0, val = 1;
        while (val < x) {
            val *= 2;
            steps++;
        }
        cout << steps + 2 << endl;
    }
    return 0;
}
