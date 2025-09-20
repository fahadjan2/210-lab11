// COMSC-210 | Lab 11 | Fahad Fawad Ahmad
// IDE used: Visual Studio
#include <iostream>
using namespace std;

const int NR_GAMES = 3;

//A struct that stores info of a game in a game library, the title, total plays, and how many are currently playing it. It also stores reviews in a dynamic array
struct Game {
    string title;
    int totalPlays;
    int currentActive;
    string * reviews;

    ~Game() {
        if (reviews)
            delete [] reviews;
        reviews = nullptr;
    }
};

int main() {
    Game * gameLibrary = new Game[NR_GAMES];

    
}