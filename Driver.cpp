/*
    Title: Program One
	Authors: Sawyer Blanchford, Anthony Cosentino, Zachary Jones, Gabe Simpkins
	Date: 9/16/2024
	Purpose: 
*/

#include <iostream>
#include <fstream> //used to read from and write to text files
#include<string>
#include<iomanip>
#include<cctype>
#include<climits>

using namespace std;



// hello 
class Forest 
{
    private:
        
        string paths [7];
        const int numPaths = 7;
        int pathCleared;

    public:
    void showPaths();
    void choosePath(int choice);
    //constructor
         Forest() : pathCleared(0) 
         {
            paths [0] = "";
            paths [1] = "";
            paths [2] = "";
            paths [3] = "";
            paths [4] = "";
            paths [5] = "";
            paths [6] = "";
        }

    //destructor
         ~Forest()
         {
         }

    void showPaths()
    {
        cout << "Choose a path:\n";
        cout << "1: " << paths[0] << endl;
        if (pathCleared == 1)
        {
            
        }
    }
    
    
    
    
    void showPaths()
    {
        cout << "Choose a path:\n";
        for (int i = 0; i < numPaths; i++)
        {
            cout << i + 1 << ": " << paths [i] << endl;
        }
    }

    void choosePath(int choice)
    {
        if (choice < 1 || choice > numPaths)
        {
            cout << "Invalid choice" << endl;
            return;
        }
    }
    

            

    
};

class Character
{

	private: 
        const int maxCharacters = 7;        string name;
        double healthPoints;
        double attackStat;
        int speed;
        string* arrayOfitems;
        int numItems;
        
    public:

    /*void Character::setName(string n)
    {
        name = n;
    };put in character.cpp
    */
    Character* selectCharacter(string name, double healthPoints, double attackStat, int speed)
    {
        Character *selectCharacter = new Character;

        selectCharacter-> name = name;
        selectCharacter-> healthPoints = healthPoints;
        selectCharacter-> attackStat = attackStat;
        selectCharacter-> speed = speed;
        selectCharacter-> arrayOfitems = new string[numItems];
    }
    void printCharacters(Character* selectCharacter)
    {
        cout << "Character Name:    " << selectCharacter->name << endl;
        cout << "Health Points:   " << selectCharacter->healthPoints << endl;
        cout << "Hit Points:  " << selectCharacter->attackStat << endl;
        cout << "Speed :    " << selectCharacter->speed << endl;
    }
};

class Interactions
{

    private:
        int damage, remaninghealth;
        string* battlelog;
    public:
        int damage(int);
        int remaninghealth(int,int);
};
int damage(int attack)
{   int damagemulti,damage;
    damagemulti = (rand() % 3) + 1;
    if (damagemulti == 1)
    {   
        damage = attack * 0.75;
    }
    if (damagemulti == 2)
    {   
        damage = attack;
    }
    if (damagemulti == 3)
    {   
        damage = attack * 1.25;
    }
    
    
    return damage;
}
int remaininghealth(int damage,int health)
{   
    int HPleft;
    HPleft = health - damage;
    return HPleft;
}

int runGame(int startingPoint){
    
    switch (startingPoint){
        case 1:

        case 2:

        case 3:

        case 4:


    }

    return startingPoint;
}


int main ()
{
    int choice = 0; //this number is used for user input choices
    bool cont = true; //determines if the program loops again
    string fileName; // used to name and locate names of text files
    ifstream Myfile; // used to read from text files
    ofstream MYfile; // used to write to text files
    int startingPoint; //printed into the save
    
    

    //print ascii art of game title
        //this is filler game title art
        cout << "   ___ _ _ _               ___                       _____ _ _   _\n";      
        cout << "  / __(_| | | ___ _ __    / _ \\__ _ _ __ ___   ___  /__   (_| |_| | ___ \n";
        cout << " / _\\ | | | |/ _ | '__|  / /_\\/ _` | '_ ` _ \\ / _ \\   / /\\| | __| |/ _ \\ \n";
        cout << "/ /   | | | |  __| |    / /_\\| (_| | | | | | |  __/  / /  | | |_| |  __/ \n";
        cout << "\\/    |_|_|_|\\___|_|    \\____/\\__,_|_| |_| |_|\\___|  \\/   |_|\\__|_|\\___|  \n";
                
    do{
        
        cout << "\n\n\nselect option:\n(1)\t\t(2)\t\t(3)\t\t(any other number)";
        cout << "|START NEW GAME|\t|START LOAD GAME|\t|DELETE SAVE|\t|QUIT PROGRAM|";
        choice = getValidateInput();
        
        switch (choice){
            case 1:
                cout << "Name New Save File: (Ex. File_Name.txt)";
                cin >> fileName;

                for (int i = 0; i < fileName.length(); i++)  //replaces spaces with underscore
                    if (fileName[i] == ' ')
                        fileName[i] = '_';

                Myfile.open(fileName); //creates and opens new save text file
                

                //character selection
                
                
                //start game
                startingPoint = runGame(startingPoint);

                //print starting point to save file
                
                Myfile.close();
                break;
            case 2:
                while (!Myfile.is_open()){
                    cout << "Which save file would you like to open? (Ex. File_Name.txt)";
                    cin >> fileName;
                    Myfile.open(fileName);
                    if (Myfile.is_open())
                        break;
                    cout << "\nNo file with that name exists. Try again? Yes(1) or No (2)\n";
                    choice = getValidateInput();
                    if (choice != 1)
                        break;
                }

                startingPoint = runGame(startingPoint);
                
                //print starting point to save file

                Myfile.close();
                break;
            case 3:
                while (!Myfile.is_open()){
                    cout << "Which save file would you like to delete? (Ex. File_Name.txt)";
                    cin >> fileName;
                    Myfile.open(fileName);
                    if (Myfile.is_open())
                        break;
                    cout << "\nNo file with that name exists. Try again? Yes(1) or No (2)\n";
                    choice = getValidateInput();
                    if (choice != 1)
                        break;
                }
                //remove(Myfile); REMOVE FILE
                
                
                break;
            default:
                choice = 4;
        }

    }while (choice == 4);
    
    cout << "\nThanks for playing!\n";
                //maybe add ascii art here
                //this is a test
            

    return 0;
}



int getValidateInput(){
	int num;
	
	
		while(!(cin >> num))
		{
			cout << "Please enter a valid number" << endl;
			cin.clear(); //clears all stream bits (good, bad, eof, fail)
			cin.ignore(10000, '\n'); //removes up to 10000 characters from buffer until a newline is removed
			cout << "\nEnter a number: ";
		}
	
		
	return num;
}

