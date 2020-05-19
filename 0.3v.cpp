#include "0.3v.h"

int main()
{
  int kiek = 0;
  std::string failo_pav = "NULL";
  srand(time(NULL));

  intro(kiek, failo_pav);
  Studentas A[kiek];
  (failo_pav == "NULL") ? ivedimas(A, kiek) : ivedimas_is_failo(A, failo_pav, kiek);
  isvedimas(A, kiek);
  return 0;
}
