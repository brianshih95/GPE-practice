/*
�ܩ����`�M���_�ƥ��w�L�k����
�Ӱ��ƪ����p�U�A���`�M���@�b���ӷ�@�I�]���e�q
�N�ܦ�0/1�I�]���D�F
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;
    cin.ignore();   // �קKgetline�N"\n"��@string
    while(m--){
        string line;
        stringstream ss;
        getline(cin, line);
        ss << line;

        vector<int> v;
        int weight, sum = 0;
        while(ss >> weight){
            v.push_back(weight);
            sum += weight;
        }

        if(sum & 1){
            cout << "NO" << '\n';
            continue;
        }

        vector<bool> dp(sum + 1, 0);    // dp[i]��ܲ{��������O�_��զ�i����
        dp[0] = 1;

        for(int i=0; i<v.size(); i++)
            for(int j=sum; j>=v[i]; j--)
                if(dp[j - v[i]])
                    dp[j] = 1;

        cout << (dp[sum/2] ? "YES" : "NO") << '\n';

    }
    return 0;
}
