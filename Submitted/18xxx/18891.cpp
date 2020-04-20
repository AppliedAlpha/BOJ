#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct party {
    string name;
    int ri, vote, total;
    double rate, prop_rate, p1, p2, p3, p2_rate, p3_rate;
    bool prop_able;
};

struct t {
    double value;
    int index;
};

bool tcomp(const t &a, const t &b) {
    return a.value > b.value;
}

bool pcomp(const party &a, const party &b) {
    if (a.total != b.total) return a.total > b.total;
    else return a.name < b.name;
}

int p, v, non_ri, non_vote;
int prop_vote_total = 0, p1_total = 0;
int non_seat = 300;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> p >> v;
    non_ri = 253;
    non_vote = v;
    vector<party> vp(p);
    for (auto & i : vp) {
        cin >> i.name >> i.ri >> i.vote;
        non_ri -= i.ri;
        non_vote -= i.vote;
    }
    non_seat -= non_ri;

    for (auto & i : vp) {
        i.rate = (double)i.vote / (v - non_vote);
        if (i.rate >= 0.03 || i.ri >= 5) {
            i.prop_able = true;
            prop_vote_total += i.vote;
        }
        else non_seat -= i.ri;
    }

    for (auto & i : vp) {
        if (i.prop_able) {
            i.prop_rate = (double)i.vote / prop_vote_total;
            i.p1 = ((double)non_seat * i.prop_rate - i.ri) / 2;
            i.p1 = ((i.p1 < 1) ? 0 : round(i.p1));
            p1_total += (int)i.p1;
        }
    }

    if (p1_total < 30) {
        vector<t> temp;
        int p2_total = 0;
        for (int i=0; i<vp.size(); i++) {
            if (vp[i].prop_able) {
                vp[i].p2_rate = (30 - p1_total) * vp[i].rate;
                vp[i].p2 = vp[i].p1;
                vp[i].p2 += (int) vp[i].p2_rate;
                p2_total += vp[i].p2;
                vp[i].p2_rate -= (int) vp[i].p2_rate;
                temp.push_back({vp[i].p2_rate, i});
            }
        }
        sort(temp.begin(), temp.end(), tcomp);
        for (auto i : temp) {
            if (p2_total < 30) {
                vp[i.index].p2++;
                p2_total++;
            }
            else break;
        }
    }
    else if (p1_total > 30) {
        vector<t> temp;
        int p2_total = 0;
        for (int i=0; i<vp.size(); i++) {
            if (vp[i].prop_able) {
                vp[i].p2_rate = (30 * vp[i].p1) / p1_total;
                vp[i].p2 += (int) vp[i].p2_rate;
                p2_total += vp[i].p2;
                vp[i].p2_rate -= (int) vp[i].p2_rate;
                temp.push_back({vp[i].p2_rate, i});
            }
        }
        sort(temp.begin(), temp.end(), tcomp);
        for (auto i : temp) {
            if (p2_total < 30) {
                vp[i.index].p2++;
                p2_total++;
            }
            else break;
        }
    }
    else for (auto & i : vp) i.p2 = i.p1;

    vector<t> temp2;
    int p3_total = 0;
    for (int i=0; i<vp.size(); i++) {
        if (vp[i].prop_able) {
            vp[i].p3_rate = 17 * vp[i].prop_rate;
            vp[i].p3 += (int) vp[i].p3_rate;
            p3_total += vp[i].p3;
            vp[i].p3_rate -= (int) vp[i].p3_rate;
            temp2.push_back({vp[i].p3_rate, i});
        }
    }
    sort(temp2.begin(), temp2.end(), tcomp);
    for (auto i : temp2) {
        if (p3_total < 17) {
            vp[i.index].p3++;
            p3_total++;
        }
        else break;
    }

    for (auto & i : vp) {
        i.total = i.ri + i.p2 + i.p3;
    }

    sort(vp.begin(), vp.end(), pcomp);

    for (auto i : vp) {
        cout << i.name << ' ' << i.total << '\n';
    }

    return 0;
}