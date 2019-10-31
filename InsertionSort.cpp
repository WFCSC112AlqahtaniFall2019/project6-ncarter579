#include <iostream>
#include <vector>
#include <cassert>
#include "BinaryInsertionSort.h"
#include "Node.h"
#include "LinkedList.h"
#include <ctime>
using namespace std;

int main() {
        int seed, length;
        cin >> seed >> length;
        srand(seed);

        LinkedList list;  //creating the linked list

        vector<int> v(length);

        // generate vector of random integers
        int random;   //creating a variable to store the random number generated in
        for (int i = 0; i < v.size(); i++) {
            random = rand() % 100;
            v[i] = random;
            list.append(random);    //appending values to the list
        }

        // binary insertion sort
        clock_t start_binaryInsertionSort = clock();  //using clocks to track time it takes for sort function to complete
        insertionSort(v, v.size());
        clock_t end_binaryInsertionSort = clock();

        // check if sorted
        for (int i = 1; i < v.size(); i++) {
            assert(v[i - 1] <= v[i]);
        }

        cout << "Printing binary insertion sort" << endl;
        // print out sorted list
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        // FINISH ME
        cout << "InsertionSort before sorting" << endl;
        list.print();  //printing the list before sorting
        cout << endl;

        clock_t start_InsertionSort = clock();   //using clocks to track time it takes for sort function to complete
        list.InsertionSort();    //calling the InsertionSort function
        clock_t end_InsertionSort = clock();

        cout << "InsertionSort after sorting" << endl;
        list.print();   //printing the list after it's been sorted
        cout << endl;

        //calculating the time it took each function and storing the time in a variable
        double elapsed_binaryInsertionSort = double(end_binaryInsertionSort - start_binaryInsertionSort) / CLOCKS_PER_SEC;
        double elapsed_InsertionSort = double(end_InsertionSort - start_InsertionSort) / CLOCKS_PER_SEC;

        cout << elapsed_binaryInsertionSort << " " << elapsed_InsertionSort << endl;  //printing variables to the user
}