#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<long long int> book;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        long long int buf;
        cin >> buf;
        book.push_back(buf);
    }
    if (n == 2) {
        if (book[0] != 1) 
            cout << "1";
        else 
            cout << "2";
    } else if (n == 3) {
        if (book[0] - (book[1] - book[0]) >= 1) 
            cout << book[0] - (book[1] - book[0]);
        else if ((book[1] - book[0]) % 2 == 0) 
            cout << (book[0] + book[1]) / 2;
        else 
            cout << book[1] + (book[1] - book[0]);
    } else {
        long long int d = book[1] - book[0];
        for (int i = 2; i < n - 1; i++) {
            if (book[i] - book[i-1] != d) {
                if (book[i] - book[i-1] == 2 * d) 
                    cout << (book[i] + book[i-1]) / 2;
                else 
                    cout << (book[0] + book[1]) / 2;
                break;
            }
            if (i == n - 2) {
                if (book[0] - d >= 1) 
                    cout << book[0] - d;
                else 
                    cout << book[n-2] + d;
            }
        }
    }
    cout << "\n";
}