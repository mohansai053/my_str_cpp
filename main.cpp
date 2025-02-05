#include"header.h"
using namespace std;

int main()
{
    mystring var;
    cin>>var;
    cout <<"Entered String is : "<< var << endl;

    mystring var2;
    cin >> var2;
    var = var + var2;

    cout <<"Modified String is : "<< var <<endl;

    return 0;
}