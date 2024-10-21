#include <iostream>
#include <string>
#include <bitset>
using namespace std;

// Function to perform S-box substitution
int sbox_substitute(int input, int sbox[4][16]) {
    int row = ((input & 0x20) >> 4) | (input & 0x01); // Extract row bits
    int col = (input & 0x1E) >> 1;                    // Extract column bits
    return sbox[row][col];
}

int main() {
    int xor_result[48] = { /* XOR result of right part and key (48 bits) */ };

    int sbox1[4][16] = {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    };

    // Perform S-box substitution for each 6-bit block of the XOR result
    for (int i = 0; i < 48; i += 6) {
        int input = (xor_result[i] << 5) | (xor_result[i + 1] << 4) |
                    (xor_result[i + 2] << 3) | (xor_result[i + 3] << 2) |
                    (xor_result[i + 4] << 1) | xor_result[i + 5];

        int output = sbox_substitute(input, sbox1);
        cout << "S-box output: " << output << endl;
    }
}
