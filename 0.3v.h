#ifndef vektorius_h
#define vektorius_h

#include <iostream>
#include <iomanip>
#include <random>
#include <utility>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

// Pradinė talpa pažymių vektoriaus
#define N 500
// Lygiavimas galutiniame išvedime
#define L 17
// Tikslumas galutiniame išvedime
#define T 2

struct Studentas
{
  std::string vard, pav;
  std::vector<int> p;
  double vid, med;
};

void intro(int &kiek, std::string &failo_vardas);
std::string get_me(bool (*fun)(std::string &), const char zinute[]);
bool skaicius(std::string &tmp);
bool adresas(std::string &tmp);
bool zodis(std::string &tmp);
bool pasirinkti(const char zinute[]);

void medianos_radimas(Studentas &A);
void galutinio_radimas(Studentas &A);

void pazymiu_ivedimas(Studentas &A);
void atsitiktiniai_pazymiai(Studentas &A);
void pav_rikiavimas(Studentas A[], const int &kiek);

void ivedimas(Studentas A[], const int &kiek);
void ivedimas_is_failo(Studentas A[], const std::string &failo_pav, int &kiek);

void isvedimas(const Studentas A[], const int &kiek);

#endif
