#include <iostream>
#include <cstring>
using namespace std;

void cls();
void draw();
void cls_draw();
bool isUpper(char);
string Encrypt(string cleanText, int key);
string Decrypt(string cipherText, int key);

int main() {

    string cleanText = "" , cipherText = "";
    int i , key;
    char op;

    cls_draw();
    cout << "-1- To Encrypt " << endl;
    cout << "-2- To Decrypt " << endl;
    cout << "-3- Exit" << endl;
    cout << "Choose one of them: ";
    cin >> op;

    switch (op) {
    case '1':
        cout << "Enter The Text You Want To Encrypt: ";
        cin >> cleanText;

        cout << "Enter The Key: ";
        cin >> key;

        cls_draw();
        cout << "Encrypted Text ===> " << Encrypt(cleanText, key) << endl;
        break;
    case '2':
        cout << "Enter The Text You Want To Decrypt: ";
        cin >> cipherText;

        cout << "Enter The Key: ";
        cin >> key;

        cls_draw();
        cout << "Decrypted Text ===> " << Decrypt(cipherText, key) << endl;
        break;
    case '3':
        cout << "Good Bye! " << endl;
        system("exit");
        break;
    default:
        cls_draw();
        cout << "Invalid Error!" << endl;
        break;
    }

    return 0;
}

void cls() {
    if (system("cls")) system("clear");
}

void draw() {
    cout << "\t\t    ██████  █████  ███████ ███████  █████  ██████       ██████ ██ ██████  ██   ██ ███████ ██████" << endl;
    cout << "\t\t   ██      ██   ██ ██      ██      ██   ██ ██   ██     ██      ██ ██   ██ ██   ██ ██      ██   ██ " << endl;
    cout << "\t\t   ██      ███████ █████   ███████ ███████ ██████      ██      ██ ██████  ███████ █████   ██████  " << endl;
    cout << "\t\t   ██      ██   ██ ██           ██ ██   ██ ██   ██     ██      ██ ██      ██   ██ ██      ██   ██ " << endl;
    cout << "\t\t    ██████ ██   ██ ███████ ███████ ██   ██ ██   ██      ██████ ██ ██      ██   ██ ███████ ██   ██ " << endl;
    cout << "\t\t\t\t\t\t\t\t\t V 1.0" << endl;
}

void cls_draw() {
    cls();
    draw();
}


bool isUpper(char c) {
    if (c >= 65 && c <= 90)
        return true;
    else
        return false;
}

string Encrypt(string cleanText, int key) {

    string cipherText = "";

    for (int i = 0; i < cleanText.length(); i++) {

        if (isUpper(cleanText[i]))
            cipherText += char(int(cleanText[i] + key - 65)% 26 + 65);
        else
            cipherText += char(int(cleanText[i] + key - 97)% 26 + 97);
    }
    return cipherText;
}

string Decrypt(string cipherText, int key) {

    string cleanText = "";

    for (int i = 0; i < cipherText.length(); i++) {

      if (isUpper(cipherText[i]))
          cleanText += char(int(cipherText[i] - key - 65)% 26 + 65);
      else
          cleanText += char(int(cipherText[i] - key - 97)% 26 + 97);
    }
    return cleanText;
}
