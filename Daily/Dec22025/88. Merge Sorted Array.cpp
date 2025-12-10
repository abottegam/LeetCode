
/*
88. Merge Sorted Array

Hint
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 
respectively. Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, 
where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/
#include <vector>
#include <iostream>
using namespace std;

/*
Runtime
0 ms |   Beats 100.00%
O(m+n)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x = n - 1;
        int z = m - 1;
        while (x > -1) {
            if (z != -1) {
                if (nums2[x] > nums1[z]) {
                    nums1[x + z + 1] = nums2[x];
                    x--;
                }
                else if (nums1[z] == nums2[x]) {
                    nums1[z + x + 1] = nums1[z];
                    nums1[z + x] = nums2[x];
                    x--;
                    z--;
                }
                else {
                    nums1[x + z + 1] = nums1[z];
                    z--;
                }
            }
            else{
                nums1[x + z + 1] = nums2[x];
                x--;
            }
        }
    }
};

int main(){
    Solution solution;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,4,5};
    solution.merge(nums1, 3, nums2, nums2.size());
}
