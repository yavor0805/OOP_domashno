#include "FilmRanking.cpp"
#include "Crypto.cpp"
#include <iostream>

using namespace std;

int main(){


    Crypto cTest = Crypto("Test", 1.5, 0.0015);
    cTest.SetCurrentPrice(153.2);
    cTest.priceDifference();
    cTest.print();

    

    Film test = Film();
    test.setFilmName("The Dark Knight Rises");
    test.setProducerName("Christopher Nolan");
    test.setRewards(10);


    Film test2 = Film();
    test2.setFilmName("Jurassic Park");
    test2.setProducerName("Steven Spielberg");
    test2.setRewards(5);

    Film test3 = Film();
    test3.setFilmName("U.S.A");
    test3.setProducerName("Dubioza Kolektiv");
    test3.setRewards(1); 

    Film test4 = Film();
    test4.setFilmName("Joker");
    test4.setProducerName("Todd Phillips");
    test4.setRewards(50); 

    Film test5 = Film();
    test5.setFilmName("Interstellar");
    test5.setProducerName("Christopher Nolan");
    test5.setRewards(69); 

    FilmRanking ranking = FilmRanking();
    ranking.addFilm(test);    
    ranking.addFilm(test2);
    ranking.addFilm(test3);
    ranking.addFilm(test4);
    ranking.addFilm(test5);



    FilmRanking ranking2 = FilmRanking(ranking); 
    Film test6 = Film();
    test6.setFilmName("The Godfather");
    test6.setProducerName("Francis Ford Coppola");
    test6.setRewards(500); 

    ranking2.addFilm(test6);

    FilmRanking ranking3 = ranking2;

    Film test7 = Film();
    test7.setFilmName("Schindler's List");
    test7.setProducerName("Steven Spielberg");
    test7.setRewards(101); 

    ranking3.addFilm(test7);


    ranking.printTopN(3);
    cout << "\n------------------------\n";
    ranking2.printTopN(4);
    cout << "\n------------------------\n";
    ranking3.printTopN(ranking3.getCount());

    return 0;
}