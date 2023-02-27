/*
每兩兩一組，跟別人借一瓶湊成3個，得到新的一瓶喝掉在還別人
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n){
        cout << n + n / 2 << '\n';
    }
    return 0;
}
