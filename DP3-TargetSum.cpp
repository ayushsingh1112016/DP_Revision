#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (target > sum || target < -sum) {
            return 0; 
        }
        
        vector<int> dp(2 * sum + 1, 0);
        dp[sum] = 1; 
        
        for (int num : nums) {
            vector<int> next(2 * sum + 1, 0);
            for (int i = 0; i < dp.size(); ++i) {
                if (dp[i] != 0) {
                    next[i + num] += dp[i];
                    next[i - num] += dp[i];
                }
            }
            dp = next;
        }
        
        return dp[target + sum];
    }