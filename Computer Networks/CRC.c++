#include <iostream>
#include <string>
using namespace std;

string xorOperation(string a, string b) {
    string result = "";
    for (int i = 1; i < b.length(); i++) {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

string mod2div(string dividend, string divisor) {
    int pick = divisor.length();
    string temp = dividend.substr(0, pick);

    while (pick < dividend.length()) {
        if (temp[0] == '1')
            temp = xorOperation(divisor, temp) + dividend[pick];
        else
            temp = xorOperation(string(pick, '0'), temp) + dividend[pick];
        pick++;
    }

    if (temp[0] == '1')
        temp = xorOperation(divisor, temp);
    else
        temp = xorOperation(string(pick, '0'), temp);

    return temp;
}

void crc() {
    string data, divisor;
    cout << "Enter data: ";
    cin >> data;
    cout << "Enter divisor: ";
    cin >> divisor;

    string appendedData = data + string(divisor.length() - 1, '0');
    string remainder = mod2div(appendedData, divisor);
    string codeword = data + remainder;

    cout << "Transmitted codeword: " << codeword << endl;
}

int main() {
    crc();
    return 0;
}
