#include "Intrebare.h"
#include <iostream>
#include <vector>
#include <memory>  // Pentru smart pointers
#include <fstream>
#include <sstream>
#include <thread>
#include <mutex>

// Funcția pentru încărcarea întrebărilor din fișier
std::vector<std::shared_ptr<Intrebare>> incarcaIntrebariDinFisier(const std::string& nivelDificultate) {
    std::vector<std::shared_ptr<Intrebare>> intrebari;
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
            intrebari.push_back(std::make_shared<Intrebare>(text, optiuni, raspunsCorect, dificult));
        }
    }

    return intrebari;
}

// Demonstrație pentru Itemul 13: Smart Pointers (unique_ptr și shared_ptr)
void demonstreazaItem13() {
    std::cout << "=== Demonstratie Item 13: Smart Pointers ===\n";

    // Utilizare std::unique_ptr pentru o întrebare
    std::unique_ptr<Intrebare> intrebareUnica(new Intrebare(
        "Care este capitala Italiei?",
        std::vector<std::string>{"Roma", "Paris", "Berlin", "Madrid"},
        0,
        "Mediu"
    ));

    intrebareUnica->afiseazaIntrebare();

    // Utilizare std::shared_ptr pentru a partaja întrebare între mai multe instanțe
    auto intrebarePartajata = std::make_shared<Intrebare>(
        "Ce limbă se vorbește în Spania?",
        std::vector<std::string>{"Engleză", "Franceză", "Spaniolă", "Italiană"},
        2,
        "Usor"
    );

    auto copieShared = intrebarePartajata;

    std::cout << "\nPrima instanță de shared_ptr:\n";
    intrebarePartajata->afiseazaIntrebare();

    std::cout << "\nA doua instanță de shared_ptr (copiată):\n";
    copieShared->afiseazaIntrebare();

    std::cout << "\nNumăr de referințe active la obiectul shared_ptr: " << copieShared.use_count() << "\n";

    std::cout << "=== Sfârșitul demonstratiei Item 13 ===\n\n";
}

// Funcție pentru afișarea întrebărilor pe un thread separat (Item 14)
void afiseazaIntrebarePeThread(const std::shared_ptr<Intrebare>& intrebare) {
    intrebare->afiseazaIntrebare();
}

// Demonstrație pentru Itemul 14: Utilizarea Mutex-ului pentru Gestionarea Resurselor
void demonstreazaItem14() {
    std::cout << "=== Demonstratie Item 14: Mutex pentru Gestionarea Resurselor ===\n";

    // Creăm o întrebare partajată între mai multe thread-uri
    auto intrebarePartajata = std::make_shared<Intrebare>(
        "Care este capitala Franței?",
        std::vector<std::string>{"Paris", "Londra", "Berlin", "Madrid"},
        0,
        "Usor"
    );

    // Pornim două thread-uri care apelează funcția de afișare simultan
    std::thread t1(afiseazaIntrebarePeThread, intrebarePartajata);
    std::thread t2(afiseazaIntrebarePeThread, intrebarePartajata);

    // Așteptăm ca thread-urile să termine execuția
    t1.join();
    t2.join();

    std::cout << "=== Sfârșitul demonstratiei Item 14 ===\n\n";
}

int main() {
    // Demonstrează itemul 13: Smart Pointers
    demonstreazaItem13();

    // Demonstrează itemul 14: Mutex pentru Gestionarea Resurselor
   // demonstreazaItem14();

    // TriviaGame: Funcționalitatea principală
    //TriviaGame();

    return 0;
}