#include "0.4v.h"

int main()
{
  // Pagrindiniai kintamieji
  std::vector<Studentas> A;
  bool  naudoti_sablonus = false,
        pasirinkimas;
  std::string failo_pav = "NULL";
  srand(time(NULL));
  // Programos pradžia
  intro(failo_pav, naudoti_sablonus);
  if (naudoti_sablonus)
  {
    // tik
    failu_sukurimas();
    // tak
    std::cout << "\nIš kurio failo norite, kad programa dirbtų? (pasirinkimas iš jau sugeneruotų šablonų).\n";
    failo_pav_is_ekrano(failo_pav, naudoti_sablonus);
    // tik
    ivedimas_is_failo(A, failo_pav, A.size());
    // tak
    std::cout << "\nAr norite, kad studentų duomenis išvestų ekrane?\n1. Jei taip, tada y arba Y.\n2. Jei ne, tada n arba N. Tuomet duomenis išves į du failus: vargseliai.txt ir kietekai.txt.\n";
    pasirinkimas = pasirinkti("");
    (pasirinkimas) ? isvedimas_i_ekrana(A) : surusiavimas(A);
  }
  else
  {
    (failo_pav == "NULL") ? ivedimas_is_ekrano(A) : ivedimas_is_failo(A, failo_pav, kiek_studentu(failo_pav));
    std::cout << "\nAr norite, kad studentų duomenis išvestų ekrane?\n1. Jei taip, tada y arba Y.\n2. Jei ne, tada n arba N. Tuomet duomenis išves į du failus: vargseliai.txt ir kietekai.txt.\n";
    pasirinkimas = pasirinkti("");
    (pasirinkimas) ? isvedimas_i_ekrana(A) : surusiavimas(A);
  }
  // Programos pabaiga
  return 0;
}
