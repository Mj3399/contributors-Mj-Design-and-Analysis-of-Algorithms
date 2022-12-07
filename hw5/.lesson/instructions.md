**Problem 2.** You are planning to organize a large party at Northwestern. You are expecting many guests. You want to give each guest a cupcake from
your favorite bakery Bake++. Cupcakes are available in `k` different packages `0`,`1`,..., `k-1`. Package `i` costs `package[i].cost` cents and contains 
`package[i].size` cupcakes. You need to design an algorithm that chooses which packages to order to minimize the total purchase price. Note that (1) you can order
more than `n` cupcakes; and (2) the price per cupcake can be different for different packages.

--------------

**Example.** You need to order `1060` cupcakes. The available packages are (`0`) 100 cupcakes for $250.00, (`1`) 50 cupcake for $150.00, and `2` 1 cupcake for $3.50. The optimal solution to this problem is to order ten
 `0` packages, one `1` package, and ten `2` packages. In this case, you are ordering 

10 x 100 + 1 x 50 + 10 x 1 = 1,060

cupcakes and paying 

10 x $250.00 + 1 x $150.00 + 10 x $3.50= $2,685

dollars.

--------------

Your goal is to design a dynamic programming algorithm for this problem. Implement the following function.

```cpp
int MinimumPrice(int guestCount, const std::vector<Package>& packages)
```                 

The function should return the minimum possible price. The parameters are as follows: `guestCount` is the number of guests; `packages` is a vector of packages. Each entry in the array has two fields: `cost` &mdash; the cost of the package
and `size` &mdash; the number of cupcakes in the package.

--------------


Your program should be fast! It should pass all tests in no more than 300ms.

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
``student_code_5.h`` and submit it on Canvas! Make sure that this file does not contain any commented out code. Also, please, check that your code does not print any debug output.