#include <stdio.h>
int arr[100][100];
void put_rect(int i, int j) {
    int k, p;
    int tmp = j;
    for (k = 0; k < 10; k++) {
        j = tmp;
        for(p = 0; p < 10; p++) {
            arr[i][j] = 1;
            j++;
        }
        i++;
    }
}
int calc_rect_size()
{
    int i, j, cnt = 0;
    for(i = 0; i < 100; i++)
        for(j = 0; j < 100; j++)
            if( arr[i][j] )
                cnt++;
    return cnt;
}

int main(int argc, char* argv[]) {
    int i, num, tmp1, tmp2;
    scanf("%d", &num);
    for(i = 0; i < num; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        put_rect(tmp1, tmp2);
    }
    printf("%d\n", calc_rect_size());
}
