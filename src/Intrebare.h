#ifndef INTREBARE_H
#define INTREBARE_H

#include <string>
#include <vector>

class Intrebare {
private:
    std::string textIntrebare;
    std::vector<std::string> optiuni;
    int indexRaspunsCorect;
    std::string dificultate;  // Noul atribut pentru nivelul de dificultate

public:
    // Constructor
    Intrebare(const std::string& text, const std::vector<std::string>& opt, int indexCorect, const std::string& dificult);

    // Destructor
    ~Intrebare();

    // Metode
    void afiseazaIntrebare() const;
    bool esteCorect(int raspunsUtilizator) const;
    std::string getDificultate() const;  // Noua metodă pentru a obține dificultatea întrebării
};

#endif // INTREBARE_H
