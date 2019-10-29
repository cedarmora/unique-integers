#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iterator>
using namespace std;


void readIntegersFile(string fileName, vector<int>& integers, int& target) {
    ifstream integersFile;
    integersFile.open(fileName);


    integersFile >> target;

    int number;
    while(integersFile >> number) {
        integers.push_back(number);
    }

    integersFile.close();

}

// Return a pair of integers that sum up to a target sum from an array of unique integers.
vector<int> findPair(vector<int> integers, int target) {
    vector<int> pair;
    unordered_map<int, int> int_map; // Is unordered_map rather than ordered_map because ordered_map has O(log n) read and write times,
    // whereas unordered_map has O(1) read and write times, assuming it has a uniform hash function.

    // First create a hash of integers in O(n) time that exists so that we can check whether integers exist in O(1) time.
    for (int integer : integers) {
        int_map[integer] += 1; // Default value for the value of a nonexistent key is 0.
    }

    // Now go through the integers and using the hash check if the correct integer to meet the target exists. Also O(n)
    // Using iterators just for practice. Range based for loop would be less code and clearer though.
    vector<int>::iterator integer;
    int possibleOtherInteger;
    for (integer = integers.begin(); integer < integers.end(); integer++) {
        possibleOtherInteger = target - *integer;
        if (int_map[possibleOtherInteger] > 0)  { // if other integer exists in map, it exists in the vector
            pair.at(0) = *integer; // So we found it!
            pair.at(1) = possibleOtherInteger; // Yay!
            return pair;
        }
    }

    // If it gets to here, there are no integers that sum to the target
    throw "No pair of integers sums to the target value";
}

int main() {
    vector<int> integers;
    int target;


    readIntegersFile("input.txt", integers, target);

    try {
        vector<int> results = findPair(integers, target);
        cout << "Pair of integers is: " <<  results.at(0) << ", " << results.at(1);
    } catch (exception& e) {
        cerr << e.what() << endl;
    }
}
