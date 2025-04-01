/*
Nome, cognome e matricola: Cael Kyler Padilla | 307931
Esercitazione_1_IO Exercise2

Nota dello studente: sono consapevole del fatto che il codice è commentato passo per passo e potrebbe risultare troppo;
per scopi didattici, ed essendo i primi codici nel linguaggio cpp, preferisco spiegarmi ogni passaggio che faccio
anche per aiutarmi ad ottimizzare il codice in una forma più corto ed efficiente.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
Per mappare un punto x dell'intervallo [a,b]=[1,5] ad un punto y dell'intervallo [c,d]=[-1,2]
usiamo la formula seguente: y= c+ (((x-a)/(b-a)))*(d-c)= -1 + ((x-1)/4)*3 .

Quindi scrivo una funzione che svolge tale mappatura.
*/

double map(double x) {
    double mappedVal = -1 + (x-1) * 3/4 ;
    return mappedVal;
}

// MAIN

int main() {
    // per comodità mi salvo nel infileName il nome del file che mi serve

    std::string infileName = "data.txt";
    std::ifstream infile(infileName);    // apro il file in modalità lettura


    // è bene controllare che il file si apra correttamente; se non si apre, allora segnalo l'errore

    if (!infile.is_open()) {
        std:: cerr << "Il file non si apre correttamente." << std::endl;   // un messaggio che indica che il file non si apre bene
        return 1;   // mi segnala che il file non si apre bene
    }

    //Dato che i risultati devono essere stampati su un file result.txt, creo il file e ci scrivo già gli header.

    std::string  outfileName = "result.txt";
    std::ofstream outfile(outfileName);   //apro il file in writing mode

    if (!outfile.is_open()) {
        std:: cerr << "Il file non si apre correttamente." << std::endl;   // un messaggio che indica che il file non si apre bene
        return 1;   // mi segnala che il file non si apre bene
    }

    outfile << "# N Mean" << std::endl;   //header


    /*
    Ora leggo il valore di ogni riga in formato double;
    Lo mappo con la funzione 'map';
    Lo raccolgo in un vettore.
    */

    std::vector<double> valList;   //valList è un vector o lista di valori double
    std::string line;

    while (getline(infile, line)) {

        double val = std::stod(line);   //trasforma il valore di ogni riga in double
        double valFin = map(val);   //uso la funzione map per mappare un valore val nel nuovo intervallo
        valList.push_back(valFin);   //aggiunge nel vector valList il valore mappato valFin 
    }

    infile.close();   //La inFile non mi serve più, per cui la chiudo.

    /*
    Ora che ho la vector di valori mappati, posso calcolare la media secondo le istruzioni;
    Stampare sul outFile ogni risultato.
    */

    double sum = 0.0;   // è la somma dei primi i valori della lista per ogni i

    for (size_t i = 0; i <valList.size(); ++i) {
        sum += valList[i];
        double mean = sum/ (i+1);

        outfile << i+1 << " " << std::scientific << mean << std::endl;
    }

    outfile.close();   //ricordo di chiudere l'outFile

    return 0;
}
