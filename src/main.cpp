
#include "Intrebare.h"
#include "Obiect.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


std::vector<Intrebare> incarcaIntrebariDinFisier(const std::string& nivelDificultate) {
    std::vector<Intrebare> intrebari;
    std::ifstream file("intrebari.txt");

    if (!file) {
        std::cerr << "Eroare: Nu s-a putut deschide fișierul intrebari.txt" << std::endl;
        return intrebari;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string text, opt1, opt2, opt3, opt4, dificult;
        int raspunsCorect;

        std::getline(ss, text, ';');
        std::getline(ss, opt1, ';');
        std::getline(ss, opt2, ';');
        std::getline(ss, opt3, ';');
        std::getline(ss, opt4, ';');
        ss >> raspunsCorect;
        ss.ignore(1, ';');
        std::getline(ss, dificult, ';');

        if (dificult == nivelDificultate) {
            std::vector<std::string> optiuni = {opt1, opt2, opt3, opt4};
            intrebari.emplace_back(text, optiuni, raspunsCorect, dificult);
        }
    }

    return intrebari;
}


// Itemul 5: Ierarhia de clase 

void demonstreazaItem5() {
    std::cout << "=== Demonstratie Item 5: Ierarhia de clase ===\n";

    // Creăm un obiect de bază
    Obiect obj("ObiectDeBaza");
    obj.descrie();

    // Creăm un obiect derivat
    ObiectDerivat objDer("ObiectDerivat", 42);
    objDer.descrie();

    // Utilizăm polimorfismul (tratăm obiectul derivat ca un obiect de bază)
    Obiect* objPtr = new ObiectDerivat("ObiectDerivatCaBaza", 99);
    objPtr->descrie();

    // Distrugem obiectul derivat alocat dinamic
    delete objPtr;

    std::cout << "=== Sfârșitul demonstratiei Item 5 ===\n\n";
}


//  Itemul 6: Dezactivarea copy/move constructor ===

void demonstreazaItem6() {
    std::cout << "=== Demonstratie Item 6: Dezactivarea copy/move constructor ===\n";

    // Încărcăm întrebările din fișier
    std::vector<Intrebare> intrebari = incarcaIntrebariDinFisier("Usor");

    if (intrebari.empty()) {
        std::cout << "Nu s-au găsit întrebări pentru nivelul de dificultate ales.\n";
        return;
    }

    // Selectăm prima întrebare din vector
    Intrebare intrebare1 = std::move(intrebari[0]);

    // Mutăm întrebarea într-un alt obiect
    Intrebare intrebare2 = std::move(intrebare1);

    // Afișăm întrebarea mutată
    std::cout << "Întrebarea mutată:\n";
    intrebare2.afiseazaIntrebare();

    // Afișăm starea întrebării sursă după mutare
    std::cout << "Întrebarea sursă după mutare:\n";
    intrebare1.afiseazaIntrebare();

    std::cout << "=== Sfârșitul demonstratiei Item 6 ===\n";
}


void TriviaGame() {
    std::cout << "=== TriviaGame ===\n";

    std::string nivel;
    std::cout << "Alegeți nivelul de dificultate (Usor, Mediu, Dificil): ";
    std::cin >> nivel;

    // Încărcăm întrebările din fișier
    std::vector<Intrebare> intrebari = incarcaIntrebariDinFisier(nivel);

    if (intrebari.empty()) {
        std::cout << "Nu s-au găsit întrebări pentru nivelul de dificultate ales.\n";
    } else {
        int scor = 0;
        for (const auto& intrebare : intrebari) {
            intrebare.afiseazaIntrebare();
            int raspuns;
            std::cout << "Răspunsul tău (1-4): ";
            std::cin >> raspuns;

            if (intrebare.esteCorect(raspuns)) {
                std::cout << "Corect!\n";
                scor++;
            } else {
                std::cout << "Greșit.\n";
            }
            std::cout << std::endl;
        }
        std::cout << "Scorul final: " << scor << " din " << intrebari.size() << std::endl;
    }
}


int main() {
    
    // Demonstrează itemul 5: Ierarhia de clase
    //demonstreazaItem5();

    // Demonstrează itemul 6: Dezactivarea copy/move constructor
    //demonstreazaItem6();

    // TriviaGame: Funcționalitatea principală
    TriviaGame();

    return 0;
}