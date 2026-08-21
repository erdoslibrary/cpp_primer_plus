#include <iostream>

// 1. 기본 클래스 템플릿
template <typename T, typename U>
class PairPrinter {
public:
    void print() {
        std::cout << "Generic template" << std::endl;
    }
};

// 2. 부분 특수화: 두 번째 타입이 int 인 경우
template <typename T>
class PairPrinter<T, int> {
public:
    void print() {
        std::cout << "Partial specialization (int)" << std::endl;
    }
};

// 3. 부분 특수화: 두 타입 모두 포인터 타입인 경우
template <typename T, typename U>
class PairPrinter<T*, U*> {
public:
    void print() {
        std::cout << "Partial specialization (pointer)" << std::endl;
    }
};

// 4. 완전 특수화: <double, double>인 경우
template <>
class PairPrinter<double, double> {
public:
    void print() {
        std::cout << "Full specialization (double, double)" << std::endl;
    }
};

int main() {
    PairPrinter<double, char> p1;
    PairPrinter<double, int> p2;
    PairPrinter<int, int> p3;
    PairPrinter<int*, int*> p4;

    p1.print();
    p2.print();
    p3.print();
    p4.print();
    return 0;
}