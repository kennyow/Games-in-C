#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

using namespace std;

//Function header
void MenuInicial();


void limpaTela(){
    system("CLS");
}

void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10]){

    //navigation aid    
    int linha, coluna;
    //Fill the boardgame with water (A)
    for(linha = 0; linha < 10; linha++){
        for(coluna = 0; coluna < 10; coluna++){
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }
    }
}

void exibeMapa(){

 //indicator column's map
    int cont;
    for (cont = 0; cont < 10; cont++){
        if(cont ==0){
            cout << "     ";
        }
        cout << cont << " ";
    }
    cout << "\n";

    for (cont = 0; cont < 10; cont++){
        if(cont ==0){
            cout << "     ";
        }
        cout << "| ";
    }
    cout << "\n";

}

void exibeTabuleiro(char tabuleiro[10][10], char mascara[10][10],bool mostraGabarito){

    //Putting colors
    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };

    //navigation aid    
    int linha, coluna;
    //Show the boardgame
    for(linha = 0; linha < 10; linha++){
        cout << linha << " - ";
        for(coluna = 0; coluna < 10; coluna++){

            switch(mascara[linha][coluna]){
                case 'A':
                    cout << blue << " " << mascara[linha][coluna] << normal;
                    break;
                case 'P':
                    cout << green << " " << mascara[linha][coluna] << normal;
                    break;
                default:
                    cout << normal << " " << mascara[linha][coluna] << normal;
                    break;
            }
        }
        cout << "\n";
    }
    if (mostraGabarito ==true){

        for(linha = 0; linha < 10; linha++){
        for(coluna = 0; coluna < 10; coluna++){
            cout << " " << tabuleiro[linha][coluna];
        }
        cout << "\n";
    }
    }
    }


void posicionaBarcos(char tabuleiro[10][10]){

    int quantidade = 10, quantidadePosicionada = 0;


    while(quantidadePosicionada < quantidade){

        int linhaAleatoria = rand() % 10; //Generates a random number bewteen 0 and 9
        int colunaAleatoria = rand() % 10;


        if (tabuleiro[linhaAleatoria][colunaAleatoria] == 'A'){
            //it will position boats randomly
            tabuleiro[linhaAleatoria][colunaAleatoria] = 'P';
            //Add the positional boat counter
            quantidadePosicionada++;

        }
        


    }

}

void verificaTiro(char tabuleiro[10][10], int linhaJogada, int colunaJogada, int *pontos, string *mensagem){
     //Calculate the total score
    switch(tabuleiro[linhaJogada][colunaJogada]){
        case 'P':    
            *pontos += 10;
            *mensagem = "You hit a small Boat!";
            break;
        case 'A':
            *mensagem = "You hit the Sea!";
            break;
    }

}


void jogo(string nomeDoJogador){

    ///Main Variables
    char tabuleiro[10][10], mascara[10][10];     
    //Positions to be choosed
    int linhaJogada, colunaJogada;
    //User's point game
    int pontos = 0;
    //Attempts and maximum attempts
    int tentativas = 0, maximoDeTentativas = 5;
    //Options to end the game
    int opcao;
    //Feedback message
    string mensagem = "Welcome OnBoard!"; 

    //Starts the boardgame with water
    iniciaTabuleiro(tabuleiro, mascara);

    //Place boats randomly
    posicionaBarcos(tabuleiro);


    //While loop
    while (tentativas < maximoDeTentativas){

        limpaTela();

        //Show the map
        exibeMapa();
            
        //Show the boardgame
        exibeTabuleiro(tabuleiro, mascara, false);

        cout << "\nPontos:" << pontos << ", Tentativas Restantes:" << maximoDeTentativas - tentativas;
        cout << "\n" << mensagem;
        //Insert the values

        linhaJogada = -1;
        colunaJogada = -1;

    while ((linhaJogada < 0 || colunaJogada < 0) || (linhaJogada > 9 || colunaJogada > 9) ){
        cout << "\n" << nomeDoJogador << ", Insert the line : " <<endl;
        cin >> linhaJogada;
        cout << "\n" << nomeDoJogador << ", Insert the column : "  << endl;
        cin >> colunaJogada;
    }


    // Looks for that happened

    verificaTiro(tabuleiro, linhaJogada, colunaJogada, &pontos, &mensagem);

    //Show what is on rhe boardgame
    mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];
    
    
    tentativas++;
    }
    
    cout << "The game has ended. What do you wanna do?\n" << endl;
    cout << "1 - Play Again" << endl;
    cout << "2 - Go to Menu" << endl;
    cout << "3 - Exit" << endl;
    cin >> opcao;
    switch(opcao){
            case 1:
                jogo(nomeDoJogador);
                break;
            case 2:
                MenuInicial();
                break;

    }
    
}

void MenuInicial(){

    //Option chosen by the player
    int opcao = 0;

    //Player Name
    string nomeDoJogador;


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
                // Asking the user's name:
                cout << "What is you name?" << endl;
                cin >> nomeDoJogador;
                jogo(nomeDoJogador);
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

    //Creating random numbers
    srand((unsigned)time(NULL));
    //Main Menu
    MenuInicial();
    
    return 0;
}