#pragma once
/*
30. Substring with Concatenation of All Words (HARD)

You are given a string s and an array of strings words of the same length.
Return all starting indices of substring(s) in s that is a concatenation
of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans{};

        int n = words.size();
        int m = words[0].size();
        int nn = s.size();
        int concatLength = n * m;

        if (concatLength > nn) // string shorter than concat of words
            return ans;

        unordered_map<char, int> wordsMap = charCountMap(words);
        unordered_map<string, int> wordCountMap{};
        for (auto word : words) {
            wordCountMap[word]++;
        }

        // Initialise unordered map from first n*m chars in s
        unordered_map<char, int> stringMap{};
        for (int i = 0; i < concatLength; ++i) {
            stringMap[s[i]]++;
        }
        for (int i = 0; i <= nn - concatLength; ++i) {
            // Check the words map has same counts as sliding string map
            if (isSameMap(wordsMap, stringMap)) { // If maps are the same we will test it meets the condition
                bool flag = true;   // Flags whether to add index i to ans
                unordered_map<string, int> wordCounts{};
                for (int j = i; j < i + concatLength; j += m) {
                    string temp = s.substr(j, m);
                    wordCounts[temp]++;
                    if (wordCounts[temp] > wordCountMap[temp]) {
                        flag = false;
                        break;
                    }
                }
                // If condition is met add i to ans
                if (flag)
                    ans.push_back(i);
            }
            // erase char i in stringMap and add char i+concatLength
            stringMap[s[i]]--;
            stringMap[s[i + concatLength]]++;
        }

        return ans;

    }

    unordered_map<char, int> charCountMap(vector<string>& v) {
        // returns the unordered map of the count of each char in vec of strings
        unordered_map<char, int> ans{};
        for (auto s : v) {
            for (auto c : s) {
                ans[c]++;
            }
        }

        return ans;
    }

    bool isSameMap(unordered_map<char, int>& x, unordered_map<char, int>& y) {
        // Returns if two maps are same   
        for (auto p : x) {
            if (y[p.first] != p.second)
                return false;
        }

        return true;
    }
};