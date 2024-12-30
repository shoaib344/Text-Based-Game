#include"fighting_s.h"
#include"fighting_g.h"

int main(){
    while(true){

    cout<<"PUZZLE" << endl;
    cout<<"============="<<endl;
    puzzle_g();
    cout << endl;


    cout << endl;
    cout<<"FIGHTING"<<endl;
    cout<<"============="<<endl;
    fighting_g();
    cout << endl;


    cout<<"PUZZLE" << endl;
    cout<<"============="<<endl;
    puzzle_d();

    cout<<"PUZZLE" << endl;
    cout<<"============="<<endl;
    puzzle_s();

    cout << "FIGHTING" << endl;
    cout<<"================"<<endl;
    fighting_s();

    cout<<"INVENTORY LEFT"<<endl;
    cout<<"================"<<endl;
    item();

    cout <<"Do You Want To Play Again?: ";
    std::string player;
    cin >> player;
    if(player != "yes"){
        cout <<"Thank you for playing the game!"<<endl;
        cout << endl;
        break;
    }    
    }
}

