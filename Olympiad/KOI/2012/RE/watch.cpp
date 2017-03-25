#include <iostream>
using namespace std;

int main() {
    int hour, minute;
    int duration_in_min;
    cin >> hour >> minute;
    cin >> duration_in_min;
    minute += duration_in_min;
    hour += minute / 60;
    minute %= 60;
    hour %= 24;
    cout << hour << ' ' << minute << endl;
}
