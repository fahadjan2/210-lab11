// COMSC-210 | Lab 11 | Fahad Fawad Ahmad
// IDE used: Visual Studio
#include <iostream>
#include <string>
using namespace std;

const int NR_GAMES = 3; //The number of games in the library
const int NR_REVIEWS = 4; //Number of reviews

//A struct that stores info of a game in a game library, the title, how many are currently playing it, and total plays. It also stores reviews in a dynamic array
struct Game {
    string title;
    int currentActive;
    int totalPlays;
    string * reviews;

    ~Game() {
        if (reviews)
            delete [] reviews;
        reviews = nullptr;
    }
};

void inputGame(Game *);

int main() {
    Game * gameLibrary = new Game[NR_GAMES];

    for (int i = 0; i < NR_GAMES; i++) {
        inputGame(&gameLibrary[i]);
    }
}

void inputGame(Game * gLibrary) {
    static int num = 1;
    cout << "Enter info for game " << num << endl;
    
    cout << "Title: ";
    cin >> gLibrary->title;

    cout << "Players currently playing: ";
    cin >> gLibrary->currentActive;

    cout << "Total plays: ";
    cin >> gLibrary->totalPlays;

    cout << "Enter " << NR_REVIEWS << " reviews: " << endl;
    for (int i = 0; i < NR_REVIEWS; i++) {
        cout << "Enter review " << i + 1 << endl;
        cin >> gLibrary->reviews[i];
    }

    num++;
}