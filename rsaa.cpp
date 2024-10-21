// RSA Encryption and Decryption
#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to calculate modular exponentiation (to handle large powers mod n)
long long modExp(long long base, int exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    // Step 1: Input two prime numbers
    cout << "Enter two prime numbers (p and q):" << endl;
    int p, q;
    cin >> p >> q;

    // Step 2: Calculate n and φ(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Step 3: Choose an encryption key e such that 1 < e < φ(n) and gcd(e, φ(n)) = 1
    int e = 3;
    while (gcd(e, phi) != 1) {
        e++;
    }
    cout << "Chosen public key 'e' = " << e << endl;

    // Step 4: Calculate decryption key 'd' such that (d * e) % φ(n) = 1
    int d = 0;
    for (int i = 1; ; i++) {
        if ((1 + i * phi) % e == 0) {
            d = (1 + i * phi) / e;
            break;
        }
    }
    cout << "Calculated private key 'd' = " << d << endl;

    // Step 5: Input the message to be encrypted (must be less than n)
    cout << "Enter a number to be encrypted (less than n = " << n << "):" << endl;
    int message;
    cin >> message;

    if (message >= n) {
        cout << "Number can't be encrypted, it should be less than n." << endl;
        return 1;
    }

    // Step 6: Encrypt the message: ciphertext = (message^e) % n
    int encrypted = modExp(message, e, n);
    cout << "Encrypted text: " << encrypted << endl;

    // Step 7: Decrypt the message: decrypted = (ciphertext^d) % n
    int decrypted = modExp(encrypted, d, n);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
