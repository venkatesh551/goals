#include <iostream>
#include <queue>
#include <stack>

class Transaction {

    private:
        std::string name;
        std::string date;
        double value;

    public:
        Transaction(std::string &n, std::string &d, double v) :
            name(n), date(d), value(v) {

        }
        Transaction(const Transaction &p) {
            name = p.name;
            date = p.date;
            value = p.value;
        }

        bool operator > (const Transaction &p, const Transaction &q) {
            return p.value > q.value;
        }

        std::ostream & operator << (std::ostream &ofs, const Transaction &t) {
            return ofs << t.name << " " << t.date << " " << t.value << "\n";
        }

};

int main(int argc, char *argv[]) {

    int m = atoi(argv[1]);
 
    std::priority_queue<Transaction, std::vector<Transaction>, std::greater<Transaction> > minPQ;

    std::string name, date;
    double val;
    while (true) {
        std::cin >> name >> date >> val;
        if (std::cin.eof()) {
            break;
        }
        minPQ.insert(Transaction(name, date, val));
        if (minPQ.size() > m) {
            minPQ.pop();
        }
    }
    std::stack<Transaction> st;
    while (!minPQ.empty()) {
        st.push(minPQ.top());
        minPQ.pop();
    }
    for (const Transaction t : st) {
        std::cout << t ;
    }

    return 0;
}


