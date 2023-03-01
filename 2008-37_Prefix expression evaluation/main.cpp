// 無測資

//從後面開始看，一個個放入stack，遇到operator就取出兩個再放進新的數值

#include <bits/stdc++.h>

using namespace std;

bool isoperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string expr;
    while(getline(cin, expr)){
        if(expr == ".")
            break;

        vector<string> v;
        stringstream ss(expr);
        string tmp;
        while(ss >> tmp)
            v.push_back(tmp);
        reverse(v.begin(), v.end());

        stack<int> s;
        int num1, num2;
        bool flag = 0;  // illegal expression detected
        for(int i=0; i<v.size(); i++){
            if(isoperator(v[i][0])){    // string轉char可用s[0]
                if(s.empty()){
                    flag = 1;
                    break;
                }
                num1 = s.top();
                s.pop();
                if(s.empty()){
                    flag = 1;
                    break;
                }
                num2 = s.top();
                s.pop();
                if(v[i] == "+")
                    s.push(num1 + num2);
                else if(v[i] == "-")
                    s.push(num1 - num2);
                else if(v[i] == "*")
                    s.push(num1 * num2);
                else if(v[i] == "/")
                    s.push(num1 / num2);
                else if(v[i] == "%")
                    s.push(num1 % num2);
            }
            else
                s.push(stoi(v[i]));
        }

        if(!flag)
            cout << s.top() << '\n';
        else
            cout << "illegal" << '\n';
    }
    return 0;
}
