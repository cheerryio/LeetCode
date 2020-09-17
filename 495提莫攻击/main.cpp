
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
    * 1. 对timeSeries只有一个元素，返回duration
    * 2. 对timeSeries有两个以上元素，一个指针指向i，一个指向i+1，如果*(i+1)-*i<duration，time+=*(i+1)-*i
    *    否则加duration。如果此时i+1是timeSeries.end()，time+=duration,返回time
    */
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0)
            return 0;
        if (timeSeries.size() == 1)
            return duration;
        vector<int>::iterator front = timeSeries.begin();
        vector<int>::iterator back = front+1;
        int time = 0;
        while (back != timeSeries.end()) {
            if (*back - *front < duration)
                time += *back - *front;
            else
                time += duration;
            front++;
            back++;
        }
        time += duration;
        return time;
    }
};

int main() {
    vector<int> timeSeries = { 1,4 };
    int duration = 2;
    Solution a;
    int time = a.findPoisonedDuration(timeSeries, duration);
    cout << "time is:" << time << endl;
    return 0;
}