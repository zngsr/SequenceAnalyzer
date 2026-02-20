#include "DNASequence.hpp"
#include <algorithm> 
#include <cctype>

// Constructor 
DNASequence::DNASequence(std::string seq){
    std::transform(seq.begin(), seq.end(), seq.begin(), ::toupper);
    sequence = seq;
    len = sequence.length();
}

// Return the original toupper sequence
std::string DNASequence::orgSeq(){
    return sequence;
}

// Returns the total number of nucleotides
int DNASequence::getLength(){
    return len;
}

// Calculates the percentage of Guanine and Cytosine in the sequence
double DNASequence::calculateGCContent(){
    double GC = 0;
    for(int i = 0; i < len; i++){
        if(sequence[i] == 'G' || sequence[i] == 'C'){
            GC++;
        }
    }
    return (GC / double(len)) * 100;
}

// Generates the complementary DNA strand (A->T, T->A, G->C, C->G)
std::string DNASequence::getComplement(){
    std::string complement = "";
    for(int i = 0; i < len; i++){
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

// Biological Transcription: Transcribes the DNA sequence to mRNA using the template strand
std::string DNASequence::transcribeFromTemplate(){
    std::string mRNA = "";

    for(int i = 0; i < len; i++){
        if(sequence[i] == 'A'){
            mRNA += 'U';
        }
        else if(sequence[i] == 'T'){
            mRNA += 'A';
        }
        else if(sequence[i] == 'G'){
            mRNA += 'C';
        }
        else if(sequence[i] == 'C'){
            mRNA += 'G';
        }
    }
    return mRNA;
}

// Standard Transcription: Converts the coding strand directly to mRNA (Replaces T with U)
std::string DNASequence::transcribeToRNA(){
    std::string mRNA = "";

    for(int i = 0; i < len; i++){
        if(sequence[i] == 'T'){
            mRNA += 'U';
        }
        else{
            mRNA += sequence[i];
        }
    }
    return mRNA;
}

// Generates the reverse complement by first getting the complement and then reversing the string
std::string DNASequence::reverseComplement(){
    std::string revComplement = "";

    revComplement = getComplement();
    std::reverse(std::begin(revComplement), std::end(revComplement));
    return revComplement;
}