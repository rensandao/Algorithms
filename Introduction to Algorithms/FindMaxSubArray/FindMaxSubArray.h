#ifndef FINDMAXSUBARRAY_H
#define FINDMAXSUBARRAY_H

#include <vector>

namespace AL {
class Solution001 {
    std::vector<int> FindMaxCrossingSubArray(int A[], int low, int high, int mid);
    std::vector<int> FindMaxSubArray(int A[], int low, int high);
}
    
class Solution002 {
    std::vector<int> FindMaxCrossingSubArray(int A[], int low, int high, int mid);
    std::vector<int> FindMaxSubArray(int A[], int high);
}
    
}

#endif // FINDMAXSUBARRAY_H
