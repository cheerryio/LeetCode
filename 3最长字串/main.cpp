#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <deque>
#include <limits>
#include <algorithm>

using namespace std;

/*
* 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

*/

/*
* 第一个指针，指向结果不重复字符串开头的位置
* 第二个指针指向结果不重复字符串末尾的位置，他要一直移动，希望不要找到重复字符串
* 第三个指针在第二个指针每找到一个字符就遍历已经找到的字符看有没有重复的，如果有，记录下这个最长的长度，然后
* 让第一个指针指向现在第三个指针所在的位置，继续上面的步骤
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2)
            return s.size();
        string::iterator start=s.begin(), end, i;
        int length = 0;
        int maxLength = 0;
        bool repeat = false;
        end = start;
        while (end != s.end()) {
            if (end == start) {
                length++;
                end++;
                continue;
            }
            repeat = false;
            for (i = start; i < end; i++) {
                if (*i == *end) {
                    repeat = true;
                    break;
                }
            }
            if (repeat) {
                start = i + 1;
                end++;
                maxLength = max(maxLength, length);
                length = end-start;
            }
            else {
                length++;
                end++;
            }
        }
        return max(maxLength,length);
    }
};

int main() {
    string s = "dvdf";
    Solution a;
    int length = a.lengthOfLongestSubstring(s);
    cout << length << endl;
	return 0;
}