#include <iostream>

int main() {


    try {

        throw "msg";

    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }



    return 0;
}


