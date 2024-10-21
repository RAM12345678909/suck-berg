#include <iostream>
using namespace std;

// Function to perform left circular shift
void leftShift(int* key_half, int shifts) {
    for (int i = 0; i < shifts; i++) {
        int temp = key_half[0];
        for (int j = 1; j < 28; j++) {
            key_half[j - 1] = key_half[j];
        }
        key_half[27] = temp;
    }
}

int main() {
    // Initial 64-bit key (example)
    int key[64] = {
        0, 1, 1, 0, 1, 0, 0, 1,
        1, 0, 0, 1, 1, 1, 0, 0,
        0, 1, 0, 1, 1, 0, 1, 0,
        1, 0, 1, 0, 0, 0, 1, 1,
        1, 0, 1, 0, 0, 1, 1, 0,
        0, 0, 1, 1, 1, 0, 1, 0,
        0, 1, 0, 1, 1, 1, 0, 0,
        1, 0, 1, 0, 0, 1, 0, 1
    };

    // Permutation choice 1 (PC-1) to reduce 64 bits to 56 bits
    int pc1[56] = {
        57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4
    };

    // Key after PC-1 permutation
    int key_56_bit[56];
    for (int i = 0; i < 56; i++) {
        key_56_bit[i] = key[pc1[i] - 1];
    }

    // Splitting key into two halves
    int left_key[28], right_key[28];
    for (int i = 0; i < 28; i++) {
        left_key[i] = key_56_bit[i];
        right_key[i] = key_56_bit[i + 28];
    }

    // Number of left shifts for each round
    int left_shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

    // Permutation choice 2 (PC-2) to reduce 56 bits to 48 bits
    int pc2[48] = {
        14, 17, 11, 24, 1, 5, 3, 28,
        15, 6, 21, 10, 23, 19, 12, 4,
        26, 8, 16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55, 30, 40,
        51, 45, 33, 48, 44, 49, 39, 56,
        34, 53, 46, 42, 50, 36, 29, 32
    };

    // Generate 16 round keys
    int round_keys[16][48];
    for (int round = 0; round < 16; round++) {
        // Left shift both halves
        leftShift(left_key, left_shifts[round]);
        leftShift(right_key, left_shifts[round]);

        // Combine left and right halves
        int combined_key[56];
        for (int i = 0; i < 28; i++) {
            combined_key[i] = left_key[i];
            combined_key[i + 28] = right_key[i];
        }

        // Apply PC-2 permutation to get 48-bit round key
        for (int i = 0; i < 48; i++) {
            round_keys[round][i] = combined_key[pc2[i] - 1];
        }

        // Output round key for demonstration
        cout << "Round " << round + 1 << " key: ";
        for (int i = 0; i < 48; i++) {
            cout << round_keys[round][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
