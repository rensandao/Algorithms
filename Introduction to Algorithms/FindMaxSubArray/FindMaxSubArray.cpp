/*
Author: rensandao
Source: https://github.com/rensandao/Algorithms/edit/master/Introduction%20to%20Algorithms/FindMaxSubArray.cpp
First Created: 2019-04-07
*/

/*
利用分支策略求解最大子数组的问题。
所谓最大子数组：即给定一个数组A[low..high]，其元素有正有负值，找到和为最大的元素组合。
有很多实际问题都可以转化为这样的问题，比如：
《算法导论》中提到的模拟计算买卖股票的时机，因为现实中并非仅仅在最高点买最低点卖的策略最赚；

1.通常将实际问题变换为类似求解最大(连续)子数组的形式的问题；
2.利用分治策略步骤：分解-解决-合并。
分支技术首先意味着划分为两个规模尽量相等的子数组。即中央位置mid.然后再考虑求解两个子数组A[low..mid]和A[mid+1..high]
此时，A[low..high]的任何连续子数组A[i..j]所处的位置必然是属于三种情况之一：
1)完全位于子数组A[low..mid]中，因此low <= i <= j <= mid;
2)完全位于子数组A[mid+1..high]中，因此mid< i <= j <= high;
3)跨越了中点，因此low <= i <= mid < j <= high。

即最大子数组必然是此三种情况之一。

而A[low..mid]和A[mid+1..high]这两个子问题仍是最大数组问题，规模减小。因此可以递归求解。
那么，剩下的重要工作就是找到第3种情况的最大子数组，然后在三种情况中比较得到最大者。

注：比较的结果可能有多组和的结果一样的。可以保存
可用数组或vector
用数组容易出错。
*/

#include "FindMaxSubArray.h"
#include <climits>
#include <vector>

using namespace std;
using namespace AL;

vector<int> AL::FindMaxCrossingSubArray(int A[], int low, int high, int mid) {
    int left_sum = INT_MIN;
    int sum1 = 0, max_left = 0;

    for (int i=mid; i>=low; i--) {
        sum1 += A[i];
        if (sum1 > left_sum) {
            left_sum = sum1;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    int sum2 = 0, max_right = 0;
    for (int j=mid+1; j<=high; j++) {
        sum2 += A[j];
        if (sum2 > right_sum) {
            right_sum = sum2;
            max_right = j;
        }
    }

    vector<int> a = {max_left, max_right, left_sum + right_sum};
    return a;
}

//递归， 考虑三种基本情况的结果比较。
//返回结果，三个数值：max_left, max_right, sum
vector<int> AL::FindMaxSubArray(int A[], int low, int high) {
    vector<int> left_res, right_res, cross_res, final_res;

    if (low == high) {
        final_res = {low, high, A[low]};

    } else {

        int mid = (low + high) / 2;
        //left
        left_res = FindMaxSubArray(A, low, mid);
        //right
        right_res = FindMaxSubArray(A, mid+1, high);

        //cross
        cross_res = FindMaxCrossingSubArray(A, low, high, mid);

        int left_sum = left_res[2];
        int right_sum = right_res[2];
        int cross_sum = cross_res[2];

        if (left_sum >= right_sum && left_sum >= cross_sum) {
            final_res = left_res;
        } else if (right_sum >= left_sum && right_sum >= cross_sum) {
            final_res = right_res;
        } else {
            final_res = cross_res;
        }
    }

    return final_res;
}
