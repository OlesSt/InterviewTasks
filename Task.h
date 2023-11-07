#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <bitset>



void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    std::vector<int> temp{};

    for (int i {0}; i < nums1.size(); i++)
    {
        temp.push_back(nums1[i]);
//        if (nums1[i] != 0)
//        {
//            temp.push_back(nums1[i]);
//        }
    }

    for (int i {0}; i < nums2.size(); i++)
    {
        temp.push_back(nums2[i]);
//        if (nums2[i] != 0)
//        {
//            temp.push_back(nums2[i]);
//        }
    }

    std::sort(temp.begin(),temp.end());

    nums1 = temp;
}
void print(const std::vector<int> &v)
{
    for(int i = 0; i < v.size(); i++)
    { std::cout << v[i] << " ";}
    std::cout << std::endl;
}

namespace Task
{
void runTask()
{

    std::vector<int>num01 {-1,0,0,3,3,3,0,0,0};
    std::vector<int>num02 {1,2,2};
    int m = 6;
    int n = 3;

    merge(num01, m, num02, n); // [1,2,2,3,5,6]

    print(num01);

}
}



#endif // TASK_H
