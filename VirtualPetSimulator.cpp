/**
* @file     VirtualPetSimulator.cpp
* @author   Eveline Chang
* @brief    Term Project 
* @version  3.0
* @date     10 June 2026
* @note     Virtual Pet
*
* @copyright Copyright (c) 2026
*
*/


#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime> 
using namespace std;

// initial setting of virtual pet
const int INITIAL_PET_AGE = 0;
const int AGE_INCREASE = 1;
const int MAX_STATUS = 20; 
const int MIN_STATUS = 0;
const int MAX_AGE = 40; 
const int INITIAL_MONEY = 5000;
const int DOCTOR_COST = 500;

// Void Function
void feed(int& hunger, int& happiness, int& cleanliness, int& age, string petName);
void play(int& hunger, int& happiness, int& cleanliness, int& age, string petName); 
void talk(int& hunger, int& happiness, int& cleanliness, int& age, string petName); 
void clean(int& hunger, int& happiness, int& cleanliness, int& age, string petName); 
void timePass(int& hunger, int& happiness, int& cleanliness, int& age, int amount = 1); 
double mood(int hunger, int happiness, int cleanliness); 
void checkPet(int hunger, int happiness, int cleanliness, int age, bool& gameRunning, string petName); 
void checkMaxStatus(int& hunger, int& happiness, int& cleanliness); 
void petSleep(int& hunger, int& happiness, int& cleanliness, int& age, string petName);
void visitDoctor(int& hunger, int& happiness, int& cleanliness, int& age, int& money, string petName);


int main()
{ 
    // https://www.youtube.com/watch?v=-NA_B_vJP14&t=105s
    // give different random value. 
    srand(time(0)); 

    char again;
    do
    {
        int age = INITIAL_PET_AGE;
        // https://www.w3schools.com/cpp/cpp_howto_random_number.asp
        
        int happiness = rand() % 20 + 7; 
        int hunger = rand() % 20 + 7; 
        int cleanliness = rand() % 20 + 7; 
        int money = INITIAL_MONEY;


        string petName;
        int userChoice;
        bool gameRunning = true;
        
        cout << "Welcome to Virtual Pet 1.0. \n";
        cout << "Please enter the name of your pet: \n";
        cin >> petName;
        
        cout << "======= Game Start =======\n";
        do
        {
            cout << petName << " is " << age << " years old.\n";
            cout << "Money: $" << money << endl;
            cout << "Here is what you can do with " << petName << ".\n";
            cout << "1. Feed your pet.\n";
            cout << "2. Play with your pet.\n";
            cout << "3. Talk to your pet.\n";
            cout << "4. Clean your pet.\n"; 
            cout << "5. Let your pet sleep.\n";
            cout << "6. Take your pet to the doctor. ($500)\n";
            cout << "7. Quit the game.\n"; 
            cin >> userChoice;

            if (userChoice == 1)
            {
                feed(hunger, happiness, cleanliness, age, petName); 
            }
            else if (userChoice == 2)
            {
                play(hunger, happiness, cleanliness, age, petName); 
            }
            else if (userChoice == 3)
            {
                talk(hunger, happiness, cleanliness, age, petName); 
            }
            else if (userChoice == 4)
            {
                clean(hunger, happiness, cleanliness, age, petName); 
            }
            else if (userChoice == 5)
            {
                petSleep(hunger, happiness, cleanliness, age, petName);
            }
            else if (userChoice == 6)
            {
                visitDoctor(hunger, happiness, cleanliness, age, money, petName);
            }
            else if (userChoice == 7) 
            {
                cout << "Goodbye...\n";
                gameRunning = false;
            }
            else
            {
                cout << "Invalid input, please try again.\n";
            }
            
            checkMaxStatus(hunger, happiness, cleanliness); 
            checkPet(hunger, happiness, cleanliness, age, gameRunning, petName); 
        }
        while (gameRunning == true);

        cout << "Do you want to start a new game? (Y/N): "<< endl;
        cin >> again;      
    }
    while (again == 'y' || again == 'Y');

    cout << "Bye! Thanks for playing!" << endl;

    return 0;
}


// Function definitions
double mood(int hunger, int happiness, int cleanliness)
{
    return (hunger + happiness + cleanliness) / 3.0;
}

void timePass(int& hunger, int& happiness, int& cleanliness, int& age, int amount)
{
    int decrease = rand() % 2 + 1;

    age = age + amount;
    hunger = hunger - decrease;
    happiness = happiness - decrease;
    cleanliness = cleanliness - decrease;
}

void feed(int& hunger, int& happiness, int& cleanliness, int& age, string petName) 
{
    int foodChoice;

    // arrays for food options, each food will plus different value.
    string foodNames[3] = {"Snacks", "Meat", "Veggie"};
    int foodBonus[3] = {1, 5, 2};

    cout << "What do you want to feed " << petName << "?\n";
    cout << "1. " << foodNames[0] << ".\n";
    cout << "2. " << foodNames[1] << ".\n";
    cout << "3. " << foodNames[2] << ".\n";
    cout << "Please enter your choice: ";
    cin >> foodChoice;

    if (foodChoice == 1)
    {
        cout << "You feed " << petName << " " << foodNames[0] << ".\n";
        hunger = hunger + foodBonus[0];
        timePass(hunger, happiness, cleanliness, age); // snacks
    }
    else if (foodChoice == 2)
    {       
        cout << "You feed " << petName << " " << foodNames[1] << ".\n";
        hunger = hunger + foodBonus[1];
        timePass(hunger, happiness, cleanliness, age); // meat
    }
    else if (foodChoice == 3)
    {
        cout << "You feed " << petName << " " << foodNames[2] << ".\n";
        hunger = hunger + foodBonus[2];
        timePass(hunger, happiness, cleanliness, age); // veggie
    }
    else
    {
        cout << "Invalid input, please try again.\n";
    }

    cout << "======= continue =======\n"; 
}

void play(int& hunger, int& happiness, int& cleanliness, int& age, string petName) 
{
    int playChoice;

    // arrays for play options 
    string playNames[2] = {"Freezbee", "Go to the park"};
    int playBonus[2] = {3, 4};

    cout << "What do you want to do with " << petName << "?\n";
    cout << "1. " << playNames[0] << ".\n";
    cout << "2. " << playNames[1] << ".\n";
    cout << "Please enter your choice: ";
    cin >> playChoice;

    if (playChoice == 1)
    {
        cout << "You play " << playNames[0] << " with " << petName << ".\n";
        happiness = happiness + playBonus[0];
        timePass(hunger, happiness, cleanliness, age); // freezbee
    }
    else if (playChoice == 2)
    {       
        cout << "You play with " << petName << " at the park.\n";
        happiness = happiness + playBonus[1];
        timePass(hunger, happiness, cleanliness, age); // park
    }
    else
    {
        cout << "Invalid input, please try again.\n";
    }

    cout << "======= continue =======\n";
}

// clean the pet
void clean(int& hunger, int& happiness, int& cleanliness, int& age, string petName)
{
    int cleanChoice;

    // arrays for clean options 
    string cleanNames[2] = {"Brush the pet", "Take a bath"};
    int cleanBonus[2] = {2, 4};

    cout << "What do you want to do with " << petName << "?\n";
    cout << "1. " << cleanNames[0] << ".\n";
    cout << "2. " << cleanNames[1] << ".\n";
    cout << "Please enter your choice: ";
    cin >> cleanChoice;

    if (cleanChoice == 1)
    {
        cout << "You clean " << petName << " by brushing its fur.\n";
        cleanliness = cleanliness + cleanBonus[0];

        // cleaning will reduce hunger and happiness
        hunger = hunger - 1;
        happiness = happiness - 1;

        timePass(hunger, happiness, cleanliness, age);
    }
    else if (cleanChoice == 2)
    {
        cout << "You give " << petName << " a bath.\n";
        cleanliness = cleanliness + cleanBonus[1];

        hunger = hunger - 1;
        happiness = happiness - 2;

        timePass(hunger, happiness, cleanliness, age);
    }
    else
    {
        cout << "Invalid input, please try again.\n";
    }

    cout << "======= continue =======\n";
}

void talk(int& hunger, int& happiness, int& cleanliness, int& age, string petName) 
{
    cout << "~~~You talk to " << petName << ".~~~\n";
    cout << "~~~" << petName << " says... \n";

    if (hunger > 16)
    {
        cout << "I am full!\n";
    }
    else if (hunger >= 11)
    {
        cout << "I am not hungry!\n";
    }
    else if (hunger >= 6)
    {
        cout << "I am somewhat hungry.\n";
    }
    else
    {
        cout << "I am hungry!\n";
    }

    if (happiness > 16)
    {
        cout << "I am happy :)\n";
    }
    else if (happiness >= 11)
    {
        cout << "I am okay.\n";
    }
    else if (happiness >= 6)
    {
        cout << "Content.....\n";
    }
    else
    {
        cout << "I am unhappy :(\n";
    }

    
    if (cleanliness > 16)
    {
        cout << "I am clean!\n";
    }
    else if (cleanliness >= 11)
    {
        cout << "I am kind of clean.\n";
    }
    else if (cleanliness >= 6)
    {
        cout << "I am kind of smelly.\n";
    }
    else
    {
        cout << "I am smelly!\n";
    }

    
    double currentMood = mood(hunger, happiness, cleanliness);

    if (currentMood > 16)
    {
        cout << "I am happy.\n";
    }
    else if (currentMood >= 11)
    {
        cout << "I am okay.\n";
    }
    else if (currentMood >= 6)
    {
        cout << "I am frustrated.\n";
    }
    else
    {
        cout << "I am mad.\n";
    }

    // current status
    string statNames[4] = {"Age", "Hunger", "Cleanliness", "Happiness"};
    int statLevels[4] = {age, hunger, cleanliness, happiness};
                
    cout << "*** Current Status ***\n";
    for (int i = 0; i < 4; i++)
    {
        cout << statNames[i] << ": " << statLevels[i] << endl;
    }
    cout << "**********************\n";
    cout << "======= continue =======\n";

    timePass(hunger, happiness, cleanliness, age); 
}

void checkMaxStatus(int& hunger, int& happiness, int& cleanliness) 
{
    if (happiness > MAX_STATUS)
    {
        happiness = MAX_STATUS;
    }

    if (hunger > MAX_STATUS)
    {
        hunger = MAX_STATUS;
    }

    if (cleanliness > MAX_STATUS)
    {
        cleanliness = MAX_STATUS;
    }
}

void checkPet(int hunger, int happiness, int cleanliness, int age, bool& gameRunning, string petName) 
{
    if (hunger < MIN_STATUS)
    {
        cout << "Game over. You didn't feed the pet. " << petName << " is dead.\n";
        gameRunning = false;
    }

    else if (happiness < MIN_STATUS)
    {
        cout << "Game over. Your pet feels disappointed. " << petName << " ran away.\n";
        gameRunning = false;
    }

    else if (cleanliness < MIN_STATUS)
    {
        int sickChance = rand() % 2;

        if (sickChance == 0)
        {
            cout << "Game over. " << petName << " got too sick and passed away.\n";
            gameRunning = false;
        }
        else
        {
            cout << petName << " is sick because it is too dirty.\n";
        }
    }

    else if (age >= MAX_AGE)
    {
        cout << "Game over. Thank you for taking good care of " << petName << ". "
        << petName << " lives a happy life.\n";
        gameRunning = false;
    }
}

void petSleep(int& hunger, int& happiness, int& cleanliness, int& age, string petName)
{
    cout << petName << " takes a nice nap.\n";

    happiness = happiness + 3;
    hunger = hunger - 2;
    cleanliness = cleanliness - 1;

    timePass(hunger, happiness, cleanliness, age);

    cout << petName << " feels more relaxed after sleeping.\n";
    cout << "======= continue =======\n";
}

void visitDoctor(int& hunger, int& happiness, int& cleanliness, int& age, int& money, string petName)
{
    if (money < DOCTOR_COST)
    {
        cout << "You do not have enough money to take " << petName << " to the doctor.\n";
        cout << "You need $" << DOCTOR_COST << ", but you only have $" << money << ".\n";
        cout << "======= continue =======\n";
        return;
    }

    money = money - DOCTOR_COST;

    cout << "You take " << petName << " to the doctor.\n";
    cout << "Doctor cost: $" << DOCTOR_COST << endl;
    cout << "Money left: $" << money << endl;

    cleanliness = cleanliness + 10;
    happiness = happiness + 3;
    hunger = hunger - 1;

    timePass(hunger, happiness, cleanliness, age);

    cout << petName << " feels better now.\n";
    cout << "======= continue =======\n";
}

