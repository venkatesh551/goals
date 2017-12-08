#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cstring>
#include <map>


std::map<std::string, std::string> book_mapping;

struct Book{

    Book(){}
    Book(const std::string &auth, const std::string &titl):
        author(auth), title(titl) {
    }

    bool operator()(const Book &p, const Book &q) {
        if (p.author == q.author) {
            return p.title < q.title;
        } else{
            return p.author < q.author;
        }
    }

    std::string author;
    std::string title;

};

bool startswith(std::string &str, std::string word) {

    int len = word.length();
    int n   = str.length();
    if (n < len) {
        return false;
    }
    return memcmp(str.data(), word.data(), len) == 0;
}

void printBookList(const std::vector<Book> &book_lst) {

    for (const auto &ele: book_lst) {
        std::cout << ele.author << ", " << ele.title << std::endl;
    }
}

void printBooksOrder(std::vector<Book> &book_lst, std::vector<std::string> &lst) {

    std::vector<Book> return_items;
    for (const auto & title: lst) {
        return_items.emplace_back(book_mapping[title], title);
    }
    std::sort(return_items.begin(), return_items.end(), Book());

    for (const auto &ele: return_items) {
        auto it_pos = std::lower_bound(book_lst.begin(), book_lst.end(),
                                       ele, Book());
        if (it_pos == book_lst.begin()) {
            std::cout << "Put " << ele.title << " first" << std::endl;
        } else {
            std::cout << "Put " << ele.title << " after " << 
                      (*it_pos).title << std::endl;
        }
    }
    std::cout << "END\n";
}

int main() {

    std::vector<Book> book_lst;
    std::string line;
    std::string author, title;

    while (true) {
        std::getline(std::cin, line);
        if (line == "END") {
            break;
        }
        /* split here */
        int len = line.length();
        int pos = line.find_last_of('"', len);
        title = line.substr(0, pos+1);
        author = line.substr(pos+5);
        book_lst.emplace_back(author, title);
        book_mapping[title] = author;
    }

    std::sort(book_lst.begin(), book_lst.end(), Book());
    std::vector<std::string> return_list;
    std::string book_name;

    while (true) {
        std::getline(std::cin, line);
        if (line == "SHELVE") {
            printBooksOrder(book_lst, return_list);
            return_list.clear();
        }
        else if (startswith(line, "RETURN")) {

            int len = line.length();
            int pos = line.find_first_of('"', 0);
            book_name = line.substr(pos);
            return_list.emplace_back(book_name);
        }
        else if (line == "END") {
            return 0;
        }
    }

    return 0;
}



