#include "FastaReader.hpp"
#include <fstream>
#include <string>
#include <stdexcept>
#include <algorithm>

// Constructor: Opens the file and throws an error if it fails
FastaReader::FastaReader(const std::string& fPath){
    Fasta.open(fPath);
    if(!Fasta.is_open()){
        throw std::runtime_error("File could not be found or opened: " + fPath);
    }
}

// Destructor: Closes the file stream when the object is destroyed
FastaReader::~FastaReader(){
    Fasta.close();
}

// Parses the FASTA file, skipping headers and removing whitespace/returns
std::string FastaReader::readSeq(){
    std::string seq = "";
    while(std::getline(Fasta, seq)){
        if(!(seq.empty()) && seq[0] != '>'){
            if(seq.back() == '\r'){
                seq.pop_back();
            }
            seq.erase(std::remove(seq.begin(), seq.end(), ' '), seq.end());
            sequence += seq;
        }
    }
    return sequence;
}
