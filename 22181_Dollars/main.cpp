#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

// 因索引值為整數，coin全乘100
vector<int> coin = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
vector<ll> table(30001);    // table[i]代表money為i時有幾種組合

void create_table(){
    table[0] = 1;   // base
    for(int i=0; i<coin.size(); i++)
        for(int j=coin[i]; j<table.size(); j++)
            table[j] += table[j-coin[i]];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    create_table();

    double money;
    while(cin >> money && money){
        // 因浮點數精度問題，此處要用round，不能用int
        cout << fixed << setprecision(2) << setw(6) << money << setw(17) << table[round(money*100)] << '\n';
    }
    return 0;
}
