/*
1539. Kth Missing Positive Number

Given an array arr of positive integers sorted in a strictly increasing order,
and an integer k.

Return the kth positive integer that is missing from this array.



Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.


Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length


Follow up:

Could you solve this problem in less than O(n) complexity?
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Runtime
0 ms |   Beats 100.00%
O(n+k)
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;
        int i = 0;
        while (i<arr.size()+missing.size())
        {
            if (i+1 != arr[i-missing.size()])
            {
                missing.push_back(i + 1);
            }
            if (missing.size() == k)
            {
                return missing.back();
            }
            
            i++;
        }
        return i+k-missing.size();
    }
};

int main(){
    Solution solution;
    vector<int> arr = {2, 4, 6, 7};
    cout << solution.findKthPositive(arr, 5);
}