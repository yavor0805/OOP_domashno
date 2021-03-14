#include "FilmRanking.h"
#include<iostream>

void swap(Film* film1, Film* film2)  
{  
    Film temp = *film1;  
    *film1 = *film2;  
    *film2 = temp;  
}

void bubbleSort(Film arr[], int n)  
{  
    for (int i = 0; i < n-1; i++)      
        for (int j = 0; j < n-i-1; j++)  
            if (arr[j].getRewards() < arr[j+1].getRewards()) 
                swap(&arr[j], &arr[j+1]);  
}

void FilmRanking::copy(const FilmRanking& other){
    this->size = other.size;
    this->count = other.count;
    this->films = new Film[size];
    for(int i = 0; i < count; i++){
        this->films[i]=other.films[i];
    }
};

void FilmRanking::erase(){
    delete[] films;
}

FilmRanking::FilmRanking(){
    this->films = new Film[1];
    this->films[0] = Film();
    this->size = 1;
    this->count= 0;        
}

FilmRanking::FilmRanking(const FilmRanking& other){
    this->copy(other);
}

FilmRanking& FilmRanking::operator=(const FilmRanking& other){
    if(this != &other){
        this->erase();
        this->copy(other);
    }
    return *this;
}

FilmRanking::~FilmRanking(){
    this->erase();
}

size_t FilmRanking::getSize(){
    return this->size;
}

size_t FilmRanking::getCount(){
    return this->count;
}

Film FilmRanking::getFilm(int id){
    if(id > count || id < 0) std::cout << "No such id" << std::endl;
    else return films[id];
}

void FilmRanking::addFilm(const Film& film){
    if(count == size){
        Film* temp = new Film[size];
        for(int i = 0; i < count;i++){
            temp[i] = films[i];
        }
        this->size = size*2;
        this->films = new Film[size];
        for(int i = 0; i < count;i++){
            films[i]=temp[i];
        }
        films[count] = film;
        delete[] temp;
        count++;
    }
    else{
        films[count] = film;
        count++;
    }
}

void FilmRanking::printTopN(size_t n){
    bubbleSort(films, this->count);
    if(n > this->count){
        for(int i = 0; i < count; i++){
            std::cout << i+1 << ": ";
            films[i].print();
        }
    }
    else{
        for(int i = 0; i < n; i++){
            std::cout << i+1 << ": ";
            films[i].print();
        }
    }
}

void FilmRanking::print(){
    for(int i = 0; i < count; i++){
        std::cout<< i << ": ";
        films[i].print();
    }
}





