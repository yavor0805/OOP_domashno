#include<iostream>
#include<cstring>

class Crypto{
    private:
        char name[30];
        double lastPrice;
        double currentPrice;

    public:
        Crypto(){
            SetName("NONE");
            SetCurrentPrice(0.0);
            SetLastPrice(0.0);
        }
        Crypto(char* name){
            SetName(name);
            SetCurrentPrice(0.0);
            SetLastPrice(0.0);
        }
        Crypto(char* name, double currentPrice){
            SetName(name);
            SetCurrentPrice(currentPrice);
            SetLastPrice(0.0);
        }
        Crypto(char* name, double currentPrice, double lastPrice){
            SetName(name);
            SetCurrentPrice(currentPrice);
            SetLastPrice(lastPrice);
        }

        void SetName(char* name){
            if(strlen(name) >= 30){
                std::cout << "Name is too long. Setting to default.\n";
                strcpy(this->name, "NONE");
            }
            else{
                strcpy(this->name, name);
            }
        }
        char* GetName(){
            return name;
        }


        void SetLastPrice(double lastPrice){
            if(lastPrice < 0) {
                std::cout<<"Last Price can't be negative! Setting to default 0.\n";
                this->lastPrice = 0;
            }
            else this->lastPrice = lastPrice;
        }
        double GetLastPrice(){
            return lastPrice;
        }


        void SetCurrentPrice(double currentPrice){
            SetLastPrice(this->currentPrice);
            if(currentPrice < 0){
            std::cout<<"Current Price can't be negative! Setting to default 0.\n";
            this->currentPrice = 0;
            }
            else this->currentPrice = currentPrice;
        }
        double GetCurrentPrice(){
            return currentPrice;
        }


        void priceDifference(){
            double difference, percentage;
            if(lastPrice > currentPrice){
                difference = lastPrice - currentPrice;
                percentage = (difference / lastPrice) * 100;
                std::cout << "Price difference: -" << percentage << "%" << std::endl;
            }
            else{
                difference = currentPrice - lastPrice;
                percentage = (difference / lastPrice) * 100;
                std::cout << "Price difference: " << percentage << "%" << std::endl;
            }
        }

        void print(){
            printf("\nName: %s\n", name);
            std::cout << "Current Price: " << currentPrice << "\n";
            std::cout << "Last Price: " << lastPrice << std::endl;
        }


    ~Crypto(){
        delete name;
    }

};