#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll s, d;
    while(cin >> s >> d){
        while(d > 0){
            d -= s;
            s++;
        }
        cout << s - 1 << '\n';
    }
    return 0;
}
