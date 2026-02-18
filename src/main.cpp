#include <iostream>
#include "DNASequence.hpp"

int main(){
    // Create a DNASequence object 
    DNASequence myDNA("ATGCGTACGTTAG");

    std::cout << "--- Sequence Analyzer Result ---" << std::endl;
    std::cout << "Original Sequence: ATGCGTACGTTAG" << std::endl;
    std::cout << "Sequence Length: " << myDNA.getLength() << " bp" << std::endl;
    std::cout << "GC Content: " << myDNA.calculateGCContent() << " %" << std::endl;
    std::cout << "Complementary Strand: " << myDNA.getComplement() << std::endl;
    std::cout << "RNA (From Template): " << myDNA.transcribeFromTemplate() << std::endl;
    std::cout << "RNA (Standard): " << myDNA.transcribeToRNA() << std::endl;

    // Generate and display the reverse complement of the sequence
    std::cout << "Reverse Complementary Strand: " << myDNA.reverseComplement() << std::endl;
    
    return 0;
}