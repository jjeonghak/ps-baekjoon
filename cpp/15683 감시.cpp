#include<iostream>
#include<vector>
using namespace std;

int n, m, ans, cnt;
int map[9][9];
vector<pair<int, pair<int, int>>> v;

pair<int, int> casef(int c, int y, int x) {
    switch (c) {
    case 0:
        x++;
        break;
    case 1:
        y++;
        break;
    case 2:
        x--;
        break;
    case 3:
        y--;
        break;
    }
    return { y, x };
}

int sol(int c, int y, int x) {
    int sum = 0;
    int ny = y, nx = x;
    while (1) {
        pair<int, int> l = casef(c, ny, nx);
        ny = l.first;
        nx = l.second;
        if (ny < n && ny >= 0 && nx < m && nx >= 0) {
            if (map[ny][nx] == 0) {
                sum++;
                map[ny][nx] = -1;
            }
            else if (map[ny][nx] == 6) return sum;
        }
        else return sum;
    }
}

void set(int c, int submap[][9]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c) map[i][j] = submap[i][j];
            else submap[i][j] = map[i][j];
        }
    }
}

void bt(int total) {
    if (v.empty()) {
        if (total > cnt) cnt = total;
        return;
    }
    int submap[9][9];
    set(0, submap);
    int subcnt = 0;
    pair<int, pair<int, int>> p = v.back();
    v.pop_back();
    switch (p.first) {
    case 1:
        for (int i = 0; i < 4; i++) {
            subcnt = sol(i, p.second.first, p.second.second);
            bt(total + subcnt);
            set(1, submap);
        }
        break;
    case 2:
        for (int i = 0; i < 2; i++) {
            subcnt = sol(i, p.second.first, p.second.second) + sol(i + 2, p.second.first, p.second.second);
            bt(total + subcnt);
            set(1, submap);
        }
        break;
    case 3:
        for (int i = 0; i < 4; i++) {
            subcnt = sol(i, p.second.first, p.second.second) + sol((i + 1) % 4, p.second.first, p.second.second);
            bt(total + subcnt);
            set(1, submap);
        }
        break;
    case 4:
        for (int i = 0; i < 4; i++) {
            subcnt = sol(i, p.second.first, p.second.second) + sol((i + 1) % 4, p.second.first, p.second.second)
                + sol((i + 2) % 4, p.second.first, p.second.second);
            bt(total + subcnt);
            set(1, submap);
        }
        break;
    case 5:
        for (int i = 0; i < 4; i++) {
            subcnt += sol(i, p.second.first, p.second.second);
        }
        bt(total + subcnt);
        set(1, submap);
        break;
    }
    v.push_back(p);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) ans++;
            else if (map[i][j] != 6) v.push_back({ map[i][j], {i, j} });
        }
    }
    bt(0);
    cout << ans - cnt;
    return 0;
}
