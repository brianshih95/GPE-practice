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
        vector<double> v(m);    // �s�U��Υb�|
        for(int i=0; i<m; i++)
            cin >> v[i];

        double ans = 1e18;
        sort(v.begin(), v.end());   // ���F��next_permutation�]�M�Ҧ��ƦC�A�ݥ�sort
        do{
            vector<double> tmp(m);  // tmp[i]���ei�Ӷ� + ��i+1�Ӷꪺ���b��A�һݭn���Ŷ�
            double cur = 2 * v[0];
            tmp[0] = v[0];

            for(int i=1; i<m; i++){
                tmp[i] = v[i];

                for(int j=0; j<i; j++)  // �����ݬO�_��\�L�h
                    tmp[i] = max(tmp[i], tmp[j] + 2*sqrt(v[i]*v[j]));   // (r1+r2)^2 - (r1-r2)^2 = 4*r1*r2

                cur = max(cur, tmp[i] + v[i]);
            }

            ans = min(ans, cur);    // ���Ҧ��զX�̤p��

        }while(next_permutation(v.begin(), v.end()));   // e.g. 123, 132, 213, 231, 312, 321

        cout << fixed << setprecision(3) << ans << '\n';    // fixed�f�tsetprecision��T�w�p���I
    }
    return 0;
}
