// 數論，這種題要找規律
// 1. (i^i)%10 == ((i%10)^i)%10, ex.72^72 == 2^72
// 2. (Σ(i^i%10))%10 每20個循環會增加4，總共每100個循環一次

#include <bits/stdc++.h>

using namespace std;

int last_digit(int num, int pow){
    int x = 1;
    for(int i=0; i<pow; i++){
        x *= num;
        x %= 10;
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> table(20, 0);
    for(int i=1; i<20; i++)
        table[i] = (table[i-1] + last_digit(i%10, i)) % 10;

    string s;
    while(cin >> s){
        if(s == "0")
            break;

        // 只須看後面2位
        int n;
        if(s.size() < 3)
            n = stoi(s);
        else
            n = (s[s.size()-2]-'0')*10 + s[s.size()-1]-'0';

        cout << (table[n%20] + 4*(n/20)) % 10 << '\n';
    }
    return 0;
}
