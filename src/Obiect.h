#ifndef OBIECT_H
#define OBIECT_H

#include <iostream>
#include <string>

// Clasa de bază
class Obiect {
protected:
    std::string nume;

public:
    // Constructor
    Obiect(const std::string& numeObiect = "Obiect") : nume(numeObiect) {
        std::cout << "Obiectul de bază \"" << nume << "\" a fost creat.\n";
    }

    // Destructor
    virtual ~Obiect() {
        std::cout << "Destructorul clasei de bază \"" << nume << "\" a fost apelat.\n";
    }

    // Metodă virtuală pentru demonstrarea polimorfismului
    virtual void descrie() const {
        std::cout << "Sunt un obiect de bază cu numele \"" << nume << "\".\n";
    }
};

// Clasa derivată
class ObiectDerivat : public Obiect {
private:
    int valoareDerivata;

public:
    // Constructor
    ObiectDerivat(const std::string& numeObiect = "ObiectDerivat", int valoare = 0)
        : Obiect(numeObiect), valoareDerivata(valoare) {
        std::cout << "Obiectul derivat \"" << nume << "\" a fost creat.\n";
    }

    // Destructor
    ~ObiectDerivat() override {
        std::cout << "Destructorul clasei derivate \"" << nume << "\" a fost apelat.\n";
    }

    // Suprascrierea metodei descrie
    void descrie() const override {
        std::cout << "Sunt un obiect derivat cu numele \"" << nume << "\" și valoarea \"" << valoareDerivata << "\".\n";
    }
};

#endif // OBIECT_H