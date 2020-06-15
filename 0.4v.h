#ifndef vektorius_h
#define vektorius_h

#include <iostream>
#include <iomanip>
#include <random>
#include <utility>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cmath>
#include <chrono>

// Pradinė talpa pažymių vektoriaus
#define N 100
// Pradinė talpa studentų vektoriaus
#define S 1e5
// Lygiavimas išvedime
#define L 17
// Tikslumas išvedime
#define T 2
// Kiek turi pažymių vienas studentas faile
#define Kiek 6

struct Studentas
{
  std::string vard, pav;
  std::vector<int> p;
  double vid, med;
};

// Atsitiktinių skaičių generatorius
class RandInt {
public:
  RandInt(int low, int high) : mt{rd()}, dist{low, high} { }
  int operator()() { return dist(mt); } // generuok int’ą
private:
  std::random_device rd;
  std::mt19937 mt;
  std::uniform_int_distribution<int> dist;
};

// Pagalbinės funkcijos
std::string get_me(bool (*fun)(std::string &), const char zinute[]);
bool skaicius(std::string &tmp);
bool adresas(std::string &tmp);
bool zodis(std::string &tmp);
bool pasirinkti(const char zinute[]);
void failo_pav_is_ekrano(std::string &failo_vardas, const bool &naudoti_sablonus);

// Šabloninių failų sukūrimo funkcija
void failu_sukurimas();
// Bendra pradinė informacija
void intro(std::string &failo_vardas, bool &naudoti_sablonus);

int medianos_radimas(Studentas A);
void galutinio_radimas(Studentas &A);

// Rankinis pažymių įvedimas
void pazymiu_ivedimas(Studentas &A);
// Atsitiktinių pažymių generavimas naudojamas, kai duomenis įvedama per ekraną
void atsitiktiniai_pazymiai(Studentas &A);

void ivedimas_is_ekrano(std::vector<Studentas> &A);
// Kiek studentų yra faile. Reikalinga, kai reikia surasti ne šabloninio failo eilučių skaičių
int kiek_studentu(const std::string &failo_pav);
void ivedimas_is_failo(std::vector<Studentas> &A, const std::string &failo_pav, const int &n);

void isvedimas_i_ekrana(const std::vector<Studentas> &A);
// Surušiavimas į vargselius ir kietekus, tada jų įvedimas į atitinkamus failus
void surusiavimas(const std::vector<Studentas> &A);
void isvedimas_i_faila(const std::vector<Studentas> &A, const std::string &failo_pav, const bool &pasirinkimas);

#endif
