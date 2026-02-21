#pragma once 

#include <string>

// A class to represent and analyze a single DNA sequence
class DNASequence {
    private:
        std::string sequence;
        int len;

        // Checks if the sequence contains only valid standard nucleotides (A, T, G, C).
        bool isValid() const;

    public:
        // Constructor 
        DNASequence(std::string seq);

        // Returns the original sequence automatically converted to uppercase.
        std::string orgSeq() const;

        // Method to get sequence length
        int getLength() const;

        // Calculates the GC content percentage
        double calculateGCContent() const;

        // Generates the complementary DNA strand (A->T, T->A, G->C, C->G)
        std::string getComplement() const;

        // Biological Transcription: Builds mRNA from the template strand (A->U, T->A, G->C, C->G)
        std::string transcribeFromTemplate() const;

        // Standard Bioinformatics Transcription: Assumes the coding strand and replaces T with U
        std::string transcribeToRNA() const;

        // Generates the reverse complement of the DNA sequence (5'->3' to 3'->5')
        std::string reverseComplement() const;
};