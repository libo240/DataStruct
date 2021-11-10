#ifndef SORT_H
#define SORT_H

#include <vector>

class Sort
{
public:
    Sort();

    static std::vector<int> BubbleSort(std::vector<int> &vctRaw);

    static std::vector<int> SelectSort(std::vector<int> &vctRaw);

    //插入排序
    static std::vector<int> InsertSort(std::vector<int> &vctRaw);

    //希尔排序
    static std::vector<int> ShellSort(std::vector<int> &vctRaw);

    //堆排序
    static std::vector<int> HeapSort(std::vector<int> &vctRaw);

    //归并排序
    static std::vector<int> MergeSort(std::vector<int> &vctRaw);

    //快速排序
    static std::vector<int> QuickSort(std::vector<int> &vctRaw);


private:
    static void PercDown(std::vector<int> &vctRaw, int imin, int imax);

    static void MSort(std::vector<int> &vctRaw, std::vector<int> &vctRet, int iLeft, int iRight);
    static void Merge(std::vector<int> &vctRaw, std::vector<int> &vctRet,
                      int Lpos, int Rpos, int RightEnd);

    static void Qsort(std::vector<int> &vctRaw, int iLeft, int iRight);

    static int Median3(std::vector<int> &vctRaw, int iLeft, int iRight);

    static void Swap(int *iVal1, int * iVal2);

    static void InsertSort(std::vector<int> &vctRaw, int iBeg, int iCount);
};

#endif // SORT_H
