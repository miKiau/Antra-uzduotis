#ifndef vektorius_h
#define vektorius_h

#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>

// Studento pažymių maksimumas
#define N 500

struct Studentas
{
  std::string vard, pav;
  std::vector<int> p;
  double vid, med;
};

void intro(int &kiek);
int get_int(std::string zinute);
std::string get_string();
bool pasirinkti(std::string zinute);
void surusiavimas(Studentas &A);
void medianos_radimas(Studentas &A);
void pazymiu_ivedimas(Studentas &A);
void atsitiktiniai_pazymiai(Studentas &A);
void ivedimas(Studentas A[], int kiek);
void isvedimas(Studentas A[], int kiek);

#endif
