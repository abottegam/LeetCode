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
#include <bits/stdc++.h>

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

        //     vector<int> map1;
        //     //finding max element
        //     int max = 0;
        //     for (int num : nums){
        //         if(abs(num) > max){
        //             max = abs(num);
        //         }
        //     }
        //     //assigning size of map to max element and initializing to 0
        //     map1.assign(max, 0);

        //     //counting frequencies
        //     for (int num : nums)
        //     {
        //         map1[abs(num)-1]++;
        //     }

        //     //organizing
        //     priority_queue<pair<int, int>> p1;
        //     for (int i = 0; i<map1.size(); i++)
        //     {
        //         p1.push(make_pair(map1.at(i), i+1));
        //     }

        //     map1.erase(map1.begin(), map1.end());

        //     for (size_t i = 0; i < k; i++)
        //     {
        //         map1.push_back(p1.top().second);
        //         p1.pop();
        //     }
        //     return map1;

        // }

        //---------------------------Third attempt---------------------------
        /*
        Runtime
        0 ms | Beats 100.00%
        O(NlogN)
        */
        unordered_map<int,int> map;
        for(int num: nums){
            if (!map.count(num))
            {
                map[num] = 1;
            }
            else{
                map[num]++;
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, myComp> p1;

        for (auto pair:map)
        {
            p1.push(pair);
        }
        vector<int> ans;
        for (size_t i = 0; i < k; i++)
        {
            ans.push_back(p1.top().first);
            p1.pop();
        }
        
        return ans;
    }
    struct myComp
    {
        constexpr bool operator()(
            pair<int, int> const &a,
            pair<int, int> const &b)
            const noexcept
        {
            if(a.second == b.second){
                return b.second;
            }
            return a.second < b.second;
        }
    };
};

int main(){
    Solution solution;
    vector<int> nums = {-1,-1};
    int k = 1;
    vector<int> reply = solution.topKFrequent(nums, k);
    string print = "[ ";
    for (auto i : reply)
    {
        print = print + to_string(i) + ", ";
    }
    print.erase(print.end()-2, print.end()-1);
    print+= "]";
    cout << print;
}