/**
 *       Author :   Sakib62
 *       Created:   Thu__13.Oct.2022__21:01:16
 *       File   :   E_Scuza.cpp
**/
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << ">" << #x << ": " << x << "\n"; 

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("Input.txt", "r", stdin); freopen("Output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;

    cin >> testCase;
    while(testCase--) {
        int n, q, mxtill=0, ind=0;
        cin >> n >> q;
//The i-th step is ai meters higher than its predecessor.
//The first step is a1 meters higher than the ground, and the ground starts at 0 meters.
        long long stair[n+1], prefix[n+1]={0};
        map<int, int>mp;

        for(int i=1; i<=n; i++) {
            cin >> stair[i];
            prefix[i]=prefix[i-1]+stair[i];
            //tracking max difference height and corresponding position
            if(i==1) {
                mxtill=stair[i];
                ind=i;
            }
            else {
                if(stair[i]>=mxtill) {
                    mxtill=stair[i];
                    ind=i;
                }
            }
            mp.insert({mxtill, ind});//at each index what is the max difference in heights
        }
        for(int i=1;i<=q;i++) {//queries
            int len;
            cin >> len;
            auto ptr=mp.upper_bound(len);//first height difference that cannot be crossed. Stop at this position
            if(ptr==mp.end()) cout<<prefix[n]<<" ";//if all difference can be crossed, then whole stair can be climbed
            else {
                int y=ptr->second;
                cout<<prefix[y-1]<<" ";//total heights till that position
            }
        }
        cout<<"\n";
    }
}