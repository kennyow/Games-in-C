#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

using namespace std;

//Clear screen
void limpaTela(){
    system("CLS");
}

string retornaPalavraAleatoria(){

    //Vector with available words
    string palavras[3] = {"abacaxi", "manga", "morango"};

    //Index generated in range {0, 1, 2} - The rest of the division by 3
    int indiceAleatorio = rand() % 3;

    //Return the random word
    return palavras[indiceAleatorio];

}

string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){

    //Counter
    int cont = 0;
    string palavraComMascara; 

    //Put the Mask
    while (cont < tamanhoDaPalavra){
        palavraComMascara += "_";
        cont++;
    }
    return palavraComMascara;

}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem){
    //Print
    cout << mensagem << "\n";
    cout << "Word: "<< palavraComMascara;
    cout << "\nRemaining Attempts: " << tentativasRestantes;
    

    //Counter
    int cont = 0;

    //Print the letters played:
    cout << "\nLetters played: ";
    for( cont = 0; cont < letrasJaArriscadas.size(); cont++){
        cout << letrasJaArriscadas[cont] << ", ";
    }
    


}

int JogarSozinho(){

    //Word to be guessed
    string palavra = retornaPalavraAleatoria();

    //Word size
    int tamanhoDaPalavra = palavra.size();

    //Masked word
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);

    ///Main Variables
    int tentativas = 0, maximoDeTentativas = 10;
    int cont = 0;
    char letra; //Chosen Letter
    int opcao;  //To restart the game
    string letrasJaArriscadas;    //Letters already played
    string mensagem ="Welcome to the game!";                //Player feedback
    string palavraArriscada;                                //User's bet
    bool jaDigitouLetra = false, acertouLetra = false;          //repeated letter and guessed the letter



    while(palavra!= palavraComMascara && maximoDeTentativas - tentativas > 0){

        //Clear the screen
        limpaTela();

        //Show the actual status of the game
        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasJaArriscadas, mensagem );
         
        //Read the letter
        cout << "\nType a letter or 1 to write the entire word: \n";
        cin >> letra;

        //Write the word
        if (letra == '1'){
            cin >> palavraArriscada; 
            if (palavraArriscada == palavra){
                palavraComMascara = palavraArriscada;
                //mensagem= "You got the word right!!";
            }else{
                tentativas = maximoDeTentativas;
            }
        }

        //Scroll through repeated letters
        for (cont = 0; cont < tentativas; cont++){

            //If it finds the letter
            if(letrasJaArriscadas[cont]==letra){    
                //Print
                cout << "\n";
                mensagem = "This letter has already been typed!\n";
                jaDigitouLetra = true;
                }
        }

        if (jaDigitouLetra == false){

            //increment the letters
            letrasJaArriscadas += tolower(letra);

        //Scrolls through the actual word  
        for(cont = 0; cont < tamanhoDaPalavra; cont++){

            //if the letter exists 
            if(palavra[cont] == tolower(letra)){

                //changes it to palavraComMascara
                palavraComMascara[cont] = palavra[cont];

                acertouLetra = true;
            }

    }
        //Message displayed depending on the result
        if (acertouLetra = false){
            //Print
            cout << "\n";
            mensagem = "That's incorrect!";
        }else{
            //Print
            cout << "\n";
            mensagem = "You get it!";
            acertouLetra = false;
        }

        //Add 1 to the attempts
        tentativas++;

    }
        //Restart the variable
        jaDigitouLetra = false;
        acertouLetra = false;

}
  
    if (palavra ==palavraComMascara){
        //WIN message
        limpaTela();
        cout<< "\n** Congratulations! You WIN!! **\n";
        cout<< "\n";
        //Print
        cout << "** The chosen word was " << palavra << " **";
        cout<< "\nDo you want to try again?\n";
        cout<< "1 - Yes\n";
        cout<< "2 - No\n";
        cin >> opcao;
        return opcao;       

    }else{
        //LOSE message
        limpaTela();
        cout<< "\n** Sorry! You LOSE!! **\n";
        cout<< "\n";
        //Print
        cout << "** The chosen word was " << palavra << " **";
        cout<< "\nDo you want to try again?\n";
        cout<< "1 - Yes\n";
        cout<< "2 - No\n";
        cin >> opcao;
        return opcao;  
    }
    

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
            cout << "\n";
            cout << "** GAME STARTED **\n";
            if (JogarSozinho() == 1){
                MenuInicial();
            };
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

    //Generate random numbers:
    srand((unsigned)time(NULL));

    //Main Menu
    MenuInicial();

   return 0; 
}