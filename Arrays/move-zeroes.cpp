#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //brute force
        vector<int> v; int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                v.push_back(nums[i]);
            } else {
                count++;
            }
        }
        nums.clear();
        for(int i=0; i<v.size(); i++){
            nums.push_back(v[i]);
        }
        for(int i=0; i<count; i++){
            nums.push_back(0);
        }
    }
};