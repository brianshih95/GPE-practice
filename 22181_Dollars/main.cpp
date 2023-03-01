#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

// �]���ޭȬ���ơAcoin����100
vector<int> coin = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
vector<ll> table(30001);    // table[i]�N��money��i�ɦ��X�زզX

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
        // �]�B�I�ƺ�װ��D�A���B�n��round�A�����int
        cout << fixed << setprecision(2) << setw(6) << money << setw(17) << table[round(money*100)] << '\n';
    }
    return 0;
}
