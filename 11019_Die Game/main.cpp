// 4 faces will change in 1 roll

#include <bits/stdc++.h>

using namespace std;

void toNorth(vector<int>& die){
    int tmp = die[0];
    die[0] = die[3];
    die[3] = die[1];
    die[1] = die[2];
    die[2] = tmp;
}

void toSouth(vector<int>& die){
    int tmp = die[0];
    die[0] = die[2];
    die[2] = die[1];
    die[1] = die[3];
    die[3] = tmp;
}

void toEast(vector<int>& die){
    int tmp = die[0];
    die[0] = die[4];
    die[4] = die[1];
    die[1] = die[5];
    die[5] = tmp;
}

void toWest(vector<int>& die){
    int tmp = die[0];
    die[0] = die[5];
    die[5] = die[1];
    die[1] = die[4];
    die[4] = tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n && n){
        vector<string> commands(n);
        for(int i=0; i<n; i++)
            cin >> commands[i];

        vector<int> die = {1, 6, 2, 5, 3, 4};   // top, bottom, north, south, west, east

        for(auto command: commands){
            if(command == "north")
                toNorth(die);
            else if(command == "south")
                toSouth(die);
            else if(command == "east")
                toEast(die);
            else if(command == "west")
                toWest(die);
        }

        cout << die[0] << '\n'; // top

    }
    return 0;
}
