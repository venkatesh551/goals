#include <iostream>
#include <vector>
#include <cassert>

namespace utils {

    struct Interval {
        uint64_t startOffset{};
        uint64_t endOffset{};

    };

    std::ostream &  operator << (std::ostream &os, const Interval &interval) {
        os << "start = " << interval.startOffset  << " "
           << "end  = " << interval.endOffset << " ";
        return os;
    }

    /* Check Two Intervals are Overlapping or Not 
     * Returns `true` if they are overlapping, otherwise false
     */

    bool isIntervalsOverlapping(const Interval &v1, const Interval &v2) {
        return std::max(v1.startOffset, v2.startOffset) <= 
               std::min(v1.endOffset, v2.endOffset);
    }

    /* Returns Overlapped Area of two Intervals as a new Interval
     * Precondition : Intervals should Overlap
     * Postcondition : return value's startOffset <= endOffset
     */
    Interval getIntervalsOverlapArea(const Interval &v1, const Interval & v2) {
        assert(isIntervalsOverlapping(v1, v2));
        uint64_t startOffset = std::max(v1.startOffset, v2.startOffset);
        uint64_t endOffset = std::min(v1.endOffset, v2.endOffset);
        return {startOffset, endOffset};
    }

    /* Removes the `overlapped portion` from the `requested` interval and
     * returns Intervals which needs to matched
     * e.g., req = [30, 150] overlap = [40, 50] it returns 
     * {[30-39], [51-150]}
     * e.g : req = [30, 150] overlap = [30, 40] it returns [41-150]
     * e.g : req = [30, 150] overlap = [70, 150] it returns [30-69]
     * e.g : req = [60, 70] overlap = [60, 60] it returns [61, 70]
     * Precondition : Intervals should Overlap and `overlapped` should be a
     * strictly subset of `requested`
     */
    std::vector<Interval> reduceIntervalMatch(const Interval &requested,
                                              const Interval &overlapped) {
        assert(requested.startOffset <= overlapped.startOffset && 
               requested.endOffset >= overlapped.endOffset);

        if (requested.startOffset == overlapped.startOffset && 
            requested.endOffset == overlapped.endOffset) { 
            // perfect Match
            return {};
        } else if (requested.startOffset == overlapped.startOffset) { 
            // Only startOffset's are Matching
            return {Interval{overlapped.endOffset + 1, requested.endOffset}};
        } else if (requested.endOffset == overlapped.endOffset) { 
            // Only endOffset's are Matching
            assert(requested.endOffset != 0);
            return {Interval{requested.startOffset, overlapped.startOffset - 1}};
        } else if (requested.startOffset < overlapped.startOffset &&
                   requested.endOffset > overlapped.endOffset) {
            // `overlapped` is a strict subset in the requested Interval
            return { Interval{requested.startOffset, overlapped.startOffset -1},
                    Interval {overlapped.endOffset + 1, requested.endOffset}};
        } else {
            assert(false);
        }
    }
    /* Returns the List of Intervals which needs to be selected for `req` Interval.
     * v : list of intervals
     * Precondition : valid `req` interval 
     **/
    std::vector<Interval>
    findIntervals(const std::vector<Interval> &v, const Interval &req) {
    
        int idx = v.size();
        assert (req.startOffset <= req.endOffset);

        std::vector<Interval> result {}, curList = {req};
        for (auto it = v.crbegin(); it != v.crend(); ++it) {
            std::vector<Interval> nextList {};
            while (!curList.empty()) {
                const Interval &curInterval = curList.back();
                if (isIntervalsOverlapping(curInterval, *it)){
                        const Interval & overlapPortion = 
                            getIntervalsOverlapArea(curInterval, *it);
                        result.emplace_back(overlapPortion); // It needs modification
                        // debug prints
                        --idx;
                        std::cout << idx << " : " << *it << "  : " << overlapPortion << std::endl;
                        // end
                        for (const auto & ele : reduceIntervalMatch(curInterval, overlapPortion)) {
                            nextList.emplace_back(ele);
                        }
                } else {
                    nextList.emplace_back(curInterval);
                }
                curList.pop_back();
            }
            curList = std::move(nextList);
        }
        std::cout << "--------" << std::endl;
        return result;
    }


}

using namespace utils;


int main() {

    findIntervals({Interval{0, 80}, Interval{10, 150}, Interval{40, 60} }, 
                  Interval{30, 70});

    findIntervals({Interval{0, 100}, Interval{50, 200}, Interval{150, 300}, 
                  Interval{50, 100}, Interval{40, 60}},
                  Interval{30, 150});

    findIntervals({Interval{0, 100}, Interval{101, 200}, Interval{201, 300} }, 
                  Interval{50, 250});

    findIntervals({Interval{0, 200}, Interval{40, 50}, Interval{60, 80} }, 
                  Interval{80, 90});

    findIntervals({Interval{0, 100}, Interval{101, 200}}, 
                  Interval{50, 300});

    findIntervals({Interval{0, 100}}, 
                  Interval{200, 300});

    findIntervals({Interval{0, 100}}, 
                  Interval{80, 80});

    return 0;
}



