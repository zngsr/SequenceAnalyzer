#pragma once

#include <fstream>
#include <string>

class FastaReader{
    private:
        std::string sequence = "";
        std::ifstream Fasta;
    public:
        // Opens the FASTA file and checks if it exists 
        FastaReader(const std::string& fPath);

        // Closes the file stream safely when done
        ~FastaReader();

        // Parses the file, skips headers, cleans whitespace, and returns the full sequence
        std::string readSeq();
};