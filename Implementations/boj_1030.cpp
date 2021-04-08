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
    ���� ������ y,x ��ǥ�� �Ű������� �˻� ����,
    ó������ ��ü ������������ ���캸��, ���� ������ �ɰ���� �˻��Ѵ�.
    ���� t=0(�簢�� �ϳ�)�� ��쿡�� ���� �ܰ迡�� ��� ���� �˻縦 �ϴ� �Լ� Ư����
    ��� ������ �ƴ��� �ǹ��Ѵ�. ������ 0�� ����.
*/
int doSth(int y, int x, int t) {
    int res = 0;
    if (t == 0)
        return 0;

    //width_current = ���� �˻����� ������ ũ��
    //width_next = ���� �˻��� ������ ũ��
    int width_current = pow(n, t);
    int width_next = width_current / n;

    //���� ������ n*n���� ���� ������ ���� �� �� ��° ������ ������ �Ǵ��� ����ϴ� �κ�
    int y_partition = y / width_next;
    int x_partition = x / width_next;


    //(n - k)/2 �� 1�� ĥ������ ��� �κ��� ������
    //(n + k)/2 �� �� ����
    //���� ������ ��� �κ������� �˻��ϴ� �κ�, �� �� ������ ����� �� �͵� ���� 1�̰�, �׷��� ������ ������ �������� �˻� 
    if (x_partition >= (n - k) / 2 &&
        x_partition < (n + k) / 2 &&
        y_partition >= (n - k) / 2 &&
        y_partition < (n + k) / 2) {
        return 1;
    }

    //x Ȥ�� y % width_next�� ���� �˻��� �������� x Ȥ�� y�� �� �������� � ������ ������ ���� ����
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