#include "DNASequence.hpp" // Include the header file / Başlık dosyasını dahil et

// Constructor implementation / Yapıcı metot uygulaması
DNASequence::DNASequence(std::string seq){
    sequence = seq;
}

// getLength implementation / getLength uygulaması
int DNASequence::getLength(){
    return sequence.length();
}

double DNASequence::calculateGCContent(){
    double GC = 0;
    for(int i = 0; i < sequence.length(); i++){
        if(sequence[i] == 'G' || sequence[i] == 'C'){
            GC++;
        }
    }
    return (GC / double(sequence.length())) * 100;
}