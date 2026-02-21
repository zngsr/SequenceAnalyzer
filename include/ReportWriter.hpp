#pragma once

#include "DNASequence.hpp"
#include <fstream>
#include <string>

class ReportWriter {
    private:
    public:
        // Saves the sequence analysis results and 80-character FASTA blocks to a text file
        void saveReport(const DNASequence& dna, const std::string& fileName, int a, int t, int g, int c);
};