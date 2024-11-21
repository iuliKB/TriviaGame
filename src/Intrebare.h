

#ifndef INTREBARE_H
#define INTREBARE_H

#include <string>
#include <vector>

class Intrebare {
private:
    std::string* textIntrebare = nullptr;              // Pointer alocat dinamic
    std::vector<std::string>* optiuni = nullptr;      // Pointer alocat dinamic
    int indexRaspunsCorect = 0;                       // Index răspuns corect
    std::string* dificultate = nullptr;               // Pointer alocat dinamic

public:
    // Constructor implicit
    Intrebare();

    // Constructor cu parametri
    Intrebare(const std::string& text, const std::vector<std::string>& opt, int indexCorect, const std::string& dificult);

    // Destructor
    ~Intrebare();

    // Dezactivăm copierea
    Intrebare(const Intrebare& other) = delete;            // Constructor de copiere dezactivat
    Intrebare& operator=(const Intrebare& other) = delete; // Operator de atribuire dezactivat

    // Permitem mutarea (move constructor și move assignment)
    Intrebare(Intrebare&& other) noexcept;
    Intrebare& operator=(Intrebare&& other) noexcept;

    // Metode
    void afiseazaIntrebare() const;
    bool esteCorect(int raspunsUtilizator) const;
    std::string getDificultate() const;
};

#endif // INTREBARE_H