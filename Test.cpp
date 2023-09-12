/*
#include <iostream>
#include <bitset>
#include <climits>
#include <iomanip>
#include <intrin.h>

using namespace std;





struct float_num
{
    float_num(unsigned int numVal)
    {
        num = *reinterpret_cast<float*>(&numVal);
        numBin = numVal;
    }
    float_num(float numVal)
    {
        num = numVal;
        numBin = *reinterpret_cast<unsigned int*>(&numVal);
    }

    float num;
    unsigned int numBin;


    void print(int expLength, int manLength)
    {
        bitset<32> numBinBit(numBin);
        //cout << hex << "HEX: " << numBin << dec << "\t";
        cout << "BIN: " << numBinBit[manLength + expLength] << " ";
        for (int i = (manLength + expLength - 1); i > (manLength - 1); i--)
        {
            cout << numBinBit[i];
        }
        cout << " ";
        for (int i = (manLength - 1); i >= 0; i--)
        {
            cout << numBinBit[i];
        }

        cout << endl << endl;
        //cout << fixed << setprecision(7) << "DEC: " << num << endl << endl;
    }
};

//--------------------------------------------------------------------------------------------------------




unsigned long long manMult(unsigned int manA, unsigned int manB)//умножение
{
    unsigned long long result = 0;
    unsigned long long bufA = manA;
    while (manB != 0)
    {
        if (manB & 1)
            result += bufA;

        manB >>= 1;
        bufA <<= 1;
    }
    return result;
}

int expAdd(int& expA, int& expB, unsigned long long& manRes, int expLength, int manLength)
{
    expA -= (pow(2, (expLength - 1)) - 1); expB -= (pow(2, (expLength - 1)) - 1);
    int expRes = (expA + expB);
    if (manRes & (0x80000000000000UL >> (56 - ((manLength + 1) * 2)))) expRes++;
    return expRes + (pow(2, (expLength - 1)) - 1);
}

unsigned int mul(unsigned int& a, unsigned int& b, int expLength, int manLength)
{
    unsigned int result = 0;

    unsigned int signA = a >> (expLength + manLength);
    int expA = ((a >> manLength) & (0xffff >> (16 - expLength)));
    unsigned int manA = a & (0x7FFFFFF >> (27 - manLength));

    unsigned int signB = b >> (expLength + manLength);
    int expB = ((b >> manLength) & (0xffff >> (16 - expLength)));
    unsigned int manB = b & (0x7FFFFFF >> (27 - manLength));

    manA = manA | (0x8000000 >> (27 - manLength));
    manB = manB | (0x8000000 >> (27 - manLength));


    unsigned long long manRes = manMult(manA, manB);
    int expRes = expAdd(expA, expB, manRes, expLength, manLength);

    unsigned int signRes = signA ^ signB;

    // “ут надо продолжать

    if (manRes & (0x80000000000000ul >> (56 - (manLength + 1) * 2))) manRes >>= 1;
    manRes &= (0b00111111111111111111111111111111111111111111111111111111ul >> (56 - (manLength + 1) * 2));

    if ((manRes & (0b1100000000000000000000000000 >> (28 - (manLength + 1)))) || ((manRes & 0b0100000000000000000000000000 >> (28 - (manLength + 1)))) && (manRes & (0b0011111111111111111111111111 >> (28 - (manLength + 1))))) manRes += (0b1000000000000000000000000000 >> (28 - (manLength + 1)));

    result = 0;
    result += manRes >> manLength;
    result += expRes << manLength;
    result += signRes << (manLength + expLength);

    return result;
}
//----------------------------------------------------------------------------------------------------------
//void tester()
//{
//    double number = 6.25;
//    unsigned long long bits = *reinterpret_cast<unsigned long long*>(&number);
//    cout << "Double: " << bits << endl;
//    cout << "Size Double: " << sizeof(bits) << endl;
//    bitset<sizeof(bits) * 8> bitset_number{bits};
//    cout << "Binary: " << bitset_number << endl;
//    cout << "Dec: " << bitset_number.to_ullong() << endl;
//}


int main()
{
    setlocale(LC_ALL, "rus");

    int manLength = 23;
    int expLength = 8;

    //cout << "¬ведите размер экспаненты и мантисы" << endl;
    
   // cin >> expLength;

    //cin >> manLength;

    float_num num1(0b01000100110001000001001001000000u);
    num1.print(expLength, manLength);
    float_num num2(0b11000100110001000001001001000000u);
    num2.print(expLength, manLength);
    float_num num3(mul(num1.numBin, num2.numBin, expLength, manLength));
    cout << "RESULT:" << endl;
    num3.print(expLength, manLength);

}
*/