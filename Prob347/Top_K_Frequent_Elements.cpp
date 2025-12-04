/*
347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer 
in any order.



Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]



Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.


Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        //---------------------------First attempt---------------------------
        /* 
        Runtime 
        7 ms    |   Beats 16.70 %
        O(N*K)
        */
        // vector<int> top;
        // unordered_map<int,int> map;
        // for(int num: nums){
        //     if (!map.count(num))
        //     {
        //         map[num] = 1;
        //     }
        //     else{
        //         map[num]++;
        //     }
        // }
        // int index;

        // for (int i = 0; i < k; i++)
        // {
        //     int max = 0;
        //     for (auto elem:map)
        //     {
        //         if(elem.second > max){
        //             max = elem.second;
        //             index = elem.first;
        //         }
        //     }
        //     top.push_back(index);
        //     map.erase(index);
        // }

        // return top;

        //---------------------------Second attempt---------------------------
        unordered_map<int, int> map;
        for(int num: nums){
            if (!map.count(num))
            {
                map[num] = 1;
            }
            else{
                map[num]++;
            }
        }
        for (size_t i = 0; i < k; i++)
        {
            
        }
        
    }
};

int main(){
    Solution solution;
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    int k = 2;
    vector<int> reply = solution.topKFrequent(nums, k);
    cout << "[ ";
    for (auto i : reply)
    {
        cout << i << ", ";
    }
    cout << "]";
}