#include<stdlib.h>
#include<algorithm>
#include<iostream>

using namespace std;
/**
 * TASK
 * Do the internal representation of a polynomial function. You must implement the following
 * operations: addition, subtraction and multiplication User operator overloading. Use a C++ data
 * structure for storing coefficients.
 */
class polynom {
    int *coef;
    int len;
public:
    polynom(int*, int);
    polynom operator+(polynom);
    polynom operator-(polynom);
    polynom operator*(polynom);
    void print();
private:
    polynom addition(polynom, int);
    static int getValue(int *coef, int len, int index) {
        int value = 0;
        if (index < len)
            value = coef[index];
        return value;
    }
};

polynom::polynom(int *coef, int len) {
    this->len = len;
    this->coef = new int[len];
    for (int i = 0; i < len; i++) {
        this->coef[i] = coef[i];
    }
}

void polynom::print() {
    if (len > 0 && coef[0] != 0)
        cout << coef[0];
    for (int i = 1; i < len; i++) {
        int c = coef[i];
        if (c != 0) {
            if (c != 0) {
                cout << (c > -1 ? " + " : " - ");
                if (c > 1 || c < -1)
                    cout << abs(c);
            }
            cout << 'x';
            if (i > 1)
                cout << '^' << i;
        }
    }
    cout << "\n";
}

polynom polynom::addition(polynom p, int isPlus) {
    int maxLen = max(len, p.len);
    polynom result = polynom(new int[maxLen], maxLen);
    for (int i = 0; i < maxLen; i++)
        if (isPlus)
            result.coef[i] = getValue(coef, len, i) + getValue(p.coef, p.len, i);
        else
            result.coef[i] = getValue(coef, len, i) - getValue(p.coef, p.len, i);
    return result;
}

polynom polynom::operator+(polynom p) {
    return addition(p, 1);
}

polynom polynom::operator-(polynom p) {
    return addition(p, 0);
}

polynom polynom::operator*(polynom p) {
    int maxLen = len + p.len - 1;
    polynom result = polynom(new int[maxLen], maxLen);
    for (int i = 0; i < len; i++)
        for (int j = 0; j < p.len; j++)
            result.coef[i + j] += coef[i] * p.coef[j];
    return result;
}

int main() {
    int a[3] = { 3, 2, 2 };
    polynom p1 = polynom(a, 3);
    int b[4] = { 4, 6, 0, 7 };
    polynom p2 = polynom(b, 4);
    polynom psum = p1 * p2;
    psum.print();
    polynom prod = p1 * p2;
    prod.print();
}
