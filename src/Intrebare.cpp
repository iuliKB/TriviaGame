#include "Intrebare.h"
#include <iostream>
#include <mutex>

// Inițializăm mutex-ul static
std::mutex Intrebare::mtx;

// Constructor cu parametri
Intrebare::Intrebare(const std::string& text, const std::vector<std::string>& opt, int indexCorect, const std::string& dificult) {
    textIntrebare = std::make_unique<std::string>(text);
    optiuni = std::make_unique<std::vector<std::string>>(opt);
    indexRaspunsCorect = indexCorect;
    dificultate = std::make_unique<std::string>(dificult);
}

// Constructor de mutare
Intrebare::Intrebare(Intrebare&& other) noexcept {
    textIntrebare = std::move(other.textIntrebare);
    optiuni = std::move(other.optiuni);
    indexRaspunsCorect = other.indexRaspunsCorect;
    dificultate = std::move(other.dificultate);
}

// Operator de atribuire prin mutare
Intrebare& Intrebare::operator=(Intrebare&& other) noexcept {
    if (this != &other) {
        textIntrebare = std::move(other.textIntrebare);
        optiuni = std::move(other.optiuni);
        indexRaspunsCorect = other.indexRaspunsCorect;
        dificultate = std::move(other.dificultate);
    }
    return *this;
}

// Afișează întrebarea și opțiunile protejat prin mutex
void Intrebare::afiseazaIntrebare() const {
    std::lock_guard<std::mutex> lock(mtx); // Blocare mutex
    if (textIntrebare && optiuni) {
        std::cout << *textIntrebare << std::endl;
        for (size_t i = 0; i < optiuni->size(); ++i) {
            std::cout << i + 1 << ". " << (*optiuni)[i] << std::endl;
        }
    } else {
        std::cout << "Întrebare sau opțiuni neinițializate!" << std::endl;
    }
}

// Verifică dacă răspunsul utilizatorului este corect protejat prin mutex
bool Intrebare::esteCorect(int raspunsUtilizator) const {
    std::lock_guard<std::mutex> lock(mtx); // Blocare mutex
    return raspunsUtilizator - 1 == indexRaspunsCorect;
}

// Returnează dificultatea întrebării
std::string Intrebare::getDificultate() const {
    return dificultate ? *dificultate : "";
}