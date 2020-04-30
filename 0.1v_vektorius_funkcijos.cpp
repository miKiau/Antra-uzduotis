#include "0.1v_vektorius.h"

#ifndef vektoriu_fukcijos
#define vektoriu_fukcijos

void intro(int &kiek)
{
  std::cout << "\n--------------------------------------------------\n";
  std::cout << "Sveiki atvykę į studento vidurkio/medianos app\n";
  std::cout << "--------------------------------------------------\n\n";
  kiek = get_int("Iveskite kiek bus studentu duomenu:\n");
  std::cout << "\nPrograma fiksuoja tik vieno žodžio vardą ir pavardę.\n";
}
int get_int(std::string zinute)
{
  int tmp;
  std::cout << zinute;
  std::cin >> tmp;
  while (!std::cin)
  {
    std::cout << "Rastas netinkamas simbolis.\n";
    std::cin.clear();
    std::cin.ignore(256,'\n');
    std::cin >> tmp;
  }
  std::cin.ignore(256,'\n');
  return tmp;
}
// string tipo, vien tik is raidziu sudaryto zodzio gavimas
std::string get_string()
{
  std::string tmp;
  bool netinka;
  do
  {
    netinka = false;
    std::cin >> tmp;
    std::cin.ignore(256, '\n');
    for (char e : tmp)
    {
      if ( !((e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z')))
      {
        netinka = true;
        std::cout << "Rastas netinkamas simbolis.\n";
        break;
      }
    }
  }
  while (netinka);
  return tmp;
}
bool pasirinkti(std::string zinute)
{
  std::string tmp;
  std::cout << zinute;
  while (true)
  {
    tmp = std::cin.get();
    std::cin.ignore(256, '\n');
    if (tmp == "y" || tmp == "Y")
    {
      return true;
    }
    else if (tmp == "N" || tmp == "n")
    {
      return false;
    }
    else
    {
      std::cout << "Rastas netinkamas simbolis.\n";
    }
  }
}
void medianos_radimas(Studentas &A)
{
  A.p.shrink_to_fit();
  std::sort(A.p.begin(), A.p.end());
  if (A.p.size() % 2 == 0)
  {
    A.med = (double)(A.p[A.p.size()/2 - 1] + A.p[A.p.size()/2]) / 2;
  }
  else
  {
    A.med = A.p[A.p.size() / 2];
  }
}
void pazymiu_ivedimas(Studentas &A)
{
  int tmp;
  double sum = 0;
  std::cout <<  "Įveskite studento pažymius ir egzamino rezultatą\n(Įveskite ne skaitmenį, jei norite pabaigti įvedimą;\nĮveskite tik raidę, jei norite pereiti į atsitiktinį skaičių generavimą):\n";
  while (std::cin >> tmp)
  {
    if (tmp > 10 || tmp < 0)
    {
      std::cout << "Pažymys turi būti dešimtbalėje sistemoje.\n";
      continue;
    }
    A.p.push_back(tmp);
    sum += tmp;
  }
  // Error'o išvalymas
  std::cin.clear();
  std::cin.ignore(256,'\n');
  // Patikrinimas ar išvis kažkas buvo įvesta
  if (A.p.size() != 0)
  {
    A.vid = sum / A.p.size();
    medianos_radimas(A);
  }
  else
  {
    std::cout << "Neįvedėte jokių pažymių, todėl parenkame atsitiktinį pažymių generavimą.\n";
    atsitiktiniai_pazymiai(A);
  }
}
void atsitiktiniai_pazymiai(Studentas &A)
{
  double sum = 0;
  for (int kiek = get_int("Kiek bus pažymių?\n"), i = 0; i < kiek; i++)
  {
    A.p.push_back(rand()%11);
    sum += A.p[i];
  }
  A.vid = sum / A.p.size();
  medianos_radimas(A);
}
void ivedimas(Studentas A[], int kiek)
{
  for (int i = 0; i < kiek; i++)
  {
    std::cout << "\nStudentas nr." << i+1 << std::endl;
    std::cout << "Iveskite studento vardą:\n";
    A[i].vard = get_string();
    std::cout << "Iveskite studento pavardę:\n";
    A[i].pav = get_string();
    A[i].p.reserve(N);
    if (pasirinkti("\nPasirinkite:\n1. Atsitiktinai sugeneruoti pažymiai, spausti y arba Y.\n2. Suvesti pažymius, spausti n arba N.\n"))
    {
      atsitiktiniai_pazymiai(A[i]);
    }
    else
    {
      pazymiu_ivedimas(A[i]);
    }
  }
}
void isvedimas(Studentas A[], int kiek)
{
  bool pasirinkimas = pasirinkti("\nPasirinkite:\n1. Pateikti studentų vidurkį, spausti y arba Y.\n2. Pateikti studentų medianą, spausti n arba N.\n");
  std::cout << "\n--------------------------------------------------\n";
  std::cout << "Pavardė" << std::setw(10)  << " " << "Vardas" << std::setw(10) << "  ";
  if (pasirinkimas)
  {
    std::cout << " Galutinis (Vid.)\n";
  }
  else
  {
    std::cout << " Mediana (Med.)\n";
  }
  std::cout << "--------------------------------------------------\n";
  for (int i = 0; i < kiek; i++)
  {
    std::cout << std::setw(17) << std::left << A[i].pav
     << std::setw(17) << std::left << A[i].vard;
     if (pasirinkimas)
     {
       std::cout << std::setw(17) << std::left << std::setprecision(2) << std::fixed << A[i].vid << "\n";
     }
     else
     {
       std::cout << std::setw(17) << std::left << std::setprecision(2) << std::fixed << A[i].med << "\n";
     }
  }
  std::cout << "--------------------------------------------------\n\n";
}
#endif
