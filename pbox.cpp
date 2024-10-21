#include <iostream>
using namespace std;

// Function to perform P-box permutation
void pbox_permutation(int input[32], int output[32], int pbox[32]) {
    for (int i = 0; i < 32; i++) {
        output[i] = input[pbox[i] - 1];
    }
}

int main() {
    int sbox_output[32] = { /* Output from S-boxes */ };
    int permuted_output[32];

    int pbox[32] = {
        16, 7, 20, 21, 29, 12, 28, 17,
        1, 15, 23, 26, 5, 18, 31, 10,
        2, 8, 24, 14, 32, 27, 3, 9,
        19, 13, 30, 6, 22, 11, 4, 25
    };

    // Perform P-box permutation
    pbox_permutation(sbox_output, permuted_output, pbox);

    cout << "P-box permuted output: ";
    for (int i = 0; i < 32; i++) {
        cout << permuted_output[i] << " ";
    }
    cout << endl;
}
