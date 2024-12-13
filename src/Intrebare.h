#ifndef INTREBARE_H
#define INTREBARE_H

#include <string>
#include <vector>
#include <memory> // Pentru smart pointers
#include <mutex>  // Pentru mutex

class Intrebare {
private:
    std::unique_ptr<std::string> textIntrebare;
    std::unique_ptr<std::vector<std::string>> optiuni;
    int indexRaspunsCorect = 0;
    std::unique_ptr<std::string> dificultate;

    static std::mutex mtx; // Mutex static pentru protejarea accesului

public:
    // Constructor cu parametri
    Intrebare(const std::string& text, const std::vector<std::string>& opt, int indexCorect, const std::string& dificult);

    // Constructor de mutare
    Intrebare(Intrebare&& other) noexcept;
    Intrebare& operator=(Intrebare&& other) noexcept;

    // Dezactivăm copierea
    Intrebare(const Intrebare& other) = delete;
    Intrebare& operator=(const Intrebare& other) = delete;

    // Metode
    void afiseazaIntrebare() const;
    bool esteCorect(int raspunsUtilizator) const;
    std::string getDificultate() const;
};

#endif // INTREBARE_H