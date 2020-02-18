#include <iostream>
#include <string>
using namespace std;

/*
              U
           0  1  2
           3  4  5
           6  7  8
 L        __________    R            B
 36 37 38|F18 19 20 | 45 46 47 | 27 28 29
 39 40 41| 21 22 23 | 48 49 50 | 30 31 32
 42 43 44| 24 25 26 | 51 52 53 | 33 34 35
         -----------
           9 10 11
          12 13 14
          15 16 17
          D
*/

enum FACE{U, D, F, B, L, R, SIZE};
char init[7] = "wyrogb";
char arr[55];
int conv[256];
int cube[SIZE][3][3];
char temp[3][3];

int rot[6][12] = {
        {36,37,38,18,19,20,45,46,47,27,28,29},        //U
        {33,34,35,51,52,53,24,25,26,42,43,44},        //D
        {6,7,8,44,41,38,11,10,9,45,48,51},            //F
        {2,1,0,53,50,47,15,16,17,36,39,42},           //B
        {0,3,6,35,32,29,9,12,15,18,21,24},            //L
        {8,5,2,26,23,20,17,14,11,27,30,33}            //R
};

void rotate(FACE f,int cnt){
    char que[12];
    while (cnt--) {
        for (int i = 0; i < 12; i++)
            que[i] = arr[rot[f][i]];
        for (int i = 0; i < 12; i++)
            arr[rot[f][i]]= que[(i + 3) % 12];
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
                temp[j][2-i] = arr[cube[f][i][j]];
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
                arr[cube[f][i][j]] = temp[i][j];
    }
}

void cubing() {
    int n;
    cin >> n;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            arr[i*9+j] = init[i];
        }
    }
    while (n--) {
        string in;
        cin >> in;
        int f = conv[in[0]], cnt = conv[in[1]];
        rotate((FACE)f, cnt);
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) cout << arr[cube[0][i][j]];
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r;
    cin >> r;
    conv['-'] = 3;
    conv['+'] = 1;
    conv['U'] = U;
    conv['D'] = D;
    conv['F'] = F;
    conv['B'] = B;
    conv['L'] = L;
    conv['R'] = R;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                cube[i][j][k] = i*9 + j*3 + k;
    while (r--) cubing();
    return 0;
}