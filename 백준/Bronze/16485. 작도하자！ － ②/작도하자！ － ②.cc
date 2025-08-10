#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double c, b;
    cin >> c >> b;
    cout << fixed << setprecision(10) << c / b << "\n";
    return 0;
}
