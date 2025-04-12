#include <iostream>
#include <string>
#include <utility>

using namespace std;

pair<int, int> get_coords(int level, long long d) {
    if (level == 1) {
        if (d == 1) return {1, 1};
        else if (d == 2) return {2, 2};
        else if (d == 3) return {2, 1};
        else return {1, 2};
    }
    long long s = 1LL << (level - 1);
    long long s_sq = s * s;
    if (d <= s_sq) {
        auto p = get_coords(level - 1, d);
        return {p.first, p.second};
    } else if (d <= 2 * s_sq) {
        auto p = get_coords(level - 1, d - s_sq);
        return {p.first + s, p.second + s};
    } else if (d <= 3 * s_sq) {
        auto p = get_coords(level - 1, d - 2 * s_sq);
        return {p.first + s, p.second};
    } else {
        auto p = get_coords(level - 1, d - 3 * s_sq);
        return {p.first, p.second + s};
    }
}

long long get_number(int level, int x, int y) {
    if (level == 1) {
        if (x == 1 && y == 1) return 1;
        else if (x == 2 && y == 2) return 2;
        else if (x == 2 && y == 1) return 3;
        else return 4;
    }
    long long s = 1LL << (level - 1);
    if (x <= s && y <= s) {
        return get_number(level - 1, x, y);
    } else if (x > s && y > s) {
        long long base = s * s;
        return base + get_number(level - 1, x - s, y - s);
    } else if (x > s) {
        long long base = 2 * s * s;
        return base + get_number(level - 1, x - s, y);
    } else {
        long long base = 3 * s * s;
        return base + get_number(level - 1, x, y - s);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        while (q--) {
            string type;
            cin >> type;
            if (type == "->") {
                int x, y;
                cin >> x >> y;
                cout << get_number(n, x, y) << '\n';
            } else {
                long long d;
                cin >> d;
                pair<long long,long long>x = get_coords(n, d);
                cout << x.first << ' ' << x.second << '\n';
            }
        }
    }

    return 0;
}