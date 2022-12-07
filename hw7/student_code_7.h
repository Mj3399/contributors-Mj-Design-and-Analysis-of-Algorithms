//////////////////////////////////////////////////////
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
//    7. Submit your source code ("student_code_7.h")
//       on Canvas.
//////////////////////////////////////////////////////

// required libraries
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
// you can include standard C++ libraries here

// This function should return your name.
// The name should match your name in Canvas

std::string DefaultProblemSet() { return "small"; }

struct Lot {
  int x1;
  int x2;
  int y1;
  int y2;
  int cost;
};

struct GoldMine {
  int x;
  int y;
  int value;
};

struct object {
  int x;
  int i;
  int t; // 0 for start 1 for end or 7 for mine
};
struct objecty {
  int y;
  int i;
};
// are lambda functions really faster?? verdict is that yes yes they are, also &
// reference is faster than not using one for some reason

int FindBestLot(const std::vector<Lot> &lots,
                const std::vector<GoldMine> &goldMines) {

  std::vector<object> l;
  std::vector<int> p(lots.size(), 0);
  int maxProfit = -1;
  int Answer = -1;

  // populate event list with lots
  for (int i = 0; i < lots.size(); i++) {

    l.push_back(object{lots[i].x1, i, 0});

    l.push_back(object{lots[i].x2, i, 1});
  }
  // populate event list with mines
  for (int i = 0; i < goldMines.size(); i++) {

    l.push_back(object{goldMines[i].x, i, 7});
  }
  // sort by x
  std::sort(l.begin(), l.end(), [](object &x, object &y) { return x.x < y.x; });

  std::map<int, objecty> myset;
  // now we insert our events into a map sorted by y now
  for (int i = 0; i < l.size(); i++) {

    // insert the start line of a lot
    switch (l[i].t) {
    case 0:

      myset.insert({lots[l[i].i].y1, {lots[l[i].i].y2, l[i].i}});

      break;

      // if its the end line of a lot we wanna find the matching start and kill
      // it
    case 1:
      p[l[i].i] = p[l[i].i] - lots[l[i].i].cost;
      if (p[l[i].i] > maxProfit) {
        maxProfit = p[l[i].i];
        Answer = l[i].i;
      }
      myset.erase(lots[l[i].i].y1);
      break;

      // if its a mine then  immediately go to find lower
    // bound cuz that should be the answer
    case 7:
      auto ans = myset.lower_bound(goldMines[l[i].i].y);
      if (ans != myset.begin()) {
        ans--;
      }
      if (goldMines[l[i].i].y >= (*ans).first &&
          goldMines[l[i].i].y <= (*ans).second.y) {
        p[(*ans).second.i] = p[(*ans).second.i] + goldMines[l[i].i].value;
        break;
      }
    }
  }

  // then return the answer
  return Answer /* your answer */;
}
