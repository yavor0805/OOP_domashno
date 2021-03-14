#include "Crypto.h"


void Crypto::erase(){
    delete[] this->name;
}

Crypto::Crypto(){
    SetName("NONE");
    SetCurrentPrice(0.0);
    SetLastPrice(0.0);
}

Crypto::Crypto(char* name){
    SetName(name);
    SetCurrentPrice(0.0);
    SetLastPrice(0.0);    
}

Crypto::Crypto(char* name, double currentPrice){
    SetName(name);
    SetCurrentPrice(currentPrice);
    SetLastPrice(0.0);
}

Crypto::Crypto(char* name, double currentPrice, double lastPrice){
    SetName(name);
    SetCurrentPrice(currentPrice);
    SetLastPrice(lastPrice);
}

void Crypto::SetName(const char* _name){
    if(strlen(name) >= 30){
        std::cout << "Name is too long. Setting to default.\n";
        strcpy(this->name, "NONE");
    }
    else{
	    strcpy_s(this->name, _name);
    }
}

char* Crypto::GetName(){
    return name;
}

void Crypto::SetLastPrice(double lastPrice){
    if(lastPrice < 0) {
        std::cout<<"Last Price can't be negative! Setting to default 0.\n";
        this->lastPrice = 0;
    }
        else this->lastPrice = lastPrice;
}

double Crypto::GetLastPrice(){
        return this->lastPrice;
}

void Crypto::SetCurrentPrice(double currentPrice){
            SetLastPrice(this->currentPrice);
            if(currentPrice < 0){
            std::cout<<"Current Price can't be negative! Setting to default 0.\n";
            this->currentPrice = 0;
            }
            else this->currentPrice = currentPrice;
        }

double Crypto::GetCurrentPrice(){
            return currentPrice;
}


void Crypto::priceDifference(){
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

void Crypto::print(){
    printf("\nName: %s\n", name);
    std::cout << "Current Price: " << currentPrice << "\n";
    std::cout << "Last Price: " << lastPrice << std::endl;
}


Crypto::~Crypto(){
    this->erase();
}


