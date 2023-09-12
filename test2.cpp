
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



void sum(unsigned int& a, unsigned int& b, int expLength, int manLength, unsigned int& sign_res, unsigned int& exp_res, unsigned int& man_res)
{
    unsigned long long result = 0;

    unsigned int signA = a >> (expLength + manLength);
    int expA = ((a >> manLength) & (0xffff >> (16 - expLength)));
    unsigned int manA = a & (0x7FFFFFF >> (27 - manLength));

    unsigned int signB = b >> (expLength + manLength);
    int expB = ((b >> manLength) & (0xffff >> (16 - expLength)));
    unsigned int manB = b & (0x7FFFFFF >> (27 - manLength));

    unsigned int signRes = signA ^ signB;
    manA = manA | (0x8000000 >> (27 - manLength));
    manB = manB | (0x8000000 >> (27 - manLength));

    int exp;
    if (expA == expB)
        exp = expA;
    else if ((expA > expB) and (expA - expB <= manLength))
    {
        exp = expA - expB;
        manB >>= exp;
        exp = expA;
    }
    else if ((expB > expA) and (expA - expB <= manLength))
    {
        exp = expB - expA;
        manA >>= exp;
        exp = expB;   
    }
    unsigned long long manRes = 0;
    if ((expA>expB and expA-expB<= manLength) or (expB > expA and expB - expA <= manLength))
    {
        while (manB != 0)
        {
            manRes = manA & manB;
            manA ^= manB;
            manB = manRes << 1;
        }
        manRes = manA;
    }
    else 
    {
        if (expA > expB) 
        {
            manRes = manA;
        }
        else 
        {
            manRes = manB;
        }
    }
    
    cout << manRes << endl;
    cout << exp << endl;

    manRes=

    result = 0;
                                                 cout <<"1-----   "<< result << endl << endl;
    result += manRes;
                                                 cout << "2-----   " << result << endl << endl;
    result += exp << manLength;
                                                 cout << "3-----   " << result << endl << endl;
    result += signRes << (manLength + expLength);
                                                 cout << "4-----   " << result << endl << endl;

    sign_res = signRes;
    exp_res = exp;
    man_res = manRes;


    //(manRes && (0x8000000 >> (27 - manLength)))

}


int main()
{
    setlocale(LC_ALL, "rus");

    int manLength = 23;
    int expLength = 8;
    unsigned int sign_res=0, exp_res=0, man_res=0;
    //cout << "¬ведите размер экспаненты и мантисы" << endl;

   // cin >> expLength;

    //cin >> manLength;

    float_num num1(0b01000000110001000001001001000000u);
    num1.print(expLength, manLength);
    float_num num2(0b01000001110001000001001001001000u);
    num2.print(expLength, manLength);
    sum(num1.numBin, num2.numBin, expLength, manLength, sign_res, exp_res, man_res);

    //float_num num3(sum(num1.numBin, num2.numBin, expLength, manLength));
    cout << "RESULT:" << endl;

    cout << sign_res<<endl;
    cout << exp_res << endl;
    cout << man_res << endl;


}