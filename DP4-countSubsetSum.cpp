#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int perfectSum(vector<int> arr, int n, int t)
{
    int mod = 1000000007;
    vector<int> last(t+1, 0);
    last[0] = 1; // There's always one way to get sum 0, which is to pick no elements

    for(int i = 0; i < n; i++) {
        vector<int> curr(t+1, 0);
        for(int j = 0; j <= t; j++) {
            int take = 0;
            if(arr[i] <= j) {
                take = last[j - arr[i]];
            }
            int nottake = last[j];
            curr[j] = (take + nottake) % mod;
        }
        last = curr;
    }

    return last[t];
}

