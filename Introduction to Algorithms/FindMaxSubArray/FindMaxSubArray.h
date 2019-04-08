#ifndef FINDMAXSUBARRAY_H
#define FINDMAXSUBARRAY_H

#include <vector>

namespace AL {

    std::vector<int> FindMaxCrossingSubArray(int A[], int low, int high, int mid);
    std::vector<int> FindMaxSubArray(int A[], int low, int high);

}

#endif // FINDMAXSUBARRAY_H
