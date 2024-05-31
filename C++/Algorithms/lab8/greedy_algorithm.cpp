#include <iostream>
#include <vector>
#include <algorithm>
struct Interval 
{
    int start;
    int end;
    bool operator<(const Interval& other) const 
    {
        return end < other.end;
    }
};
std::vector<Interval> pickIntervals(std::vector<Interval>& intervals) 
{
    std::sort(intervals.begin(), intervals.end());
    std::vector<Interval> selected;
    int lastEndTime = -1;
    for (const auto& interval : intervals) 
    {
        if (interval.start >= lastEndTime) 
        {
            selected.push_back(interval);
            lastEndTime = interval.end;
        }
    }
    return selected;
}
int main() 
{
    std::vector<Interval> intervals = 
    {
        {7, 7}, {3, 6}, {1, 3}, {3, 6}, {2, 6},
        {1, 5}, {5, 6}, {4, 4}, {2, 4}
    };
    std::vector<Interval> selected = pickIntervals(intervals);
    std::cout << "Вибрані інтервали:\n";
    for (const auto& interval : selected) 
    {
        std::cout << "|" << interval.start << "; " << interval.end << "|\n";
    }
    return 0;
}