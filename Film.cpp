#include "Film.h"

using namespace std;


int main(){

    Film test = Film();
    test.setFilmName("Jurassic Park");
    test.setProducerName("Steven Spielberg");
    test.setRewards(10);


    Film test2 = Film();

    test2 = test;

    test.setProducerName("Todd Phillips");
    
    
    test.print();
    test2.print();


    return 0;
}