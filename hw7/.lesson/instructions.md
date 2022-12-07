**Problem 2.** The gold mining company Gold336 wants to buy a lot of land. It has a list of available lots `lots`. Each lot `i` is an axis-parallel rectangle with coordinates `lots[i].x1`, `lots[i].x2`, `lots[i].y1`, `lots[i].y2`. The cost of the lot is `lots[i].cost`. The company also has a list of gold mines `goldMines`. Mine `j` has coordinates `goldMines[j].x` and `goldMines[j].y` and value `goldMines[j].value`. The total revenue that Gold336 can get from lot `i` equals the sum of values of gold mines located on the property. The profit from the lot equals the revenue from that lot minus its cost. Your goal is to design an algorithm that finds the best lot. Lots do not overlap (they are disjoint rectangles). If there are two or more lots that bring the same profit you can output any of them.

--------------

Please, design a **sweep line** algorithm for this problem. Implement the following function.

```cpp
int FindBestLot(const std::vector<Lot>& lots,
                const std::vector<GoldMine>& goldMines)
```                 

The function should return the index of the most profitable lot. The parameters are as follows: `lots` is the list of lots; `goldMines` is the list of gold mines.

--------------


Your program should be fast! It should pass all tests in no more than 2s. Also, its running time should be _O(n log n)_.

Compile your code!

You can use any standard C++ compiler to compile your code. We recommend using `clang++`. To compile your code, please type `make` or, alternatively, 

```
clang++ -std=c++17 -pedantic-errors -O3 main.cpp -o main
```

Test your code!

Please, run unit tests:
``` 
./main small
./main large
```

We also recommend that you run memory tests:
```
make memtest
./memtest small
./memtest large
```

Submit your code!

After you tested your code, please, download 
``student_code_7.h`` and submit it on Canvas! Make sure that this file does not contain any commented out code. Also, please, check that your code does not print any debug output.