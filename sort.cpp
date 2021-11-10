#include "sort.h"
#include <iostream>

using namespace std;
Sort::Sort()
{

}

std::vector<int> Sort::BubbleSort(std::vector<int> &vctRaw)
{
    for (size_t i = 0; i < vctRaw.size(); ++i)
    {
        size_t m = 0;
        for(m = 0; m < vctRaw.size() - 1; ++m)
        {
            int iTemp = vctRaw[m];
            if(iTemp > vctRaw[m + 1])
            {
                vctRaw[m] = vctRaw[m + 1];
                vctRaw[m + 1] = iTemp;
            }
        }
    }

    return  vctRaw;
}

std::vector<int> Sort::SelectSort(std::vector<int> &vctRaw)
{
    for (size_t i = 0; i < vctRaw.size(); ++i)
    {
        size_t iMinIndex = i;
        for (size_t j = i; j < vctRaw.size(); ++j)
        {
            if(vctRaw[iMinIndex] > vctRaw[j])
            {
                iMinIndex = j;
            }
        }

        if(i != iMinIndex)
        {
            int iTemp = vctRaw[i];
            vctRaw[i] = vctRaw[iMinIndex];
            vctRaw[iMinIndex] = iTemp;
        }
    }

    return vctRaw;
}

std::vector<int> Sort::InsertSort(std::vector<int> &vctRaw)
{
    for (size_t i = 1; i < vctRaw.size(); ++i)
    {
        for (size_t j = i; j > 0; --j)
        {
            if(vctRaw[j - 1] > (vctRaw[j]))
            {
                int iTemp = vctRaw[j];
                vctRaw[j] = vctRaw[j - 1];
                vctRaw[j - 1] = iTemp;
            }
            else
            {
                break;
            }
        }
    }

    return vctRaw;
}

std::vector<int> Sort::ShellSort(std::vector<int> &vctRaw)
{
    size_t iSize = vctRaw.size();

    for(int iSpace = iSize/2; iSpace > 0; iSpace /= 2)
    {
        for(int i = iSpace; i < iSize; ++i)
        {
            for(int j = i; j > 0 && (j - iSpace >= 0); j -= iSpace)
            {
                int m = vctRaw[j - iSpace];
                int n = vctRaw[j];
                if(m > n)
                {
                    int iTemp = vctRaw[j];
                    vctRaw[j] = vctRaw[j - iSpace];
                    vctRaw[j - iSpace] = iTemp;
                }
                else
                {
                    break;
                }
            }
        }
    }

    return vctRaw;
}

std::vector<int> Sort::HeapSort(std::vector<int> &vctRaw)
{
    int i, iSize = vctRaw.size();
    for(i = iSize/2; i >= 0; --i)
    {
        PercDown(vctRaw, i, iSize);
    }
    for(i = iSize - 1; i > 0; --i)
    {
        int iTemp = vctRaw[0];
        vctRaw[0] = vctRaw[i];
        vctRaw[i] = iTemp;
        PercDown(vctRaw, 0, i);
    }

    return vctRaw;
}

std::vector<int> Sort::MergeSort(std::vector<int> &vctRaw)
{
    std::vector<int> vctRet(vctRaw.size());

    MSort(vctRaw, vctRet, 0, vctRaw.size() - 1);
    return vctRaw;
}

std::vector<int> Sort::QuickSort(std::vector<int> &vctRaw)
{
    Qsort(vctRaw, 0, vctRaw.size() - 1);

    return vctRaw;
}

#define LeftChild(i) (2 * (i) + 1)
void Sort::PercDown(std::vector<int> &vctRaw, int imin, int imax)
{
    int iChild, iTemp;

    for(iTemp = vctRaw[imin]; LeftChild(imin) < imax; imin = iChild)
    {
        iChild = LeftChild(imin);
        if(iChild != imax - 1 && vctRaw[iChild + 1] > vctRaw[iChild])
        {
            ++iChild;
        }
        if(iTemp < vctRaw[iChild])
        {
            vctRaw[imin] = vctRaw[iChild];
        }
        else
        {
            break;
        }
    }
    vctRaw[imin] = iTemp;
}

void Sort::MSort(std::vector<int> &vctRaw, std::vector<int> &vctRet, int iLeft, int iRight)
{
    int iCenter;
    if(iLeft < iRight)
    {
        iCenter = (iLeft + iRight) / 2;
        MSort(vctRaw, vctRet, iLeft, iCenter);
        MSort(vctRaw, vctRet, iCenter + 1, iRight);
        Merge(vctRaw, vctRet, iLeft, iCenter + 1, iRight);
    }
}

void Sort::Merge(std::vector<int> &vctRaw, std::vector<int> &vctRet, int Lpos, int Rpos, int RightEnd)
{
    int iLeftEnd, Num, Tmp;
    iLeftEnd = Rpos - 1;
    Tmp = Lpos;
    Num = RightEnd - Lpos + 1;
    while (Lpos <= iLeftEnd && Rpos <= RightEnd)
    {
        if(vctRaw[Lpos] <= vctRaw[Rpos])
        {
            vctRet[Tmp++] = vctRaw[Lpos++];
        }
        else
        {
            vctRet[Tmp++] = vctRaw[Rpos++];
        }
    }
    while (Lpos <= iLeftEnd)
    {
        vctRet[Tmp++] = vctRaw[Lpos++];
    }
    while (Rpos <= RightEnd)
    {
        vctRet[Tmp++] = vctRaw[Rpos++];
    }

    for(int i = 0; i < Num; ++i, --RightEnd)
    {
        vctRaw[RightEnd] = vctRet[RightEnd];
    }
}

#define Cutoff (3)
void Sort::Qsort(std::vector<int> &vctRaw, int iLeft, int iRight)
{
    int i, j;
    int iPivot;

    if(iLeft + Cutoff <= iRight)
    {
        iPivot = Median3(vctRaw, iLeft, iRight);
        i = iLeft;
        j = iRight - 1;
        while (true)
        {
            while (vctRaw[++i] < iPivot){}
            while (vctRaw[--j] > iPivot){}

            if(i < j)
            {
                Swap(&vctRaw[i], &vctRaw[j]);
            }
            else
            {
                break;
            }
        }

        Swap(&vctRaw[i], &vctRaw[iRight - 1]);

        Qsort(vctRaw, iLeft, i - 1);
        Qsort(vctRaw, i + 1, iRight);
    }
    else
    {
        InsertSort(vctRaw, iLeft, iRight);
    }
}

int Sort::Median3(std::vector<int> &vctRaw, int iLeft, int iRight)
{
    int iCenter = (iRight + iLeft) / 2;

    if(vctRaw[iLeft] > vctRaw[iCenter])
    {
        Swap(&vctRaw[iLeft], &vctRaw[iCenter]);
    }
    if(vctRaw[iLeft] > vctRaw[iRight])
    {
        Swap(&vctRaw[iLeft], &vctRaw[iRight]);
    }
    if(vctRaw[iCenter] > vctRaw[iRight])
    {
        Swap(&vctRaw[iCenter], &vctRaw[iRight]);
    }

    Swap(&vctRaw[iCenter], &vctRaw[iRight - 1]);

    return vctRaw[iRight - 1];
}

void Sort::Swap(int *iVal1, int *iVal2)
{
    int iTemp = *iVal1;
    *iVal1 = *iVal2;
    *iVal2 = iTemp;
}

void Sort::InsertSort(std::vector<int> &vctRaw, int iBeg, int iCount)
{
    for (size_t i = iBeg + 1; i <= iCount; ++i)
    {
        for (size_t j = i; j > iBeg; --j)
        {
            if(vctRaw[j - 1] > (vctRaw[j]))
            {
                Swap(&vctRaw[j], &vctRaw[j - 1]);
            }
            else
            {
                break;
            }
        }
    }

//    return vctRaw;
}
