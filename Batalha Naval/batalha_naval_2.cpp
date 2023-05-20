#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <locale.h>

using namespace std;


void limpaTela(){
    system("CLS");
}

void iniciaTabuleiro(char tabuleiro[10][10]){

    //navigation aid    
    int linha, coluna;
    //Fill the boardgame with water (A)
    for(linha = 0; linha < 10; linha++){
        for(coluna = 0; coluna < 10; coluna++){
            tabuleiro[linha][coluna] = 'A';
        }
    }
}

void exibeTabuleiro(char tabuleiro[10][10]){

    //navigation aid    
    int linha, coluna;
    //Show the boardgame
    for(linha = 0; linha < 10; linha++){
        for(coluna = 0; coluna < 10; coluna++){
            cout << " " << tabuleiro[linha][coluna];
        }
        cout << "\n";
    }
}

void jogo(){

    ///Main Variables
    char tabuleiro[10][10];     
    //navigation aid    
    int linha, coluna;

    //Starts the boardgame with water
    iniciaTabuleiro(tabuleiro);
    
    //Show the boardgame
    exibeTabuleiro(tabuleiro);

    
}

void MenuInicial(){

    //Option chosen by the player
    int opcao = 0;


    // While the player does not enter the correct value, the menu is shown again
    limpaTela();
    while ( opcao < 1 || opcao > 3){
        cout << "\n";
        cout << "**** WELCOME TO BATTLESHIP GAME! ****";
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
            cout << "\n";
            cout << "** GAME STARTED **\n";
            cout << "\n";
            jogo();
                break;

            case 2:
            //Game info
            cout << "\n";
            cout << "** GAME INFO **";
                break;

            case 3:
            //End of the session
            cout << "\n";
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