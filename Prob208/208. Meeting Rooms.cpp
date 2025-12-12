/*
253. Meeting Rooms II

Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.



Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1


Constraints:

1 <= intervals.length <= 104
0 <= starti < endi <= 106
*/

#include <iostream>
#include <vector>


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
    }
};

int main(){
    Solution solution;
    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
    solution.minMeetingRooms(intervals);
}