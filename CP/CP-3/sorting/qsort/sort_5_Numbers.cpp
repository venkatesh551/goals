#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

/*
 https://cs.stackexchange.com/questions/44981/least-number-of-comparisons-needed-to-sort-order-5-elements/44982#44982
 
    Sort the first two pairs.
    Order the pairs w.r.t. their respective larger element.

    Call the result [a,b,c,d,e]; we know a<b<d and c<d

    First Insert e into [a,b,d] , 
    Next Insert c into the result of step 3.

    (Note :If we insert c then e, it increases no of comparisons)

    The first step clearly takes two comparisons, the second only one.
    The last two steps take two comparisons each;

    we insert into a three-element list in both cases and compare 
    with the middle element first. That makes a total of seven comparisons.

*/

void printVector(std::vector<int> &v)
{
    for (const auto ele: v) {
        std::cout << ele << " ";
    }
    std::cout << "\n";

}

int sort_5_elements(std::vector<int> &v) {

    if (v[0] > v[1]) {
        std::swap(v[0], v[1]);
    }
    if (v[2] > v[3]) {
        std::swap(v[2], v[3]);
    }
    if (v[1] > v[3]) {
        std::swap(v[0], v[2]);
        std::swap(v[1], v[3]);
    }
    std::vector<int> temp;
    // v[2] < v[3], insert v[4] into v[0] < v[1] < v[3]  
    if (v[4] < v[1]) {
        if (v[4] < v[0]) {
            temp = {v[4], v[0], v[1], v[3]};
        } else {
            temp = {v[0], v[4], v[1], v[3]};
        }
    } else {
        if (v[4] < v[3]) {
            temp = {v[0], v[1], v[4], v[3]};
        } else {
            temp = {v[0], v[1], v[3], v[4]};
        }
    }
    int c = v[2];
    if (c < temp[1]) {
        if ( c < temp[0]) {
            v = {c, temp[0], temp[1], temp[2], temp[3]};
        } else {
            v = {temp[0], c, temp[1], temp[2], temp[3]};
        }
    } else {
        if (c < temp[2]) {
            v = {temp[0], temp[1], c, temp[2], temp[3]};
        }
        else {
            v = {temp[0], temp[1], temp[2], c, temp[3]};
        }
    }

}


int main() {

    std::vector<int> v = {1, 2, 3, 5, 4};
    std::vector<int> result = {1, 2, 3, 4, 5};
    do {
        std::vector<int> input(v);
        sort_5_elements(input);
        assert(input == result);
    } while (std::next_permutation(v.begin(), v.end()));

    return 0;
}




