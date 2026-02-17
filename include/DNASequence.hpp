#pragma once 

#include <string>

// A class to represent and analyze a single DNA sequence
class DNASequence {
    private:
        std::string sequence;

    public:
        // Constructor 
        DNASequence(std::string seq);

        // Method to get sequence length
        int getLength();

        // Calculates the GC content percentage
        double calculateGCContent();

        // Generates the complementary DNA strand (A->T, T->A, G->C, C->G)
        std::string getComplement();
};