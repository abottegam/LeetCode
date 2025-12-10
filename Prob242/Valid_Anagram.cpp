/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false
*/

#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

/*
Runtime
0 ms    |   Beats 100.00%
O(N)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }

        int alphabet_s[26] = {0};
        int alphabet_t[26] = {0};

        for (int i = 0; i < s.length(); i++)
        {

            alphabet_s[s[i] - 'a']++;
            alphabet_t[t[i]-'a']++;
        }


        for (int i = 0; i < 26; ++i)
        {
            if (alphabet_s[i] != alphabet_t[i])
            {
                return false; // Found a mismatch
            }
        }
        return true; // All elements match
    }
};

int main(){
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    cout << (solution.isAnagram(s,t)? "True": "False");
}