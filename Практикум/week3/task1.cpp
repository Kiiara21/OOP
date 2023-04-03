#include <iostream>
#include <cstring>
#include <cassert>
#include "debug_new.h"
#include <fstream>

struct Duration{
    int minutes;
    int seconds;
};

class Song {

private:

    char* m_name;
    Duration m_duration;
    char* m_genre;

    void erase(){
        delete[] m_name;
        delete[] m_genre;
    }

    void copy(const Song& other){
        setName(other.m_name);
        setGenre(other.m_genre);
        setDuration(other.m_duration.minutes, other.m_duration.seconds);
    }

public:

    Song(){
        setName("");
        setDuration(0, 0);
        setGenre("");
    }

    Song(const char* name, const Duration& duration, const char* genre){
        setName(name);
        setDuration(duration.minutes, duration.seconds);
        setGenre(genre);
    }

    // rule of three

    Song(const Song& other){
        copy(other);
    } 

    Song& operator=(const Song& other){
        if(&other != this){
            erase();
            copy(other);
        }
        return *this;
    } 

    ~Song(){
        erase();
    } 

    const char* getName() const { return m_name; }
    int getMinutes() const { return m_duration.minutes; }
    int getSeconds() const { return m_duration.seconds; }
    const char* getGenre() const { return m_genre; }

    void setName(const char* name){
        delete[] m_name;
        assert(name != nullptr);

        m_name = new (std::nothrow) char[strlen(name) + 1];
        if(!m_name){
            std::cout << "Memory problem!";
            return;
        }
        strcpy(m_name, name);
    }

    void setDuration(const int minutes, const int seconds){
        m_duration.minutes = minutes;
        m_duration.seconds = seconds;
    }

    void setGenre(const char* genre){
        delete[] m_genre;
        assert(genre != nullptr);

        m_genre = new (std::nothrow) char [strlen(genre) + 1];
        if(!m_genre){
            std::cout << "Memory porblem!";
            return;
        }

        strcpy(m_genre, genre);
    }

    void print() const {
        std::cout << m_name << " " << m_duration.minutes << ":" << m_duration.seconds << " " << m_genre << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Song& song);

};

std::ostream& operator<<(std::ostream& out, const Song& song){
    out << song.m_name << " " << song.m_genre << "\n";
    return out;
}

const int INITIAL_CAPACITY = 2;
const int INCREASE_STEP = 2;

class Playlist {

private:

    char* m_name;
    Song* m_songs;
    int m_numberOfSongs;
    int m_capacity;

    void erase(){
        delete[] m_songs; // call destructor of Song class
        delete[] m_name;
    }

    void copy(const Playlist& other){
        m_songs = new (std::nothrow) Song [other.m_capacity];
        if(!m_songs){
            std::cout << "Memory problem!";
            return;
        }
        for(int i = 0; i < m_numberOfSongs; ++i){
            m_songs[i] = other.m_songs[i];
        }

        setName(other.m_name);
        m_numberOfSongs = other.m_numberOfSongs;
        m_capacity = other.m_capacity;
    }

    void resize(){
        Song* newSongs = new (std::nothrow) Song [m_capacity * INCREASE_STEP];
        if(!newSongs){
            std::cout << "Mempory problem!";
            return;
        }

        for(int i = 0; i < m_numberOfSongs; ++i){
            newSongs[i] = m_songs[i];
        }

        delete[] m_songs;
        m_songs = newSongs;
        m_capacity *= INCREASE_STEP;
    }

    int getSongIndex(const char* songName){
        for(int i = 0; i < m_numberOfSongs; ++i){
            if(strcmp(m_songs[i].getName(), songName) == 0){
                return i;
            }
        }
        std::cout << "There is no have such song!";
        return -1;
    }

public:

    Playlist(const char* name){
        delete[] m_name;
        assert(name != nullptr);
        m_songs = new (std::nothrow) Song [INITIAL_CAPACITY];
        if(!m_songs){
            std::cout << "Memory problem!";
            return;
        }
        m_numberOfSongs = 0;
        m_capacity = INITIAL_CAPACITY;
        setName(name);
    }

    void setName(const char* name){
        m_name = new (std::nothrow) char [ strlen(name) + 1];
        if(!m_name){
            std::cout << "Memory problem!";
            return;
        }
        strcpy(m_name, name);
    }

    Playlist(const Playlist& other){
        copy(other);
    } 
    
    Playlist& operator=(const Playlist& other){
        if(this != &other){
            delete[] m_songs;
            copy(other);
        }
        return *this;
    }

    ~Playlist(){
        erase();
    }

    const char* getName() const { return m_name; }
    int getNumberOfSongs() const { return m_numberOfSongs; }

    void printPlaylistInfo() const {
        std::cout << getName() << " playlist have " << getNumberOfSongs() << " songs\n";

        for(int i = 0; i < m_numberOfSongs; ++i){
            m_songs[i].print();
        }
    }
    
    void addSong(const Song& toAdd){
        if(m_numberOfSongs == m_capacity){
            resize();
        }

        for(int i = 0; i < m_numberOfSongs; ++i){
            if(strcmp(m_songs[i].getName(), toAdd.getName()) == 0){
                std::cout << "Already have that song!";
                return;
            }
        }

        m_songs[m_numberOfSongs] = toAdd;
        m_numberOfSongs++;
    }
    
    bool removeSong(const char* songName){
        if(m_numberOfSongs == 0){
            std::cout << "Dont have any songs!";
            return false;
        }

        for(int i = 0; i < m_numberOfSongs; ++i){
            if(strcmp(m_songs[i].getName(), songName) == 0){
                m_songs[i] = m_songs[m_numberOfSongs - 1];
                m_numberOfSongs--; 
                return true;
            }
        }
        return false;
    }

    Song& operator[](unsigned int index){
        assert(index <= m_numberOfSongs);
        return m_songs[index];
    }

    Song& operator[](unsigned int index) const{
        assert(index <= m_numberOfSongs);
        return m_songs[index];
    }

};

int main(){

    Duration d1;
    d1.minutes = 3;
    d1.seconds = 45;

    Song s1("habibi", d1, "chalga");
    Song s2("bla", d1, "chalga");

    Playlist p1("kiara`s");
    p1.addSong(s1);
    p1.addSong(s2);
    p1.printPlaylistInfo();
    p1.removeSong("bla");
    p1.printPlaylistInfo();

    std::cout << "result from operator[]: " << p1[1];
    p1[1] = p1[0];
    std::cout << "result from operator[]: " << p1[1];

    checkMemoryLeaks();
    return 0;
}