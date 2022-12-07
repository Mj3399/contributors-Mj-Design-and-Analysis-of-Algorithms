///////////////////////////////////////////////
// You need to
//    1. Carefully read the instructions.
//    2. Implement function FindOptimalSchedule.
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
//       ("student_code_3.h") on Canvas.
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
struct Job {
  int start;
  int finish;
};
bool comp(Job a, Job b) {
return (a.finish < b.finish); 
}
int FindOptimalSchedule(std::vector<Job> highPriorityJobs,
                        std::vector<Job> lowPriorityJobs) {
  sort(highPriorityJobs.begin(), highPriorityJobs.end(), comp);
  sort(lowPriorityJobs.begin(), lowPriorityJobs.end(), comp);
  int p = 0;
  int finish2 = 0;
  int finish = highPriorityJobs[highPriorityJobs.size() - 1].finish;
  for (int i = 0; i < lowPriorityJobs.size(); i++) {
    if (lowPriorityJobs[i].start >= finish) {
      finish = lowPriorityJobs[i].finish;
      p++;
    }
    int start = highPriorityJobs[0].start;
    if (lowPriorityJobs[i].finish <= start &&
        lowPriorityJobs[i].start >= finish2) {
      finish2 = lowPriorityJobs[i].finish;
      p++;
      ;
    }
  }
  int j = 0;
  if (highPriorityJobs.size() != 1 && highPriorityJobs.size() != 2) {
    for (int i = 0; i < highPriorityJobs.size() - 1; i++) {
      int fin = highPriorityJobs[i].finish;
      while (j < lowPriorityJobs.size() &&
             lowPriorityJobs[j].finish <= highPriorityJobs[i + 1].start) {
        if (lowPriorityJobs[j].start >= fin) {
          fin = lowPriorityJobs[j].finish;
          p++;
        }
        j++;
      }
    }
  } else {
    if (highPriorityJobs.size() == 2) {
      int finish3 = highPriorityJobs[0].finish;
      int start3 = highPriorityJobs[1].start;
      for (int i = 0; i < lowPriorityJobs.size(); i++) {
        if (lowPriorityJobs[i].start >= finish3 &&
            lowPriorityJobs[i].finish <= start3) {
          finish3 = lowPriorityJobs[i].finish;
          p++;
        }
      }
    }
  }
  return p;
}