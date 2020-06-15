#include "0.4v.h"

// Šabloninė funkcija gauti iš vartotojo pasirinktus duomenis
std::string get_me(bool (*fun)(std::string &), const char zinute[])
{
  std::string tmp;
  std::cout << zinute;
  while (fun(tmp)) {std::cin.ignore(256, '\n');}
  std::cin.ignore(256, '\n');
  return tmp;
}
// Įdėjus į get_me vartotojas turi įvesti skaičių
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
// Įdėjus į get_me vartotojas turi įvesti adresą
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
    std::cout << "Netinkamas failo pavadinimas.\n";
    return true;
  }
}
// Įdėjus į get_me vartotojas turi įvesti žodį
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
// Pasirinkimo funkcija, naudojama, kai vartotojas turi atsakyti į taip arba ne klausimą
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
void failo_pav_is_ekrano(std::string &failo_vardas, const bool &naudoti_sablonus)
{
  failo_vardas = get_me(adresas, "");
  do
  {
    std::ifstream fd(failo_vardas);
    if(!fd)
    {
      fd.close();
      failo_vardas = get_me(adresas, "Tokio failo nėra.\n");
    }
    else if(naudoti_sablonus)
    {
      if (failo_vardas == "d103.txt" || failo_vardas == "d104.txt" || failo_vardas == "d105.txt" || failo_vardas == "d106.txt" || failo_vardas == "d107.txt")
      {
        std::cout << "Tinkamas failo pavadinimas. Jei kraunasi, prašome palaukti.\n";
        fd.close();
        break;
      }
      else
      {
        fd.close();
        failo_vardas = get_me(adresas, "Pasirinkite iš sugeneruotų .txt formato failų.\n");
      }
    }
    else
    {
      std::cout << "Tinkamas failo pavadinimas.\n";
      fd.close();
      break;
    }
  }
  while (true);
}
// Šabloninių failų sukūrimo funkcija
void failu_sukurimas()
{
  RandInt rndvard(0, 100), rndsk(0, 10);
  std::string failo_pav;
  char tmp;
  std::cout << "\nŠablonų sukūrimo pradžia.\n";
  for (int i = 3; i < 8; i++)
  {
    tmp = '0' + i;
    failo_pav = {'d','1','0',tmp,'.','t','x','t'};
    std::ofstream rez(failo_pav);
    rez << std::setw(L) << std::left << "Pavardė"
     << std::setw(L - 2) << std::left << "Vardas"
     << "ND1  ND2  ND3  ND4  ND5  Egzaminas\n";
    for (int j = 1, stogas = pow(10,i); j <= stogas; j++)
    {
      rez << "Pavardė" << std::setw(9) << std::left << rndvard();
      rez << "Vardas" << std::setw(9) << std::left << rndvard();
      for (int z = 0; z < Kiek; z++)
      {
        rez << std::setw(5) << std::left << rndsk();
      }
      rez << std::endl;
    }
    rez.close();
    std::cout << "Sugeneruotas " << failo_pav << std::endl;
  }
  std::cout << "\nFailų sukūrimas baigtas.\n";
}
// Bendra pradinė informacija
void intro(std::string &failo_vardas, bool &naudoti_sablonus)
{
  std::cout << "\n--------------------------------------------------\n";
  std::cout << "Sveiki atvykę į studento vidurkio/medianos app\n";
  std::cout << "--------------------------------------------------\n\n";
  bool pasirinkimas = pasirinkti("Ar norite duomenis suvesti ranka?\n1. Jei taip, tada parašykite y arba Y.\n2. Jei ne, tada n arba N.\n");
  if (!pasirinkimas)
  {
    naudoti_sablonus = pasirinkti("\nAr norite, kad programa sugeneruotų šabloniškus failus iš 10^3, 10^4, 10^5, 10^6 ir 10^7 studentų?\n1. Jei taip, tada parašykite y arba Y.\n2. Jei ne, tada n arba N. Tuomet reikės suvesti turimo '.txt' formato failo pavadinimą.\n");
    if (!naudoti_sablonus)
    {
      std::cout << "Įveskite nuo 5 iki 20 simbolių ilgio, txt formato duomenų failo pavadinimą (pvz, duom.txt):\n";
      failo_pav_is_ekrano(failo_vardas, naudoti_sablonus);
    }
  }
}
int medianos_radimas(Studentas A)
{
  std::sort(A.p.begin(), A.p.end());
  return (A.p.size() % 2 == 0) ? (double)(A.p[A.p.size()/2 - 1] + A.p[A.p.size()/2]) / 2 : A.p[A.p.size() / 2];
}
void galutinio_radimas(Studentas &A)
{
  double sum = 0;
  for (const auto &e : A.p) {sum += e;}
  A.vid = (sum - A.p[A.p.size() - 1])/(A.p.size()-1) * 0.4 + A.p[A.p.size() - 1] * 0.6;
}
// Rankinis pažymių įvedimas
void pazymiu_ivedimas(Studentas &A)
{
  int tmp;
  std::cout <<  "Įveskite studento pažymius ir egzamino rezultatą\n(Įveskite ne skaitmenį, jei norite pabaigti įvedimą;\nĮveskite tik raidę, jei norite pereiti į atsitiktinį skaičių generavimą):\n";
  A.p.reserve(N);
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
    A.p.shrink_to_fit();
    galutinio_radimas(A);
    A.med = medianos_radimas(A);
  }
  else
  {
    std::cout << "Neįvedėte jokių pažymių, todėl parinkta atsitiktinis pažymių generavimas.\n";
    atsitiktiniai_pazymiai(A);
  }
}
// Atsitiktinių pažymių generavimas naudojamas, kai duomenis įvedama per ekraną
void atsitiktiniai_pazymiai(Studentas &A)
{
  RandInt rndsk(0, 10);
  A.p.reserve(N);
  for (int kiek = stoi(get_me(skaicius, "Kiek bus pažymių?\n")), i = 0; i < kiek; i++)
    A.p.push_back(rndsk());
  A.p.shrink_to_fit();
  galutinio_radimas(A);
  A.med = medianos_radimas(A);
}
void ivedimas_is_ekrano(std::vector<Studentas> &A)
{
  int tmp;
  A.reserve(S);
  while (true)
  {
    std::cout << "\nJei norite pabaigti studentų įvedimą, tada įveskite raidę w vietoje naujo studento pavardės.\n";
    tmp = A.size();
    std::cout << "\nStudentas nr." << tmp+1 << std::endl;
    A.push_back(Studentas());
    A[tmp].pav = get_me(zodis, "Iveskite studento pavardę:\n");
    if (A[tmp].pav == "w")
    {
      if (tmp == 0)
      {
        std::cout << "Įveskite bent vieno studento duomenis.\n";
        A.pop_back();
        continue;
      }
      else
      {
        A.pop_back();
        break;
      }
    }
    A[tmp].vard = get_me(zodis, "Iveskite studento vardą:\n");
    A[tmp].p.reserve(N);
    std::cout << "\nAr atsitiktinai sugeneruoti pažymius?:\n1. Taip, spausti y arba Y.\n2. Ne, suvesiu pats. Spausti n arba N.\n";
    (pasirinkti("")) ? atsitiktiniai_pazymiai(A[tmp]) : pazymiu_ivedimas(A[tmp]);
  }
  A.shrink_to_fit();
  sort(A.begin(), A.end(), [](Studentas const &a, Studentas const &b) -> bool {return a.pav < b.pav;});
}
// Kiek studentų yra faile. Reikalinga, kai reikia surasti ne šabloninio failo eilučių skaičių
int kiek_studentu(const std::string &failo_pav)
{
  int k = 0;
  std::string tmp;
  std::ifstream fd(failo_pav);
  while (getline(fd, tmp)) {k++;}
  fd.close();
  return k - 1;
}
void ivedimas_is_failo(std::vector<Studentas> &A, const std::string &failo_pav, const int &n)
{
  int tmp;
  try
  {
    std::ifstream fd(failo_pav);
    // Ignoruoju pirmąją eilutę, kur parašyta stulpelių pavadinimai
    fd.ignore(256, '\n');
    A.reserve(S);
    // Pažymių nuskaitymas
    for (int i = 0; i < n; i++)
    {
      A.push_back(Studentas());
      fd >> A[i].pav >> A[i].vard;
      A[i].p.reserve(N);
      for (int j = 0; j < Kiek; j++)
      {
        fd >> tmp;
        A[i].p.push_back(tmp);
      }
      galutinio_radimas(A[i]);
      A[i].med = medianos_radimas(A[i]);
    }
    fd.close();
    A.shrink_to_fit();
    sort(A.begin(), A.end(), [](Studentas const &a, Studentas const &b) -> bool {return a.pav < b.pav;});
  }
  catch (...)
  {
    std::cout << "ERROR\n";
    // To be continued
  }
}
void isvedimas_i_ekrana(const std::vector<Studentas> &A)
{
  bool pasirinkimas = pasirinkti("\nAr išvesti vidurkį?\n1. Taip, tada y arba Y.\n2. Ne, tada n arba N. Tuomet išves medianą.\n");
  std::cout << "\n-------------------------------------------------------------------\n";
  std::cout << std::setw(L) << std::left << "Pavardė"
   << std::setw(L) << std::left << "Vardas";
  if (pasirinkimas)
    std::cout << std::setw(L) << std::left << "Galutinis (Vid.)";
  else
    std::cout << std::setw(L) << std::left << "Galutinis (Med.)";
  std::cout << "\n-------------------------------------------------------------------\n";
  for (const auto &e : A)
  {
    std::cout << std::setw(L) << std::left << e.pav
      << std::setw(L) << std::left << e.vard;
    if (pasirinkimas)
      std::cout << std::setw(L) << std::left << std::setprecision(T) << std::fixed << e.vid << std::endl;
    else
      std::cout << std::setw(L) << std::left << std::setprecision(T) << std::fixed << e.med << std::endl;
  }
  std::cout << "-------------------------------------------------------------------\n\n";
}
// Surušiavimas į vargselius ir kietekus, tada jų įvedimas į atitinkamus failus
void surusiavimas(const std::vector<Studentas> &A)
{
  std::vector<Studentas> varg, kiet;
  varg.reserve(A.size() + 1);
  kiet.reserve(A.size() + 1);
  bool pasirinkimas = pasirinkti("\nAr išvesti vidurkį?\n1. Taip, tada y arba Y.\n2. Ne, tada n arba N. Tuomet išves medianą.\n");
  // tik
  for (const auto &e : A)
  {
    ((pasirinkimas && e.vid < 5.0) || (!pasirinkimas && e.med < 5.0)) ? varg.push_back(e) : kiet.push_back(e);
  }
  // tak
  varg.shrink_to_fit();
  kiet.shrink_to_fit();
  sort(varg.begin(), varg.end(), [](Studentas const &a, Studentas const &b) -> bool {return a.pav < b.pav;});
  sort(kiet.begin(), kiet.end(), [](Studentas const &a, Studentas const &b) -> bool {return a.pav < b.pav;});
  // tik
  isvedimas_i_faila(varg, "vargseliai.txt", pasirinkimas);
  isvedimas_i_faila(kiet, "kietekai.txt", pasirinkimas);
  // tak
}
void isvedimas_i_faila(const std::vector<Studentas> &A, const std::string &failo_pav, const bool &pasirinkimas)
{
  try
  {
    std::ofstream fr(failo_pav);
    fr << "-------------------------------------------------------------------\n";
    fr << std::setw(L) << std::left << "Pavardė"
      << std::setw(L) << std::left << "Vardas";
    if (pasirinkimas)
      fr << std::setw(L) << std::left << "Galutinis (vid.)";
    else
      fr << std::setw(L) << std::left << "Galutinis (med.)";
    fr << "\n-------------------------------------------------------------------\n";
    for (const auto &e : A)
    {
      fr << std::setw(L) << std::left << e.pav
        << std::setw(L) << std::left << e.vard;
      if (pasirinkimas)
        fr << std::setw(L) << std::left << std::setprecision(T) << std::fixed << e.vid << std::endl;
      else
        fr << std::setw(L) << std::left << std::setprecision(T) << std::fixed << e.med << std::endl;
    }
    fr << "-------------------------------------------------------------------\n\n";
    fr.close();
  }
  catch (...)
  {
    std::cout << "ERROR\n";
  }
}
