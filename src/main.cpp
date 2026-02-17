#include <iostream>
#include "DNASequence.hpp"

int main(){
    // Create a DNASequence object 
    DNASequence myDNA("ATGCGTACGTTAG");

    std::cout << "--- Sequence Analyzer Result ---" << std::endl;
    std::cout << "Original Sequence: ATGCGTACGTTAG" << std::endl;
    std::cout << "Sequence Length: " << myDNA.getLength() << " bp" << std::endl;
    std::cout << "GC Content: " << myDNA.calculateGCContent() << " %" << std::endl;

    // Test the newly added Complementary Strand function
    std::cout << "Complementary Strand: " << myDNA.getComplement() << std::endl;
    
    return 0;
}