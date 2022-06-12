//
// Created by 朱玥 on 2022/6/12.
//
#include <iostream>
#include <vector>

#include "46. Permutations/permutations.h"

using namespace std;

int main()
{
  auto a = new Solution();

  int n = 3;

  vector<int> v;
  v.reserve(n);
  for (int i = 0; i < n; i++)
  {
    v.push_back(i + 1);
  }
  vector<vector<int> > vv;
  vv = a->permute(v);

  for (auto &i: vv)
  {
    cout << "{ ";
    for (int j: i)
    {
      cout << j << " ";
    }
    cout << "}" << endl;
  }
}

/*
{ 1 2 3 }
{ 2 1 3 }
{ 3 2 1 }
{ 1 3 2 }
{ 2 3 1 }
{ 3 1 2 }
*/

/*
 *    The algorithm - Take each element in array to the first place.
 *
 *    For example:
 *
 *         0) initialization
 *
 *             pos = 0
 *             [1, 2, 3]
 *
 *         1) take each element into the first place,
 *
 *             pos = 1
 *             [1, 2, 3]  ==>  [2, 1, 3] , [3, 1, 2]
 *
 *             then we have total 3 answers
 *             [1, 2, 3],  [2, 1, 3] , [3, 1, 2]
 *
 *         2) take each element into the "first place" -- pos
 *
 *             pos = 2
 *             [1, 2, 3]  ==>  [1, 3, 2]
 *             [2, 1, 3]  ==>  [2, 3, 1]
 *             [3, 1, 2]  ==>  [3, 2, 1]
 *
 *             then we have total 6 answers
 *             [1, 2, 3],  [2, 1, 3] , [3, 1, 2], [1, 3, 2], [2, 3, 1], [3, 2, 1]
 *
 *          3) pos = 3 which greater than length of array, return.
 *
 */
