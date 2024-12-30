#include <iostream>
#include <ctime>
#include <cstdlib>
#include<array>
#include"puzzle_g.h"

using namespace std;

void fighting_s() {
array<string,3> weapon_items ={"Knife","Baseball bat","Gun"};
array <int,3> weapon_damage {10,15,25};

    int playerHealth = 100;
    int enemyHealth = 100;
  
    while (playerHealth > 0 && enemyHealth > 0) {

        // Player attack
        // ------------
        cout<<"Select 1 for knife (damage 10)"<<endl;
        cout << "Select 2 for baseball bat (damage 15)"<<endl;
        cout <<"Select 3 for gun (damage 25)"<<endl;
        cout << "Choose your weapon to Attack(1-3): ";
        
        int playerAttack;
        cin >> playerAttack;
        cin.clear();
        cin.ignore(1000, '\n');
        

            // KNIFE
        if (Inventory["knife"] == 0) {
        cout << "You have run out of knifes and cannot attack!" << endl;       
        }
        else if(playerAttack==1){
            cout<< "You Chose "<<weapon_items[0]<<" From Your Inventory"<<"."<<endl;
            enemyHealth -= weapon_damage[0];
            Inventory["knife"]--; 
            cout <<endl;
            cout <<"The Player has attacked the enemy with "<<weapon_items[0]<<endl;
            cout <<"An enemy's health is reduced to "<<enemyHealth << " now.";     
        }
        
            // BASEBALL BAT
        if (Inventory["baseball bat"] == 0) {
        cout << "You have run out of baseball bats and cannot attack!" << endl;      
        }
        else if(playerAttack==2){
            cout<< "You Chose "<<weapon_items[1]<<" From Your Inventory"<<"."<<endl;
            enemyHealth -= weapon_damage[1];
            Inventory["baseball bat"]--;
            cout <<endl;
            cout <<"The Player has attacked the enemy with "<<weapon_items[1]<<endl;
            cout <<"An enemy's health is reduced to "<<enemyHealth << " now."<<endl;;
        }

            // GUN
        if (Inventory["ammo"] == 0) {
        cout << "You have run out of ammo and cannot attack!" << endl;
        }
        else if(playerAttack==3){
            cout<< "You Chose "<<weapon_items[2]<<" From Your Inventory"<<"."<<endl;
            enemyHealth -= weapon_damage[2];
            Inventory["ammo"]--;
            cout <<endl;
            cout <<"The Player has attacked the enemy with "<<weapon_items[2]<<endl;
            cout <<"An enemy's health is reduced to "<<enemyHealth << " now.";
        }
        cout <<endl;

        // Enemy attack
        // ------------
        int items = sizeof(weapon_items)/sizeof(weapon_items[0]);   
        srand(time(NULL));  
        int index = rand() % items;
        int enemyAttack = weapon_damage[index];
        string weapons = weapon_items[index];
        cout <<endl;
        cout << "The "<< weapons <<" was used by the opponent to attack the player."<<endl; 
        playerHealth-=enemyAttack;
        if (playerHealth < 20 && Inventory["medkit"] > 0) {
           cout << "The player regenerated 20 health by using a medkit." << endl;

            playerHealth += 20;
            Inventory["medkit"]--;
        }
        cout <<"The player's health has dropped to "<<playerHealth<<endl;               
        cout<<endl;   
        cout << "Your health: " << playerHealth << endl;
        cout << "Enemy health: " << enemyHealth << endl;
        cout <<endl;
    }
 
        if (playerHealth > 0) {
            cout << "Congratulations! You were successful in getting away from the house." << endl;
            cout <<"ESCAPED"<<endl;
            cout << endl;
        }  
        else if (playerHealth == enemyHealth){
            cout << "Tie! "<<endl;
        }       
        else {
            cout << "Sorry, You Have failed to get out of the house." << endl;
            cout << "FAILED"<<endl;
            
        }
}