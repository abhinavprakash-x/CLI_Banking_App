// #include <iostream>
// #include <vector>
// #include <string>
// #include <cmath>
// using namespace std;

// // Convert string to hex
// string toHex(const string& input) {
//     const char* hexDigits = "0123456789abcdef";
//     string hex;
//     for (unsigned char c : input) {
//         hex.push_back(hexDigits[(c >> 4) & 0xF]);
//         hex.push_back(hexDigits[c & 0xF]);
//     }
//     return hex;
// }

// string encrypt(const string& password) {
//     string step1 = password;
//     vector<int> step2(password.size());
//     string step3;

//     for (size_t i = 0; i < password.length(); ++i) {
//         step1[i] += 4;                     // shift
//         step2[i] = int(step1[i]);          // convert to int
//         step2[i] /= 2;                     // divide by 2
//         step2[i] = int(pow(step2[i], 1.069420)); // nonlinear pow
//         step3.push_back(char(step2[i] % 256));   // prevent overflow
//     }
//     return toHex(step3);
// }

// int main() {
//     string password;
//     cout << "Enter Password: ";
//     cin >> password;

//     string encrypted = encrypt(password);
//     cout << "Encrypted (hex): " << encrypted << endl;
// }


#include<iostream>
using namespace std;

string hash_password(const string& password) {
    return std::to_string(hash<string>{}(password));
}

int main(){
    cout<< hash_password("Admin@123");
    return 0;
}