# include <iostream>
#include<map>
using namespace std ;

map<string,int> Inventory{
    {"knife",0},{"baseball bat",0},{"gun",0},{"ammo",0},{"medkit",0} 
};

void item(){
for (const auto& item : Inventory) {
        std::cout << item.first << ": " << item.second << std::endl;
    }
}

void increase_resource(){
Inventory["ammo"]++;
Inventory["medkit"]++;
}

void increase_weapon(){
Inventory["ammo"]++;
Inventory["knife"]++;
Inventory["baseball bat"]++;
Inventory["gun"]++;
}


