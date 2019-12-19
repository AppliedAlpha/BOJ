#include <iostream>
#include <vector>
using namespace std;

long long sum(std::vector<int> &a) {
    long long s = 0;
    for (auto & n : a) s += n;
    return s;
}

int main() {
    return 0;
}