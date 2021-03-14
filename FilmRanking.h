#include "Film.cpp"
#include <iostream>
#include <cstring>

class FilmRanking{
    private:
        size_t size;
        size_t count;
        Film* films;

        void copy(const FilmRanking& other);
        void erase();

    public:    
        FilmRanking();
        FilmRanking(const FilmRanking& other);
        FilmRanking& operator=(const FilmRanking& other);
        ~FilmRanking();

        size_t getSize();
        size_t getCount();
        Film getFilm(int id);
        void addFilm(const Film& film);
        void printTopN(size_t n);
        void print();
};


