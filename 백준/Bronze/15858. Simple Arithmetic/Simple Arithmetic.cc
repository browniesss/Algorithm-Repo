#include <iostream>
#include <iomanip>  // setprecision

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    double result = static_cast<double>(a) * b / c;

    cout << fixed << setprecision(10) << result << endl;

    return 0;
}