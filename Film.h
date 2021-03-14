#include <iostream>
#include <cstring>

class Film{
    private:
        char* filmName;
        char* producerName;
        size_t rewards;
        void copy(const Film& other){
            this->filmName = new char[strlen(other.filmName)+1];
            strcpy_s(this->filmName, strlen(other.filmName)+1, other.filmName);

            this->producerName = new char[strlen(other.producerName)+1];
            strcpy_s(this->producerName, strlen(other.producerName)+1, other.producerName);

            this->rewards = other.rewards;
        };
        void erase(){
            delete[] this->filmName;
            delete[] this->producerName;
        };
    public:

        Film(){
            this->filmName = new char[1];
            this->filmName[0] = '\0';

            this->producerName = new char[1];
            this->producerName[0] = '\0';

            this->rewards = 0;
            
        }
        Film(const Film& other){
            this->copy(other);
        }
        Film& operator=(const Film& other){
            if(this != &other){
                this->erase();
                this->copy(other);
            }
            return *this;
        }
        ~Film(){
            this->erase();
        }


        void setFilmName(const char* _name){
            	delete[] this->filmName;
	            this->filmName = new char[strlen(_name) + 1];
	            strcpy_s(this->filmName, strlen(_name) + 1, _name);
        }
        char* getFilmName(){
            return this->filmName;
        }
        void setProducerName(const char* _name){
                delete[] this->producerName;
	            this->producerName = new char[strlen(_name) + 1];
	            strcpy_s(this->producerName, strlen(_name) + 1, _name);
        }
        char* getProducerName(){
            return this->producerName;
        }
        void setRewards(size_t rewards){
            this->rewards = rewards;
        }
        size_t getRewards(){
            return this->rewards;
        }

        void print(){
            std::cout << "Film Name: " << this->filmName;
            std::cout << "\tProducer Name: " << this->producerName;
            std::cout << "\tRewards: " << this->rewards << std::endl;
        }

};