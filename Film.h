#include <iostream>
#include <cstring>

class Film{
private:
    char* filmName;
    char* producerName;
    size_t rewards;
    void copy(const Film& other);
    void erase();
public:

    Film();
    Film(const Film& other);
    Film& operator=(const Film& other);
    ~Film();

    void setFilmName(const char* _name);
    char* getFilmName();
    void setProducerName(const char* _name);
    char* getProducerName();
    void setRewards(size_t rewards);
    size_t getRewards();
    void print();

};