#include "Intrebare.h"
#include <iostream>

// Constructor implicit
Intrebare::Intrebare() {
    this->textIntrebare = new std::string("Întrebare implicită");
    this->optiuni = new std::vector<std::string>({"Răspuns 1", "Răspuns 2", "Răspuns 3", "Răspuns 4"});
    this->indexRaspunsCorect = 0;
    this->dificultate = new std::string("Usor");
}

// Constructor cu parametri
Intrebare::Intrebare(const std::string& text, const std::vector<std::string>& opt, int indexCorect, const std::string& dificult) {
    this->textIntrebare = new std::string(text);
    this->optiuni = new std::vector<std::string>(opt);
    this->indexRaspunsCorect = indexCorect;
    this->dificultate = new std::string(dificult);
}

// Destructor
Intrebare::~Intrebare() {
    delete this->textIntrebare;
    delete this->optiuni;
    delete this->dificultate;
}

// Constructor de mutare
Intrebare::Intrebare(Intrebare&& other) noexcept {
    this->textIntrebare = other.textIntrebare;
    this->optiuni = other.optiuni;
    this->indexRaspunsCorect = other.indexRaspunsCorect;
    this->dificultate = other.dificultate;

    other.textIntrebare = nullptr;
    other.optiuni = nullptr;
    other.dificultate = nullptr;
}

// Operator de atribuire prin mutare
Intrebare& Intrebare::operator=(Intrebare&& other) noexcept {
    if (this != &other) {
        delete this->textIntrebare;
        delete this->optiuni;
        delete this->dificultate;

        this->textIntrebare = other.textIntrebare;
        this->optiuni = other.optiuni;
        this->indexRaspunsCorect = other.indexRaspunsCorect;
        this->dificultate = other.dificultate;

        other.textIntrebare = nullptr;
        other.optiuni = nullptr;
        other.dificultate = nullptr;
    }
    return *this;
}

// Afișează întrebarea și opțiunile
void Intrebare::afiseazaIntrebare() const {
    if (this->textIntrebare && this->optiuni) {
        std::cout << *(this->textIntrebare) << std::endl;
        for (size_t i = 0; i < this->optiuni->size(); ++i) {
            std::cout << i + 1 << ". " << (*this->optiuni)[i] << std::endl;
        }
    } else {
        std::cout << "Întrebare sau opțiuni neinițializate!" << std::endl;
    }
}

// Verifică dacă răspunsul utilizatorului este corect
bool Intrebare::esteCorect(int raspunsUtilizator) const {
    return raspunsUtilizator - 1 == this->indexRaspunsCorect;
}

// Returnează dificultatea întrebării
std::string Intrebare::getDificultate() const {
    return *(this->dificultate);
}

