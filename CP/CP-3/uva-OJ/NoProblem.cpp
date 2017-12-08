#include <iostream>
#include <vector>

constexpr int NUM_MONTHS = 12;

void readVector(std::vector<int> &v) {

    for (int i = 0; i < NUM_MONTHS; ++i) {
        std::cin >> v[i];
    }
}

void printEachMonthReport(std::vector<int> &created,
                          std::vector<int> &required,
                          int start) {
    for (int i = 0; i < NUM_MONTHS; i++) {
        if(start >= required[i]) {
            std::cout << "No problem! :D" << std::endl;
            start -= required[i];
        } else {
            std::cout << "No problem. :(" << std::endl;
        }
        start += created[i];
    }

}

int main()
{

    int s;
    std::vector<int> created(NUM_MONTHS), required(NUM_MONTHS);
    int counter = 1;
    while (std::cin >> s && s >= 0) {
        readVector(created);
        readVector(required);
        std::cout << "Case " << counter++ << ":" << std::endl;
        printEachMonthReport(created, required, s);
    }






    return 0;
}
