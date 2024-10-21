
#include <iostream>
#include <string>

using namespace std;

string encryptCeaserCipher(string message, int shift)
{
    string encryptedMessage;
    for (int i = 0; i < message.length(); i++)
    {
        if (isalpha(message[i]))
        {
            char base = isupper(message[i]) ? 'A' : 'a';
            encryptedMessage += char((message[i] - base + shift) % 26 + base);
        }
        else
        {
            encryptedMessage += message[i];
        }
    }
    return encryptedMessage;
}

string decryptCeaserCipher(string encryptedMessage, int shift)
{
    string decryptedMessage;
    for (int i = 0; i < encryptedMessage.length(); i++)
    {
        if (isalpha(encryptedMessage[i]))
        {
            char base = isupper(encryptedMessage[i]) ? 'A' : 'a';
            decryptedMessage += char((encryptedMessage[i] - base - shift + 26) % 26 + base);
        }
        else
        {
            decryptedMessage += encryptedMessage[i];
        }
    }
    return decryptedMessage;
}

int main()
{
    string message;
    int shift;

    cout << "Enter Message: ";
    getline(cin, message);

    cout << "Enter Shift: ";
    cin >> shift;

    string encrypted = encryptCeaserCipher(message, shift);
    string decrypted = decryptCeaserCipher(encrypted, shift);

    cout << "Ceaser Cipher Encrypted: " << encrypted << endl;
    cout << "Ceaser Cipher Decrypted: " << decrypted << endl;

    return 0;
}

