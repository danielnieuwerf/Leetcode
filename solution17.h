#include <vector>
#include <string>

using namespace std;

/*
Problem: Given a string of digits from 2 to 9 inclusive return all the possible letter combinations
         the string of digits may represent if typed on a mobile phone.

Solution: Run letterCombinations(digits)
*/
class Solution {
private:
    vector<string> adjust_answer(vector<string> strings, char digit) {
        vector<string> new_strings{};
        string new_digits = map_digit(digit);

        if (strings.size() == 0) {
            for (auto c : new_digits) {
                string s = "";
                s.push_back(c);
                new_strings.push_back(s);
            }
        }

        for (auto s : strings) {
            for (auto c : new_digits) {
                new_strings.push_back(s + c);
            }
        }

        return new_strings;
    }

    string map_digit(char d) {
        if (d == '2')
            return "abc";
        if (d == '3')
            return "def";
        if (d == '4')
            return "ghi";
        if (d == '5')
            return "jkl";
        if (d == '6')
            return "mno";
        if (d == '7')
            return "pqrs";
        if (d == '8')
            return "tuv";
        if (d == '9')
            return "wxyz";

        return "";
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans{};
        for (char digit : digits)
            ans = adjust_answer(ans, digit);
        return ans;
    }
};

