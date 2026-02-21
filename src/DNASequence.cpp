#include "DNASequence.hpp"
#include <algorithm> 
#include <cctype>
#include <stdexcept>

// Initializes the sequence, converts to uppercase, and validates it
DNASequence::DNASequence(std::string seq){
    std::transform(seq.begin(), seq.end(), seq.begin(), ::toupper);
    sequence = std::move(seq);

    if(isValid() == false){
        throw std::invalid_argument("Invalid nucleotide detected! Only A, T, G, C are allowed.");
    }

    len = sequence.length();
}

// Validates the sequence using early return for maximum performance.
bool DNASequence::isValid() const{
    for(char n : this ->sequence){
        if(n != 'A' && n != 'T' && n != 'G' && n != 'C'){
            return false;
        }
    }
    return true;
}

// Returns the formatted sequence for display purposes.
std::string DNASequence::orgSeq() const{
    return sequence;
}

// Returns the total number of nucleotides
int DNASequence::getLength() const{
    return len;
}

// Calculates the percentage of Guanine and Cytosine in the sequence
double DNASequence::calculateGCContent() const{
    double GC = 0;
    for(int i = 0; i < len; i++){
        if(sequence[i] == 'G' || sequence[i] == 'C'){
            GC++;
        }
    }
    return (GC / double(len)) * 100;
}

// Counts and assigns the total number of A, T, G, and C nucleotides
void DNASequence::getNucleotideCounts(int& a, int& t, int& g, int& c){
    for(char n : this -> sequence){
        if(n == 'A') a++;
        else if(n == 'T') t++;
        else if(n == 'G') g++;
        else if(n == 'C') c++;
    }
}

// Generates the complementary DNA strand (A->T, T->A, G->C, C->G)
std::string DNASequence::getComplement() const{
    std::string complement = "";
    complement.reserve(len);
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
std::string DNASequence::transcribeFromTemplate() const{
    std::string mRNA = "";
    mRNA.reserve(len);

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
std::string DNASequence::transcribeToRNA() const{
    std::string mRNA = "";
    mRNA.reserve(len);

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
std::string DNASequence::reverseComplement() const{
    std::string revComplement = getComplement();

    std::reverse(std::begin(revComplement), std::end(revComplement));
    return revComplement;
}