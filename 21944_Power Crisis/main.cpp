// Josephus problem
// �s���̽s��f(n, m) = (f(n - 1, m) + m) % n

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n && n){
        n--;    // ��1�ӥ����A���h��
        int m;
        for(m=1; m<n; m++){
            int survive = 0;    // �s�����s��(0~n-1)

            // �qf(1, m)�@�����f(n, m)
            for(int i=1; i<=n; i++)
                survive = (survive + m) % i;

            if(survive == 11)   // �]�h����1�ӡA�B�s���q0�}�l�AWellington��11��
                break;
        }
        cout << m << '\n';
    }
    return 0;
}
