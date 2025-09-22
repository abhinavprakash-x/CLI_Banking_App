#include<iostream>
using namespace std;

int main(){
    //change of plans use a database "MySQL" to store data
    

    //CLI Based Login System
    int repeat = 1, user_choice;
    do{
        cout<<"CLI Based Banking Application\n";
        cout<<"------------------------------\n";
        cout<<"Main Menu \n";
        cout<<"1. Login as Administrator \n";
        cout<<"2. Login as Customer \n";
        cout<<"3. Exit System \n";
        cout<<"Choose Your Preferred Option: ";
        cin>>user_choice;
        if(user_choice == 1) cout<<"Admin"; //call admin menu
        else if(user_choice == 2) cout<<"Customer"; //call customer menu
        else if(user_choice == 3) return 0; //exit program NB: save data before exit
        else cout<<"Wrong Option Selected";
    } while(repeat == 1);



    //commit transactions made in the database
}