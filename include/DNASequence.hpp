#pragma once // Prevents multiple inclusions / Dosyanın birden fazla kez dahil edilmesini önler

#include <string>

// DNA Sequence Class / DNA Dizilimi Sınıfı
class DNASequence {
    private:
        // Attributes (Variables) / Özellikler (Değişkenler)
        std::string sequence;

    public:
        // Constructor / Yapıcı Metot
        // Initializes the object / Nesneyi başlatır
        DNASequence(std::string seq);

        // Method to get sequence length / Dizilim uzunluğunu alma metodu
        int getLength();
};