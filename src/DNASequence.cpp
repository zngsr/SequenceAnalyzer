#include "DNASequence.hpp" 

// Constructor 
DNASequence::DNASequence(std::string seq){
    sequence = seq;
}

// Returns the total number of nucleotides
int DNASequence::getLength(){
    return sequence.length();
}

// Calculates the percentage of Guanine and Cytosine in the sequence
double DNASequence::calculateGCContent(){
    double GC = 0;
    for(int i = 0; i < sequence.length(); i++){
        if(sequence[i] == 'G' || sequence[i] == 'C'){
            GC++;
        }
    }
    return (GC / double(sequence.length())) * 100;
}

// Generates the complementary DNA strand (A->T, T->A, G->C, C->G)
std::string DNASequence::getComplement(){
    std::string complement = "";
    for(int i = 0; i < sequence.length(); i++){
        if(sequence[i] == 'A'){
            complement += 'T';
        }
        else if(sequence[i] == 'T'){
            complement += 'A';
        }
        else if(sequence[i] == 'G'){
            complement += 'C';
        }
        else if(sequence[i] == 'C'){
            complement += 'G';
        }
    }
    return complement;
}