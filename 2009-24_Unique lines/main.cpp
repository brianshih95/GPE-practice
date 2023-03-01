#include <bits/stdc++.h>
#define pdd pair<double, double>

using namespace std;

struct Line{
    // y = ax + b
    double a;
    double b;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cases;
    cin >> cases;
    while(cases--){
        set<pdd> seen;  // 紀錄已經出現的line

        int n;
        cin >> n;
        vector<int> x(n), y(n);
        for(int i=0; i<n; i++){
            cin >> x[i] >> y[i];

            for(int j=0; j<i; j++){
                Line line;
                double x_dif = x[i] - x[j];
                double y_dif = y[i] - y[j];

                if(x_dif){
                    line.a = y_dif / x_dif;
                    line.b = y[i] - line.a * x[i];
                }
                else{
                    line.a = DBL_MAX;
                    line.b = x[i];
                }

                seen.insert({line.a, line.b});
            }
        }

        cout << seen.size() << '\n';
    }
    return 0;
}
