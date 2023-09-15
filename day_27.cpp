// product of array except self fastest solution

#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> ans(n, 1);
    int left = 1, right = 1;
    for(int i = 0; i < n; i++) 
    {
        ans[i] = ans[i] * left;
        ans[n - i - 1] = ans[n - i - 1] * right;
        left = left * nums[i];
        right = right * nums[n - i - 1];
    }
    return ans;
}