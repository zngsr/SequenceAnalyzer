#include <iostream>
#include <limits>
#include <chrono>
#include "DNASequence.hpp"
#include "FastaReader.hpp"
#include "ReportWriter.hpp"

// Clears the terminal screen using ANSI escape codes
void clearScreen(){
    std::cout << "\033[2J\033[1;1H";
}

// Displays the main interactive menu for the Sequence Analyzer
void displayMenu(){
    std::cout << "\n" << "╔═══════════════════════════════════════════╗" << std::endl;
    std::cout << "║            SEQUENCE ANALYZER              ║" << std::endl;
    std::cout << "║    Biologist by Degree / Dev by Design    ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
    std::cout << "  [1] Analyze New DNA Sequence" << std::endl;
    std::cout << "  [2] Analyze New .fasta/.fna DNA Sequence" << std::endl;
    std::cout << "  [3] Exit" << std::endl;
    std::cout << "─────────────────────────────────────────────" << std::endl;
    std::cout << " >> Choice: ";
}

// Main program loop handling user input, routing, and error management
int main(){
    int choice = 0;
    std::string userInput;
    std::string userPath;

    while(choice != 3){
        try{
            clearScreen();
            displayMenu();

            if(!(std::cin >> choice)){
                throw std::runtime_error("Invalid character input! Please use numbers only.");
            }

            if(choice < 1 || choice > 3){
                throw std::out_of_range("Selection out of menu range!");
            }

            // Formats long sequences by truncating the middle and showing only the ends
            auto formatSeq = [] (const std::string& s){
                if(s.length() > 160){
                    return s.substr(0, 80) + "\n      ... [" + std::to_string(s.length() - 160) + " bases hidden] ... \n      " + s.substr(s.length() - 80);
                }
                return s;
            };

            switch(choice){
                case 1:
                    clearScreen();
                    std::cout << "🧬 DNA Analysis Mode Active\n────────────────────────\n";
                    std::cout << "Enter DNA sequence to analyze: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, userInput);

                    {

                    DNASequence myDNA(userInput);

                    int countA = 0, countT = 0, countG = 0, countC = 0;
                    myDNA.getNucleotideCounts(countA, countT, countG, countC);

                    std::cout << "\n╔═══════════════════════════════════════════╗" << std::endl;
                    std::cout << "║           📊 ANALYSIS REPORT              ║" << std::endl;
                    std::cout << "╚═══════════════════════════════════════════╝" << std::endl;

                    std::cout << "  🧬 Sequence Information:" << std::endl;
                    std::cout << "  ├─ Length    : " << myDNA.getLength() << " bp" << std::endl;
                    std::cout << "  ├─ GC Content: %" << myDNA.calculateGCContent() << std::endl;
                    std::cout << "  ├─ Freq (A-T): A: " << countA << " | T: " << countT << std::endl;
                    std::cout << "  ├─ Freq (G-C): G: " << countG << " | C: " << countC << std::endl;
                    std::cout << "  └─ Original  : " << formatSeq(myDNA.orgSeq()) << std::endl;

                    std::cout << "\n  ⛓️  Strand Transformations:" << std::endl;
                    std::cout << "  ├─ Complement : " << formatSeq(myDNA.getComplement()) << std::endl;
                    std::cout << "  └─ Rev-Comp   : " << formatSeq(myDNA.reverseComplement()) << std::endl;

                    std::cout << "\n  🧪 Transcription (RNA):" << std::endl;
                    std::cout << "  ├─ Biological (Template): " << formatSeq(myDNA.transcribeFromTemplate()) << std::endl;
                    std::cout << "  └─ Standard (Coding): " << formatSeq(myDNA.transcribeToRNA()) << std::endl;

                    std::cout << "\n─────────────────────────────────────────────" << std::endl;
                    std::cout << " >> Press Enter to continue...";

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();

                    }

                    break;
                case 2: {
                    clearScreen();
                    std::cout << "📂 FASTA/FNA Analysis Mode Active\n────────────────────────\n";
                    std::cout << "Drag & drop file or enter path: ";
    
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, userPath);

                    auto start = std::chrono::high_resolution_clock::now();

                    FastaReader fasta(userPath);

                    std::cout << "\nReading file... please wait.\n";
                    std::string extractedSeq = fasta.readSeq();

                    DNASequence myDNA(std::move(extractedSeq));

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> ms_double = end - start;

                    int countA = 0, countT = 0, countG = 0, countC = 0;
                    myDNA.getNucleotideCounts(countA, countT, countG, countC);

                    std::cout << "\n╔═══════════════════════════════════════════╗" << std::endl;
                    std::cout << "║           📊 ANALYSIS REPORT              ║" << std::endl;
                    std::cout << "╚═══════════════════════════════════════════╝" << std::endl;

                    std::cout << "  ⏱️  Execution Time : " << ms_double.count() << " ms\n" << std::endl;

                    std::cout << "  🧬 Sequence Information:" << std::endl;
                    std::cout << "  ├─ Length    : " << myDNA.getLength() << " bp" << std::endl;
                    std::cout << "  ├─ GC Content: %" << myDNA.calculateGCContent() << std::endl;
                    std::cout << "  ├─ Freq (A-T): A: " << countA << " | T: " << countT << std::endl;
                    std::cout << "  ├─ Freq (G-C): G: " << countG << " | C: " << countC << std::endl;
                    std::cout << "  └─ Original  : " << formatSeq(myDNA.orgSeq()) << std::endl;

                    std::cout << "\n  ⛓️  Strand Transformations:" << std::endl;
                    std::cout << "  ├─ Complement : " << formatSeq(myDNA.getComplement()) << std::endl;
                    std::cout << "  └─ Rev-Comp   : " << formatSeq(myDNA.reverseComplement()) << std::endl;

                    std::cout << "\n  🧪 Transcription (RNA):" << std::endl;
                    std::cout << "  ├─ Biological (Template): " << formatSeq(myDNA.transcribeFromTemplate()) << std::endl;
                    std::cout << "  └─ Standard (Coding): " << formatSeq(myDNA.transcribeToRNA()) << std::endl;

                    char saveChoice;
                    std::cout << " >> Do you want to save the report? (y/N): ";
                    std::cin >> saveChoice;

                    if(saveChoice == 'y' || saveChoice == 'Y'){
                        std::string fileName;
                        std::cout << " >> Enter file name (e.g., result.txt): ";
                        std::cin >> fileName;

                        fileName.erase(fileName.find_last_not_of(" \t\r\n") + 1);

                        ReportWriter writer;
                        writer.saveReport(myDNA, fileName, countA, countT, countG, countC);
                    }

                    std::cout << "\n─────────────────────────────────────────────" << std::endl;
                    std::cout << " >> Press Enter to continue...";

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();

                    break;
                }
                case 3:
                    std::cout << "\nExiting Sequence Analyzer...\n";
                    break;
            }

        } catch (const std::runtime_error& e){
            std::cerr << "\n[ERROR]: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Press Enter to try again...";
            std::cin.get();
        } catch(const std::out_of_range& e){
            std::cerr << "\n[ERROR]: " << e.what() << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Press Enter to try again...";
            std::cin.get();
        }catch(const std::invalid_argument& e){
            std::cerr << "\n[ERROR]: " << e.what() << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Press Enter to try again...";
            std::cin.get();
        }catch(...){
            std::cerr << "\nAn unknown error occurred!" << std::endl;
        }
    }

    return 0;
}