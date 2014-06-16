#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool compareBinToHex(string binary, string hex);
int digitToValue(char c);
int convertToBase(string number, int base);

int main(int argc, char const *argv[])
{
	string binary, hex;
	binary = "1010";
	hex = "A";
	if (compareBinToHex(binary,hex))
	{
		cout << "hello" << endl;
	}
	return 0;
}

bool compareBinToHex(string binary, string hex)
{
	int n1 = convertToBase(binary,2);
	int n2 = convertToBase(hex,16);
	if (n1 < 0 || n2 < 0){
		return false;
	}else{
		return n1 == n2;
	}
}

int convertToBase(string number, int base)
{
	if (base < 2 || (base > 2 && base != 16))
		return -1;
	int value = 0;
	for (int i = number.length()-1; i >= 0; i--){
        int digit = digitToValue(number[i]);
        if(digit < 0 || digit >= base)
            return -1;
        int exp = number.length() - i -1;
        value += digit * pow(base,exp);
	}
	return value;
}

int digitToValue(char c)
{
    if(c >= '0' && c <= '9')
        return c-'0';
    else if(c >= 'A' && c <= 'F')
        return 10 + c - 'A';
    else if(c >= 'a' && c <= 'f')
        return 10 + c - 'a';
    return -1;
}
