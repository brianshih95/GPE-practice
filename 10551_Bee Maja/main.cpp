#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

const int MAX = 100000 + 5;
vector<pii> dp(MAX, {0, 0});

void create_table(){
    // 先處理x座標
    // 規律為 +0, -1 * k, +0 * round, +1 * k, +0 * round
    int round = 0;
    int k = 1;
    for(int i=2; i<MAX; ){
        round++;

        dp[i].X = dp[i-1].X;
        i++;

        for(int j=0; j<k && i<MAX; j++, i++)
            dp[i].X = dp[i-1].X - 1;
        k++;

        for(int j=0; j<round && i<MAX; j++, i++)
            dp[i].X = dp[i-1].X;

        for(int j=0; j<k && i<MAX; j++, i++)
            dp[i].X = dp[i-1].X + 1;
        k++;

        for(int j=0; j<round && i<MAX; j++, i++)
            dp[i].X = dp[i-1].X;
    }

    // 再處理y座標
    // 規律為 -1 * round, +0 * round, -1 * k, +0 * round, +1 * round
    round = 0;
    k = 2;
    for(int i=2; i<MAX; ){
        round++;

        for(int j=0; j<round && i<MAX; j++, i++)
            dp[i].Y = dp[i-1].Y + 1;

        for(int j=0; j<round && i<MAX; j++, i++)
            dp[i].Y = dp[i-1].Y;

        for(int j=0; j<k && i<MAX; j++, i++)
            dp[i].Y = dp[i-1].Y - 1;
        k += 2;

        for(int j=0; j<round && i<MAX; j++, i++)
            dp[i].Y = dp[i-1].Y;

        for(int j=0; j<round && i<MAX; j++, i++)
            dp[i].Y = dp[i-1].Y + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    create_table();

    int n;
    while(cin >> n)
        cout << dp[n].X << ' ' << dp[n].Y << '\n';

    return 0;
}
