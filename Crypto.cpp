#include "Crypto.h"

using namespace std;

int main(){

    Crypto test = Crypto("TEst", 1.5, 0.0015);
    test.SetCurrentPrice(0.1);
    test.priceDifference();
    test.print();

    return 0;
}