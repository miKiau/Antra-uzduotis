#ifndef masyvas_h
#define masyvas_h

#include <iostream>
#include <iomanip>
#include <random>

// Studento pažymių maksimumas
#define N 500

struct Studentas
{
  std::string vard, pav;
  int paz[N], n;
  double vid, med;
};

using std::cout;
using std::cin;
using std::string;

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
