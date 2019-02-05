#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

///SORT: Receives the iterator from begin and from the end of array
    /// It can receive a function of sorting
    /// This function is bool and when returns true, a swap happens
    /// default : bool comp (int i, int j) { return (i < j) } to sort in ascending order.

///LOWER BOUND
    /// Return a iterator to the first element in range [first, last) which does not compare less than val
    /// (return min x | x <= val)

///UPPER BOUND
    /// Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
    /// (return min x | x >= val)


///BINARY_SEARCH
    /// Returns true if any element in the range [first,last) is equivalent to val, and false otherwise.


///NEXT_PERMUTATION
    /// Rearranges the elements in the range [first,last) into the next lexicographically greater permutation.

///PARTIAL_SORT
    ///Rearranges the elements in the range [first,last), in such a way that the elements before middle are the smallest elements
    ///in the entire range and are sorted in ascending order, while the remaining elements are left without any specific order.
        ///Ex:   int myints[] = {9,8,7,6,5,4,3,2,1};
        ///std::partial_sort (myvector.begin(), myvector.begin()+5, myvector.end());
        /// result: myvector contains: 1 2 3 4 5 9 8 7 6


///ITERATORS AND REVERSE ITERATORS





typedef struct {
  int id;
  int solved;
  int penalty;
} team;

bool icpc_cmp(team a, team b) {
  if (a.solved != b.solved) // can use this primary field to decide sorted order
    return a.solved > b.solved;   // ICPC rule: sort by number of problem solved
  else if (a.penalty != b.penalty)       // a.solved == b.solved, but we can use
                                       // secondary field to decide sorted order
    return a.penalty < b.penalty;       // ICPC rule: sort by descending penalty
  else                        // a.solved == b.solved AND a.penalty == b.penalty
    return a.id < b.id;                      // sort based on increasing team ID
}

int main() {
  int *pos, arr[] = {10, 7, 2, 15, 4};
  vector<int> v(arr, arr + 5);          // another way to initialize vector
  vector<int>::iterator j;

  // sort descending with vector
  sort(v.rbegin(), v.rend());        // example of using 'reverse iterator'
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    printf("%d ", *it);                     // access the value of iterator
  printf("\n");
  printf("==================\n");

  // sort descending with integer array
  sort(arr, arr + 5);                                          // ascending
  reverse(arr, arr + 5);                                    // then reverse
  for (int i = 0; i < 5; i++)
    printf("%d ", arr[i]);
  printf("\n");
  printf("==================\n");

  random_shuffle(v.begin(), v.end());          // shuffle the content again
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    printf("%d ", *it);
  printf("\n");
  printf("==================\n");
  partial_sort(v.begin(), v.begin() + 2, v.end());     // partial_sort demo
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    printf("%d ", *it);
  printf("\n");
  printf("==================\n");

  // sort ascending
  sort(arr, arr + 5);                           // arr should be sorted now
  for (int i = 0; i < 5; i++)                            // 2, 4, 7, 10, 15
    printf("%d ", arr[i]);
  printf("\n");
  sort(v.begin(), v.end());                // sorting a vector, same output
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    printf("%d ", *it);
  printf("\n");
  printf("==================\n");

  // multi-field sorting example, suppose we have 4 ICPC teams
  team nus[4] = { {1, 1, 10},
                  {2, 3, 60},
                  {3, 1, 20},
                  {4, 3, 60} };

  // without sorting, they will be ranked like this:
  for (int i = 0; i < 4; i++)
    printf("id: %d, solved: %d, penalty: %d\n",
           nus[i].id, nus[i].solved, nus[i].penalty);

  sort(nus, nus + 4, icpc_cmp);         // sort using a comparison function
  printf("==================\n");
  // after sorting using ICPC rule, they will be ranked like this:
  for (int i = 0; i < 4; i++)
    printf("id: %d, solved: %d, penalty: %d\n",
           nus[i].id, nus[i].solved, nus[i].penalty);
  printf("==================\n");

  // there is a trick for multi-field sorting if the sort order is "standard"
  // use "chained" pair class in C++ and put the highest priority in front
  typedef pair < int, pair < string, string > > state;
  state a = make_pair(10, make_pair("steven", "grace"));
  state b = make_pair(7, make_pair("steven", "halim"));
  state c = make_pair(7, make_pair("steven", "felix"));
  state d = make_pair(9, make_pair("a", "b"));
  vector<state> test;
  test.push_back(a);
  test.push_back(b);
  test.push_back(c);
  test.push_back(d);
  for (int i = 0; i < 4; i++)
    printf("value: %d, name1 = %s, name2 = %s\n", test[i].first,
    ((string)test[i].second.first).c_str(), ((string)test[i].second.second).c_str());
  printf("==================\n");
  sort(test.begin(), test.end());   // no need to use a comparison function
  // sorted ascending based on value, then based on name1,
  // then based on name2, in that order!
  for (int i = 0; i < 4; i++)
    printf("value: %d, name1 = %s, name2 = %s\n", test[i].first,
      ((string)test[i].second.first).c_str(), ((string)test[i].second.second).c_str());
  printf("==================\n");

  // binary search using lower bound
  pos = lower_bound(arr, arr + 5, 7);                              // found
  printf("%d\n", *pos);
  j = lower_bound(v.begin(), v.end(), 7);
  printf("%d\n", *j);

  pos = lower_bound(arr, arr + 5, 77);                         // not found
  if (pos - arr == 5) // arr is of size 5 ->
                      //    arr[0], arr[1], arr[2], arr[3], arr[4]
                      // if lower_bound cannot find the required value,
                      //   it will set return arr index +1 of arr size, i.e.
                      //   the 'non existent' arr[5]
                      // thus, testing whether pos - arr == 5 blocks
                      //   can detect this "not found" issue
    printf("77 not found\n");
  j = lower_bound(v.begin(), v.end(), 77);
  if (j == v.end()) // with vector, lower_bound will do the same:
                    //   return vector index +1 of vector size
                    // but this is exactly the position of vector.end()
                    //   so we can test "not found" this way
    printf("77 not found\n");
  printf("==================\n");

  // useful if you want to generate permutations of set
  next_permutation(arr, arr + 5); // 2, 4, 7, 10, 15 -> 2, 4, 7, 15, 10
  next_permutation(arr, arr + 5); // 2, 4, 7, 15, 10 -> 2, 4, 10, 7, 15
  for (int i = 0; i < 5; i++)
    printf("%d ", arr[i]);
  printf("\n");

  next_permutation(v.begin(), v.end());
  next_permutation(v.begin(), v.end());
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    printf("%d ", *it);
  printf("\n");
  printf("==================\n");

  // sometimes these two useful simple macros are used
  printf("min(10, 7) = %d\n", min(10, 7));
  printf("max(10, 7) = %d\n", max(10, 7));

  return 0;
}
