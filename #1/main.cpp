#include <iostream>
#include <string>
using namespace std;

 struct Struttura_Solfeggio {
    string nome_nota;
    int indice;
};

/*Attenzione in c++ non si puo creare un array che contenga elementi di tipi diversi
my_array = [1, "A", 2, "B", 3, "C"]*/

 void note(string nota_cromatica, string nota_solfetto) {
    string scala_cromatica[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    // Ottengo dimensione divideno i byte array divso byte singolo elemento
    int size_scala_cromatica = sizeof(scala_cromatica) / sizeof(scala_cromatica[0]);
    Struttura_Solfeggio mappa_solfeggi[] =
        {{"Do", 0},
         {"Re", 2},
         {"Mi", 4},
         {"Fa", 5},
         {"So", 7},
         {"La", 9},
         {"Ti", 11}};
    int size_mappa_solfeggi = sizeof(mappa_solfeggi) / sizeof(mappa_solfeggi[0]);
    int indice_nota_cromatica_inserita;
    int indice_nota_solfetto_inserita;
    bool trovato_nota_crom = false;
    bool trovato_nota_solf = false;
    for (int i = 0; i < size_scala_cromatica; i++) {
        if (scala_cromatica[i] == nota_cromatica) {
            trovato_nota_crom = true;
            indice_nota_cromatica_inserita = i;
            break;
        }
    }
     if (!trovato_nota_crom) {
        cout << "Nota cromatica non valida! Per fadore controlla input" << endl;
        return;
    }

    for (int i = 0; i < size_mappa_solfeggi; i++) {
        if (mappa_solfeggi[i].nome_nota == nota_solfetto) {
            trovato_nota_solf= true;
            indice_nota_solfetto_inserita = mappa_solfeggi[i].indice;
            break;
        }
    }
     if (!trovato_nota_solf) {
        cout << "Nota solfège non valida! Per favore controlla input" << endl;
        return;
    }
    /*Attenzion  somma in modulo 12*/
     int indice_nota_finale = (indice_nota_cromatica_inserita + indice_nota_solfetto_inserita) % size_scala_cromatica;
    cout << "La nota corrispondente è: " << scala_cromatica[indice_nota_finale] << endl;
}
 int main() {
    note("C", "Do");
    note("C", "Re");
    note("C", "Mi");
    note("D", "Mi");
    note("A#", "Fa");
     return 0;
}