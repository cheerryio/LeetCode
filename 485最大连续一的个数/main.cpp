
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int x = 0, max = 0;
        enum State {free,working};
        State state = free;
        for (vector<int>::iterator i = nums.begin(); i < nums.end(); i++) {
            if (*i == 1) {
                switch (state) {
                case free:
                    state = working;
                    x += 1;
                    break;
                case working:
                    x += 1;
                    break;
                default:
                    break;
                }
            }
            else {
                switch (state) {
                case free:
                    break;
                case working:
                    max = (x > max ?x : max);
                    x = 0;
                    state = free;
                    break;
                default:
                    break;
                }
            }
        }
        max = (x > max ? x : max);
        return max;
    }
};

int main() {
    Solution a;
    vector<int> nums{ 1,1,0,1,1,1 };
    int r = a.findMaxConsecutiveOnes(nums);
    cout << r << endl;
    return 0;
}