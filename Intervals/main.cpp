#include <iostream>
#include <vector>
#include "merge.cpp"
using namespace std;


void schedule(Interval* A, int n)
{
    mergeSort(A, 0, n, 0);
    vector<Interval> S;
    for (int i = 0; i < n; ++i) {
        bool fine = true;
        for (int j = 0; j < S.size(); ++j) {
            if (A[i].s > S[j].f) continue;
            fine = false;
        }
        if (fine) {
            S.push_back(A[i]);
            cout << A[i].s << " - " << A[i].f << endl;
        }
    }  
}

/*void colour(Interval* A, int n) {
    mergeSort(A, 0, n, 1);
}*/

int main () {
    cout << "Input number of intervals" << endl;
    int n;
    cin >> n;
    Interval intervals[n];
    cout << "Input intervals" << endl;
    for (int i = 0; i < n; ++i) {
        int start, fin;
        cin >> start >> fin;
        intervals[i] = {start, fin};
    }

    cout << "Options: s - Schedule Intervals, c - Colour Intervals" << endl;
    char op;
    switch (op)
    {
        case 's':
            schedule(intervals, n);
            break;
        case 'c':
            //colour(intervals);
            break;
    }
}