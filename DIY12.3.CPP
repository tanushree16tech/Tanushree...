#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    const vector<int> values = {1, 2, 3, 4, 5};

    const long long product =
        accumulate(values.begin(), values.end(), 1LL,
                   [](long long result, int value) {
                       return result * value;
                   });

    const int evenSum =
        accumulate(values.begin(), values.end(), 0,
                   [](int sum, int value) {
                       return value % 2 == 0 ? sum + value : sum;
                   });

    cout << "Product: " << product << endl;
    cout << "Sum of even values: " << evenSum << endl;

    return 0;
}