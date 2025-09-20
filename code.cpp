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
void displayGame(Game *);

int main() {
    Game * gameLibrary = new Game[NR_GAMES];
    cout << "test123" << endl;

    for (int i = 0; i < NR_GAMES; i++) {
        inputGame(&gameLibrary[i]);
    }

    for (int i = 0; i < NR_GAMES; i++) {
        displayGame(&gameLibrary[i]);
    }

    delete [] gameLibrary;
    return 0;
}

//inputGame() function takes in a dynamic struct array and asks user input and initializes all the members in the struct, including the dynamic reviews array. Doesn't return anything
void inputGame(Game * gLibrary) {
    static int num = 1;
    cout << "Enter info for game " << num << endl;
    
    cout << "Title: ";
    getline(cin, gLibrary->title);

    cout << "Players currently playing: ";
    cin >> gLibrary->currentActive;

    cout << "Total plays: ";
    cin >> gLibrary->totalPlays;

    gLibrary -> reviews = new string[NR_REVIEWS];
    cout << "Enter " << NR_REVIEWS << " reviews: " << endl;
    cin.ignore();
    for (int i = 0; i < NR_REVIEWS; i++) {
        cout << "Enter review " << i + 1 << endl;
        getline(cin, gLibrary->reviews[i]);
    }

    cout << endl;
    num++;
}

//displayGame() function receives a value in a struct array and displays all the members in a given struct index. Doesn't return anything
void displayGame(Game * gLibrary) {
    static int num = 1;
    cout << "\nGame " << num << ": " << endl;
    cout << "Title: " << gLibrary->title << endl;
    cout << "Current Active Players: " << gLibrary->currentActive << endl;;
    cout << "Total Plays: " << gLibrary->totalPlays << endl;
    
    cout << "Reviews: " << endl;
    for (int i = 0; i < NR_REVIEWS; i++) {
        cout << "Review " << i + 1 << ": " << gLibrary->reviews[i] << endl;
        cout << endl;
    }

    num++;
}