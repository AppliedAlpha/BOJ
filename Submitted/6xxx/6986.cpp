#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, cnt = 0;
    double cut, prec, tmp;
    cin >> n >> k;

    auto *score = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        score[i] = (int)(tmp*10);
        cnt += score[i];
    }
    sort(score, score + n);
    for (int i = 0; i < k; i++) cnt -= (score[i] + score[n - 1 - i]);
    double ct = cnt;
    ct /= 10;
    double ctp = k * (score[k] + score[n - k - 1]);
    ctp /= 10;
    cut = round(ct / (n - 2 * k) * 100) / 100;
    prec = round((ct + ctp) / n * 100) / 100;

    cout << fixed;
    cout.precision(2);
    cout << cut << '\n' << prec;
    delete[] score;
}