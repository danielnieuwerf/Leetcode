#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // Dynamic Programming
        // split k into back+front
        vector<int> back(k);
        vector<int> front(k);

        int n = cardPoints.size();
        front[0] = cardPoints[0];
        back[0] = cardPoints[n - 1];

        for (int i = 1; i < k; ++i)
            front[i] = cardPoints[i] + front[i - 1];

        for (int i = 1; i < k; ++i)
            back[i] = cardPoints[n - i - 1] + back[i - 1];

        // take all from back or all from front
        int max = back[k - 1];
        if (front[k - 1] > max) {
            max = front[k - 1];
        }

        // take i+1 from back and k-(i+1) from front
        for (int i = 0; i < k - 1; ++i) {
            int y = back[i] + front[k - i - 2];
            if (y > max) {
                max = y;
            }
        }

        return max;
    }
};
