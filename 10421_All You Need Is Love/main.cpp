#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        // stoi(string s, 0, int base), 能把字串轉為整數
        int num1 = stoi(s1, 0, 2);
        int num2 = stoi(s2, 0, 2);

        cout << "Pair #" << i << ": ";
        // __gcd(num1, num2), 能取得最大公因數
        if(__gcd(num1, num2) != 1)
            cout << "All you need is love!\n";
        else
            cout << "Love is not all you need!\n";
    }
    return 0;
}

/*
int gcd(int a, int b){
    int t;
    while(b > 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
*/
