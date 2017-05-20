/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> res = new ArrayList<Interval>();
        int i = 0, length = intervals.size();
        while(i < length && intervals.get(i).end < newInterval.start){
            res.add(intervals.get(i++));
        }
        while(i < length && intervals.get(i).start <= newInterval.end){
            newInterval = new Interval(
                Math.min(intervals.get(i).start, newInterval.start),
                Math.max(intervals.get(i).end, newInterval.end)
            );
            i++;
        }
        res.add(newInterval);
        while(i < length)   res.add(intervals.get(i++));
        return res;
    }
}