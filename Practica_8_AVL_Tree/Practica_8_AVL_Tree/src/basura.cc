#include <iostream>
#include<vector>


void merge(std::vector<int>& v, int inicio, int mitad, int fin) {
    std::vector<int> aux(v.size());
    int i = inicio, j = mitad + 1, k = inicio;
    while (i <= mitad && j <= fin) {
        if (v[i] < v[j]) {
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
        }
        k++;
    }
    while (i <= mitad) {
        aux[k] = v[i];
        i++;
        k++;
    }
    while (j <= fin) {
        aux[k] = v[j];
        j++;
        k++;
    }
    for (int i = inicio; i <= fin; i++) {
        v[i] = aux[i];
    }
}

void mergeSort(std::vector<int>& v, int inicio, int fin) {
    if (inicio < fin) {
        int mitad = (inicio + fin) / 2;
        mergeSort(v, inicio, mitad);
        mergeSort(v, mitad + 1, fin);
        merge(v, inicio, mitad, fin);
    }
}

int main () {
  std::vector<int> v {9,7,8,3,2,1};

  mergeSort(v, 0, v.size() - 1);

}