#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

/*
 * Implementation of Sorting Algorithms
 * I. Humeyra Dogus
 *
 * This program compares two sorting algorithms: insertion sort
 * and merge sort. For each algorithm, there is a counter and
 * counts how many times a comparison is made to sort the array.
 * Once this logic is implemented, integer arrays of 1000 and 10000
 * elements created with random values inside.
 *
 */
using namespace std;
int counter = 0; // counter
/**
 * Merge Function
 *
 * This function merges two sorted halves.
 */
void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1; // number of elements in array
    int n2 = right - middle;

    int* L = new int[n1];  // new sub array(left)
    int* R = new int[n2]; // new sub array (right)

    for (i = 0; i < n1; i++) // for loop to check left subarray
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++) // for loop to check right subarray
        R[j] = arr[middle + 1 + j];

    i = 0; j = 0; k = left;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
        counter++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    if (left < right){
        int middle = left + (right - left) / 2; // assign the middle index of vector

        mergeSort(arr, left, middle); // recursive call for 1st half of the vector
        mergeSort(arr, middle + 1, right); // recursive call for 2nd half of the vector

        merge(arr, left, middle, right); // merge 1st and 2nd halves
    }
}
/**
 * insertionSort Function
 *
 * This is the insertionSort Function for sorting the array.
 */
template <typename Comparable>
void insertionSort( vector<Comparable> & a )
{
    int counter = 0; // counter
    for( int p = 1; p < a.size( ); ++p ){ // find unsorted part of the array
        Comparable tmp = std::move( a[ p ] ); // assign unsorted first element to temporary variable tmp

        if (!(p == 0)){
            counter++; // increment the counter
        }
        int j;
        for( j = p; j > 0 && tmp < a[ j - 1 ]; --j ){ // find sorted part of the array
            if (j > 1){
                counter++; // increment the counter
            }
            a[ j ] = std::move( a[ j - 1 ] ); // assign small element to front
        }

        a[ j ] = std::move( tmp ); // swap largest element with smaller element
    }
    cout << counter <<endl; // prompt the total count
}
/**
 * This is the main function of the program.
 * This fuction creates 2 arrays and 2 vectors.
 * The contents of arrays and vectors are assigned randomly.
 * This function prints the counter values for
 * 1000 element merge/insertion sort and 10000 element
 * merge/insertion sort.
 *
 * @return no params or returns
 */
int main() {
    cout<< "The number of comparisons in 1000 ELEMENT array by using INSERTION SORT: ";
    vector<int> vector; // create vector
    srand((unsigned)time(NULL)); // create random values
    for(int i = 0; i < 1000; i++) { // for loop to iterate over all elements
        int random = rand(); // random
        vector.push_back(random); // push the random values into the vector
    }

    insertionSort(vector); // call the insertionSort function

    //prompt
    cout<< "The number of comparisons in 10000 ELEMENT array by using INSERTION SORT: ";
    std::vector<int> vector2; // create vector2
    for(int i = 0; i < 10000; i++) { // for loop to iterate over all elements
        int random = rand(); // random
        vector2.push_back(random); // push the random values into the vector
    }
    insertionSort(vector2); // call the insertionSort function

//--------------------------------------------------

    cout << "---------------------" << endl;
    int* arr = new int[1000]; // create an array contains that 1000 elements

    for (int i = 0; i < 1000; i++) {// for loop to iterate over 1000 elements
        arr[i] = rand() ; // assign each random values into the array
    }

    mergeSort(arr, 0, 1000 - 1); // call the merge sort

    delete[] arr; // delete the array
    // prompt
    cout << "The number of comparisons in 1000 ELEMENT array by using MERGE SORT: " << counter << endl;

    int* arr2 = new int[10000];  // create an array contains that 10000 elements

    for (int i = 0; i < 10000; i++) { // for loop to iterate over 10000 elements
        arr2[i] = rand() ; // assign each random values into the array
    }

    mergeSort(arr2, 0, 10000 - 1); // call the merge sort

    delete[] arr2; // delete array2
    cout << "The number of comparisons in 10000 ELEMENT array by using MERGE SORT: " << counter << endl;

    return 0;
}