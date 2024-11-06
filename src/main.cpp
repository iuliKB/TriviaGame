#include "Intrebare.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

// Funcție pentru a încărca întrebările din fișier
std::vector<Intrebare> incarcaIntrebariDinFisier(const std::string& nivelDificultate) {
    std::vector<Intrebare> intrebari;
    std::ifstream file("intrebari.txt");

    if (!file) {
        std::cerr << "Nu s-a putut deschide fisierul intrebari.txt" << std::endl;
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

// Funcție pentru a normaliza inputul de dificultate
std::string normalizeazaDificultate(const std::string& input) {
    if (input.empty()) return "";
    
    std::string rezultat = input;
    rezultat[0] = std::toupper(rezultat[0]);  // Prima literă mare
    for (size_t i = 1; i < rezultat.size(); ++i) {
        rezultat[i] = std::tolower(rezultat[i]);  // Restul literelor mici
    }
    return rezultat;
}

int main() {
    std::string nivel;
    std::cout << "Alegeți nivelul de dificultate (Usor, Mediu, Dificil): ";
    std::cin >> nivel;

    // Normalizăm inputul de dificultate
    nivel = normalizeazaDificultate(nivel);

    // Încărcăm întrebările corespunzătoare nivelului de dificultate selectat
    std::vector<Intrebare> intrebari = incarcaIntrebariDinFisier(nivel);

    if (intrebari.empty()) {
        std::cout << "Nu s-au găsit întrebări pentru nivelul de dificultate ales." << std::endl;
        return 1;
    }

    int scor = 0;
    for (const auto& intrebare : intrebari) {
        intrebare.afiseazaIntrebare();
        int raspuns;
        std::cout << "Răspunsul tău: ";
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

    return 0;
}
