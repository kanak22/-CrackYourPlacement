#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // brute force - two passes
        int c0 = 0, c1 = 0, c2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                c0++;
            }
            else if (nums[i] == 1)
            {
                c1++;
            }
            else
            {
                c2++;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i <= c0 - 1)
            {
                nums[i] = 0;
            }
            else if (i > c0 - 1 && i <= c0 + c1 - 1)
            {
                nums[i] = 1;
            }
            else if (i > c0 + c1 - 1 && i <= c0 + c1 + c2 - 1)
            {
                nums[i] = 2;
            }
        }

        // one-pass solution with constant space
        int low, mid, high;
        low = mid = 0;
        high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};