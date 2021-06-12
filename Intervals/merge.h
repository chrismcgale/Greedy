#include <iostream>
#include <vector>
using namespace std;

struct Interval
{
    int s, f;
};

void mergeSort(Interval *&A, int l, int r, int mode);