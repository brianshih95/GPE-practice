// Josephus problem
// 存活者編號f(n, m) = (f(n - 1, m) + m) % n

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n && n){
        n--;    // 第1個必停，先去掉
        int m;
        for(m=1; m<n; m++){
            int survive = 0;    // 存活的編號(0~n-1)

            // 從f(1, m)一路算到f(n, m)
            for(int i=1; i<=n; i++)
                survive = (survive + m) % i;

            if(survive == 11)   // 因去掉第1個，且編號從0開始，Wellington變11號
                break;
        }
        cout << m << '\n';
    }
    return 0;
}
