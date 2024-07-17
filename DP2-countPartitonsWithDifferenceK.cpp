#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int countPartitions(int n, int d, vector<int>& arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);  
    vector<int> prev(sum + 1, 0);
    prev[0] = 1;
    for(int i = 0; i < n; i++){
        vector<int> curr(sum + 1, 0);  // Added closing semicolon
        for(int j = 0; j <= sum; j++){  // Changed n to sum
            if(j >= arr[i]) {  // Added bounds check
                curr[j] = (prev[j] + prev[j - arr[i]]) % 1000000007;
            } else {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    int ans = 0;
    for(int i=0; i<=sum; i++){
        if(prev[i] && sum-2*i == d) ans =(ans + prev[i])%1000000007;
    }
    return ans;
};