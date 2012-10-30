#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include <vector>

using namespace std;

/**
 * TASK
 * Do the internal representation of a polynomial function. You must implement the following
 * operations: addition, subtraction and multiplication User operator overloading. Use a arrays for
 * storing coefficients.
 */

class polynom {
public:
    vector<int> coef;
    polynom();
    polynom operator+(polynom);
    polynom operator-(polynom);
    polynom operator*(polynom);
    void print();
private:
    polynom addition(polynom, int);
    static int getValue(vector<int> coef, int index) {
        int value = 0;
        if (index < coef.size())
            value = coef[index];
        return value;
    }
};

polynom::polynom() {
}

void polynom::print() {
    int len = coef.size();
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
    int maxLen = max(coef.size(), p.coef.size());
    polynom result = polynom();
    for (int i = 0; i < maxLen; i++)
        if (isPlus)
            result.coef.push_back(getValue(coef, i) + getValue(p.coef, i));
        else
            result.coef.push_back(getValue(coef, i) - getValue(p.coef, i));
    return result;
}

polynom polynom::operator+(polynom p) {
    return addition(p, 1);
}

polynom polynom::operator-(polynom p) {
    return addition(p, 0);
}

polynom polynom::operator*(polynom p) {
    int len = coef.size();
    int len2 = p.coef.size();
    int maxLen = len + len2 - 1;
    polynom result = polynom();
    for (int i = 0; i < maxLen; i++)
        result.coef.push_back(0);
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len2; j++)
            result.coef[i + j] += coef[i] * p.coef[j];
    return result;
}

int main() {
    polynom p1 = polynom();
    p1.coef.push_back(3);
    p1.coef.push_back(2);
    p1.coef.push_back(2);
    polynom p2 = polynom();
    p2.coef.push_back(4);
    p2.coef.push_back(6);
    p2.coef.push_back(0);
    p2.coef.push_back(7);
    polynom psum = p1 + p2;
    psum.print();
    polynom pprod = p1 + p2;
    pprod.print();
}
