#include <iostream>
#include <memory>

int f() {
    return 0;
}

class Test {

private:
    const std::shared_ptr<std::string> s{std::make_shared<std::string>()};

};

int g()
{
    int f;
    // f();
    return ::f();
}


int main() {






    return 0;
}
