#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 40005;
int left_child[MAXN];
int right_child[MAXN];
int max_diameter = 0;

int dfs(int u) {
    if (u == -1) {
        return 0;
    }

    int l_depth = dfs(left_child[u]);
    int r_depth = dfs(right_child[u]);

    max_diameter = max(max_diameter, l_depth + r_depth);
    return 1 + max(l_depth, r_depth);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; ++i) {
        cin >> left_child[i] >> right_child[i];
    }

    // The tree is guaranteed to be rooted at vertex 1
    dfs(1);

    // Output the maximum length of the marathon
    cout << max_diameter << "\n";

    return 0;
}
