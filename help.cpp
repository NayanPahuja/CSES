#include <iostream>
using namespace std;

class Math {
public:
    // Overloaded functions for different parameter types
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Math math;
    cout << "Add two integers: " << math.add(5, 10) << endl;
    cout << "Add two doubles: " << math.add(3.2, 4.4) << endl;
    cout << "Add three integers: " << math.add(1, 2, 3) << endl;
    return 0;
}
