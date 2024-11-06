#include "Intrebare.h"
#include <iostream>

// Inițializarea membrilor în constructor, inclusiv `dificultate`
Intrebare::Intrebare(const std::string& text, const std::vector<std::string>& opt, int indexCorect, const std::string& dificult)
    : textIntrebare(text), optiuni(opt), indexRaspunsCorect(indexCorect), dificultate(dificult) {
}

Intrebare::~Intrebare() {
    // Destructor - eliberarea automată a memoriei, dacă sunt alocări dinamice
}

void Intrebare::afiseazaIntrebare() const {
    std::cout << textIntrebare << std::endl;
    for (size_t i = 0; i < optiuni.size(); ++i) {
        std::cout << i + 1 << ". " << optiuni[i] << std::endl;
    }
}

bool Intrebare::esteCorect(int raspunsUtilizator) const {
    return raspunsUtilizator - 1 == indexRaspunsCorect;
}

std::string Intrebare::getDificultate() const {
    return dificultate;
}
