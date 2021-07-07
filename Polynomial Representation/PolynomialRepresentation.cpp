#include <bits/stdc++.h>
using namespace std;

class Term {
public:
    int coef;
    int expo;
    Term(){};
    Term(int coef, int expo) {
        this->coef = coef;
        this->expo = expo;
    }
};

class Polynomial {
private:
    int n;
    int count;
    Term *terms;

public:
    Polynomial(int n) {
        this->n = n;
        this->terms = new Term[n];
        this->count = 0;
    }

    void insertTerm(int coef, int expo) {
        if (count >= n)
            return;

        terms[count].coef = coef;
        terms[count++].expo = expo;
    }

    Polynomial *addPolynomial(Polynomial *other) {
        int i = 0;
        int j = 0;
        Polynomial *res = new Polynomial(this->n + other->n);

        while (i < n and j < other->n) {
            if (terms[i].expo > other->terms[j].expo) {
                res->insertTerm(terms[i].coef, terms[i].expo);
                i++;
            } else if (terms[i].expo < other->terms[j].expo) {
                res->insertTerm(other->terms[j].coef, other->terms[j].expo);
                j++;
            } else {
                res->insertTerm(terms[i].coef + other->terms[j].coef, other->terms[j].expo);
                i++;
                j++;
            }
        }

        return res;
    }

    void printPolynomial() {
        for (int i = 0; i < count; ++i)
            cout << terms[i].coef << "x^" << terms[i].expo << " + ";
        cout << endl;
    }
};

int main() {

    Polynomial p1(3);
    p1.insertTerm(2, 2);
    p1.insertTerm(2, 1);
    p1.insertTerm(1, 0);
    p1.printPolynomial();

    Polynomial p2(4);
    p2.insertTerm(3, 3);
    p2.insertTerm(3, 2);
    p2.insertTerm(3, 1);
    p2.insertTerm(5, 0);
    p2.printPolynomial();

    p1.addPolynomial(&p2)->printPolynomial();

    return 0;
}