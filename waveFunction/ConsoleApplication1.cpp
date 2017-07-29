// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void pauseExecution() {
    int xyz;
    cin >> xyz;
}


void swapElements(vector<int> &A, int i, int j) {
    A[i] = A[i] + A[j];
    A[j] = A[i] - A[j];
    A[i] = A[i] - A[j];
}

void createWaveAtIndex(vector<int> &A, int i) {
    //cout << "createWaveAtIndex for " << 
    int n = A.size();
    if ((i + 2) <= (n - 1)) {
        if (A[i] >= max(A[i + 1], A[i + 2])) {
            if (A[i + 1] > A[i + 2]) {
                swapElements(A, i + 1, i + 2);
            }
        }
        else if ((A[i] >= min(A[i + 1], A[i + 2])) && (A[i] <= max(A[i + 1], A[i + 2]))) {
            if (A[i + 1] > A[i + 2]) {
                swapElements(A, i + 1, i + 2);
            }
        }
        else if (A[i] >= max(A[i + 1], A[i + 2])) {
            swapElements(A, i, i + 2);
            if (A[i] <= A[i + 1]) {
                swapElements(A, i, i + 1);
            }
        }
        else { // A[i] <= min(A[i+1], A[i+2]))
            swapElements(A, i, i + 1);
            if (A[i] > A[i + 2]) {
                swapElements(A, i, i + 2);
            }
        }
        createWaveAtIndex(A, (i + 2));
    }
    else if ((i + 1) <= (n - 1)) {
        if (A[i] < A[i + 1]) {
            swapElements(A, i, i + 1);
        }
        return;
    }
    else {
        return;
    }
}

void sortTheArray(vector<int> &A, int i, int start, int n) {
    if (i == 0) {
        return;
    }

    if (n <= 1) {
        if (A[i] >= A[start]) {
            A.insert(A.begin() + start + 1, A[i]);
        }
        else {
            A.insert(A.begin() + start, A[i]);
        }

        A.erase(A.begin() + i + 1);

        if ((i + 1) < A.size()) {
            sortTheArray(A, i + 1, 0, i + 1);
        }
        return;
    }

    if (n % 2 != 0) { // size is odd
        if (A[i] >= A[floor(start + ((n - 1) / 2))]) { // in the upper half
            sortTheArray(A, i, (start + ((n - 1) / 2)), (n + 1) / 2);
        }
        else { // in the lower half
            sortTheArray(A, i, start, (n + 1) / 2);
        }
    }
    else { // size is even
        if (A[i] >= A[floor(start + (n / 2))]) { // in the upper half
            sortTheArray(A, i, (start + (n / 2)), (n / 2));
        }
        else { // in the lower half
            sortTheArray(A, i, start, (n / 2));
        }
    }
}

vector<int> wave(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    // sort the array first:
    sortTheArray(A, 1, 0, 1);

    createWaveAtIndex(A, 0);

    return A;
}

int main()
{
    vector<int> A = { 5,1,3,2,4 };

    wave(A);
    //int n = A.size();
    //for (int i = 0; i < n; i++) {
    //    cout << "A[i] -- " << i << " : " << A[i] << endl;
    //}

    pauseExecution();
    return 0;
}


