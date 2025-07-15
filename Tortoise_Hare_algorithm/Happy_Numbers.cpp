#include <iostream>
#include <cmath>
using namespace std;

int getNextNum (int n) {
    int sum{};
    while (n) {
        sum += (int) pow(n % 10, 2);
        n /= 10;
    }
    return sum;
}

bool isHappy (int num) {
    int slow = num;
    int fast = getNextNum(num);

    while (fast != 1) {
        slow = getNextNum(slow);
        fast = getNextNum(getNextNum(fast));

        if (fast == slow) {
            return false;
        }
    }
    return true;
}

int main () {
    int num{};

    cout << "Enter a number : " << endl;
    cin >> num;

    if (isHappy(num)) {
        cout << num << " IS a Happy Number !" << endl;
    } else {
        cout << num << " is NOT a Happy Number !" << endl;
    }
    return 0;
}