#include<iostream>
#include<cstring>

class Crypto{
    private:
        char name[30];
        double lastPrice;
        double currentPrice;
        void erase();

    public:
        Crypto();
        Crypto(char* name);
        Crypto(char* name, double currentPrice);
        Crypto(char* name, double currentPrice, double lastPrice);
        void SetName(const char* _name);
        char* GetName();
        void SetLastPrice(double lastPrice);
        double GetLastPrice();
        void SetCurrentPrice(double currentPrice);
        double GetCurrentPrice();
        void priceDifference();
        void print();
        ~Crypto();

};