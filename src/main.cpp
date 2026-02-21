#include <iostream>
#include <limits>
#include "DNASequence.hpp"

void clearScreen(){
    std::cout << "\033[2J\033[1;1H";
}

void displayMenu(){
    std::cout << "\n" << "╔═══════════════════════════════════════════╗" << std::endl;
    std::cout << "║            SEQUENCE ANALYZER              ║" << std::endl;
    std::cout << "║    Biologist by Degree / Dev by Design    ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
    std::cout << "  [1] Analyze New DNA Sequence" << std::endl;
    std::cout << "  [2] Exit" << std::endl;
    std::cout << "─────────────────────────────────────────────" << std::endl;
    std::cout << " >> Choice: ";
}

int main(){
    int choice = 0;
    std::string userInput;

    while(choice != 2){
        try{
            clearScreen();
            displayMenu();

            if(!(std::cin >> choice)){
                throw std::runtime_error("Invalid character input! Please use numbers only.");
            }

            if(choice < 1 || choice > 2){
                throw std::out_of_range("Selection out of menu range!");
            }

            switch(choice){
                case 1:
                    clearScreen();
                    std::cout << "🧬 DNA Analysis Mode Active\n────────────────────────\n";
                    std::cout << "Enter DNA sequence to analyze: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, userInput);

                    {

                    DNASequence myDNA(userInput);

                    std::cout << "\n╔═══════════════════════════════════════════╗" << std::endl;
                    std::cout << "║           📊 ANALYSIS REPORT              ║" << std::endl;
                    std::cout << "╚═══════════════════════════════════════════╝" << std::endl;

                    std::cout << "  🧬 Sequence Information:" << std::endl;
                    std::cout << "  ├─ Original  : " << myDNA.orgSeq() << std::endl;
                    std::cout << "  ├─ Length    : " << myDNA.getLength() << " bp" << std::endl;
                    std::cout << "  └─ GC Content: %" << myDNA.calculateGCContent() << std::endl;

                    std::cout << "\n  ⛓️  Strand Transformations:" << std::endl;
                    std::cout << "  ├─ Complement : " << myDNA.getComplement() << std::endl;
                    std::cout << "  └─ Rev-Comp   : " << myDNA.reverseComplement() << std::endl;

                    std::cout << "\n  🧪 Transcription (RNA):" << std::endl;
                    std::cout << "  ├─ Biological (Template): " << myDNA.transcribeFromTemplate() << std::endl;
                    std::cout << "  └─ Standard (Coding): " << myDNA.transcribeToRNA() << std::endl;

                    std::cout << "\n─────────────────────────────────────────────" << std::endl;
                    std::cout << " >> Press Enter to continue...";

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();

                    }

                    break;
                case 2:
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