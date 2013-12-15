#include <iostream>
#include <limits>

using namespace std;

int main( )
{
    cout << "The maximum value for type float is:  "
         << numeric_limits<float>::max()   
         << endl;
    cout << "The maximum value for type double is:  "
         << numeric_limits<double>::max()
         << endl;
    cout << "The maximum value for type float is:  "
         << numeric_limits<int>::max()
         << endl;
    cout << "The maximum value for type short int is:  "
         << numeric_limits<short int>::max()
         << endl;
    cout << "The maximum value for type int is: "
         << numeric_limits<int>::max()
         << endl;
    return 0;
}
