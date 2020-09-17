
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
    * 1. ��timeSeriesֻ��һ��Ԫ�أ�����duration
    * 2. ��timeSeries����������Ԫ�أ�һ��ָ��ָ��i��һ��ָ��i+1�����*(i+1)-*i<duration��time+=*(i+1)-*i
    *    �����duration�������ʱi+1��timeSeries.end()��time+=duration,����time
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