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
//       ("student_code_4.h") on Canvas.
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

int MaxTotalTime(const std::vector<int> &minutes, int limit) {

  if (minutes.empty()) {
    return 0;
  }

  int N = minutes.size();

  std::vector<int> optValues(N, 0);

  if (minutes[0] > limit) {
    optValues[0] = 0;
  } else {
    optValues[0] = minutes[0];
  }

  if (N > 1) {
    if (minutes[1] <= limit && ((minutes[1] + optValues[0]) <= limit)) {
      optValues[1] = optValues[0] + minutes[1];

    } else {
      if (minutes[1] <= limit) {
        optValues[1] = std::max(optValues[0], minutes[1]);

      } else {
        optValues[1] = optValues[0];
      }
    }

    for (int i = 2; i < N; i++) {
      if (minutes[i] <= limit) {
        if (minutes[i - 1] + minutes[i] <= limit) {
          optValues[i] = optValues[i - 1] + minutes[i];

        } else {
          optValues[i] =
              std::max(optValues[i - 1], optValues[i - 2] + minutes[i]);
        }

      } else {
        optValues[i] = optValues[i - 1];
      }
    }
  }

  return optValues.back();
}
