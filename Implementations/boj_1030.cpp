#include <iostream>
using namespace std;
int s, n, k, r1, r2, c1, c2;

int pow(int num, int x) {
    int res = 1;
    while (x--) {
        res *= num;
    }
    return res;
}

/*
    영역 범위의 y,x 좌표를 매개변수로 검색 수행,
    처음에는 전체 영역기준으로 살펴보고, 점차 영역을 쪼개어가며 검색한다.
    만약 t=0(사각형 하나)의 경우에는 이전 단계에서 가운데 여부 검사를 하는 함수 특성상
    가운데 지점이 아님을 의미한다. 때문에 0을 리턴.
*/
int doSth(int y, int x, int t) {
    int res = 0;
    if (t == 0)
        return 0;

    //width_current = 현재 검색중인 영역의 크기
    //width_next = 다음 검색할 영역의 크기
    int width_current = pow(n, t);
    int width_next = width_current / n;

    //현재 영역을 n*n개의 다음 영역을 나눌 때 몇 번째 영역에 포함이 되는지 계산하는 부분
    int y_partition = y / width_next;
    int x_partition = x / width_next;


    //(n - k)/2 는 1로 칠해지는 가운데 부분의 시작점
    //(n + k)/2 는 그 끝점
    //현재 영역의 가운데 부분인지를 검색하는 부분, 둘 다 영역의 가운데면 볼 것도 없이 1이고, 그렇지 않으면 영역을 좁혀가며 검사 
    if (x_partition >= (n - k) / 2 &&
        x_partition < (n + k) / 2 &&
        y_partition >= (n - k) / 2 &&
        y_partition < (n + k) / 2) {
        return 1;
    }

    //x 혹은 y % width_next는 다음 검색할 영역에서 x 혹은 y가 그 영역에서 어떤 변위를 가지는 지를 말함
    else {
        return res |= doSth(y % width_next, x % width_next, t - 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            cout << doSth(i, j, s);
        }
        cout << endl;
    }
    return 0;
}