#include <iostream>
#include "DNASequence.hpp"

int main(){
    // Create a DNASequence object / Bir DNASequence nesnesi oluştur
    DNASequence myDNA("ATGCGTACGTTAG");

    // Print the length / Uzunluğu ekrana yazdır
    std::cout << "DNA Sequence: 'ATGCGTACGTTAG'" << std::endl;
    std::cout << "DNA Sequence Length: " << myDNA.getLength() << std::endl;
    std::cout << "GC Content: " << myDNA.calculateGCContent() << std::endl;
    
    return 0;
}