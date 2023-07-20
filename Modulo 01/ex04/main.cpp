#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char* av[])
{
    if (ac != 4) {
        std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream inputFile(filename.c_str());  // c_str ritorna un puntatore a stringa con carattere nullo finale, senza non va
    if (!inputFile)
    {
        std::cerr << "Error opening the input file." << std::endl;
        return 1;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str()); // c_str ritorna un puntatore a stringa con carattere nullo finale, senza non va
    if (!outputFile)
    {
        std::cerr << "Error creating or opening the output file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) // leggiamo il file riga per riga
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) // con line.find cerchiamo s1 nella riga(line). Se la trova entriamo dentro e cambiamo s1 con s2. Find riporta il nuovo indice dove sta s1 o npos.
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length()); // sottostringa prima di s1 + s2 + sottostringa dopo s1 fino al termine.
            pos += s2.length(); // avendo cambiato line dobbiamo smuovere la posizione della lunghezza di s2.
        }
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Replacement done" << std::endl;
    return 0;
}