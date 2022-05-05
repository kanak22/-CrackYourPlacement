#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        //brute force
          int ans=0;
        
        vector<int> v(nums);
        sort(v.begin(),v.end());
        
        int start=v.size(),end=0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=v[i]){
               start=min(start,i);
                end=max(end,i);
            } 
        }
        
        ans = end-start+1;
        if(ans<= 0){
            return 0;
        }
        return ans;

        //optimised
       int mi= INT_MAX, ma=INT_MIN;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<nums[i-1]){
                mi = min(mi,nums[i]);
            }
        }
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]>nums[i+1]){
                ma = max(ma,nums[i]);
            }
        }
        int l,r;
        for(int i=0; i<nums.size(); i++){
            if(mi < nums[i]){
                l=i;
                break;
            }
        }
        for(int i=nums.size()-1; i>=0; i--){
            if(ma>nums[i]){
                r=i;
                break;
            }
        }
        if(r-l<0){ return 0;}
        return r-l+1;
    }
};