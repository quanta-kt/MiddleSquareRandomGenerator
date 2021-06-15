# Middle Square Method
Middle Square Method a simple algorithm to generate pseudo random numbers.

More on the algorithm here: https://en.wikipedia.org/wiki/Middle-square_method

# Building
No makefiles are provided, build using g++ as:
```
g++ main.cpp middlesquare.cpp -I ./include -o middlesquare
```
And run using:
```
./middlesquare
```
The main.cpp uses generator to generate and print 10 random numbers, seeded by time

# Issues/Limitations
At the time of writting the implementaion has following issues:

- next() starts producing 0 values indifinately once the seed reaches 0.

# License
This project is licanced under _[Do What the F*ck You Want to Public License](http://www.wtfpl.net/)_