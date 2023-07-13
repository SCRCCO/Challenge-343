#ifndef struttura_h
#define struttura_h
 #include <string>
 struct Struttura_Solfeggio {
    std::string nome_nota;
    int indice;
};
void note(std::string nota_cromatica, std::string nota_solfetto);
 #endif