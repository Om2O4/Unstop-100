#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<long long, int> freq;
    
    freq.reserve(2048 * 1024);

    for (int i = 0; i < n; ++i) {
        long long s = 0;
        for (int j = i; j < n; ++j) {
            s += a[j];
            freq[s]++;
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long s = 0;
        for (int j = i; j < n; ++j) {
            s += a[j];
            auto it = freq.find(s);
            if (it != freq.end()) {
                it->second--;
            }
        }
        s = 0;
        for (int j = i; j >= 0; --j) {
            s += a[j];
            auto it = freq.find(s);
            if (it != freq.end()) {
                ans += it->second;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
