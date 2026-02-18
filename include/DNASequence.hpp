#pragma once 

#include <string>

// A class to represent and analyze a single DNA sequence
class DNASequence {
    private:
        std::string sequence;
        int len;

    public:
        // Constructor 
        DNASequence(std::string seq);

        // Method to get sequence length
        int getLength();

        // Calculates the GC content percentage
        double calculateGCContent();

        // Generates the complementary DNA strand (A->T, T->A, G->C, C->G)
        std::string getComplement();

        // Biological Transcription: Builds mRNA from the template strand (A->U, T->A, G->C, C->G)
        std::string transcribeFromTemplate();

        // Standard Bioinformatics Transcription: Assumes the coding strand and replaces T with U
        std::string transcribeToRNA();
};