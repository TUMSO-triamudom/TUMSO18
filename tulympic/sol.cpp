#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int, int> ii;
int a[20005];
int ti[20005][10];
ii tmp[20005], score[20005];
bool cmp(ii a, ii b)
{
    if (a.x != b.x)
        return a.x > b.x;
    else
        return a.y < b.y;
}
int main()
{
    int n, m, x, t;
    cin >> n >> m >> x >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        score[i].y = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> ti[i][j];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            tmp[j] = {ti[j][i], j};
        sort(tmp + 1, tmp + n + 1);
        for (int j = 1; j <= n; j++)
            score[tmp[j].y].x += a[j];
    }
    sort(score + 1, score + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        if (score[i].y == x)
        {
            cout << i;
            if (t == 2)
                cout << " " << score[i].x;
        }
}
