#include <iostream>
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
                trocas++;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
             
        }
    }
    
}

void bubbleSort(vector<int> &arr, int n, long long int& trocas, long long int& comp) {
    bool swapped;
    
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                trocas++;
                comp++;
            }else{
                comp++;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void shellSort(vector<int> &arr, int n, long long int &trocas, long long int &comp){
    int i, j, value;
    int h = 1;
    while (h < n){
        comp++;
        h = 3 * h + 1;
    }
    while (h > 0){
        comp++;
        for (i = h; i < n; i++){
            value = arr[i];
            j = i;
            while (j > h - 1 && value <= arr[j - h]){
                comp++;
                arr[j] = arr[j - h];
                trocas++;
                j = j - h;
            }
            comp++;
            if (j != i){
                trocas++;
                arr[j] = value;
            }
        }
        h = h / 3;
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


//funções para ler string
// Função para imprimir o vetor
void printArray_S(vector<string> arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Implementação dos algoritmos de ordenação
void selectionSort_S(vector<string> &arr, int n, long long int& trocas, long long int& comp) {
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
                trocas++;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            
        }
    }
    
}

void bubbleSort_S(vector<string> &arr, int n, long long int& trocas, long long int& comp) {
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

void shellSort_S(vector<string> &arr, int n, long long int &trocas, long long int &comp){
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            string temp = arr[i];
            trocas++;

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                comp++;
                trocas++;
            }

            arr[j] = temp;
            trocas++;
        }
    }
}

void insertionSort_S(vector<string> &arr, int n, long long int& trocas, long long int& comp) {
    
    for (int i = 1; i < n; i++) {
        string key = arr[i];
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

void merge_S(vector<string> &arr, int l, int m, int r, long long int& trocas, long long int& comp) {
    int n1 = m - l + 1;
    int n2 = r - m;

    string L[n1], R[n2];
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

void mergeSort_S(vector<string> &arr, int l, int r, long long int& trocas, long long int& comp) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort_S(arr, l, m, trocas, comp);
        mergeSort_S(arr, m + 1, r, trocas, comp);
        merge_S(arr, l, m, r, trocas, comp);
    }
}


int partition_S(vector<string> &arr, int low, int high, long long int& trocas, long long int& comp) {
    string pivot = arr[high];
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

void quickSort_S(vector<string> &arr, int low, int high, long long int& trocas, long long int& comp) {
    if (low < high) {
        int pi = partition_S(arr, low, high, trocas, comp);
        quickSort_S(arr, low, pi - 1, trocas, comp);
        quickSort_S(arr, pi + 1, high, trocas, comp);
    }
}

// Função principal
int main() {
    
    long long int trocas = 0, comp = 0;


    int tamanho;
    ifstream arqEntrada; 
    ofstream arqSaida; 
    char proximo[1000];
    vector<int> arr;
    string EntradaArq;
    string SaidaArq;
    string NomeMetodo;

    // para vetor de palavras 
    bool nome = false;
    vector<string> palavras;
    string palavra;

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
    cout << "17. DicionarioAleatorio-29855" << endl;
    cout << "18. DicionarioAleatorio-261791" << endl;
    cout << "19. Dicionario Inversamente ordenado - 29855" << endl;
    cout << "20. Dicionario Inversamente ordenado - 261791" << endl;
    cout << "21. Dicionario Ordenado - 29855" << endl;
    cout << "22. Dicionario Ordenado - 261791" << endl;
    cout << "Digite sua escolha (1-22): ";
    cin >> op;

    
    switch (op) {
        case 1:
            EntradaArq = "../ListaAleatoria-1000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 2:
            EntradaArq = "../ListaAleatoria-10000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 3:
            EntradaArq = "../ListaAleatoria-100000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 4:
            EntradaArq = "../ListaAleatoria-1000000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 5:
            EntradaArq = "../ListaInversamenteOrdenada-1000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 6:
            EntradaArq = "../ListaInversamenteOrdenada-10000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 7:
            EntradaArq = "../ListaInversamenteOrdenada-100000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 8:
            EntradaArq = "../ListaInversamenteOrdenada-1000000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 9:
            EntradaArq = "../ListaQuaseOrdenada-1000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 10:
            EntradaArq = "../ListaQuaseOrdenada-10000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 11:
            EntradaArq = "../ListaQuaseOrdenada-100000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 12:
            EntradaArq = "../ListaQuaseOrdenada-1000000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 13:
            EntradaArq = "../ListaOrdenada-1000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 14:
            EntradaArq = "../ListaOrdenada-10000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 15:
            EntradaArq = "../ListaOrdenada-100000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 16:
            EntradaArq = "../ListaOrdenada-1000000.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            break;
        case 17:
            EntradaArq = "../DicionarioAleatorio-29855.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            nome = true;
            break;
        case 18:
            EntradaArq = "../DicionarioAleatorio-261791.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            nome = true;
            break;
        case 19:
            EntradaArq = "../DicionarioInversamenteOrdenado-29855.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            nome = true;
            break;
        case 20:
            EntradaArq = "../DicionarioInversamenteOrdenado-261791.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            nome = true;
            break;
        case 21:
            EntradaArq = "../DicionarioOrdenado-29855.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            nome = true;
            break;
        case 22:
            EntradaArq = "../DicionarioOrdenado-261791.txt";
            SaidaArq =  "Saida_" + EntradaArq;
            arqSaida.open(SaidaArq);
            nome = true;
            break;
        default:
            cout << "Escolha inválida." << endl;
            return 1;
    }    


    if(nome == true){

        arqEntrada.open(EntradaArq);
        if (!arqEntrada.is_open()) {
            cout << "Erro ao abrir arquivo." << endl;
            return 1;
        }
     
        while (arqEntrada >> palavra) {
            palavras.push_back(palavra);
        }    
        arqEntrada.close();

    }else{
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
    }

    // Menu de escolha do método de ordenação
    int choice;
    cout << "Escolha o método de ordenação:" << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << "3. Insertion Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "6. Shell Sort" << endl;
    cout << "Digite sua escolha (1-6): ";
    cin >> choice;

    // Ordena o vetor de acordo com a escolha do usuário
    high_resolution_clock::time_point t1 = high_resolution_clock::now(); // Obtém a hora de início
    

    // Ordena o vetor de acordo com a escolha do usuário
    switch (choice) {
        case 1:
            NomeMetodo= "SelectionSort";
            if(nome==true){
                selectionSort_S(palavras, palavras.size(), trocas, comp);
            }else{
                selectionSort(arr, arr.size(), trocas, comp);
            }
            break;
        case 2:
            NomeMetodo= "BubbleSort"; 
            if(nome==true){
              bubbleSort_S(palavras, palavras.size(), trocas, comp);
            }else{
              bubbleSort(arr, arr.size(), trocas, comp);
            }
            break;
        case 3:
            NomeMetodo= "InsertionSort";
            if(nome==true){
                insertionSort_S(palavras, palavras.size(), trocas, comp);
            }else{
                insertionSort(arr, arr.size(), trocas, comp);
            }
            break;
        case 4:
            NomeMetodo= "MergeSort";
            if(nome==true){
                mergeSort_S(palavras, 0, palavras.size(), trocas, comp);
            }else{
                mergeSort(arr, 0, arr.size() - 1, trocas, comp);
            }
            break;
        case 5:
            NomeMetodo= "QuickSort";
            if(nome==true){
                quickSort_S(palavras, 0, palavras.size(), trocas, comp);
            }else{
                quickSort(arr, 0, arr.size() - 1, trocas, comp);
            }
            break;
        case 6:
            NomeMetodo= "ShellSort";
            if(nome==true){
                shellSort_S(palavras, palavras.size(), trocas, comp);
            }else{
                shellSort(arr, arr.size(), trocas, comp);
            }
            break;
        default:
            cout << "Escolha inválida." << endl;
            return 1;
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now(); // Obtém a hora de fim



    if(nome==true){
        cout << "Depois da ordenação:" << endl;
        printArray_S(palavras, palavras.size());
        cout<< "Trocas: "<< trocas <<endl;
        cout<< "Comparaçôes: "<< comp <<endl;
            // Calcula o tempo de execução e imprime na tela
        auto duration = duration_cast<microseconds>(t2 - t1).count();
        cout << "Tempo de execução: " << duration << " microssegundos." << endl;
        arqSaida << NomeMetodo << " Número de Trocas: " << trocas << " Número de Comparações: " << comp << " Tempo de Execução: " << duration << endl;

    }else{
        // Imprime o vetor depois da ordenação
        cout << "Depois da ordenação:" << endl;
        printArray(arr, arr.size());
        cout<< "Trocas: "<< trocas <<endl;
        cout<< "Comparaçôes: "<< comp <<endl;
            // Calcula o tempo de execução e imprime na tela
        auto duration = duration_cast<microseconds>(t2 - t1).count();
        cout << "Tempo de execução: " << duration << " microssegundos." << endl;
        arqSaida << NomeMetodo << " Número de Trocas: " << trocas << " Número de Comparações: " << comp << " Tempo de Execução: " << duration << endl;
    }
    return 0;
}
