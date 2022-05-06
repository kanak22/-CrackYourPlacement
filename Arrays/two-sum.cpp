#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> mp;
        for(int i=0; i<nums.size();i++){
            auto itr = mp.find((target-nums[i]));
            if( itr!= mp.end()){
                return {itr->second,i};
            }
            mp.insert({nums[i], i});
        }
        return {};
    }
};