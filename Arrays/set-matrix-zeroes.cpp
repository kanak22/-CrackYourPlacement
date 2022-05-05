#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //brute force
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<pair<int,int>> v;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    v.push_back(make_pair(i,j));
                }
            }
        }
        
        for(int i=0; i<v.size(); i++){
            int r=0,c=0;
            while(c<n){
                matrix[v[i].first][c]=0;
                c++;
            }
            while(r<m){
                matrix[r][v[i].second]=0;
                r++;
            }
        }
    }
};