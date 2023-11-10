#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

//Area of definition of the funtion headers
void menuInicial();

//Clean Screen
void limpaTela(){
    system("cls");
}

//Starting the boardgame
void iniciaTabuleiro(char tabuleiro[3][3]){

    //Navigate through all positions on the board and puts the stripe '-' on them
    int linha, coluna; 
    for (linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna < 3; coluna++){
            tabuleiro[linha][coluna] = '-';
        }
    }
}

void exibeTabuleiro(char tabuleiro[3][3]){

    //Shows the boardgame with theirs lines and columns
    int linha, coluna;
     //Show the boardgame
    for (linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna < 3; coluna++){
            cout << tabuleiro[linha][coluna];
        }
        cout << endl;
    }
}

int confereTabuleiro(char  tabuleiro[3][3]){

    //Variables
    int linha, coluna;

    //Check the lines
    for(linha = 0; linha < 3; linha++){
        if(tabuleiro[linha][0] == 'X' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
            return 1;
        }else if(tabuleiro[linha][0] == 'O' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
            return 2;
        }
    }

    //Check the columns
    for(coluna = 0; coluna < 3; coluna++){
        if(tabuleiro[0][coluna] == 'X' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
            return 1;
        }else if(tabuleiro[0][coluna] == 'O' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
            return 2;
        }
    }

    //Main Diagonal
    if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
        if(tabuleiro[0][0] == 'X'){
            return 1;
        }else{
            return 2;
        }
   }

   //Secondary Diagonal
    if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
        if(tabuleiro[0][2] == 'X'){
            return 1;
        }else{
            return 2;
        }
   }

   return 0;
}

void exibeInstrucoes(){

    cout <<"\nMapa de Posicoes" << endl;
    cout << "\n 7 | 8 | 9";
    cout << "\n 4 | 5 | 6";
    cout << "\n 1 | 2 | 3";

}



void jogo(string nomeDoJogadorUm, string nomeDoJogadorDois, int pontuacaoJogadorUm, int pontuacaoJogadorDois){

    //Player's names
    string nomeDoJogadorAtual;

    //Boardgame and General Variables 
    char tabuleiro[3][3];
    //int linha, coluna; 

    //Where the player places the play
    int linhaJogada, colunaJogada, posicaoJogada;

    //Game Stage
    int estadoDeJogo = 1;

    //Player turn( 1- X, 2 - O)
    int turnoDoJogador = 1;

    //Rounds
    int rodada = 0;

    //Option
    int opcao;

    //If the play was executed
    bool posicionouJogada;

    //Put the stripes '-' on the board
    iniciaTabuleiro(tabuleiro);

    while(rodada < 9 && estadoDeJogo == 1){

        //Clean the screen
        limpaTela();

        //Information about the round
        cout << "\nRound: " << rodada << endl;
        cout << "Points: " << nomeDoJogadorUm << " " << pontuacaoJogadorUm << " x " << pontuacaoJogadorDois << " " << nomeDoJogadorDois << endl;

        //Shows the board on screen
        exibeTabuleiro(tabuleiro);

        //Shows which number corresponds to which position
        exibeInstrucoes();

        //Update current player name
        if(turnoDoJogador == 1){
            nomeDoJogadorAtual = nomeDoJogadorUm;
        }else{
            nomeDoJogadorAtual = nomeDoJogadorDois;
        }

        posicionouJogada = false;

        //Matrix with possible positions
        int posicoes[9][2] = {{2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2}};

        while(posicionouJogada == false) {

            //Reads the play
            cout << "\n" <<nomeDoJogadorAtual << "\nEnter a position according to the map above: ";
            cin >> posicaoJogada;

            //Moves the row and column according with the positional matrix displayed on the map
            linhaJogada = posicoes[posicaoJogada -1][0];
            colunaJogada = posicoes[posicaoJogada-1][1];

            //Verifies if the position is empty
            if (tabuleiro[linhaJogada][colunaJogada] == '-'){

                //Managed to place a marker
                posicionouJogada = true;

                //Check whose turn it is to place the marker
                if (turnoDoJogador == 1){
                    tabuleiro[linhaJogada][colunaJogada] = 'X';
                    //After he played, changes for 2 and get into the looping
                    turnoDoJogador = 2;
                 }else{
                    tabuleiro[linhaJogada][colunaJogada] = 'O';
                    //After he played, returns for 1 and get into the looping again
                    turnoDoJogador = 1;
                }
            }
        }

        //Check if the game is over
        if(confereTabuleiro(tabuleiro) == 1){
            cout <<"The X Player wins!" << endl;
            pontuacaoJogadorUm++;
            estadoDeJogo = 0;
        }else if(confereTabuleiro(tabuleiro) == 2){
            cout <<"The O Player wins!" << endl;
            pontuacaoJogadorDois++;
            estadoDeJogo = 0;
        }

        //Increase one round
        rodada ++;

    }

    exibeTabuleiro(tabuleiro);
    cout << "**THE END**" << endl;
    cout << "What do you want to do?" << endl;
    cout << "1 - Keep playing" << endl;
    cout << "2 - Back to Start Menu" << endl;
    cout << "3 - Exit" << endl;
    cin >> opcao;
    if(opcao == 1){
        jogo(nomeDoJogadorUm, nomeDoJogadorDois, pontuacaoJogadorUm, pontuacaoJogadorDois);
    }else if(opcao == 2){
        menuInicial();
    }
        
    }
   


//Start Menu
void menuInicial(){

    //option choosed by the player
    int  opcao = 0;

    //Players Names
    string nomeDoJogadorUm, nomeDoJogadorDois;

    //Validation data for menu in loop
    while ( opcao < 1 || opcao > 3){
        //basic menu
        cout << "***Welcome to the HASH GAME***" << endl;
        cout << "1 - PLAY" << endl;
        cout << "2 - ABOUT" << endl;
        cout << "3 - EXIT" << endl;
        cout << "Choose an option and press Enter" << endl;
        cin >> opcao; 

        //Switch Case Menu
        switch(opcao){
            case 1:
                //Start the game
                //Desired position in the matrix
                cout << "Name Player 1: " << endl;
                cin >> nomeDoJogadorUm;
                cout << "Name Player 2: " << endl;
                cin >> nomeDoJogadorDois;
                cout << "*GAME STARTED!* \n";
                jogo(nomeDoJogadorUm, nomeDoJogadorDois, 0, 0);
                break;
            case 2:
                //About the game
                cout << "*ABOUT THE GAME*" << endl;
                cout << "created by Kennyo Wescley" << endl;
                break;
            case 3:
                //Exit message
                cout << "*SEE YOU SOON!*";
                break;
        }
    }

}


int main(){
    
    limpaTela();
    menuInicial();
    return 0;
}