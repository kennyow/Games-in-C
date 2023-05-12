#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <locale.h>

using namespace std;

//Clear screen
void limpaTela(){
    system("CLS");
}
void MenuInicial(){

     //Option chosen by the player
    int opcao = 0;

    // While the player does not enter the correct value, the menu is shown again
    limpaTela();
    while ( opcao < 1 || opcao > 3){
        cout << "\n";
        cout << "**** WELCOME TO HAGMAN GAME! ****";
        cout << "\n1 - Play";
        cout << "\n2 - About";
        cout << "\n3 - End";
        cout << "\nChoose one of the options and press ENTER: ";

        //Read the option
        cin >> opcao; 

        //If the option chosen was:
        switch(opcao){
            case 1:
            //Start the game
            cout << "** GAME STARTED **";
                break;
            case 2:
            //Game info
            cout << "** GAME INFO **";
                break;
            case 3:
            //End of the session
            cout << "** SEE YOU NEXT ! **";
                break;
    }
    }
 

}

int main(){

    //Main Menu
    MenuInicial();

   return 0; 
}