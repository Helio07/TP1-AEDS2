#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

// Função para imprimir o vetor
void printArray(vector<int> arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Implementação dos algoritmos de ordenação
void selectionSort(vector<int> &arr, int n, long long int& trocas, long long int& comp) {
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            trocas++; // Incrementa a variável de trocas
        }
    }
    
}

void bubbleSort(vector<int> &arr, int n, long long int& trocas, long long int& comp) {
    bool swapped;
    
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                trocas++;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void insertionSort(vector<int> &arr, int n, long long int& trocas, long long int& comp) {
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comp++;
            arr[j + 1] = arr[j];
            j--;
            trocas++;
        }
        arr[j + 1] = key;
        trocas++;
    }
}

void merge(vector<int> &arr, int l, int m, int r, long long int& trocas, long long int& comp) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comp++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        trocas++; // Incrementa a variável de trocas
    }

    while (i < n1) {
        arr[k++] = L[i++];
        trocas++;
    }

    while (j < n2) {
        arr[k++] = R[j++];
        trocas++;
    }
}

void mergeSort(vector<int> &arr, int l, int r, long long int& trocas, long long int& comp) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, trocas, comp);
        mergeSort(arr, m + 1, r, trocas, comp);
        merge(arr, l, m, r, trocas, comp);
    }
}


int partition(vector<int> &arr, int low, int high, long long int& trocas, long long int& comp) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comp++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            trocas++; // Incrementa a variável de trocas
        }
    }
    swap(arr[i + 1], arr[high]);
    trocas++; // Incrementa a variável de trocas
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high, long long int& trocas, long long int& comp) {
    if (low < high) {
        int pi = partition(arr, low, high, trocas, comp);
        quickSort(arr, low, pi - 1, trocas, comp);
        quickSort(arr, pi + 1, high, trocas, comp);
    }
}

// Função principal
int main() {
    
    long long int trocas = 0, comp = 0;


    int tamanho, metodo, inst;
    ifstream arqEntrada; 
    ofstream arqSaida; 
    char proximo[1000];
    vector<int> arr;
    string EntradaArq;
    string SaidaArq;
    string NomeMetodo;

    int op;
    cout << "Escolha a Instância:" << endl;
    cout << "1. Lista Aleatoria de 1k" << endl;
    cout << "2. Lista Aleatoria de 10k" << endl;
    cout << "3. Lista Aleatoria de 100k" << endl;
    cout << "4. Lista Aleatoria de 1M" << endl;
    cout << "5. ListaInversamenteOrdenada de 1k" << endl;
    cout << "6. ListaInversamenteOrdenada de 10k" << endl;
    cout << "7. ListaInversamenteOrdenada de 100k" << endl;
    cout << "8. ListaInversamenteOrdenada de 1M" << endl;
    cout << "9. Lista Quase Ordenada de 1k" << endl;
    cout << "10. Lista Quase Ordenada de 10k" << endl;
    cout << "11. Lista Quase Ordenada de 100k" << endl;
    cout << "12. Lista Quase Ordenada de 1M" << endl;
    cout << "13. Lista Ordenada de 1k" << endl;
    cout << "14. Lista Ordenada de 10k" << endl;
    cout << "15. Lista Ordenada de 100k" << endl;
    cout << "16. Lista Ordenada de 1M" << endl;
    cout << "Digite sua escolha (1-16): ";
    cin >> op;

    
    switch (op) {
        case 1:
            EntradaArq = "ListaAleatoria-1000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 2:
            EntradaArq = "ListaAleatoria-10000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 3:
            EntradaArq = "ListaAleatoria-100000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 4:
            EntradaArq = "ListaAleatoria-1000000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 5:
            EntradaArq = "ListaInversamenteOrdenada-1000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 6:
            EntradaArq = "ListaInversamenteOrdenada-10000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 7:
            EntradaArq = "ListaInversamenteOrdenada-100000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 8:
            EntradaArq = "ListaInversamenteOrdenada-1000000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 9:
            EntradaArq = "ListaQuaseOrdenada-1000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 10:
            EntradaArq = "ListaQuaseOrdenada-10000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 11:
            EntradaArq = "ListaQuaseOrdenada-100000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 12:
            EntradaArq = "ListaQuaseOrdenada-1000000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 13:
            EntradaArq = "ListaOrdenada-1000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 14:
            EntradaArq = "ListaOrdenada-10000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 15:
            EntradaArq = "ListaOrdenada-100000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 16:
            EntradaArq = "ListaOrdenada-1000000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        default:
            cout << "Escolha inválida." << endl;
            return 1;
    }    

    arqEntrada.open(EntradaArq);
    if (arqEntrada.fail()) {
        cout << "Falha ao abrir o arquivo." << endl;
        exit(1);
    }
    do {
        arqEntrada.getline(proximo, 10000);
        tamanho = atoi(proximo);
        arr.push_back(tamanho);
    } while (!arqEntrada.eof());
    arqEntrada.close();

    // Menu de escolha do método de ordenação
    int choice;
    cout << "Escolha o método de ordenação:" << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << "3. Insertion Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "Digite sua escolha (1-5): ";
    cin >> choice;

    // Ordena o vetor de acordo com a escolha do usuário
    high_resolution_clock::time_point t1 = high_resolution_clock::now(); // Obtém a hora de início
    

    // Ordena o vetor de acordo com a escolha do usuário
    switch (choice) {
        case 1:
            selectionSort(arr, arr.size(), trocas, comp);
            break;
        case 2:
            bubbleSort(arr, arr.size(), trocas, comp);
            break;
        case 3:
            insertionSort(arr, arr.size(), trocas, comp);
            break;
        case 4:
            mergeSort(arr, 0, arr.size() - 1, trocas, comp);
            break;
        case 5:
            quickSort(arr, 0, arr.size() - 1, trocas, comp);
            break;
        default:
            cout << "Escolha inválida." << endl;
            return 1;
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now(); // Obtém a hora de fim

    // Imprime o vetor depois da ordenação
    cout << "Depois da ordenação:" << endl;
    printArray(arr, arr.size());
    cout<< "Trocas: "<< trocas <<endl;
    cout<< "Comparaçôes: "<< comp <<endl;
        // Calcula o tempo de execução e imprime na tela
    auto duration = duration_cast<microseconds>(t2 - t1).count();
    cout << endl << "Tempo de execução: " << duration << " microssegundos." << endl;

    return 0;
}
