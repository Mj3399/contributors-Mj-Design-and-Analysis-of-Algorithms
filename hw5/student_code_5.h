///////////////////////////////////////////////
// You need to
//    1. Carefully read the instructions.
//    2. Implement function MinCost.
//    3. Compile your code.
//    4. Run the executable on small and large
//       unit tests.
//    5. Test and debug your code.
//       Make sure that your program does not
//       have any memory leaks.
//    6. Remove all commented out code.
//       Double check that your program does
//       not print any debug information on
//       the screen.
//    7. Submit your source code
//       ("student_code_5.h") on Canvas.
///////////////////////////////////////////////

// required libraries
#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

// you can include standard C++ libraries here

std::string DefaultProblemSet() { return "small"; }

struct Package {
  int cost;
  int size;
};
// printing code |  std::cout << "
bool myfunction(Package i, Package j) { return (i.size < j.size); }

int MinimumPrice(int guestCount, const std::vector<Package> &packages) {

  std::vector<int> s;
  std::vector<int> c;
  for (int i = 0; i < packages.size(); i++) {
    s.push_back(packages[i].size);
  }
  for (int i = 0; i < packages.size(); i++) {
    c.push_back(packages[i].cost);
  }

  int c1[packages.size()];
  int s2[packages.size()];
  for (int i = 0; i < packages.size(); i++) {
    c1[i] = c[i];
  }
  for (int i = 0; i < packages.size(); i++) {
    s2[i] = s[i];
  }

  if (guestCount == 0) {
    return 0;
  }

  if (packages.empty()) {
    return 0;
  }
  int cheap = 1000000000;
  for (int k = 0; k < packages.size(); k++) {
    if (cheap > packages[k].cost) {
      cheap = packages[k].cost;
    }
  }
  if (guestCount == 1) {
    return cheap;
  }

  int heavy = 0;
  for (int i = 0; i < packages.size(); i++) {
    if (packages[i].size > heavy) {
      heavy = packages[i].size;
    }
  }
  int dp[heavy + guestCount], i, k;
  for (int i = 1; i < heavy + guestCount; i++) {
    dp[i] = 1000000000;
  }
  dp[0] = 0;
  for (int i = 1; i < guestCount + heavy; i++) {
    for (int k = 0; k < packages.size(); k++) {
      if (s2[k] <= i) {
        dp[i] = std::min(dp[i], dp[i - s2[k]] + c1[k]);
      }
    }
  }
  int ans = 1000000000;
  for (i = guestCount; i < guestCount + heavy; i++) {
    if (ans > dp[i]) {
      ans = dp[i];
    }
  }
  return ans;
}
