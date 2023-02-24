#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        vector<double> v(m);    // 存各圓形半徑
        for(int i=0; i<m; i++)
            cin >> v[i];

        double ans = 1e18;
        sort(v.begin(), v.end());   // 為了讓next_permutation跑遍所有排列，需先sort
        do{
            vector<double> tmp(m);  // tmp[i]為前i個圓 + 第i+1個圓的左半邊，所需要的空間
            double cur = 2 * v[0];
            tmp[0] = v[0];

            for(int i=1; i<m; i++){
                tmp[i] = v[i];

                for(int j=0; j<i; j++)  // 往左看是否能蓋過去
                    tmp[i] = max(tmp[i], tmp[j] + 2*sqrt(v[i]*v[j]));   // (r1+r2)^2 - (r1-r2)^2 = 4*r1*r2

                cur = max(cur, tmp[i] + v[i]);
            }

            ans = min(ans, cur);    // 找到所有組合最小的

        }while(next_permutation(v.begin(), v.end()));   // e.g. 123, 132, 213, 231, 312, 321

        cout << fixed << setprecision(3) << ans << '\n';    // fixed搭配setprecision能固定小數點
    }
    return 0;
}
