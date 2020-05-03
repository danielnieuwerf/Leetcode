#include <string>
#include <iostream>
using namespace std;

class Solution {

public:
    string longestPalindrome(string s) {
        // deal with small strings size 0 and 1
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int max = 1;    // maximum palindromic substring length

        // expand around the centre
        string centre{};    // centre of substrings being tested
        string maxStr{};    // store maximum palindromic substring here

        // centre size 1
        for (int i = 0; i < n; ++i) {
            centre = s[i];
            int loops = 1;
            int length = 1;

            while (i - loops >= 0 && i + loops < n && s[i - loops] == s[i + loops]) {
                length += 2;
                ++loops;
            }

            if (length > max) {
                max = length;
                maxStr = s.substr(i + 1 - loops, length);
            }
        }

        // centre size 2
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                centre = s.substr(i, 2);
                int loops = 1;
                int length = 2;

                while (i - loops >= 0 && i + loops + 1 < n && s[i - loops] == s[i + loops + 1]) {
                    length += 2;
                    ++loops;
                }

                if (length > max) {
                    max = length;
                    maxStr = s.substr(i + 1 - loops, length);
                }
            }
        }

        // return max string
        if (max == 1)
            return s.substr(0, 1);

        return maxStr;
    }
};