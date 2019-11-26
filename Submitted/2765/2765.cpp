#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846264338
using namespace std;

int main() {
    double d, t;
    int r, c = 1;
    cin >> d >> r >> t;
    while (r) {
        double di = d * r * M_PI / 63360;
        printf("Trip #%d: %.2lf %.2lf\n",
               c, round(di*100)/100, round(di*360000/t)/100);
        c++;
        cin >> d >> r >> t;
    }
}