#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(vector<int> &arr, int k) {
    vector<int> last(k+1, 0);
    last[0] = 1;
    for(int n: arr){
        vector<int> curr(k+1, 0);
        curr[0] = 1;
        for(int j=1; j<=k; j++) {
            int take = 0;
            if(j>=n) take = last[j-n];
            int nottake = last[j];
            curr[j] = take || nottake;
        }
        last = curr;
    }
    return last[k];
}
