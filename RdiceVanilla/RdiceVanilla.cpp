
#include <iostream>
#include <random> 
#include <stdexcept>
#include <cmath>
#include "string"


int generateRand() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    return dis(gen);
}





int main(){
    int initialNumber = generateRand()+generateRand()+generateRand();

    int d1 = 0;
    int d2 = 0;
    int d3 = 0;

    int dc1 = 0;
    int dc2 = 0;
    int dc3 = 0;

    float minTriesPlayer = INFINITY;
    float minTriesComp = INFINITY;


    std::cout<< "Rdice: El numero inicial en esta partida sera: " << initialNumber << "\n";

    int counter = 10;
    for (int i = 0; i < 10; i++) {
        bool playerSuccess = false;
        bool compSuccess = false;
        int userTries = 0;
        int compTries = 0;
        while (!playerSuccess or !compSuccess) {
            if (!playerSuccess) {
                userTries++;
                d1 = generateRand();
                d2 = generateRand();
                d3 = generateRand();

                if (d1 + d2 + d3 == initialNumber) playerSuccess = true;
                std::cout << "Jugador: " << d1 + d2 + d3 << "\n";
            }
            if (!compSuccess) {
                compTries++;
                dc1 = generateRand();
                dc2 = generateRand();
                dc3 = generateRand();

                if (dc1 + dc2 + dc3 == initialNumber) compSuccess = true;
                std::cout << "Computador: " << dc1 + dc2 + dc3 << "\n";
            }
        }
        std::cout << "Intentos de usuario: " << userTries << "\n";
        std::cout << "Intentos de computador: " << compTries << "\n";
        if (userTries < minTriesPlayer) minTriesPlayer = userTries;
        if (compTries < minTriesComp) minTriesComp = compTries;
    }


    std::cout << "Resultado Final: \n" << "Jugador:" << minTriesPlayer << "\nComputador: " << minTriesComp << "\n";

    if (minTriesPlayer < minTriesComp) {
        std::cout << "ERES EL GANADOR :D \n";
    }else if(minTriesPlayer > minTriesComp) {
        std::cout << "PERDISTE D: \n";
    }
    else {
        std::cout << "EMPATE :S";
    }

    return 0;
}
