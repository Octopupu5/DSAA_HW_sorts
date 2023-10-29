# Homework about sorts, SE-221, Pankratov Stepan
## All data for graphs is in directory "Data_for_graphs"
## C++ part
To run C++ code, type:
```
g++ <name_of_sort> -o test
```
Then, if you would like sorted array to be printed, type
```
./test print
```
Otherwise, just without 'print'. The input data is n for all sorts with integers, n and m for sorts with strings.

## Python Notebook
All the stuff was drawn with MatPlotLib library in `generator.ipynb` file. To run multiple tests on C++ code, use the commented code:
* Choose the type of sort : 0 for insertion, 1 for merge, 2 for quick, 3 for NlogN guaranteed quick, 4 for heap, 5 for String Insertion, 6 for String Insertion with binary search, 7 for Skip List
* Choose the range of input data (n and m, if it is a string sort)
* The program will print the time execution of the sort for each test