#include <iostream>
using namespace std;

/* ########## Costanti, strutture e funzioni utilizzate durante tutto il corso del programma ########## */

const int N = 1000;

struct Coppia_di_Coordinate
{
    int x, y;
};

istream& operator>>(istream& input, Coppia_di_Coordinate& c)
{
    input >> c.x >> c.y;
    return input;
}

ostream& operator<<(ostream& output, Coppia_di_Coordinate c)
{
    output << "[" << c.x << "," << c.y << "]";
    return output;
}

bool operator==(Coppia_di_Coordinate c_1, Coppia_di_Coordinate c_2)
{
    return (c_1.x == c_2.x and c_1.y == c_2.y);
}

void inizializzatore_di_array_interi_monodimensionali(int array[N])
{
    for (int a = 0; a < N; a++)
        array[a] = 0;
}

void inizializzatore_di_array_interi_bidimensionali(int array[N][N])
{
    for (int a = 0; a < N; a++)
        inizializzatore_di_array_interi_monodimensionali(array[a]);
}

void inizializzatore_di_stringhe(char stringa[N])
{
    for (int a = 0; a < N; a++)
        stringa[a] = '\0';
}

void inizializzatore_di_array_Coppia_di_Coordinate_monodimensionali(Coppia_di_Coordinate array[N])
{
    for (int a = 0; a < N; a++)
        array[a].x = array[a].y = 0;
}

void inizializzatore_di_array_Coppia_di_Coordinate_bidimensionali(Coppia_di_Coordinate array[N][N])
{
    for (int a = 0; a < N; a++)
        inizializzatore_di_array_Coppia_di_Coordinate_monodimensionali(array[a]);
}

void eguagliatore_di_array_interi_monodimensionali(int array_1[N], int array_2[N])
{
    for (int a = 0; a < N; a++)
        array_1[a] = array_2[a];
}

void eguagliatore_di_array_Coppia_di_Coordinate_monodimensionali(Coppia_di_Coordinate array_1[N], Coppia_di_Coordinate array_2[N])
{
    for (int a = 0; a < N; a++)
        array_1[a] = array_2[a];
}

bool cercatore_di_valori_interi(int array[N], int i)
{
    for (int a = 0; a < N; a++)
        if (array[a] == i) return true;
    return false;
}

bool cercatore_di_valori_carattere(char array[N], char ch)
{
    for (int a = 0; a < N; a++)
        if (array[a] == ch) return true;
    return false;
}

bool cercatore_di_valori_Coppia_di_Coordinate(Coppia_di_Coordinate array[N], Coppia_di_Coordinate c)
{
    for (int a = 0; a < N; a++)
        if (array[a] == c) return true;
    return false;
}

void ordinatore_decrescente_di_coppie_di_array_interi(int array_1[N], int array_2[N][N])
{
    int intero_temporaneo;
    int array_temporaneo[N];
    for (int a = 0; a < N - 1; a++)
        for (int b = 0; b < N - 1; b++)
            if (array_1[b] < array_1[b + 1])
            {
                intero_temporaneo = array_1[b];
                array_1[b] = array_1[b + 1];
                array_1[b + 1] = intero_temporaneo;
                
                eguagliatore_di_array_interi_monodimensionali(array_temporaneo, array_2[b]);
                eguagliatore_di_array_interi_monodimensionali(array_2[b], array_2[b + 1]);
                eguagliatore_di_array_interi_monodimensionali(array_2[b + 1], array_temporaneo);
            }
}

void ordinatore_decrescente_di_terne_di_array_interi(int array_1[N], int array_2[N], int array_3[N][N])
{
    int intero_temporaneo;
    int array_temporaneo[N];
    
    for (int a = 0; a < N - 1; a++)
        for (int b = 0; b < N - 1; b++)
            if (array_1[b] < array_1[b + 1] or (array_1[b] == array_1[b + 1] and array_2[b] < array_2[b + 1]))
            {
                intero_temporaneo = array_1[b];
                array_1[b] = array_1[b + 1];
                array_1[b + 1] = intero_temporaneo;
                
                intero_temporaneo = array_2[b];
                array_2[b] = array_2[b + 1];
                array_2[b + 1] = intero_temporaneo;
                
                eguagliatore_di_array_interi_monodimensionali(array_temporaneo, array_3[b]);
                eguagliatore_di_array_interi_monodimensionali(array_3[b], array_3[b + 1]);
                eguagliatore_di_array_interi_monodimensionali(array_3[b + 1], array_temporaneo);
            }
}

void ordinatore_decrescente_di_array_Coppia_di_Coordinate_bidimensionali(int array_1[N], int array_2[N], Coppia_di_Coordinate array_3[N][N])
{
    int intero_temporaneo;
    Coppia_di_Coordinate array_temporaneo[N];
    for (int a = 0; a < N - 1; a++)
        for (int b = 0; b < N - 1; b++)
            if (array_1[b] < array_1[b + 1] or (array_1[b] == array_1[b + 1] and array_2[b] < array_2[b + 1]))
            {
                intero_temporaneo = array_1[b];
                array_1[b] = array_1[b + 1];
                array_1[b + 1] = intero_temporaneo;
                
                intero_temporaneo = array_2[b];
                array_2[b] = array_2[b + 1];
                array_2[b + 1] = intero_temporaneo;
                
                eguagliatore_di_array_Coppia_di_Coordinate_monodimensionali(array_temporaneo, array_3[b]);
                eguagliatore_di_array_Coppia_di_Coordinate_monodimensionali(array_3[b], array_3[b + 1]);
                eguagliatore_di_array_Coppia_di_Coordinate_monodimensionali(array_3[b + 1], array_temporaneo);
            }
}

void visualizzatore_di_array_interi_monodimensionali(int array[N], char ch = '\0')
{
    int a = 0;
    for ( ; a < N - 1 and array[a + 1]; a++)
        cout << ch << array[a] << ",";
    cout << ch << array[a];
}

void visualizzatore_di_coppie_di_array_interi(int array_1[N], const char stringa[N], int array_2[N][N], char ch = '\0')
{
    int a = 0;
    for ( ; a < N - 1 and array_1[a + 1]; a++)
    {
        cout << stringa << ": " << array_1[a] << " -> ";
        visualizzatore_di_array_interi_monodimensionali(array_2[a], ch);
        cout << "\n";
    }
    cout << stringa << ": " << array_1[a] << " -> ";
    visualizzatore_di_array_interi_monodimensionali(array_2[a], ch);
}

void visualizzatore_di_terne_di_array_interi(int array_1[N], const char stringa_1[N], int array_2[N], const char stringa_2[N], int array_3[N][N], char ch = '\0')
{
    int a = 0;
    for ( ; a < N - 1 and array_1[a + 1]; a++)
    {
        cout << stringa_1 << ": " << array_1[a] << ", " << stringa_2 << ": " << array_2[a] << " -> ";
        visualizzatore_di_array_interi_monodimensionali(array_3[a], ch);
        cout << "\n";
    }
    cout << stringa_1 << ": " << array_1[a] << ", " << stringa_2 << ": " << array_2[a] << " -> ";
    visualizzatore_di_array_interi_monodimensionali(array_3[a], ch);
}

void visualizzatore_di_array_Coppia_di_Coordinate_monodimensionali(Coppia_di_Coordinate array[N])
{
    int a = 0;
    for ( ; a < N - 1 and array[a + 1].x; a++)
        cout << array[a] << ",";
    cout << array[a];
}

void visualizzatore_di_array_Coppia_di_Coordinate_bidimensionali(int array_1[N], const char stringa_1[N], int array_2[N], const char stringa_2[N], Coppia_di_Coordinate array_3[N][N])
{
    int a = 0;
    for ( ; a < N - 1 and array_1[a + 1]; a++)
    {
        cout << stringa_1 << ": " << array_1[a] << ", " << stringa_2 << ": " << array_2[a] << " -> ";
        visualizzatore_di_array_Coppia_di_Coordinate_monodimensionali(array_3[a]);
        cout << "\n";
    }
    cout << stringa_1 << ": " << array_1[a] << ", " << stringa_2 << ": " << array_2[a] << " -> ";
    visualizzatore_di_array_Coppia_di_Coordinate_monodimensionali(array_3[a]);
}

/* ########## Funzione main() e prototipi delle funzioni delegate alla risoluzione degli esercizi ########## */

void Crittografia();
void Sottosequenze();
void Knapsack();
void Grafi();
void Movimenti_di_un_cavallo_degli_scacchi();
void Movimenti_di_un_robot();
void Pianificazione();
void Flussi_in_una_rete_di_canali();
void Regole_e_deduzioni();
void Distribuzione_di_lampioni_in_un_grafo_di_piazze();
void Vigenere();

int main()
{
    cout << "######## PROGRAMMA DI RISOLUZIONE DEGLI ESERCIZI RICORRENTI DELLE OPS ########";
        
    cout << "\n\n";
    
    int esercizio_da_risolvere;
    bool b;
    do
    {
        cout << "1. Cesare.\n";
        cout << "2. Sottosequenze.\n";
        cout << "3. Strikgnak (Minerali).\n";
        cout << "4. Grafi.\n";
        cout << "5. Movimenti di un cavallo degli scacchi.\n";
        cout << "6. Movimenti di un robot.\n";
        cout << "7. Pianificazione (Attività-ragazzi).\n";
        cout << "8. Flussi in una rete di canali.\n";
        cout << "9. Regole e deduzioni.\n";
        cout << "10. Distribuzione di lampioni in un grafo di piazze.\n";
        cout << "11. Vigenere.\n";
        cout << "Inserire il numero relativo all'esercizio da risolvere: ";
        cin >> esercizio_da_risolvere;
        cout << "\n";
        
        switch (esercizio_da_risolvere)
        {
            case 1:
                Crittografia();
                break;
            case 2:
                Sottosequenze();
                break;
            case 3:
                Knapsack();
                break;
            case 4:
                Grafi();
                break;
            case 5:
                Movimenti_di_un_cavallo_degli_scacchi();
                break;
            case 6:
                Movimenti_di_un_robot();
                break;
            case 7:
                Pianificazione();
                break;
            case 8:
                Flussi_in_una_rete_di_canali();
                break;
            case 9:
                Regole_e_deduzioni();
                break;
            case 10:
                Distribuzione_di_lampioni_in_un_grafo_di_piazze();
                break;
              case 11:
                Vigenere();
        }
        
        cout << "\n\nInserire '1' per risolvere un altro esercizio, '0' altrimenti: ";
        cin >> b;
    } while (b);
    
    cout << "Il programma è terminato con successo.\n\n\n";
    return 0;
}

/* ########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'CRITTOGRAFIA' ########## */

void Crittografia()
{
    cout << "########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'CRITTOGRAFIA' ##########\n\n";
    cout << "### NOTA PER L'UTENTE... ###\n";
    cout << "... SULLA TIPOLOGIA DEI DATI IN INPUT\n";
    cout << "1. La stringa da crittografare o da decrittografare dev'essere un'unica serie di caratteri contenente solamente le lettere dell'alfabeto inglese di 26 lettere.\n";
    cout << "... SUI LIMITI DEI DATI IN INPUT\n";
    cout << "2. La stringa da crittografare o da decrittografare non deve superare i " << N << " caratteri.\n";
    cout << "... SULL'ALGORITMO E SULL'OUTPUT\n";
    cout << "3. L'alfabeto preso in considerazione dalla sessione è quello inglese di 26 lettere.\n";
    cout << "4. Saranno visualizzate sullo schermo le possibili crittografazioni o decrittografazioni della stringa inserita, secondo il metodo di (de)crittografazione Giulio Cesare.";
    cout << "\n\n";
    
    bool b;
    do
    {
        char stringa[N];
        inizializzatore_di_stringhe(stringa);
        bool c;
        int d = 0;
        cout << "Inserire '1' se l'esercizio prevede di utilizzare due chiavi diverse per le cifre in posizione pari e quelle in posizione dispari, '0' altrimenti: ";
        cin >> c;
        if (c)
        {
            cout << "Inserire la differenza (in valore assoluto) fra la chiave delle cifre pari e quella delle cifre dispari, come numero intero (positivo): ";
            cin >> d;
        }
        cout << "Inserire la stringa de crittografare o da decrittografare: ";
        cin >> stringa;
        int a;
        cout << "Inserire '1' per crittografare la stringa, '-1' per decrittografarla: ";
        cin >> a;
        
        if (c)
        {
            int kd, kp;
            if (a == 1)
                cout << "\nEcco le possibili crittografazioni della stringa inserita, precedute dalle relative chiavi di crittografazione:\n";
            else
                cout << "\nEcco le possibili decrittografazioni della stringa inserita, precedute dalle relative chiavi di decrittografazione:\n";
            for (kd = 1; kd <= 25; kd++)
            {
                for (int v = 1; v <= 2; v++)
                {
                    if (v == 1)
                    {
                        if (kd-d < 1)
                            goto skip;
                        else
                            kp = kd-d;
                    }
                    else
                    {
                        if (kd+d > 25)
                            goto skip;
                        else
                            kp = kd + d;
                    }
                    
                    cout << "Chiave dispari: " << kd << ", Chiave pari: " << kp << " -> ";
                    for (int c = 0; c < N and stringa[c]; c++)
                    {
                        if (c%2)
                        {
                            if (stringa[c] + kp*a < 'a')
                                cout << char(stringa[c] + kp*a - 'a' + 'z' + 1);
                            else if (stringa[c] + kp*a > 'z')
                                cout << char(stringa[c] + kp*a + 'a' - 'z' - 1);
                            else
                                cout << char(stringa[c] + kp*a);
                        }
                        else
                        {
                            if (stringa[c] + kd*a < 'a')
                                cout << char(stringa[c] + kd*a - 'a' + 'z' + 1);
                            else if (stringa[c] + kd*a > 'z')
                                cout << char(stringa[c] + kd*a + 'a' - 'z' - 1);
                            else
                                cout << char(stringa[c] + kd*a);
                        }
                        if (stringa[c + 1] and c != N - 1) cout << ",";
                    }
                    cout << "\n";
                skip:
                    ;
                }
            }
        }
        else
        {
            if (a == 1)
                cout << "\nEcco le possibili crittografazioni della stringa inserita, precedute dalla relativa chiave di crittografazione:\n";
            else
                cout << "\nEcco le possibili decrittografazioni della stringa inserita, precedute dalla relativa chiave di decrittografazione:\n";
            for (int k = 1; k <= 25; k++)
            {
                cout << "Chiave: " << k << " -> ";
                for (int c = 0; c < N and stringa[c]; c++)
                {
                    if (stringa[c] + k*a < 'a')
                        cout << char(stringa[c] + k*a - 'a' + 'z' + 1);
                    else if (stringa[c] + k*a > 'z')
                        cout << char(stringa[c] + k*a + 'a' - 'z' - 1);
                    else
                        cout << char(stringa[c] + k*a);
                    if (stringa[c + 1] and c != N - 1) cout << ",";
                }
                cout << "\n";
            }
        }
        cout << "\nInserire '1' per crittografare o decrittografare un'altra stringa, '0' per uscire dalla sessione: ";
        cin >> b;
    } while (b);
    
    cout << "L'uscita dalla sessione di risoluzione dell'esercizio 'Crittografia' è avvenuta con successo.";
}

/* ########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'SOTTOSEQUENZE' ########## */

void S(int segnaposto);

int criterio_di_ricerca;
int sequenza[N];
int numero_di_elementi_della_sequenza;

int sottosequenza_temporanea[N];
int numero_di_elementi_temporaneo, somma_degli_elementi_temporanea;
int sottosequenze[N][N];
int numero_di_elementi_delle_sottosequenze[N], somma_degli_elementi_delle_sottosequenze[N];
int numero_di_sottosequenze;

void Sottosequenze()
{
    cout << "########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'SOTTOSEQUENZE' ##########\n\n";
    cout << "### NOTA PER L'UTENTE... ###\n";
    cout << "... SULLA TIPOLOGIA DEI DATI IN INPUT\n";
    cout << "1. La sequenza di cui calcolare le sottosequenze deve contenere solamente valori interi non nulli.\n";
    cout << "... SUI LIMITI DEI DATI IN INPUT\n";
    cout << "2. La sequenza di cui calcolare le sottosequenze non deve superare i " << N << " elementi.\n";
    cout << "... SULL'INPUT DEI DATI\n";
    cout << "3. Nell'inserimento della sequenza di cui calcolare le sottosequenze si devono separare due elementi successivi con uno spazio.\n";
    cout << "4. Per terminare l'inserimento degli elementi si deve inserire '0', come se fosse un elemento della sequenza.\n";
    cout << "[Esempio di sequenza in input: '3 7 6 2 9 4 8 2 3 0']\n";
    cout << "... SUI LIMITI DEI DATI IN OUTPUT E SUI MESSAGGI D'ERRORE\n";
    cout << "5. Il programma visualizzerà un messaggio d'errore se, in fase di compilazione, saranno calcolate più di " << N << " sottosequenze di almeno tre elementi della sequenza inserita che soddisfino al criterio di ricerca adottato.\n";
    cout << "... SULL'ALGORITMO E SULL'OUTPUT\n";
    cout << "6. Saranno visualizzate sullo schermo le sottosequenze di almeno tre elementi della sequenza inserita che soddisfano al criterio di ricerca adottato, con la relativa lunghezza (dove per lunghezza di una sequenza si intende il numero dei suoi elementi) e con il relativo valore (dove per valore di una sequenza si intende la somma totale dei suoi elementi).";
    cout << "\n\n";
    
    inizializzatore_di_array_interi_monodimensionali(sequenza);
    cout << "Inserire la sequenza: ";
    for (numero_di_elementi_della_sequenza = 0; numero_di_elementi_della_sequenza < N + 1; numero_di_elementi_della_sequenza++)
    {
        cin >> sequenza[numero_di_elementi_della_sequenza];
        if (!sequenza[numero_di_elementi_della_sequenza])
            break;
    }
    
    bool b;
    do
    {
        cout << "1. Sottosequenze decrescenti.\n";
        cout << "2. Sottosequenze strettamente decrescenti.\n";
        cout << "3. Sottosequenze crescenti.\n";
        cout << "4. Sottosequenze strettamente crescenti.\n";
        cout << "Inserire il numero relativo al criterio di ricerca da adottare: ";
        cin >> criterio_di_ricerca;
        
        inizializzatore_di_array_interi_monodimensionali(sottosequenza_temporanea);
        numero_di_elementi_temporaneo = somma_degli_elementi_temporanea = 0;
        inizializzatore_di_array_interi_bidimensionali(sottosequenze);
        inizializzatore_di_array_interi_monodimensionali(numero_di_elementi_delle_sottosequenze);
        inizializzatore_di_array_interi_monodimensionali(somma_degli_elementi_delle_sottosequenze);
        numero_di_sottosequenze = 0;
        
        S(0);
        ordinatore_decrescente_di_terne_di_array_interi(numero_di_elementi_delle_sottosequenze, somma_degli_elementi_delle_sottosequenze, sottosequenze);
        
        if (numero_di_elementi_delle_sottosequenze[0])
        {
            cout << "\nEcco le sottosequenze di almeno tre elementi della sequenza inserita che soddisfano al criterio di ricerca adottato, precedute dalla relativa lunghezza e dal relativo valore:\n";
            visualizzatore_di_terne_di_array_interi(numero_di_elementi_delle_sottosequenze, "Lunghezza", somma_degli_elementi_delle_sottosequenze, "Valore", sottosequenze);
        }
        else
            cout << "\nNon ci sono sottosequenze di almeno tre elementi che soddisfano al criterio di ricerca adottato.";
        
        cout << "\n\nInserire '1' per adottare un altro criterio di ricerca, '0' per uscire dalla sessione: ";
        cin >> b;
    } while (b);
    
    cout << "L'uscita dalla sessione di risoluzione dell'esercizio 'Sottosequenze' è avvenuta con successo.";
}

void S(int segnaposto)
{
    if (numero_di_elementi_temporaneo >= 3)
    {
        if (numero_di_sottosequenze == N)
        {
            cout << "\n########## Errore: Questo programma non supporta la risoluzione di questo esercizio! ##########\n\n";
            exit(-1);
        }
        eguagliatore_di_array_interi_monodimensionali(sottosequenze[numero_di_sottosequenze], sottosequenza_temporanea);
        numero_di_elementi_delle_sottosequenze[numero_di_sottosequenze] = numero_di_elementi_temporaneo;
        somma_degli_elementi_delle_sottosequenze[numero_di_sottosequenze] = somma_degli_elementi_temporanea;
        numero_di_sottosequenze++;
    }
    
    for (int a = segnaposto; a < numero_di_elementi_della_sequenza; a++)
    {
        if (!sottosequenza_temporanea[0] or ((sottosequenza_temporanea[numero_di_elementi_temporaneo - 1] >= sequenza[a] and criterio_di_ricerca == 1) or (sottosequenza_temporanea[numero_di_elementi_temporaneo - 1] > sequenza[a] and criterio_di_ricerca == 2) or (sottosequenza_temporanea[numero_di_elementi_temporaneo - 1] <= sequenza[a] and criterio_di_ricerca == 3) or (sottosequenza_temporanea[numero_di_elementi_temporaneo - 1] < sequenza[a] and criterio_di_ricerca == 4)))
        {
            sottosequenza_temporanea[numero_di_elementi_temporaneo] = sequenza[a];
            numero_di_elementi_temporaneo++;
            somma_degli_elementi_temporanea += sequenza[a];
            
            S(a + 1);
            
            somma_degli_elementi_temporanea -= sequenza[a];
            numero_di_elementi_temporaneo--;
            sottosequenza_temporanea[numero_di_elementi_temporaneo] = 0;
        }
    }
}

/* ########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'KNAPSACK' ########## */

struct Minerale
{
    int valore, peso;
};

void K(int segnaposto);

Minerale minerali[N];
int numero_di_minerali_della_lista;
int peso_massimo_caricabile, numero_di_minerali_da_trasportare;

int combinazione_temporanea[N];
int numero_di_minerali_temporaneo, valore_temporaneo, K_peso_temporaneo;
int combinazioni[N][N];
int valore_delle_combinazioni[N], peso_delle_combinazioni[N];
int numero_di_combinazioni;

void Knapsack()
{
    cout << "########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'KNAPSACK' ##########\n\n";
    cout << "### NOTA PER L'UTENTE... ###\n";
    cout << "... SULLA TIPOLOGIA DEI DATI IN INPUT\n";
    cout << "1. Ogni minerale della lista deve avere un valore e un peso interi e positivi.\n";
    cout << "2. Il peso massimo caricabile deve essere un valore intero e positivo.\n";
    cout << "... SUI LIMITI DEI DATI IN INPUT\n";
    cout << "3. I minerali della lista non devono essere più di " << N << ".\n";
    cout << "... SULL'INPUT DEI DATI\n";
    cout << "4. Nell'inserimento di un minerale si devono digitare in ordine il suo valore e il suo peso, separandoli con uno spazio.\n";
    cout << "5. Per terminare l'inserimento dei minerali si deve inserire '0' come se fosse un vero e proprio minerale.\n";
    cout << "6. L'inserimento terminerà in automatico una volta raggiunti i " << N << " minerali.\n";
    cout << "[Esempio di minerale in input: '89 93']\n";
    cout << "... SUI LIMITI DEI DATI IN OUTPUT E SUI MESSAGGI D'ERRORE\n";
    cout << "7. Il programma visualizzerà un messaggio d'errore se, in fase di compilazione, saranno calcolate più di " << N << " combinazioni di minerali della lista inserita che soddisfino al limite di peso e al numero di minerali da trasportare imposti.\n";
    cout << "... SULL'ALGORITMO E SULL'OUTPUT\n";
    cout << "8. Saranno visualizzate sullo schermo le combinazioni di minerali della lista inserita che soddisfano al limite di peso e al numero di minerali da trasportare imposti, con il relativo valore e peso.";
    cout << "\n\n";
    
    for (int a = 0; a < N; a++)
        minerali[a].valore = minerali[a].peso = 0;
    cout << "Inserire ogni minerale della lista.\n";
    for (numero_di_minerali_della_lista = 0; numero_di_minerali_della_lista < N; numero_di_minerali_della_lista++)
    {
        cout << "Minerale " << numero_di_minerali_della_lista + 1 << ": ";
        cin >> minerali[numero_di_minerali_della_lista].valore;
        if (minerali[numero_di_minerali_della_lista].valore)
            cin >> minerali[numero_di_minerali_della_lista].peso;
        else
            break;
    }
    
    bool b;
    do
    {
        cout << "Inserire il peso massimo caricabile: ";
        cin >> peso_massimo_caricabile;
        cout << "Inserire il numero di minerali da trasportare: ";
        cin >> numero_di_minerali_da_trasportare;
        
        inizializzatore_di_array_interi_monodimensionali(combinazione_temporanea);
        numero_di_minerali_temporaneo = valore_temporaneo = K_peso_temporaneo = 0;
        inizializzatore_di_array_interi_bidimensionali(combinazioni);
        inizializzatore_di_array_interi_monodimensionali(valore_delle_combinazioni);
        inizializzatore_di_array_interi_monodimensionali(peso_delle_combinazioni);
        numero_di_combinazioni = 0;
        
        K(0);
        ordinatore_decrescente_di_terne_di_array_interi(valore_delle_combinazioni, peso_delle_combinazioni, combinazioni);
        
        if (valore_delle_combinazioni[0])
        {
            cout << "\nEcco le combinazioni di minerali della lista inserita che soddisfano al limite di peso e al numero di minerali da trasportare imposti, con il relativo valore e peso:\n";
            visualizzatore_di_terne_di_array_interi(valore_delle_combinazioni, "Valore", peso_delle_combinazioni, "Peso", combinazioni, 'm');
        }
        else
            cout << "\nNon ci sono combinazioni di minerali della lista inserita che soddisfano al limite di peso e al numero di minerali da trasportare imposti.";
        
        cout << "\n\nInserire '1' per imporre un altro peso massimo caricabile e/o un altro numero di minerali da trasportare, '0' per uscire dalla sessione: ";
        cin >> b;
    } while (b);
    
    cout << "L'uscita dalla sessione di risoluzione dell'esercizio 'Knapsack' è avvenuta con successo.";
}

void K(int segnaposto)
{
    if (numero_di_minerali_temporaneo == numero_di_minerali_da_trasportare)
    {
        if (numero_di_combinazioni == N)
        {
            cout << "\n########## Errore: Questo programma non supporta la risoluzione di questo esercizio! ##########\n\n";
            exit(-1);
        }
        eguagliatore_di_array_interi_monodimensionali(combinazioni[numero_di_combinazioni], combinazione_temporanea);
        valore_delle_combinazioni[numero_di_combinazioni] = valore_temporaneo;
        peso_delle_combinazioni[numero_di_combinazioni] = K_peso_temporaneo;
        numero_di_combinazioni++;
    }
    
    for (int a = segnaposto; a < numero_di_minerali_della_lista; a++)
    {
        K_peso_temporaneo += minerali[a].peso;
        if (K_peso_temporaneo <= peso_massimo_caricabile)
        {
            combinazione_temporanea[numero_di_minerali_temporaneo] = a + 1;
            numero_di_minerali_temporaneo++;
            valore_temporaneo += minerali[a].valore;
            
            K(a + 1);
            
            valore_temporaneo -= minerali[a].valore;
            numero_di_minerali_temporaneo--;
            combinazione_temporanea[numero_di_minerali_temporaneo] = 0;
        }
        K_peso_temporaneo -= minerali[a].peso;
    }
}

/* ########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'GRAFI' ########## */

struct Arco
{
    int primo_nodo, secondo_nodo, lunghezza;
    bool bidirezionalita;
};

void G(int segnaposto);

bool tour;

Arco archi[N];
int pedaggi[N];
int numero_di_archi_della_lista;
int nodo_di_partenza, nodo_di_arrivo;

int G_percorso_temporaneo[N];
int numero_di_nodi_temporaneo, lunghezza_temporanea;
int pedaggio_temporaneo;
int pedaggio_dei_percorsi[N];
int G_percorsi[N][N];
int numero_di_nodi_dei_percorsi[N], lunghezza_dei_percorsi[N];
int G_numero_di_percorsi;

void Grafi()
{
    cout << "########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'GRAFI' ##########\n\n";
    cout << "### NOTA PER L'UTENTE... ###\n";
    cout << "... SULLA TIPOLOGIA DEI DATI IN INPUT\n";
    cout << "1. Ogni nodo del grafo deve essere indicato da un numero intero positivo. In particolare, in un grafo di n nodi, ad ogni nodo del grafo deve essere associato un numero intero compreso tra 1 ed n.\n";
    cout << "2. Ogni arco della lista deve avere una lunghezza intera.";
    cout << "... SUI LIMITI DEI DATI IN INPUT\n";
    cout << "3. Gli archi della lista non devono essere più di " << N << ".\n";
    cout << "4. Nel caso l'esercizio preveda pedaggi, i pedaggi della lista non devono essere più di " << N << ".\n";
    cout << "... SULL'INPUT DEI DATI\n";
    cout << "5. Nell'inserimento di un nodo si deve digitare solamente il numero relativo.\n";
    cout << "6. Nell'inserimento di un arco si devono digitare in ordine il suo primo nodo, il suo secondo nodo, la sua lunghezza, e, nel caso l'esercizio preveda l'utilizzo di archi a senso unico, uno '0' o un '1', a seconda che l'arco sia a senso unico o a doppio senso, separandoli con uno spazio.\n";
    cout << "7. Per terminare l'inserimento degli archi si deve inserire '0' come se fosse un vero e proprio arco. L'inserimento terminerà in automatico una volta raggiunti i " << N << " archi.\n";
    cout << "8. Nell'inserimento di un pedaggio si devono digitare in ordine il nodo caratterizzato da tale pedaggio e il valore del pedaggio, entrambi come numeri interi.\n";
    cout << "9. Per terminare l'inserimento dei pedaggi si deve inserire '0' come se fosse un vero e proprio pedaggio. L'inserimento terminerà in automatico una volta raggiunti i " << N << " archi.\n";
    cout << "[Esempio di arco in input: '1 3 7 (1)']\n";
    cout << "[Esempio di pedaggio in input: '5 7']\n";
    cout << "... SUI LIMITI DEI DATI IN OUTPUT E SUI MESSAGGI D'ERRORE\n";
    cout << "10. Il programma visualizzerà un messaggio d'errore se, in fase di compilazione, saranno calcolati più di " << N << " percorsi semplici che permettano di raggiungere il nodo di arrivo inserito dal nodo di partenza inserito.\n";
    cout << "... SULL'ALGORITMO E SULL'OUTPUT\n";
    cout << "11. Saranno visualizzati sullo schermo i percorsi semplici (ovvero i percorsi che non passano per più di una volta su uno stesso nodo) che permettono di raggiungere il nodo di arrivo inserito dal nodo di partenza inserito, oppure i tour che partono dalla casella di partenza inserita, con il relativo numero di nodi e con la relativa lunghezza.";
    cout << "\n\n";
    
    cout << "Inserire '1' se l'esercizio prevede di calcolare tour, ovvero percorsi che terminano con il nodo da cui si è partiti, '0' altrimenti: ";
    cin >> tour;
    bool c;
    cout << "Inserire '1' se l'esercizio prevede l'utilizzo di archi a senso unico, ovvero di archi che permettono di spostarsi solo dal primo nodo al secondo, e non viceversa, '0' altrimenti: ";
    cin >> c;
    for (int a = 0; a < N; a++)
        archi[a].primo_nodo = archi[a].secondo_nodo = archi[a].lunghezza = archi[a].bidirezionalita = 0;
    for (int a = 0; a < N; a++)
        pedaggi[a] = 0;
    bool d;
    cout << "Inserire '1' se l'esercizio prevede l'utilizzo di archi con un pedaggio, '0' altrimenti: ";
    cin >> d;
    cout << "Inserire ogni arco della lista.\n";
    for (numero_di_archi_della_lista = 0; numero_di_archi_della_lista < N; numero_di_archi_della_lista++)
    {
        cout << "Arco " << numero_di_archi_della_lista + 1 << ": ";
        cin >> archi[numero_di_archi_della_lista].primo_nodo;
        if (archi[numero_di_archi_della_lista].primo_nodo)
        {
            cin >> archi[numero_di_archi_della_lista].secondo_nodo >> archi[numero_di_archi_della_lista].lunghezza;
            if (c)
                cin >> archi[numero_di_archi_della_lista].bidirezionalita;
            else
                archi[numero_di_archi_della_lista].bidirezionalita = 1;
        }
        else
            break;
    }
    if (d)
        for (int a = 0; a < N; a++)
        {
            int temp;
            cout << "Pedaggio " << a + 1 << ": ";
            cin >> temp;
            if (temp)
                cin >> pedaggi[temp-1];
            else
                break;
        }
    
    bool b;
    do
    {
        cout << "Inserire il nodo di partenza: ";
        cin >> nodo_di_partenza;
        if (tour)
            nodo_di_arrivo = nodo_di_partenza;
        else
        {
            cout << "Inserire il nodo di arrivo: ";
            cin >> nodo_di_arrivo;
        }
        
        inizializzatore_di_array_interi_monodimensionali(G_percorso_temporaneo);
        numero_di_nodi_temporaneo = lunghezza_temporanea = pedaggio_temporaneo = 0;
        inizializzatore_di_array_interi_bidimensionali(G_percorsi);
        inizializzatore_di_array_interi_monodimensionali(numero_di_nodi_dei_percorsi);
        inizializzatore_di_array_interi_monodimensionali(lunghezza_dei_percorsi);
        inizializzatore_di_array_interi_monodimensionali(pedaggio_dei_percorsi);
        G_numero_di_percorsi = 0;
        
        G(nodo_di_partenza);
        if (d)
            ordinatore_decrescente_di_terne_di_array_interi(lunghezza_dei_percorsi, pedaggio_dei_percorsi, G_percorsi);
        else
            ordinatore_decrescente_di_terne_di_array_interi(lunghezza_dei_percorsi, numero_di_nodi_dei_percorsi, G_percorsi);
        
        if (numero_di_nodi_dei_percorsi[0])
        {
            if (tour)
                cout << "\nEcco i tour che partono dalla casella di partenza inserita, preceduti dal relativo numero di nodi e dalla relativa lunghezza:\n";
            else
                cout << "\nEcco i percorsi semplici che permettono di raggiungere il nodo di arrivo inserito dal nodo di partenza inserito, preceduti dal relativo numero di nodi e dalla relativa lunghezza:\n";
            if (d)
                visualizzatore_di_terne_di_array_interi(lunghezza_dei_percorsi, "Lunghezza",pedaggio_dei_percorsi, "Pedaggio", G_percorsi, 'n');
            else
                visualizzatore_di_terne_di_array_interi(lunghezza_dei_percorsi, "Lunghezza", numero_di_nodi_dei_percorsi, "Nodi", G_percorsi, 'n');
        }
        else
            if (tour)
                cout << "\nNon ci sono tour che partono dalla casella di partenza inserita.";
            else
                cout << "\nNon ci sono percorsi semplici che permettono di raggiungere il nodo di arrivo inserito dal nodo di partenza inserito.";
        
        cout << "\n\nInserire '1' per scegliere un nuovo nodo di partenza e/o un nuovo nodo di arrivo, '0' per uscire dalla sessione: ";
        cin >> b;
    } while (b);
    
    cout << "L'uscita dalla sessione di risoluzione dell'esercizio 'Grafi' è avvenuta con successo.";
}

void G(int segnaposto)
{
    if (segnaposto == nodo_di_arrivo and (!tour or G_percorso_temporaneo[0]))
    {
        if (G_numero_di_percorsi == N)
        {
            cout << "\n########## Errore: Questo programma non supporta la risoluzione di questo esercizio! ##########\n\n";
            exit(-1);
        }
        G_percorso_temporaneo[numero_di_nodi_temporaneo] = nodo_di_arrivo;
        pedaggio_temporaneo += pedaggi[nodo_di_arrivo-1];
        eguagliatore_di_array_interi_monodimensionali(G_percorsi[G_numero_di_percorsi], G_percorso_temporaneo);
        G_percorso_temporaneo[numero_di_nodi_temporaneo] = 0;
        numero_di_nodi_temporaneo++;
        numero_di_nodi_dei_percorsi[G_numero_di_percorsi] = numero_di_nodi_temporaneo;
        numero_di_nodi_temporaneo--;
        pedaggio_dei_percorsi[G_numero_di_percorsi] = pedaggio_temporaneo;
        lunghezza_dei_percorsi[G_numero_di_percorsi] = lunghezza_temporanea;
        G_numero_di_percorsi++;
        return;
    }
    
    for (int a = 0; a < numero_di_archi_della_lista; a++)
        if ((segnaposto == archi[a].primo_nodo and (!cercatore_di_valori_interi(G_percorso_temporaneo, archi[a].secondo_nodo) or (archi[a].secondo_nodo == nodo_di_arrivo and tour))) or (segnaposto == archi[a].secondo_nodo and archi[a].bidirezionalita and (!cercatore_di_valori_interi(G_percorso_temporaneo, archi[a].primo_nodo) or (archi[a].primo_nodo == nodo_di_arrivo and tour))))
        {
            G_percorso_temporaneo[numero_di_nodi_temporaneo] = segnaposto;
            pedaggio_temporaneo += pedaggi[segnaposto-1];
            numero_di_nodi_temporaneo++;
            lunghezza_temporanea += archi[a].lunghezza;
            
            if (segnaposto == archi[a].primo_nodo)
                G(archi[a].secondo_nodo);
            else
                G(archi[a].primo_nodo);
            
            lunghezza_temporanea -= archi[a].lunghezza;
            numero_di_nodi_temporaneo--;
            pedaggio_temporaneo -= pedaggi[segnaposto-1];
            G_percorso_temporaneo[numero_di_nodi_temporaneo] = 0;
        }
}

/* ########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'MOVIMENTI DI UN CAVALLO DEGLI SCACCHI' ########## */

struct Casella
{
    int premio;
    bool interdizione;
};

void C(Coppia_di_Coordinate segnaposto);

bool percorso_chiuso;

Casella campo_di_gara[N][N];
int dimensione_x, dimensione_y;
bool mosse_consentite[8];
Coppia_di_Coordinate casella_di_partenza, casella_di_arrivo;

Coppia_di_Coordinate C_percorso_temporaneo[N];
int numero_di_caselle_temporaneo, premio_temporaneo;
Coppia_di_Coordinate C_percorsi[N][N];
int numero_di_caselle_dei_percorsi[N], premio_dei_percorsi[N];
int C_numero_di_percorsi;

void Movimenti_di_un_cavallo_degli_scacchi()
{
    cout << "########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'MOVIMENTI DI UN CAVALLO DEGLI SCACCHI' ##########\n\n";
    cout << "### NOTA PER L'UTENTE... ###\n";
    cout << "... SULLA TIPOLOGIA DEI DATI IN INPUT\n";
    cout << "1. Ogni casella del campo di gara deve avere due coordinate intere e positive.\n";
    cout << "2. Ogni casella premiata deve avere un premio intero.\n";
    cout << "... SUI LIMITI DEI DATI IN INPUT\n";
    cout << "3. Le dimensioni del campo di gara non devono essere superiori a " << N << ".\n";
    cout << "... SULL'INPUT DEI DATI\n";
    cout << "4. Le dimensioni del campo di gara devono essere inserite separandole con uno spazio.\n";
    cout << "5. Nell'inserimento delle coordinate di una casella si devono digitare in ordine la sua coordinata x e la sua coordinata y, separandole con uno spazio.\n";
    cout << "6. Nell'inserimento di una casella premiata si devono inserire in ordine le sue due coordinate e il suo premio, separandoli con uno spazio.\n";
    cout << "7. Nell'inserimento di una casella interdetta, così come in quello della casella di partenza, o di arrivo, si devono inserire le sue due coordinate.\n";
    cout << "8. Per terminare l'inserimento delle caselle premiate, o delle caselle interdette, si deve inserire '0' come se fosse una vera e propria casella. L'inserimento terminerà in automatico una volta raggiunto un numero di caselle premiate o interdette pari al numero di caselle del campo di gara.\n";
    cout << "[Esempio di dimensioni del campo di gara in input: '10 10']\n";
    cout << "[Esempio di casella premiata in input: '5 8 12']\n";
    cout << "[Esempio di casella interdetta (o di casella di partenza o di arrivo) in input: '6 7']\n";
    cout << "... SUI LIMITI DEI DATI IN OUTPUT E SUI MESSAGGI D'ERRORE\n";
    cout << "9. Il programma visualizzerà un messaggio d'errore se, in fase di compilazione, saranno calcolati più di " << N << " percorsi semplici che permettano di raggiungere la casella di arrivo inserita dalla casella di partenza inserita.\n";
    cout << "... SULL'ALGORITMO E SULL'OUTPUT\n";
    cout << "10. Saranno visualizzati sullo schermo i percorsi semplici (ovvero i percorsi che non passano per più di una volta su una stessa casella) che permettono di raggiungere la casella di arrivo inserita dalla casella di partenza inserita, con il relativo numero di caselle e con il relativo premio.";
    cout << "\n\n";
    
    cout << "Inserire '1' se l'esercizio prevede di calcolare percorsi chiusi, ovvero percorsi che terminano con la casella dalla quale si è partiti, '0' altrimenti: ";
    cin >> percorso_chiuso;
    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++)
            campo_di_gara[a][b].premio = campo_di_gara[a][b].interdizione = 0;
    cout << "Inserire le dimensioni del campo di gara: ";
    cin >> dimensione_x >> dimensione_y;
    int coordinata_x_ausiliaria, coordinata_y_ausiliaria;
    cout << "Inserire ogni casella premiata della lista.\n";
    for (int a = 0; a < dimensione_x * dimensione_y; a++)
    {
        cout << "Casella premiata " << a + 1 << ": ";
        cin >> coordinata_x_ausiliaria;
        if (coordinata_x_ausiliaria)
            cin >> coordinata_y_ausiliaria >> campo_di_gara[coordinata_x_ausiliaria - 1][coordinata_y_ausiliaria - 1].premio;
        else
            break;
    }
    cout << "Inserire ogni casella interdetta della lista.\n";
    for (int a = 0; a < dimensione_x * dimensione_y; a++)
    {
        cout << "Casella interdetta " << a + 1 << ": ";
        cin >> coordinata_x_ausiliaria;
        if (coordinata_x_ausiliaria)
        {
            cin >> coordinata_y_ausiliaria;
            campo_di_gara[coordinata_x_ausiliaria - 1][coordinata_y_ausiliaria - 1].interdizione = 1;
        }
        else
            break;
    }
    cout << "Per ogni mossa inserire '1' se è consentita,'0' altrimenti.\n";
    cout << "'ono': ";
    cin >> mosse_consentite[0];
    cout << "'nno': ";
    cin >> mosse_consentite[1];
    cout << "'nne': ";
    cin >> mosse_consentite[2];
    cout << "'ene': ";
    cin >> mosse_consentite[3];
    cout << "'sse': ";
    cin >> mosse_consentite[4];
    cout << "'ese': ";
    cin >> mosse_consentite[5];
    cout << "'sso': ";
    cin >> mosse_consentite[6];
    cout << "'oso': ";
    cin >> mosse_consentite[7];
    
    bool b;
    do
    {
        cout << "Inserire la casella di partenza: ";
        cin >> casella_di_partenza;
        if (percorso_chiuso)
            casella_di_arrivo = casella_di_partenza;
        else
        {
            cout << "Inserire la casella di arrivo: ";
            cin >> casella_di_arrivo;
        }
        
        inizializzatore_di_array_Coppia_di_Coordinate_monodimensionali(C_percorso_temporaneo);
        numero_di_caselle_temporaneo = premio_temporaneo = 0;
        inizializzatore_di_array_Coppia_di_Coordinate_bidimensionali(C_percorsi);
        inizializzatore_di_array_interi_monodimensionali(numero_di_caselle_dei_percorsi);
        inizializzatore_di_array_interi_monodimensionali(premio_dei_percorsi);
        C_numero_di_percorsi = 0;
        
        C(casella_di_partenza);
        ordinatore_decrescente_di_array_Coppia_di_Coordinate_bidimensionali(premio_dei_percorsi, numero_di_caselle_dei_percorsi, C_percorsi);
        
        if (numero_di_caselle_dei_percorsi[0])
        {
            if (percorso_chiuso)
                cout << "\nEcco i percorsi chiusi che partono dalla casella di partenza inserita, preceduti dal relativo numero di caselle e dal relativo premio:\n";
            else
                cout << "\nEcco i percorsi semplici che permettono di raggiungere la casella di arrivo inserita dalla casella di partenza inserita, preceduti dal relativo numero di caselle e dal relativo premio:\n";
            visualizzatore_di_array_Coppia_di_Coordinate_bidimensionali(numero_di_caselle_dei_percorsi, "Caselle", premio_dei_percorsi, "Premio", C_percorsi);
        }
        else
            if (percorso_chiuso)
                cout << "\nNon ci sono percorsi chiusi che partono dalla casella di partenza inserita.";
            else
                cout << "\nNon ci sono percorsi semplici che permettono di raggiungere la casella di arrivo inserita dalla casella di partenza inserita.";
        
        cout << "\n\nInserire '1' per scegliere una nuova casella di partenza e/o una nuova casella di arrivo, '0' per uscire dalla sessione: ";
        cin >> b;
    } while (b);
    
    cout << "L'uscita dalla sessione di risoluzione dell'esercizio 'Movimenti di un cavallo degli scacchi' è avvenuta con successo.";
}

void C(Coppia_di_Coordinate segnaposto)
{
    if (segnaposto == casella_di_arrivo and (!percorso_chiuso or C_percorso_temporaneo[0].x))
    {
        if (C_numero_di_percorsi == N)
        {
            cout << "\n########## Errore: Questo programma non supporta la risoluzione di questo esercizio! ##########\n\n";
            exit(-1);
        }
        C_percorso_temporaneo[numero_di_caselle_temporaneo] = casella_di_arrivo;
        eguagliatore_di_array_Coppia_di_Coordinate_monodimensionali(C_percorsi[C_numero_di_percorsi], C_percorso_temporaneo);
        C_percorso_temporaneo[numero_di_caselle_temporaneo].x = C_percorso_temporaneo[numero_di_caselle_temporaneo].y = 0;
        numero_di_caselle_temporaneo++;
        numero_di_caselle_dei_percorsi[C_numero_di_percorsi] = numero_di_caselle_temporaneo;
        numero_di_caselle_temporaneo--;
        premio_temporaneo += campo_di_gara[casella_di_arrivo.x - 1][casella_di_arrivo.y - 1].premio;
        premio_dei_percorsi[C_numero_di_percorsi] = premio_temporaneo;
        premio_temporaneo -= campo_di_gara[casella_di_arrivo.x - 1][casella_di_arrivo.y - 1].premio;
        C_numero_di_percorsi++;
        return;
    }
    
    Coppia_di_Coordinate casella_temporanea;
    for (int a = 0; a < 8; a++)
    {
        switch (a)
        {
            case 0:
                casella_temporanea.x = segnaposto.x - 2;
                casella_temporanea.y = segnaposto.y + 1;
                break;
            case 1:
                casella_temporanea.x = segnaposto.x - 1;
                casella_temporanea.y = segnaposto.y + 2;
                break;
            case 2:
                casella_temporanea.x = segnaposto.x + 1;
                casella_temporanea.y = segnaposto.y + 2;
                break;
            case 3:
                casella_temporanea.x = segnaposto.x + 2;
                casella_temporanea.y = segnaposto.y + 1;
                break;
            case 4:
                casella_temporanea.x = segnaposto.x + 2;
                casella_temporanea.y = segnaposto.y - 1;
                break;
            case 5:
                casella_temporanea.x = segnaposto.x + 1;
                casella_temporanea.y = segnaposto.y - 2;
                break;
            case 6:
                casella_temporanea.x = segnaposto.x - 1;
                casella_temporanea.y = segnaposto.y - 2;
                break;
            case 7:
                casella_temporanea.x = segnaposto.x - 2;
                casella_temporanea.y = segnaposto.y - 1;
        }
        if (mosse_consentite[a] and (!cercatore_di_valori_Coppia_di_Coordinate(C_percorso_temporaneo, casella_temporanea) or (casella_temporanea == casella_di_arrivo and percorso_chiuso)) and 0 < casella_temporanea.x and casella_temporanea.x <= dimensione_x and 0 < casella_temporanea.y and casella_temporanea.y <= dimensione_y and !campo_di_gara[casella_temporanea.x - 1][casella_temporanea.y - 1].interdizione)
        {
            C_percorso_temporaneo[numero_di_caselle_temporaneo] = segnaposto;
            numero_di_caselle_temporaneo++;
            premio_temporaneo += campo_di_gara[segnaposto.x - 1][segnaposto.y - 1].premio;
            
            C(casella_temporanea);
            
            premio_temporaneo -= campo_di_gara[segnaposto.x - 1][segnaposto.y - 1].premio;
            numero_di_caselle_temporaneo--;
            C_percorso_temporaneo[numero_di_caselle_temporaneo].x = C_percorso_temporaneo[numero_di_caselle_temporaneo].y = 0;
        }
    }
}

/* ########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'MOVIMENTI DI UN ROBOT' ########## */

void R_1();
void R_2();

char comandi[N];
Coppia_di_Coordinate percorso[N];

void Movimenti_di_un_robot()
{
    cout << "########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'MOVIMENTI DI UN ROBOT' ##########\n\n";
    cout << "### NOTA PER L'UTENTE... ###\n";
    cout << "... SULLA TIPOLOGIA DEI DATI IN INPUT\n";
    cout << "1. La lista di comandi deve contenere solo lettere 'a', 'o' ed 'f'.\n";
    cout << "2. Ogni casella del percorso deve avere coordinate intere e positive.\n";
    cout << "... SUI LIMITI DEI DATI IN INPUT\n";
    cout << "3. I comandi della lista non devono essere più di " << N << ".\n";
    cout << "4. Le caselle del percorso non devono essere più di " << N << ".\n";
    cout << "... SULL'INPUT DEI DATI\n";
    cout << "5. Nell'inserimento di una casella si devono digitare le sue due coordinate, separandole con uno spazio.\n";
    cout << "6. Nell'inserimento di una direzione si deve digitare 'e' (per indicare l'orientamento verso Est), 'n' (per indicare l'orientamento verso Nord), 'o' (per indicare l'orientamento verso Ovest), o 's' (per indicare l'orientamento verso Sud).\n";
    cout << "7. La lista di comandi deve essere inserita come un'unica stringa.\n";
    cout << "8. Per terminare l'inserimento delle caselle del percorso si deve inserire '0', come se fosse una vera e propria casella. L'inserimento terminerà in automatico una volta raggiunte le " << N << " caselle.\n";
    cout << "[Esempio di casella in input: '23 12']\n";
    cout << "[Esempio di lista di comandi in input: 'faffoffaf']\n";
    cout << "... SUI LIMITI DEI DATI IN OUTPUT E SUI MESSAGGI D'ERRORE\n";
    cout << "9. Il programma visualizzerà un messaggio d'errore se, in fase di compilazione sarà calcolato un percorso che passi per più di " << N << " caselle.\n";
    cout << "10. Il programma visualizzerà un messaggio d'errore se, in fase di compilazione sarà calcolata una lista di comandi con più di " << N << " comandi.\n";
    cout << "... SULL'ALGORITMO E SULL'OUTPUT\n";
    cout << "11. Nel caso di inversioni di direzione, si presuppone che al robot si debbano imporre due comandi 'a'.\n";
    cout << "12. A seconda della sottosessione che sarà imputata, saranno visualizzati sullo schermo o il percorso che il robot compie seguendo i comandi della lista inserita, o la lista di comandi necessaria a far compiere al robot il percorso inserito.";
    cout << "\n\n";
    
    inizializzatore_di_array_Coppia_di_Coordinate_monodimensionali(percorso);
    inizializzatore_di_stringhe(comandi);
    int sottosessione_delegata;
    cout << "Inserire '1' per calcolare il percorso del robot relativamente a delle mosse prestabilite, '2' per calcolare la lista di mosse da comandare al robot affinché compia un dato percorso: ";
    cin >> sottosessione_delegata;
    if (sottosessione_delegata == 1)
        R_1();
    else
        R_2();
    
    cout << "\n\nL'uscita dalla sessione di risoluzione dell'esercizio 'Movimenti di un robot' è avvenuta con successo.";
}

void R_1()
{
    Coppia_di_Coordinate casella;
    char direzione;
    cout << "Inserire la casella di partenza: ";
    cin >> casella;
    cout << "Inserire la direzione iniziale del robot: ";
    cin >> direzione;
    cout << "Inserire la lista di comandi: ";
    cin >> comandi;
    
    int numero_di_caselle = 0;
    percorso[numero_di_caselle] = casella;
    numero_di_caselle++;
    
    for (int a = 0; comandi[a]; a++)
        if (comandi[a] == 'f')
        {
            switch (direzione)
            {
                case 'e':
                    casella.x += 1;
                    break;
                case 'n':
                    casella.y += 1;
                    break;
                case 'o':
                    casella.x -= 1;
                    break;
                case 's':
                    casella.y -= 1;
            }
            if (numero_di_caselle == N)
            {
                cout << "\n########## Errore: Questo programma non supporta la risoluzione di questo esercizio! ##########\n\n";
                exit(-1);
            }
            percorso[numero_di_caselle] = casella;
            numero_di_caselle++;
        }
        else if (comandi[a] == 'a')
            switch (direzione)
        {
            case 'e':
                direzione = 'n';
                break;
            case 'n':
                direzione = 'o';
                break;
            case 'o':
                direzione = 's';
                break;
            case 's':
                direzione = 'e';
        }
        else if (comandi[a] == 'o')
            switch (direzione)
        {
            case 'e':
                direzione = 's';
                break;
            case 'n':
                direzione = 'e';
                break;
            case 'o':
                direzione = 'n';
                break;
            case 's':
                direzione = 'o';
        }
    
    cout << "\nEcco il percorso che il robot compie seguendo i comandi della lista inserita:\n";
    visualizzatore_di_array_Coppia_di_Coordinate_monodimensionali(percorso);
}

void R_2()
{
    char direzione;
    cout << "Inserire la direzione iniziale del robot: ";
    cin >> direzione;
    char direzione_finale;
    cout << "Inserire la direzione finale del robot, o inserire '0', se non è specificato che il robot debba averne una predefinita: ";
    cin >> direzione_finale;
    cout << "Inserire ogni casella del percorso.\n";
    for (int a = 0; a < N; a++)
    {
        cout << "Casella " << a + 1 << ": ";
        cin >> percorso[a].x;
        if (percorso[a].x)
            cin >> percorso[a].y;
        else
            break;
    }
    
    int numero_di_comandi = 0;
    for (int a = 0; percorso[a + 1].x; a++)
    {
        if (numero_di_comandi == N)
        {
            cout << "\n########## Errore: Questo programma non supporta la risoluzione di questo esercizio! ##########\n\n";
            exit(-1);
        }
        if ((percorso[a + 1].x == percorso[a].x + 1 and direzione == 's') or (percorso[a + 1].y == percorso[a].y + 1 and direzione == 'e') or (percorso[a + 1].x == percorso[a].x - 1 and direzione == 'n') or (percorso[a + 1].y == percorso[a].y - 1 and direzione == 'o'))
        {
            comandi[numero_di_comandi] = 'a';
            numero_di_comandi++;
        }
        else if ((percorso[a + 1].x == percorso[a].x + 1 and direzione == 'n') or (percorso[a + 1].y == percorso[a].y + 1 and direzione == 'o') or (percorso[a + 1].x == percorso[a].x - 1 and direzione == 's') or (percorso[a + 1].y == percorso[a].y - 1 and direzione == 'e'))
        {
            comandi[numero_di_comandi] = 'o';
            numero_di_comandi++;
        }
        else if ((percorso[a + 1].x == percorso[a].x + 1 and direzione == 'o') or (percorso[a + 1].y == percorso[a].y + 1 and direzione == 's') or (percorso[a + 1].x == percorso[a].x - 1 and direzione == 'e') or (percorso[a + 1].y == percorso[a].y - 1 and direzione == 'n'))
        {
            comandi[numero_di_comandi] = 'a';
            numero_di_comandi++;
            if (numero_di_comandi == N)
            {
                cout << "\n########## Errore: Questo programma non supporta la risoluzione di questo esercizio! ##########\n\n";
                exit(-1);
            }
            comandi[numero_di_comandi] = 'a';
            numero_di_comandi++;
        }
        
        if (percorso[a + 1].x == percorso[a].x + 1)
            direzione = 'e';
        else if (percorso[a + 1].y == percorso[a].y + 1)
            direzione = 'n';
        else if (percorso[a + 1].x == percorso[a].x - 1)
            direzione = 'o';
        else if (percorso[a + 1].y == percorso[a].y - 1)
            direzione = 's';
        
        if (numero_di_comandi == N)
        {
            cout << "\n########## Errore: Questo programma non supporta la risoluzione di questo esercizio! ##########\n\n";
            exit(-1);
        }
        comandi[numero_di_comandi] = 'f';
        numero_di_comandi++;
    }
    
    if (direzione_finale != '0' and direzione_finale != direzione and numero_di_comandi == N)
    {
        cout << "\n########## Errore: Questo programma non supporta la risoluzione di questo esercizio! ##########\n\n";
        exit(-1);
    }
    if ((direzione_finale == 'e' and direzione == 's') or (direzione_finale == 'n' and direzione == 'e') or (direzione_finale == 'o' and direzione == 'n') or (direzione_finale == 's' and direzione == 'o'))
    {
        comandi[numero_di_comandi] = 'a';
        numero_di_comandi++;
    }
    else if ((direzione_finale == 'e' and direzione == 'n') or (direzione_finale == 'n' and direzione == 'o') or (direzione_finale == 'o' and direzione == 's') or (direzione_finale == 's' and direzione == 'e'))
    {
        comandi[numero_di_comandi] = 'o';
        numero_di_comandi++;
    }
    else if ((direzione_finale == 'e' and direzione == 'o') or (direzione_finale == 'n' and direzione == 's') or (direzione_finale == 'o' and direzione == 'e') or (direzione_finale == 's' and direzione == 'n'))
    {
        comandi[numero_di_comandi] = 'a';
        numero_di_comandi++;
        if (numero_di_comandi == N)
        {
            cout << "\n########## Errore: Questo programma non supporta la risoluzione di questo esercizio! ##########\n\n";
            exit(-1);
        }
        comandi[numero_di_comandi] = 'a';
        numero_di_comandi++;
    }
    
    int a = 0;
    cout << "\nEcco la lista di comandi necessaria a far compiere al robot il percorso inserito:\n";
    for (; a < numero_di_comandi - 1; a++)
    {
        cout << comandi[a] << ",";
    }
    cout << comandi[a];
}

/* ########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'PIANIFICAZIONE' ########## */

struct Attivita
{
    int ragazzi, durata;
    int giorno_iniziale, giorno_finale;
};

struct Priorita
{
    int prima_attivita, seconda_attivita;
};

void P(int segnaposto);

Attivita attivita[N];
int numero_di_attivita_della_lista;
Priorita priorita[N];
int numero_di_priorita_della_lista;

int attivita_svolte_giornalmente[N][N];
int ragazzi_impegnati_giornalmente[N], numero_di_attivita_svolte_giornalmente[N];
int numero_di_attivita_temporaneo_del_Gantt;

int attivita_finali_del_progetto[N];
int numero_di_attivita_finali_del_progetto;
int percorso_critico_temporaneo[N];
int numero_di_attivita_temporaneo_del_percorso_critico;
int percorsi_critici[N][N];
int numero_di_attivita_dei_percorsi_critici[N];
int numero_di_percorsi_critici;

void Pianificazione()
{
    cout << "########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'PIANIFICAZIONE' ##########\n\n";
    cout << "### NOTA PER L'UTENTE... ###\n";
    cout << "... SUI LIMITI DEI DATI IN INPUT\n";
    cout << "1. Le attività della lista non devono essere più di " << N << ".\n";
    cout << "2. Le priorità della lista non devono essere più di " << N << ".\n";
    cout << "... SULL'INPUT DEI DATI\n";
    cout << "3. Nell'inserimento di un'attività si devono digitare in ordine il numero di ragazzi che impegna e la sua durata, separandoli con uno spazio.\n";
    cout << "4. Nell'inserimento di una priorità si devono digitare in ordine il numero relativo alla sua prima attività e il numero relativo alla sua seconda attività, separandoli con uno spazio.\n";
    cout << "5. Per terminare l'inserimento delle attività o delle priorità si deve inserire '0', come se fosse una vera e propria attività o una vera e propria priorità. L'inserimento terminerà in automatico una volta raggiunte le " << N << " attività o priorità.\n";
    cout << "[Esempio di attività in input: '7 2']\n";
    cout << "[Esempio di priorità in input: '3 5']\n";
    cout << "... SUI LIMITI DEI DATI IN OUTPUT E SUI MESSAGGI D'ERRORE\n";
    cout << "6. Il programma visualizzerà un messaggio d'errore se, in fase di compilazione, sarà calcolato un numero di giorni minimo per completare il progetto maggiore di " << N << ".\n";
    cout << "7. Il programma visualizzerà un messaggio d'errore se, in fase di compilazione, saranno calcolati più di " << N << " percorsi critici.\n";
    cout << "... SULL'ALGORITMO E SULL'OUTPUT\n";
    cout << "8. Saranno visualizzati sullo schermo, relativamente ad ogni giorno del progetto, le attività che si svolgono in tale giorno, il numero di ragazzi impegnati in totale e il numero di attività svolte in parallelo.\n";
    cout << "9. Saranno visaulizzati sullo schermo il numero minimo di giorni sufficiente a terminare il progetto, il numero minimo di ragazzi sufficiente a terminare il progetto, ovvero il numero massimo di ragazzi impegnati in un singolo giorno del progetto, e il numero massimo di attività che si svolgono in parallelo durante il progetto.\n";
    cout << "10. Saranno visualizzati sullo schermo i percorsi critici del progetto, con il relativo numero di attività.";
    cout << "\n\n";
    
    for (int a = 0; a < N; a++)
        attivita[a].ragazzi = attivita[a].durata = priorita[a].prima_attivita = priorita[a].seconda_attivita = 0;
    cout << "Inserire ogni attività della lista.\n";
    for (numero_di_attivita_della_lista = 0; numero_di_attivita_della_lista < N; numero_di_attivita_della_lista++)
    {
        cout << "Attività " << numero_di_attivita_della_lista + 1 << ": ";
        cin >> attivita[numero_di_attivita_della_lista].ragazzi;
        if (attivita[numero_di_attivita_della_lista].ragazzi)
            cin >> attivita[numero_di_attivita_della_lista].durata;
        else
            break;
    }
    cout << "Inserire ogni priorità della lista.\n";
    for (numero_di_priorita_della_lista = 0; numero_di_priorita_della_lista < N; numero_di_priorita_della_lista++)
    {
        cout << "Priorità " << numero_di_priorita_della_lista + 1 << ": ";
        cin >> priorita[numero_di_priorita_della_lista].prima_attivita;
        if (priorita[numero_di_priorita_della_lista].prima_attivita)
            cin >> priorita[numero_di_priorita_della_lista].seconda_attivita;
        else
            break;
    }
    
ripeti:
    for (int a = 0; a < N; a++)
        attivita[a].giorno_iniziale = attivita[a].giorno_finale = 0;
    inizializzatore_di_array_interi_bidimensionali(attivita_svolte_giornalmente);
    inizializzatore_di_array_interi_monodimensionali(ragazzi_impegnati_giornalmente);
    inizializzatore_di_array_interi_monodimensionali(numero_di_attivita_svolte_giornalmente);
    numero_di_attivita_temporaneo_del_Gantt = 0;
    
    bool r, s;
    r = true;
    for (int a = 1; a < N + 1; a++)
    {
        for (int b = 0; b < numero_di_attivita_della_lista; b++)
        {
            s = true;
            if (!attivita[b].giorno_iniziale)
            {
                for (int c = 0; c < numero_di_priorita_della_lista; c++)
                    if (b + 1 == priorita[c].seconda_attivita and (attivita[priorita[c].prima_attivita - 1].giorno_finale >= a or !attivita[priorita[c].prima_attivita - 1].giorno_finale))
                    {
                        s = false;
                        break;
                    }
                if (s)
                {
                    attivita[b].giorno_iniziale = a;
                    attivita[b].giorno_finale = attivita[b].giorno_iniziale + attivita[b].durata - 1;
                }
            }
        }
        
        for (int b = 0; b < numero_di_attivita_della_lista; b++)
        {
            if (attivita[b].giorno_finale > N)
            {
                cout << "\n########## Errore: Questo programma non supporta la risoluzione di questo esercizio! ##########\n\n";
                exit(-1);
            }
            if (attivita[b].giorno_iniziale <= a and a <= attivita[b].giorno_finale)
            {
                attivita_svolte_giornalmente[a - 1][numero_di_attivita_temporaneo_del_Gantt] = b + 1;
                numero_di_attivita_temporaneo_del_Gantt++;
                ragazzi_impegnati_giornalmente[a - 1] += attivita[b].ragazzi;
                r = false;
            }
        }
        numero_di_attivita_svolte_giornalmente[a - 1] = numero_di_attivita_temporaneo_del_Gantt;
        numero_di_attivita_temporaneo_del_Gantt = 0;
        
        if (r)
            break;
    }
    
    int numero_di_giorni_del_progetto = 0, numero_massimo_di_ragazzi_impegnati_giornalmente = 0, numero_massimo_di_attivita_svolte_giornalmente = 0;
    cout << "\nEcco, relativamente ad ogni giorno del progetto, le attività che si svolgono in tale giorno, il numero di ragazzi impegnati in totale e il numero di attività svolte in parallelo:\n";
    for (; numero_di_attivita_svolte_giornalmente[numero_di_giorni_del_progetto]; numero_di_giorni_del_progetto++)
    {
        cout << "Giorno: " << numero_di_giorni_del_progetto + 1 << ", Ragazzi: " << ragazzi_impegnati_giornalmente[numero_di_giorni_del_progetto] << ", Attività svolte in parallelo: " << numero_di_attivita_svolte_giornalmente[numero_di_giorni_del_progetto] << " -> ";
        visualizzatore_di_array_interi_monodimensionali(attivita_svolte_giornalmente[numero_di_giorni_del_progetto], 'A');
        cout << "\n";
        if (ragazzi_impegnati_giornalmente[numero_di_giorni_del_progetto] > numero_massimo_di_ragazzi_impegnati_giornalmente)
            numero_massimo_di_ragazzi_impegnati_giornalmente = ragazzi_impegnati_giornalmente[numero_di_giorni_del_progetto];
        if (numero_di_attivita_svolte_giornalmente[numero_di_giorni_del_progetto] > numero_massimo_di_attivita_svolte_giornalmente)
            numero_massimo_di_attivita_svolte_giornalmente = numero_di_attivita_svolte_giornalmente[numero_di_giorni_del_progetto];
    }
    cout << "Il numero minimo di giorni sufficienti a terminare il progetto è: " << numero_di_giorni_del_progetto << "\n";
    cout << "Il numero minimo di ragazzi sufficienti a terminare il progetto, ovvero il numero massimo di ragazzi impegnati in un singolo giorno del progetto è: " << numero_massimo_di_ragazzi_impegnati_giornalmente << "\n";
    cout << "Il numero massimo di attività che si svolgono in parallelo durante il progetto è: " << numero_massimo_di_attivita_svolte_giornalmente << "\n";
    
    inizializzatore_di_array_interi_monodimensionali(attivita_finali_del_progetto);
    inizializzatore_di_array_interi_monodimensionali(percorso_critico_temporaneo);
    numero_di_attivita_temporaneo_del_percorso_critico = 0;
    inizializzatore_di_array_interi_bidimensionali(percorsi_critici);
    inizializzatore_di_array_interi_monodimensionali(numero_di_attivita_dei_percorsi_critici);
    numero_di_percorsi_critici = 0;
    bool t;
    for (int a = 0; a < numero_di_attivita_della_lista; a++)
    {
        t = true;
        for (int b = 0; b < numero_di_priorita_della_lista; b++)
            if (a + 1 == priorita[b].prima_attivita)
            {
                t = false;
                break;
            }
        if (t)
        {
            attivita_finali_del_progetto[numero_di_attivita_finali_del_progetto] = a + 1;
            numero_di_attivita_finali_del_progetto++;
        }
    }
    for (int a = 0; a < numero_di_attivita_della_lista; a++)
    {
        t = true;
        for (int b = 0; b < numero_di_priorita_della_lista; b++)
            if (a + 1 == priorita[b].seconda_attivita)
            {
                t = false;
                break;
            }
        if (t)
            P(a + 1);
    }
    ordinatore_decrescente_di_coppie_di_array_interi(numero_di_attivita_dei_percorsi_critici, percorsi_critici);
    
    if (numero_di_attivita_dei_percorsi_critici[0])
    {
        cout << "Ecco i percorsi critici del progetto preceduti dal relativo numero di attività:\n";
        visualizzatore_di_coppie_di_array_interi(numero_di_attivita_dei_percorsi_critici, "Attività", percorsi_critici, 'A');
    }
    else
        cout << "\nIl progetto non presenta percorsi critici.\n";
    
    bool ripeti;
    cout << "\nInserire '1' per modificare la durata di un'attività della lista, '0' per uscire dalla sessione: ";
    cin >> ripeti;
    if (ripeti)
    {
        int n;
        cout << "Inserire il numero dell'attività da modificare e la nuova durata come numeri interi separati da uno spazio: ";
        cin >> n;
        cin >> attivita[n - 1].durata;
        goto ripeti;
    }
    
    cout << "L'uscita dalla sessione di risoluzione dell'esercizio 'Pianificazione' è avvenuta con successo.";
}

void P(int segnaposto)
{
    if (cercatore_di_valori_interi(attivita_finali_del_progetto, segnaposto))
    {
        if (numero_di_percorsi_critici == N)
        {
            cout << "\n########## Errore: Questo programma non supporta la risoluzione di questo esercizio! ##########\n\n";
            exit(-1);
        }
        percorso_critico_temporaneo[numero_di_attivita_temporaneo_del_percorso_critico] = segnaposto;
        eguagliatore_di_array_interi_monodimensionali(percorsi_critici[numero_di_percorsi_critici], percorso_critico_temporaneo);
        percorso_critico_temporaneo[numero_di_attivita_temporaneo_del_percorso_critico] = 0;
        numero_di_attivita_temporaneo_del_percorso_critico++;
        numero_di_attivita_dei_percorsi_critici[numero_di_percorsi_critici] = numero_di_attivita_temporaneo_del_percorso_critico;
        numero_di_attivita_temporaneo_del_percorso_critico--;
        numero_di_percorsi_critici++;
        return;
    }
    
    for (int a = 0; a < numero_di_priorita_della_lista; a++)
        if (segnaposto == priorita[a].prima_attivita and attivita[segnaposto - 1].giorno_finale == attivita[priorita[a].seconda_attivita - 1].giorno_iniziale - 1)
        {
            percorso_critico_temporaneo[numero_di_attivita_temporaneo_del_percorso_critico] = segnaposto;
            numero_di_attivita_temporaneo_del_percorso_critico++;
            P(priorita[a].seconda_attivita);
            numero_di_attivita_temporaneo_del_percorso_critico--;
            percorso_critico_temporaneo[numero_di_attivita_temporaneo_del_percorso_critico] = 0;
        }
}

/* ########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'FLUSSI IN UNA RETE DI CANALI' ########## */

struct Sorgente
{
    char ID;
    int portata_individuale, portata_totale;
};

struct Canale
{
    char ID_della_prima_fonte, ID_della_seconda_fonte;
};

int F(int segnaposto);

Sorgente sorgenti[N];
int numero_di_sorgenti;
Canale canali[N];
int numero_di_canali;

void Flussi_in_una_rete_di_canali()
{
    cout << "########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'FLUSSI IN UNA RETE DI CANALI' ##########\n\n";
    cout << "### NOTA PER L'UTENTE... ###\n";
    cout << "... SULLA TIPOLOGIA DEI DATI IN INPUT\n";
    cout << "1. Ogni sorgente della lista ha un ID consistente in un singolo carattere, e una portata intera non negativa.";
    cout << "... SUI LIMITI DEI DATI IN INPUT\n";
    cout << "2. Le sorgenti della lista non devono essere più di " << N << ".\n";
    cout << "3. I canali della lista non devono essere più di " << N << ".\n";
    cout << "... SULL'INPUT DEI DATI\n";
    cout << "4. Nell'inserimento di una sorgente si devono digitare in ordine il suo ID e la sua portata, separandoli con uno spazio.\n";
    cout << "5. Nell'inserimento di un canale si devono digitare in ordine l'ID della sua sorgente a monte e l'ID della sua sorgente a valle, separandoli con uno spazio.\n";
    cout << "6. Per terminare l'inserimento delle sorgenti o dei canali si deve inserire '0' come se fosse una vera o propria sorgente o un vero e proprio canale. L'inserimento terminerà in automatico una volta raggiunte le " << N << " sorgenti o i " << N << " canali.\n";
    cout << "[Esempio di sorgente in input: 'f 9']\n";
    cout << "[Esempio di canale in input: 'g i']\n";
    cout << "... SULL'ALGORITMO E SULL'OUTPUT\n";
    cout << "7. Sarà visualizzata sullo schermo la quantità di acqua complessiva in uscita da ogni sorgente della rete.";
    cout << "\n\n";
    
    for (int a = 0; a < N; a++)
    {
        sorgenti[a].ID = canali[a].ID_della_prima_fonte = canali[a].ID_della_seconda_fonte = '\0';
        sorgenti[a].portata_individuale = sorgenti[a].portata_totale = 0;
    }
    cout << "Inserire ogni sorgente della lista.\n";
    for (numero_di_sorgenti = 0; numero_di_sorgenti < N; numero_di_sorgenti++)
    {
        cout << "Sorgente " << numero_di_sorgenti + 1 << ": ";
        cin >> sorgenti[numero_di_sorgenti].ID;
        if (sorgenti[numero_di_sorgenti].ID == '0')
        {
            sorgenti[numero_di_sorgenti].ID = '\0';
            break;
        }
        else
            cin >> sorgenti[numero_di_sorgenti].portata_individuale;
    }
    cout << "Inserire ogni canale della lista.\n";
    for (numero_di_canali = 0; numero_di_canali < N; numero_di_canali++)
    {
        cout << "Canale " << numero_di_canali + 1 << ": ";
        cin >> canali[numero_di_canali].ID_della_prima_fonte;
        if (canali[numero_di_canali].ID_della_prima_fonte == '0')
        {
            canali[numero_di_canali].ID_della_prima_fonte = '\0';
            break;
        }
        else
            cin >> canali[numero_di_canali].ID_della_seconda_fonte;
    }
    
    for (int a = 0; a < numero_di_sorgenti; a++)
        sorgenti[a].portata_totale = F(a);
    
    cout << "\nEcco la quantità d'acqua complessiva in uscita da ogni sorgente della rete:\n";
    for(int a = 0; a < numero_di_sorgenti; a++)
        cout << sorgenti[a].ID << " -> " << sorgenti[a].portata_totale << "\n";
    
    cout << "\nL'uscita dalla sessione di risoluzione dell'esercizio 'Flussi in una rete di canali' è avvenuta con successo.";
}

int F(int segnaposto)
{
    int portata = sorgenti[segnaposto].portata_individuale;
    for (int a = 0; a < numero_di_canali; a++)
    {
        if (canali[a].ID_della_seconda_fonte == sorgenti[segnaposto].ID)
        {
            int n = 0;
            for (int b = 0; b < numero_di_canali; b++)
                if (canali[b].ID_della_prima_fonte == canali[a].ID_della_prima_fonte)
                    n++;
            for (int b = 0; b < numero_di_sorgenti; b++)
                if (sorgenti[b].ID == canali[a].ID_della_prima_fonte)
                    portata += F(b) / n;
        }
    }
    return portata;
}

/* ########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'REGOLE E DEDUZIONI' ########## */

struct Regola
{
    char antecedenti[N], conseguenti[N];
    int peso;
};

void R();
bool controlla_applicabilita(int lista_di_regole[N], char antecedenti[N]);
bool R_controlla_validita(int lista_di_regole[N]);

Regola regole[N];
int numero_di_regole_della_lista;
char dati[N], richieste[N];

int lista_di_regole_temporanea[N];
int numero_di_regole_temporaneo, R_peso_temporaneo;
int liste_di_regole[N][N];
int numero_di_regole_delle_liste_di_regole[N], peso_delle_liste_di_regole[N];
int numero_di_liste_di_regole;

void Regole_e_deduzioni()
{
    cout << "########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'REGOLE E DEDUZIONI' ##########\n\n";
    cout << "### NOTA PER L'UTENTE... ###\n";
    cout << "... SULLA TIPOLOGIA DI DATI IN INPUT\n";
    cout << "1. Ogni regola della lista deve avere per antecedenti e conseguenti una lista di singoli caratteri, e, nel caso sia previsto dall'esercizio, un peso intero positivo.\n";
    cout << "2. I dati e le richieste devono essere delle liste di singoli caratteri.\n";
    cout << "... SUI LIMITI DEI DATI IN INPUT\n";
    cout << "3. Ogni singola regola della lista non deve avere più di " << N << " antecedenti o conseguenti.\n";
    cout << "4. Le regole della lista non devono essere più di " << N << ".\n";
    cout << "5. I dati e le richieste dell'esercizio non devono essere più di " << N << ".\n";
    cout << "... SULL'INPUT DEI DATI\n";
    cout << "6. Gli antecedenti e i conseguenti di una regola, così come i dati e le richieste dell'esercizio devono essere inseriti come delle uniche stringhe.\n";
    cout << "7. Nell'inserimento di una regola si devono digitare in ordine i suoi antecedenti, i suoi conseguenti e, nel caso sia previsto dall'esercizio, il suo peso.\n";
    cout << "... SUI LIMITI DEI DATI IN OUTPUT E SUI MESSAGGI D'ERRORE\n";
    cout << "8. Il programma visualizzerà un messaggio d'errore se, in fase di compilazione, saranno calcolate più di " << N << " liste di regole che consentano di dedurre le richieste inserite dai dati inseriti.\n";
    cout << "... SULL'ALGORITMO E SULL'OUTPUT\n";
    cout << "9. Nel caso due regole possano essere applicate nello stesso passaggio, si presuppone che debba essere applicata per prima la regola con numero minore.\n";
    cout << "10. Saranno visualizzate sullo schermo le liste di regole che permettono di dedurre le richieste inserite dai dati inseriti, con il relativo peso, nel caso questo sia previsto dall'esercizio.";
    cout << "\n\n";
    
    for (int a = 0; a < N; a++)
    {
        inizializzatore_di_stringhe(regole[a].antecedenti);
        inizializzatore_di_stringhe(regole[a].conseguenti);
        regole[a].peso = 0;
    }
    bool c;
    cout << "Inserire '1' se le regole dell'esercizio hanno un peso, '0' altrimenti: ";
    cin >> c;
    cout << "Inserire ogni regola della lista.\n";
    for (numero_di_regole_della_lista = 0; numero_di_regole_della_lista < N; numero_di_regole_della_lista++)
    {
        cout << "Regola " << numero_di_regole_della_lista + 1 << ": ";
        cin >> regole[numero_di_regole_della_lista].antecedenti;
        if (regole[numero_di_regole_della_lista].antecedenti[0] != '0')
        {
            cin >> regole[numero_di_regole_della_lista].conseguenti;
            if (c)
                cin >> regole[numero_di_regole_della_lista].peso;
        }
        else
        {
            regole[numero_di_regole_della_lista].antecedenti[0] = '\0';
            break;
        }
    }
    
    bool b;
    do
    {
        inizializzatore_di_stringhe(dati);
        cout << "Inserisci i dati: ";
        cin >> dati;
        inizializzatore_di_stringhe(richieste);
        cout << "Inserisci le richieste: ";
        cin >> richieste;
        
        inizializzatore_di_array_interi_monodimensionali(lista_di_regole_temporanea);
        numero_di_regole_temporaneo = R_peso_temporaneo = 0;
        inizializzatore_di_array_interi_bidimensionali(liste_di_regole);
        inizializzatore_di_array_interi_monodimensionali(numero_di_regole_delle_liste_di_regole);
        inizializzatore_di_array_interi_monodimensionali(peso_delle_liste_di_regole);
        numero_di_liste_di_regole = 0;
        
        R();
        ordinatore_decrescente_di_terne_di_array_interi(peso_delle_liste_di_regole, numero_di_regole_delle_liste_di_regole, liste_di_regole);
        
        if (numero_di_regole_delle_liste_di_regole[0])
        {
            if (c)
            {
                cout << "\nEcco le liste di regole che consentono di dedurre le richieste inserite dai dati inseriti, precedute dal relativo peso:\n";
                visualizzatore_di_coppie_di_array_interi(peso_delle_liste_di_regole, "Peso", liste_di_regole);
                cout << "\n";
            }
            else
            {
                cout << "\nEcco le liste di regole che consentono di dedurre le richieste inserite dai dati inseriti:\n";
                for (int a = 0; numero_di_regole_delle_liste_di_regole[a]; a++)
                {
                    visualizzatore_di_array_interi_monodimensionali(liste_di_regole[a]);
                    cout << "\n";
                }
            }
        }
        else
            cout << "\nNon ci sono lsite di regole che permettono di dedurre le richieste inserite dai dati inseriti.\n";
        
        cout << "\nInserire '1' per scegliere una nuova lista di dati e/o di richieste, '0' per uscire dalla sessione: ";
        cin >> b;
    } while (b);
    
    cout << "L'uscita dalla sessione di risoluzione dell'esercizio 'Regole e deduzioni' è avvenuta con successo.";
}

void R()
{
    if (R_controlla_validita(lista_di_regole_temporanea))
    {
        if (numero_di_liste_di_regole == N)
        {
            cout << "\n########## Errore: Questo programma non supporta la risoluzione di questo esercizio! ##########\n\n";
            exit(-1);
        }
        eguagliatore_di_array_interi_monodimensionali(liste_di_regole[numero_di_liste_di_regole], lista_di_regole_temporanea);
        numero_di_regole_delle_liste_di_regole[numero_di_liste_di_regole] = numero_di_regole_temporaneo;
        peso_delle_liste_di_regole[numero_di_liste_di_regole] = R_peso_temporaneo;
        numero_di_liste_di_regole++;
        return;
    }
    
    for (int a = 0; a < numero_di_regole_della_lista; a++)
    {
        if (!cercatore_di_valori_interi(lista_di_regole_temporanea, a + 1) and controlla_applicabilita(lista_di_regole_temporanea, regole[a].antecedenti) and !controlla_applicabilita(lista_di_regole_temporanea, regole[a].conseguenti))
        {
            lista_di_regole_temporanea[numero_di_regole_temporaneo] = a + 1;
            numero_di_regole_temporaneo++;
            R_peso_temporaneo += regole[a].peso;
            
            R();
            
            R_peso_temporaneo -= regole[a].peso;
            numero_di_regole_temporaneo--;
            lista_di_regole_temporanea[numero_di_regole_temporaneo] = 0;
        }
    }
}

bool controlla_applicabilita(int lista_di_regole[N], char antecedenti[N])
{
    for (int a = 0; antecedenti[a]; a++)
    {
        if (cercatore_di_valori_carattere(dati, antecedenti[a]))
            goto next;
        for (int b = 0; b < N and lista_di_regole[b]; b++)
            if (cercatore_di_valori_carattere(regole[lista_di_regole[b] - 1].conseguenti, antecedenti[a]))
                goto next;
        return false;
    next:
        ;
    }
    return true;
}

bool R_controlla_validita(int lista_di_regole[N])
{
    if (!controlla_applicabilita(lista_di_regole, richieste))
        return false;
    
    int lista_di_regole_modificata[N];
    int numero_di_regole_della_lista_di_regole_modificata;
    for (int a = 0; a < N and lista_di_regole[a]; a++)
    {
        inizializzatore_di_array_interi_monodimensionali(lista_di_regole_modificata);
        numero_di_regole_della_lista_di_regole_modificata = 0;
        for (int b = 0; b < N and lista_di_regole[b]; b++)
            if (b != a)
            {
                if (!controlla_applicabilita(lista_di_regole_modificata, regole[lista_di_regole[b] - 1].antecedenti))
                    goto next;
                lista_di_regole_modificata[numero_di_regole_della_lista_di_regole_modificata] = lista_di_regole[b];
                numero_di_regole_della_lista_di_regole_modificata++;
            }
        if (controlla_applicabilita(lista_di_regole_modificata, richieste))
            return false;
    next:
        ;
    }
    
    int sottolista_di_regole[N];
    for (int a = 0; a < N and lista_di_regole[a]; a++)
    {
        inizializzatore_di_array_interi_monodimensionali(sottolista_di_regole);
        for (int b = 0; b < a; b++)
            sottolista_di_regole[b] = lista_di_regole[b];
        for (int b = a + 1; b < N and lista_di_regole[b]; b++)
            if (controlla_applicabilita(sottolista_di_regole, regole[lista_di_regole[b] - 1].antecedenti) and lista_di_regole[b] < lista_di_regole[a])
                return false;
    }
    
    return true;
}

/* ########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'DISTRIBUZIONE DI LAMPIONI IN UN GRAFO DI PIAZZE' ########## */

struct Strada
{
    int prima_piazza, seconda_piazza;
};

void D(int segnaposto);
bool controlla_illuminazione(int piazza, int collocazione[N]);
bool D_controlla_validita_piazze(int collocazione[N]);
bool D_controlla_validita_strade(int collocazione[N]);

int mod;
Strada strade[N];
int numero_di_strade_della_lista;
int numero_di_piazze_del_grafo;

int collocazione_temporanea[N];
int numero_di_lampioni_temporaneo;
int collocazioni[N][N];
int numero_di_lampioni_delle_collocazioni[N];
int numero_di_collocazioni;

void Distribuzione_di_lampioni_in_un_grafo_di_piazze()
{
    cout << "########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'DISTRIBUZIONE DI LAMPIONI IN UN GRAFO DI PIAZZE' ##########\n\n";
    cout << "### NOTA PER L'UTENTE... ###\n";
    cout << "... SULLA TIPOLOGIA DEI DATI IN INPUT\n";
    cout << "1. Ogni piazza del grafo deve essere indicata da un numero intero positivo. In particolare, in un grafo di n piazze, ad ogni piazza del grafo deve essere associato un numero intero compreso tra 1 ed n.\n";
    cout << "... SUI LIMITI DEI DATI IN INPUT\n";
    cout << "2. Le strade della lista non devono essere più di " << N << ".\n";
    cout << "... SULL'INPUT DEI DATI\n";
    cout << "3. Nell'inserimento di una piazza si deve digitare solamente il numero relativo.\n";
    cout << "4. Nell'inserimento di una strada si devono digitare in ordine la sua prima piazza e la sua seconda piazza, separandole con uno spazio.\n";
    cout << "5. Per terminare l'inserimento delle strade si deve inserire '0' come se fosse una vera e propria strada. L'inserimento terminerà in automatico una volta raggiunte le " << N << " strade.\n";
    cout << "[Esempio di strada in input: '1 3']\n";
    cout << "... SUI LIMITI DEI DATI IN OUTPUT E SUI MESSAGGI D'ERRORE\n";
    cout << "6. Il programma visualizzerà un messaggio d'errore se, in fase di compilazione, saranno calcolate più di " << N << " collocazioni di lampioni che permettano di illuminare ogni piazza del paese e che non contino lampioni installati inutilmente.\n";
    cout << "... SULL'ALGORITMO E SULL'OUTPUT\n";
    cout << "7. Saranno visualizzate sullo schermo le collocazioni di lampioni che permettono di illuminare ogni piazza del paese e che non contino lampioni installati inutilmente, con il relativo numero di lampioni.";
    cout << "\n\n";
    
    cout << "Inserire 1 se l'esercizio richiede di trovare le collocazioni di lampioni che permettono di illuminare ogni piazza del paese, 2 se l'esercizio richiede di trovare le collocazioni di lampioni che permettono di illuminare ogni strada del paese, 3 se l'esercizio richiede di trovare le collocazioni di lampioni che permettono di illuminare ogni strada e ogni piazza del paese: ";
    cin >> mod;
    for (int a = 0; a < N; a++)
        strade[a].prima_piazza = strade[a].seconda_piazza = 0;
    numero_di_piazze_del_grafo = 0;
    cout << "Inserire ogni strada della lista.\n";
    for (numero_di_strade_della_lista = 0; numero_di_strade_della_lista < N; numero_di_strade_della_lista++)
    {
        cout << "Strada " << numero_di_strade_della_lista + 1 << ": ";
        cin >> strade[numero_di_strade_della_lista].prima_piazza;
        if (strade[numero_di_strade_della_lista].prima_piazza)
            cin >> strade[numero_di_strade_della_lista].seconda_piazza;
        else
            break;
        if (numero_di_piazze_del_grafo < strade[numero_di_strade_della_lista].prima_piazza)
            numero_di_piazze_del_grafo = strade[numero_di_strade_della_lista].prima_piazza;
        if (numero_di_piazze_del_grafo < strade[numero_di_strade_della_lista].seconda_piazza)
            numero_di_piazze_del_grafo = strade[numero_di_strade_della_lista].seconda_piazza;
    }
    
    inizializzatore_di_array_interi_monodimensionali(collocazione_temporanea);
    numero_di_lampioni_temporaneo = 0;
    inizializzatore_di_array_interi_bidimensionali(collocazioni);
    inizializzatore_di_array_interi_monodimensionali(numero_di_lampioni_delle_collocazioni);
    numero_di_collocazioni = 0;
    
    D(0);
    ordinatore_decrescente_di_coppie_di_array_interi(numero_di_lampioni_delle_collocazioni, collocazioni);
    
    cout << "\nEcco le distribuzioni di lampioni che permettono di illuminare ogni piazza del grafo e che non contano lampioni installati inutilmente, precedute dal relativo numero di lampioni:\n";
    visualizzatore_di_coppie_di_array_interi(numero_di_lampioni_delle_collocazioni, "Lampioni", collocazioni, 'n');
    
    cout << "\n\nL'uscita dalla sessione di risoluzione dell'esercizio 'Distribuzione di lampioni in un grafo di piazze' è avvenuta con successo.";
}

void D(int segnaposto)
{
    
    if ((mod == 1 and D_controlla_validita_piazze(collocazione_temporanea)) or (mod == 2 and D_controlla_validita_strade(collocazione_temporanea)) or (mod == 3 and D_controlla_validita_piazze(collocazione_temporanea) and D_controlla_validita_strade(collocazione_temporanea)))
    {
        if (numero_di_collocazioni == N)
        {
            cout << "\n########## Errore: Questo programma non supporta la risoluzione di questo esercizio! ##########\n\n";
            exit(-1);
        }
        eguagliatore_di_array_interi_monodimensionali(collocazioni[numero_di_collocazioni], collocazione_temporanea);
        numero_di_lampioni_delle_collocazioni[numero_di_collocazioni] = numero_di_lampioni_temporaneo;
        numero_di_collocazioni++;
        return;
    }
    
    for (int a = segnaposto; a < numero_di_piazze_del_grafo; a++)
    {
        collocazione_temporanea[numero_di_lampioni_temporaneo] = a + 1;
        numero_di_lampioni_temporaneo++;
        
        D(a + 1);
        
        numero_di_lampioni_temporaneo--;
        collocazione_temporanea[numero_di_lampioni_temporaneo] = 0;
    }
}

bool controlla_illuminazione_piazza(int collocazione[N], int piazza)
{
    for (int a = 0; a < numero_di_strade_della_lista; a++)
        if ((piazza == strade[a].prima_piazza and cercatore_di_valori_interi(collocazione, strade[a].seconda_piazza)) or (piazza == strade[a].seconda_piazza and cercatore_di_valori_interi(collocazione, strade[a].prima_piazza)) or cercatore_di_valori_interi(collocazione, piazza))
            goto next;
    return false;
next:
    return true;
}

bool controlla_illuminazione_strada(int collocazione[N], Strada strada)
{
    if (cercatore_di_valori_interi(collocazione, strada.prima_piazza) or cercatore_di_valori_interi(collocazione, strada.seconda_piazza))
        return true;
    else
        return false;
}

bool D_controlla_validita_piazze(int collocazione[N])
{
    
    for (int a = 1; a <= numero_di_piazze_del_grafo; a++)
        if (!controlla_illuminazione_piazza(collocazione, a))
            return false;
    
    int collocazione_modificata[N];
    int numero_di_lampioni_della_collocazione_modificata;
    for (int a = 0; a < N and collocazione[a]; a++)
    {
        inizializzatore_di_array_interi_monodimensionali(collocazione_modificata);
        numero_di_lampioni_della_collocazione_modificata = 0;
        for (int b = 0; b < N and collocazione[b]; b++)
            if (b != a)
            {
                collocazione_modificata[numero_di_lampioni_della_collocazione_modificata] = collocazione[b];
                numero_di_lampioni_della_collocazione_modificata++;
            }
        
        for (int a = 1; a <= numero_di_piazze_del_grafo; a++)
        {
            if (!controlla_illuminazione_piazza(collocazione_modificata, a))
                goto next;
        }
        return false;
    next:
        ;
    }
    
    return true;
}

bool D_controlla_validita_strade(int collocazione[N])
{
    
    for (int a = 0; a < numero_di_strade_della_lista; a++)
        if (!controlla_illuminazione_strada(collocazione, strade[a]))
            return false;
    
    int collocazione_modificata[N];
    int numero_di_lampioni_della_collocazione_modificata;
    for (int a = 0; a < N and collocazione[a]; a++)
    {
        inizializzatore_di_array_interi_monodimensionali(collocazione_modificata);
        numero_di_lampioni_della_collocazione_modificata = 0;
        for (int b = 0; b < N and collocazione[b]; b++)
            if (b != a)
            {
                collocazione_modificata[numero_di_lampioni_della_collocazione_modificata] = collocazione[b];
                numero_di_lampioni_della_collocazione_modificata++;
            }
        
        for (int a = 0; a < numero_di_strade_della_lista; a++)
        {
            if (!controlla_illuminazione_strada(collocazione_modificata, strade[a]))
                goto next;
        }
        return false;
    next:
        ;
    }
    
    return true;
}

void Vigenere()
{
  cout << "########## SESSIONE DI RISOLUZIONE DELL'ESERCIZIO 'VIGENERE' ##########\n\n";
  cout << "### NOTA PER L'UTENTE... ###\n";
  cout << "Assente";
  cout << "\n\n";

  char testo[50];
  char chiave[20];
  bool mod;
  cout << "Inserire la stringa da crittografare o decrittografare (senza spazi): ";
  cin >> testo;
  cout << "Inserire la chiave (senza spazi): ";
  cin >> chiave;
  cout << "Inserire 1 per crittografare, 0 per decrittografare: ";
  cin >> mod;

  if (mod) {
    char testo_crittografato[50];
    int k = 0; int j = 0;
    for (; testo[j] != '\0'; j++) {
      if (testo[j] + chiave[k] - 'a' > 'z')
        testo_crittografato[j] = testo[j] + chiave[k] - 'a' - ('z'-'a'+1);
      else testo_crittografato[j] = testo[j] + chiave[k] - 'a';
      k++;
      if (chiave[k] == '\0') k = 0;
    }
    testo_crittografato[j] = '\0';
    cout << "\nIl testo crittografato è: " << testo_crittografato;
  }
  else {
    char testo_decrittografato[50];
    int k = 0; int j = 0;
    for (; testo[j] != '\0'; j++) {
      if(testo[j] - chiave[k] + 'a' < 'a')
        testo_decrittografato[j] = testo[j] - chiave[k] + 'a' + ('z' - 'a' + 1);
      else testo_decrittografato[j] = testo[j] - chiave[k] + 'a';
      k++;
      if (chiave[k] == '\0') k = 0;
    }
    testo_decrittografato[j] = '\0';
    cout << "\nIl testo decrittografato è: " << testo_decrittografato;
  }
}