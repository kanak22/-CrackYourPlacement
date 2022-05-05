#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

       // brute force
       int ans;
       sort(nums.begin(), nums.end());
       for(int i=0; i<nums.size()-1; i++){
           if(nums[i]==nums[i+1]){
              ans = nums[i];
           }
       }
        return ans;

        // a bit better optimised approach;
       while(nums[0]!=nums[nums[0]]){
           swap(nums[0],nums[nums[0]]);
       }
        return nums[0];
    }
};