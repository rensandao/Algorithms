/*
Author: rensandao
Source: https://github.com/rensandao/Algorithms/new/master/Introduction%20to%20Algorithms
First Created: 2019-04-08
*/
#include <iostream>
#include "FindMaxSubArray.h"
#include <vector>
using namespace std;
using namespace AL;

int main()
{
    cout << "Hello world!" << endl;

    int A[] = {13, -2, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int high = sizeof(A) / sizeof(int) -1;

    vector<int> result = FindMaxSubArray(A, 0, high);

    for (size_t i=0; i<result.size(); i++) {
        cout << result[i] << " " << endl;
    }

    return 0;
}
