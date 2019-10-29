# Unique Integers

This is practice for interviews.

The challenge is: Given an array of unique integers, return a pair of integers that sum up to a target sum.

This solution runs in O(n) time by adding all the integers to a hash (AKA unordered\_map in c++), which takes O(n) time, then goes through each integer in the array, and uses the hash to check in O(1) time if the `target - integer` exists in the array. 

Luckily, since this is an array of unique integers, we don't need to check for the edge case where an integer cannot pair with itself.

run `make` to build and run the program.

The first line of `input.txt` is the target sum, and any subsequent integers is the array of unique integers from which to find the pair.
