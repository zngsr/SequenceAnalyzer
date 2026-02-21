#include "ReportWriter.hpp"
#include "DNASequence.hpp"
#include <fstream>
#include <filesystem>
#include <string>
#include <iostream>
#include <cstdlib>

// Generates and saves a detailed sequence report to the user's Documents folder
void ReportWriter::saveReport(const DNASequence& dna, const std::string& fileName, int a, int t, int g, int c){
    std::string targetFolder;

    const char* homeDir = std::getenv("HOME");

    if (homeDir != nullptr){
        targetFolder = std::string(homeDir) + "/Documents/SequenceReports/";
    }
    else{
        targetFolder = "./SequenceReports/";
    }

    if(!std::filesystem::exists(targetFolder)){
        std::filesystem::create_directories(targetFolder);
    }

    std::string fullPath = targetFolder + fileName;
    
    std::ofstream report(fullPath);

    if(report.is_open()){
        report << "--- SEQUENCE ANALYSIS REPORT ---\n";
        report << "========================================\n";
        report << "    Sequence Information:\n";
        report << "  - Length    : " << dna.getLength() << " bp\n";
        report << "  - GC Content: %" << dna.calculateGCContent() << std::endl;
        report << "  - Freq (A-T): A: " << a << " | T: " << t << std::endl;
        report << "  - Freq (G-C): G: " << g << " | C: " << c << std::endl;
        report << "========================================\n";
        
        // Formats and writes the given sequence in standard 80-character FASTA blocks
        auto writeFasta = [&report](const std::string& header, const std::string& seq){
            report << ">" << header << "\n";
            for(size_t i = 0; i < seq.length(); i += 80){
                report << seq.substr(i, 80) << "\n";
            }
            report << "\n";
        };

        writeFasta("Original_Sequence", dna.orgSeq());
        writeFasta("Complement", dna.getComplement());
        writeFasta("Reverse_Complement", dna.reverseComplement());
        writeFasta("Transcribed_RNA_Biological_Template", dna.transcribeFromTemplate());
        writeFasta("Transcribed_RNA_Standard_Coding", dna.transcribeToRNA());
        
        report.close();
        std::cout << "\n============================================\n";
        std::cout << " ✅ SUCCESS! Report gracefully saved to:\n";
        std::cout << " 📂 " << fullPath << "\n";
        std::cout << "============================================\n" << std::endl;
    }
    else {
        std::cerr << "❌ Error: Could not create the file!" << std::endl;
    }
}