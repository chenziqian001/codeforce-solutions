#include <iostream>
#include <bitset>
#include <cstring>  // memcpy

using namespace std;

void printFloatBinary(float f) {
    unsigned int bits = 0;
    // 把float内存按整型读出来
    memcpy(&bits, &f, sizeof(float));
    
    bitset<32> b(bits);
    cout << "float value: " << f << "\n";
    cout << "binary (32 bits): " << b << "\n";

    // 拆分各个部分
    unsigned int sign = (bits >> 31) & 1;
    unsigned int exponent = (bits >> 23) & 0xFF;
    unsigned int mantissa = bits & 0x7FFFFF;

    cout << "sign: " << sign << "\n";
    cout << "exponent (raw): " << exponent << " (actual exponent = " << (int)exponent - 127 << ")\n";
    cout << "mantissa: " << mantissa << "\n";

    cout << "符号位占1位，指数8位，尾数23位，符合IEEE 754单精度格式。\n";
}

int main() {
    float f;
    cout << "输入一个float值: ";
    cin >> f;
    printFloatBinary(f);
    system("pause");
    return 0;
}
