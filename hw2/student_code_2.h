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
//       ("student_code_2.h") on Canvas.
///////////////////////////////////////////////

// required libraries
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <utility>
#include <vector>

// you can include standard C++ libraries here

struct Price {
  int sale{0};
  int after{0};
  int before{0};
};

std::string DefaultProblemSet() { return "small"; }

bool comp(const std::pair<int, int> &a, const std::pair<int, int> &b) {

  return (a.second > b.second);
}
int MinCost(const std::vector<Price> &giftPrices, int k) {

  std::vector<std::pair<int, int>> help;

  int sum = 0;
  int saved = 0;
  int stupidsum = 0;
  for (int i = 0; i < giftPrices.size(); i++) {

    if (giftPrices[i].before > giftPrices[i].after) {
      saved = giftPrices[i].after - giftPrices[i].sale;
    } else {
      saved = giftPrices[i].before - giftPrices[i].sale;
    }
    help.push_back(std::make_pair(i, saved));
  }
  sort(help.begin(), help.end(), comp);
  int min = 0;
  for (int i = 0; i < giftPrices.size(); i++) {
    min = std::min(giftPrices[i].after, giftPrices[i].before);
    sum += min;
  }
  if (k < giftPrices.size()) {
    for (int i = 0; i < k; i++) {

      sum -= help[i].second;
    }
  } else {
    for (int i = 0; i < giftPrices.size(); i++) {
      min = std::min(std::min(giftPrices[i].after, giftPrices[i].before),
                     giftPrices[i].sale);
      stupidsum += min;
    }
    return stupidsum;
  }

  return sum;
}
