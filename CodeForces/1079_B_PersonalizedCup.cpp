#include <bits/stdc++.h>
using namespace std;

string handle;

int main() {
    cin >> handle;
    if (handle.length() <= 20) {
        cout << "1 " << handle.length() << endl;
        cout << handle << endl;
    } else if (handle.length() <= 40) {
        int row = 2, col = (handle.length()+row-1)/row;
        cout << row << " " << col << endl;
        for (int r=0; r<row; r++) {
            int j=0;
            for (int i=r*handle.length()/row; i<(r+1)*handle.length()/row; i++, j++) {
                cout << handle[i];
            }
            while (j < col) { cout << "*"; j++; }
            cout << endl;
        }
    } else if (handle.length() <= 60) {
        int row = 3, col = (handle.length()+row-1)/row;
        cout << row << " " << col << endl;
        for (int r=0; r<row; r++) {
            int j=0;
            for (int i=r*handle.length()/row; i<(r+1)*handle.length()/row; i++, j++) {
                cout << handle[i];
            }
            while (j < col) { cout << "*"; j++; }
            cout << endl;
        }
    } else if (handle.length() <= 80) {
        int row = 4, col = (handle.length()+row-1)/row;
        cout << row << " " << col << endl;
        for (int r=0; r<row; r++) {
            int j=0;
            for (int i=r*handle.length()/row; i<(r+1)*handle.length()/row; i++, j++) {
                cout << handle[i];
            }
            while (j < col) { cout << "*"; j++; }
            cout << endl;
        }
    } else if (handle.length() <= 100) {
        int row = 5, col = (handle.length()+row-1)/row;
        cout << row << " " << col << endl;
        for (int r=0; r<row; r++) {
            int j=0;
            for (int i=r*handle.length()/row; i<(r+1)*handle.length()/row; i++, j++) {
                cout << handle[i];
            }
            while (j < col) { cout << "*"; j++; }
            cout << endl;
        }
    }
}