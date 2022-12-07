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
//       ("student_code_6.h") on Canvas.
///////////////////////////////////////////////

// required libraries
#include <string>
#include <vector>

// you can include standard C++ libraries here

std::string DefaultProblemSet() { return "small"; }

int FindMaxProfit(const std::vector<int> &north, const std::vector<int> &west) {
  /* day 0 grab whichever is higher day 1 check the addition of each to day 1 */

  std::vector<std::vector<int>> opt(2, std::vector<int>(north.size(), 0));

  opt[0][0] = north[0];
  opt[0][1] = north[0] + north[1];
  opt[1][0] = west[0];
  opt[1][1] = west[0] + west[1];
  for (int i = 2; i < north.size(); i++) {
    opt[0][i] = std::max(opt[0][i - 1] + north[i], opt[1][i - 2] + north[i]);
    opt[1][i] = std::max(opt[1][i - 1] + west[i], opt[0][i - 2] + west[i]);
  }
  return std::max(opt[0][west.size() - 1],
                  opt[1][west.size() - 1]) /* your answer */;
}
