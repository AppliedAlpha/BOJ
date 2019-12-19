#include <iostream>
using namespace std;
int a, b, v;

int main() {
    cin >> a >> b >> v;
    cout << (v-a) / (a-b) + (((v-a) % (a-b)) ? 2 : 1);
}