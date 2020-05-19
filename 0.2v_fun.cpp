#include "0.2v.h"

std::string get_me(bool (*fun)(std::string &), const char zinute[])
{
  std::string tmp;
  std::cout << zinute;
  while (fun(tmp)) {std::cin.ignore(256, '\n');}
  std::cin.ignore(256, '\n');
  return tmp;
}
bool skaicius(std::string &tmp)
{
  int temp;
  try
  {
    std::cin >> temp;
    (!std::cin) ? throw 1 : tmp = std::to_string(temp);
    return false;
  }
  catch (int &e)
  {
    std::cin.clear();
    std::cout << "Įveskite skaičių.\n";
    return true;
  }
}
bool adresas(std::string &tmp)
{
  try
  {
    std::cin >> tmp;
    if (tmp.length() > 4 && tmp.length() < 21 && tmp.compare(tmp.length() - 4, 4, ".txt") == 0)
      return false;
    else throw 1;
  }
  catch (int &e)
  {
    std::cout << "Netinkamas adresas.\n";
    return true;
  }
}
bool zodis(std::string &tmp)
{
  try
  {
    std::cin >> tmp;
    for (const auto &e : tmp)
    {
      if (!((e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z')))
        throw 1;
    }
    return false;
  }
  catch (int &e)
  {
    std::cout << "Netinkamas žodis.\n";
    return true;
  }
}
bool pasirinkti(const char zinute[])
{
  // Galima dar patobulinti
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
void intro(int &kiek, std::string &failo_vardas)
{
  std::cout << "\n--------------------------------------------------\n";
  std::cout << "Sveiki atvykę į studento vidurkio/medianos app\n";
  std::cout << "--------------------------------------------------\n\n";
  bool pasirinkimas = pasirinkti("Ar norite duomenis suvesti ranka?\n1. Jei taip, tada parašykite y arba Y.\n2. Jei ne, tada n arba N.\n");
  if (pasirinkimas)
  {
    kiek = stoi(get_me(skaicius, "\nIveskite kiek bus studentų duomenų:\n"));
    std::cout << "\nPrograma fiksuoja tik vieno žodžio vardą ir pavardę.\n";
  }
  else
  {
    std::string tmp;
    kiek = 0;
    failo_vardas = get_me(adresas, "\nĮveskite nuo 5 iki 20 simbolių ilgio, txt formato duomenų failo pavadinimą (pvz, duom.txt):\n");
    do
    {
      std::ifstream fd(failo_vardas);
      if (!fd)
      {
        failo_vardas = get_me(adresas, "Tokio failo nėra. Įveskite egzituojantį ir tinkamą pavadinimą.\n");
      }
      else
      {
        while(!fd.eof())
        {
          getline(fd, tmp);
          kiek++;
        }
        fd.close();
        break;
      }
      fd.close();
    }
    while(true);
    // Naudoju 'Atom', kažkodėl išsaugojus dokumentą sukuria dar vieną eilutę pačiame gale
    // todėl atėmu pirmą ir paskutinę eilutes
    kiek -= 2;
  }
}
void medianos_radimas(Studentas &A)
{
  A.p.shrink_to_fit();
  std::sort(A.p.begin(), A.p.end());
  A.med = (A.p.size() % 2 == 0) ? (double)(A.p[A.p.size()/2 - 1] + A.p[A.p.size()/2]) / 2 : A.p[A.p.size() / 2];
}
void galutinio_radimas(Studentas &A)
{
  double sum = 0;
  for (const auto &e : A.p) {sum += e;}
  A.vid = (sum - A.p[A.p.size() - 1])/(A.p.size()-1) * 0.4 + A.p[A.p.size() - 1] * 0.6;
}
// Galima dar patobulinti
void pazymiu_ivedimas(Studentas &A)
{
  int tmp;
  std::cout <<  "Įveskite studento pažymius ir egzamino rezultatą\n(Įveskite ne skaitmenį, jei norite pabaigti įvedimą;\nĮveskite tik raidę, jei norite pereiti į atsitiktinį skaičių generavimą):\n";
  while (std::cin >> tmp)
  {
    if (tmp > 10 || tmp < 0)
    {
      std::cout << "Pažymys turi būti dešimtbalėje sistemoje.\n";
      continue;
    }
    A.p.push_back(tmp);
  }
  // Error'o išvalymas
  std::cin.clear();
  std::cin.ignore(256,'\n');
  // Patikrinimas ar išvis kažkas buvo įvesta
  if (A.p.size() != 0)
  {
    galutinio_radimas(A);
    medianos_radimas(A);
  }
  else
  {
    std::cout << "Neįvedėte jokių pažymių, todėl parinkta atsitiktinis pažymių generavimas.\n";
    atsitiktiniai_pazymiai(A);
  }
}
void atsitiktiniai_pazymiai(Studentas &A)
{
  for (int kiek = stoi(get_me(skaicius, "Kiek bus pažymių?\n")), i = 0; i < kiek; i++)
    A.p.push_back(rand()%11);
  galutinio_radimas(A);
  medianos_radimas(A);
}
void pav_rikiavimas(Studentas A[], const int &kiek)
{
  for (int i = 0; i < kiek - 1; i++)
    for (int j = 0; j < kiek - 1; j++)
      if(A[j].pav.compare(A[j+1].pav) > 0) std::swap(A[j], A[j+1]);
}
void ivedimas(Studentas A[], const int &kiek)
{
  for (int i = 0; i < kiek; i++)
  {
    std::cout << "\nStudentas nr." << i+1 << std::endl;
    A[i].pav = get_me(zodis, "Iveskite studento pavardę:\n");
    A[i].vard = get_me(zodis, "Iveskite studento vardą:\n");
    // Kad būtų mažiau veiksmų.
    A[i].p.reserve(N);
    std::cout << "\nAr atsitiktinai sugeneruoti pažymius?:\n1. Taip, spausti y arba Y.\n2. Ne, suvesiu pats. Spausti n arba N.\n";
    (pasirinkti("")) ? atsitiktiniai_pazymiai(A[i]) : pazymiu_ivedimas(A[i]);
  }
  pav_rikiavimas(A, kiek);
}
void ivedimas_is_failo(Studentas A[], const std::string &failo_pav, int &kiek)
{
  int tmp, keli = 0;
  std::string temp;
  try
  {
    std::ifstream fd(failo_pav);
    // Pažymių skaičio radimas
    do
    {
      fd >> temp;
      keli++;
    }
    while (temp != "Egzaminas");
    // Atimu pavardės ir vardo stulpelius
    keli -= 2;
    // Pažymių nuskaitymas
    for(int i = 0; i < kiek; i++)
    {
      fd >> A[i].pav >> A[i].vard;
      A[i].p.reserve(N);
      for (int j = 0; j < keli; j++)
      {
        fd >> tmp;
        A[i].p.push_back(tmp);
      }
      galutinio_radimas(A[i]);
      medianos_radimas(A[i]);
    }
    fd.close();
    pav_rikiavimas(A, kiek);
  }
  catch (...)
  {
    std::cout << "ERROR\n";
  }
}
void isvedimas(const Studentas A[], const int &kiek)
{
  std::cout << "\n--------------------------------------------------\n";
  std::cout << "Pavardė" << std::setw(10)  << " " << "Vardas" << std::setw(7) << " " << "Galutinis (Vid.)"
  << std::setw(10)  << " Galutinis (Med.)\n";
  std::cout << "--------------------------------------------------\n";
  for (int i = 0; i < kiek; i++)
  {
    std::cout
      << std::setw(L) << std::left << A[i].pav
      << std::setw(L) << std::left << A[i].vard
      << std::setw(L) << std::left << std::setprecision(T) << std::fixed << A[i].vid
      << std::setw(L) << std::left << std::setprecision(T) << std::fixed << A[i].med << "\n";
  }
  std::cout << "--------------------------------------------------\n\n";
}
