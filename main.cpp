#include <iostream>
#include <sys/time.h>
#include "sort.h"

using namespace std;

#define SIZE 10
void PrintfRet(const std::string & strKey, const vector<int> & vctSortRet);
int main()
{
    cout << "Hello World!" << endl;

    //    vector<int> vctSort{5,0,9,8,1,4,0,7,2,5};
    vector<int> vctSort(SIZE);

    for(int i = 0; i < SIZE; ++i)
    {
        int data = rand() % (10000000 + 1);
        vctSort[i] = data;
    }

    //    cout << "Raw Data : ";
    //    for (size_t i = 0, iSize = vctSort.size(); i < iSize; ++i)
    //    {
    //        cout << vctSort[i] << " ";
    //    }
    //    cout << endl;

    struct timeval tvStart, tvEnd;

    vector<int> vctSort2{5,0,9,8,1,4,0,7,2,5};

    gettimeofday(&tvStart, NULL);
    vector<int> vctBubbleSortRet =  Sort::MergeSort(vctSort);
    gettimeofday(&tvEnd, NULL);

    //    PrintfRet("Bubble", vctBubbleSortRet);
    int64_t iStart = tvStart.tv_sec * 1000000 + tvStart.tv_usec;
    int64_t iEnd = tvEnd.tv_sec * 1000000 + tvEnd.tv_usec;
    cout << "diff = " << iEnd - iStart << endl;
    iStart = iEnd;

    getchar();

    return 0;
}

void PrintfRet(const std::string & strKey, const vector<int> & vctSortRet)
{
    cout << strKey << " : ";
    //    return;
    for (size_t i = 0, iSize = vctSortRet.size(); i < iSize; ++i)
    {
        cout << vctSortRet[i] << " ";
    }
    cout << endl;
}
