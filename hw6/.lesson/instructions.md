**Problem 2.** 
In this exercise, your goal is to design an algorithm for a cryptocurrency startup. The startup has a supercomputer that can mine two types of coins: NorthCoins and WestCoins. The profit from mining these coins drastically varies over time, and your goal is to determine which of the two types of coins the startup needs to mine at what time.
The problem is that the supercomputer cannot immediately switch from mining NorthCoins to mining WestCoins or vice versa, because
each type of coins requires its own software, and it takes 1 day to load it. So, for example, if we mine NorthCoins 
on day `t`, we can start mining WestCoins only on day `t+2`. In this particular case, the supercomputer
will be loading software for WestCoins and not mining any coins on day `t+1`.

Your algorithm is given two arrays of positive numbers `north[0]`,...,`north[T-1]` and `west[0]`,...,`west[T-1]`.

* `north[t]` is the profit the startup gets from mining NorthCoins on day `t`; and

* `west[t]` is the profit the startup gets from mining WestCoins on day `t`.

Your algorithm needs to find the maximum profit the startup can get from mining NorthCoin and WestCoin at days `1`,...,`T`.

--------------

**Example.** Consider the following example: 
`north = [10, 10, 10, 10, 20]` and 
`west = [2, 15, 1, 7 , 100]`.

<h6>

|   | 1 | 2 | 3 | 4 | 5 |
| - | - | - | - | - | - |
| north | 10 | 10 | 10 | 10 | 20 |
| west | 2 | 15 | 1 | 7 | 200 |

</h6>

Then, the optimal solution
to the problem is to mine Northcoins on days 1, 2, and 3, load new software on day 4, and mine WestCoins on day 5. The profit from this s
olution is 

$10 + $10 + $10 + $100 = $130.

--------------

Your goal is to design a dynamic programming algorithm for this problem. Implement the following function.

```cpp
int FindMaxProfit (const std::vector<int>& north, 
                   const std::vector<int>& west)
```                 

Arrays `north` and `west` contain profits the startup can get from mining NorthCoin and WestCoin (respectively). Note that arrays `north` and `west`
are indexed from `0` to `T-1`, here `T` is the size of the arrays. `FindMaxProfit` should return the maximum profit startup can earn at days `0`,...., `T-1`.

--------------


Your program should be fast! It should pass all tests in no more than 5ms. We recommend that you use the bottom-up approach in your solution.

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
`student_code_6.h` and submit it on Canvas! Make sure that this file does not contain any commented out code. Also, please, check that your code does not print any debug output.