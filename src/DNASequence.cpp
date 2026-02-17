#include "DNASequence.hpp" // Include the header file / Başlık dosyasını dahil et

// Constructor implementation / Yapıcı metot uygulaması
DNASequence::DNASequence(std::string seq){
    sequence = seq;
}

// getLength implementation / getLength uygulaması
int DNASequence::getLength(){
    return sequence.length();
}