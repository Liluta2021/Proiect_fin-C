#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream IN("IN.txt");
  ofstream OUT("OUT.txt");

  int nrMonede;
  vector<int> monede;
  map<int, int> schimbBancar;

  IN >> nrMonede;
  for (int i = 0; i < nrMonede; i++) {
    int mnd;
    IN >> mnd;
    monede.push_back(mnd);
  }
  // sortam descrescator vectoru/lista
  // sort(monede.rbegin(), monede.rend());
  int key, j;
  for (int i = 1; i < monede.size(); i++)
      {
          key = monede[i];
          j = i - 1;
          while (j >= 0 && monede[j] < key)
          {
              monede[j + 1] = monede[j];
              j = j - 1;
          }
          monede[j + 1] = key;
      }
  int baniiDeSchimbat;
  IN >> baniiDeSchimbat;
  for (int moneda : monede) {
    int monedeFolosite = baniiDeSchimbat / moneda;
    schimbBancar[moneda] = monedeFolosite;
    baniiDeSchimbat -= monedeFolosite * moneda;

  }
  if (baniiDeSchimbat != 0) {
    OUT << "N-am putut schimba banii cu monedele date\n";
    IN.close();
    OUT.close();
    return 0;
  }
  for (int moneda : monede) {
    OUT << "Moneda " +to_string(moneda) + " a fost utilizata de: " + to_string(schimbBancar[moneda]) + " ori\n";
  }
  IN.close();
  OUT.close();
}
