#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

class Equation {
public:
    virtual void solve() = 0;
    virtual ~Equation() {}
};

class Linear : public Equation {
private:
    double a, b;
public:
    Linear(double a, double b) {
        this->a = a;
        this->b = b;
    }
    void solve() override {
        if (a == 0) {
            if (b == 0) {
                cout << "г������ �� ���������� ������� ����'����\n";
            }
            else {
                cout << "г������ �� �� ����'����\n";
            }
        }
        else {
            double x = -b / a;
            cout << "г������ �� ���� ����'����: x = " << x << "\n";
        }
    }
};

class Quadratic : public Equation {
private:
    double a, b, c;
public:
    Quadratic(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void solve() override {
        if (a == 0) {
            Linear l(b, c);
            l.solve();
        }
        else {
            double D = b * b - 4 * a * c;
            if (D < 0) {
                cout << "г������ �� �� ������ ����'����\n";
            }
            else if (D == 0) {
                double x = -b / (2 * a);
                cout << "г������ �� ���� ������ ����'����: x = " << x << "\n";
            }
            else {
                double x1 = (-b + sqrt(D)) / (2 * a);
                double x2 = (-b - sqrt(D)) / (2 * a);
                cout << "г������ �� ��� ������ ����'����: x1 = " << x1 << ", x2 = " << x2 << "\n";
            }
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    double a, b, c;
    Equation* eq;
    do {
        cout << "������� ��� �������:\n";
        cout << "1. ˳���� ������� ax + b = 0\n";
        cout << "2. ��������� ������� ax^2 + bx + c = 0\n";
        cout << "0. �����\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "������ ����������� a � b:\n";
            cin >> a >> b;
            eq = new Linear(a, b);
            eq->solve();
            delete eq;
            break;
        case 2:
            cout << "������ ����������� a, b � c:\n";
            cin >> a >> b >> c;
            eq = new Quadratic(a, b, c);
            eq->solve();
            delete eq;
            break;
        case 0:
            cout << "�� ���������!\n";
            break;
        default:
            cout << "������� ����, ��������� �� ���\n";
        }
    } while (choice != 0);
    return 0;
}
