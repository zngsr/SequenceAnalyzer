# Sequence Analyzer 🧬💻

*(Scroll down for Turkish 🇹🇷)*

🇬🇧 **English**

A console-based (CLI) bioinformatics engine built with **C++** and **Object-Oriented Programming (OOP)**, designed to bridge the gap between biology and software development. This project takes raw DNA sequences and performs essential biological transformations and analyses.

### 🛠️ Features (v1.0.0)
* **Basic Analysis:** Calculates total sequence length and GC (Guanine-Cytosine) content percentage.
* **Strand Generation:** Generates Complementary and Reverse Complementary sequences.
* **Dual-Engine Transcription:** * *Biological Transcription:* Synthesizes mRNA from the template strand (A->U, T->A, G->C, C->G).
  * *Standard Bioinformatics Transcription:* Direct T -> U conversion from the coding strand.

### 🚀 Roadmap (Upcoming Features)
- [ ] Interactive terminal menu for real-time sequence input via `std::cin`.
- [ ] File parsing modules to read sequences directly from `.fasta` and `.txt` files.
- [ ] Advanced sequence validation to ensure only valid nucleotides (A, T, G, C) are processed.
- [ ] **Long-Term Goal:** Transform the engine into a full-fledged Graphical User Interface (GUI) desktop application using **wxWidgets**.

### ⚙️ How to Build and Run

**Method 1: Using CMake (Recommended)**
This project uses CMake as its primary build system.
```bash
git clone https://github.com/zngsr/SequenceAnalyzer.git
cd SequenceAnalyzer
mkdir build && cd build
cmake ..
make
./SequenceAnalyzer
```

**Method 2: Quick Compile (Using g++)**
If you don't have CMake installed, you can compile the source files directly (C++20 or higher required).
```bash
git clone https://github.com/zngsr/SequenceAnalyzer.git
cd SequenceAnalyzer
g++ -std=c++20 main.cpp DNASequence.cpp -o SequenceAnalyzer
./SequenceAnalyzer
```

---

🇹🇷 **Türkçe**

Biyoloji bilimini ve yazılım dünyasını birleştirme hedefiyle geliştirilen, **C++** ve **Nesne Yönelimli Programlama (OOP)** mimarisi üzerine kurulu bir biyoinformatik konsol (CLI) uygulamasıdır. Bu proje, ham DNA dizilerini alarak temel biyolojik dönüşümleri ve analizleri gerçekleştirir.

### 🛠️ Özellikler (v1.0.0)
* **Temel Analiz:** DNA dizilerinin toplam uzunluğunu ve GC (Guanin-Sitozin) içeriğini yüzdelik olarak hesaplar.
* **İplik Üretimi:** Verilen sekansın Tamamlayıcı (Complement) ve Ters-Tamamlayıcı (Reverse Complement) dizilimlerini oluşturur.
* **Çift Motorlu Transkripsiyon:** * *Biyolojik Transkripsiyon:* Kalıp iplikten (Template Strand) eşleşme yoluyla mRNA sentezler.
  * *Standart Biyoinformatik Transkripsiyon:* Anlamlı iplikten (Coding Strand) doğrudan T -> U dönüşümü yapar.

### 🚀 Yol Haritası (Gelecek Planları)
- [ ] Kullanıcıdan anlık sekans girdisi alabilen interaktif terminal menüsü.
- [ ] Gerçek genom verilerini işlemek için `.fasta` ve `.txt` formatında dosya okuma modülleri.
- [ ] Sadece geçerli nükleotidlerin (A, T, G, C) girildiğini denetleyen validasyon sistemi.
- [ ] **Uzun Vadeli Hedef:** **wxWidgets** kütüphanesini kullanarak motoru modern bir Grafik Kullanıcı Arayüzüne (GUI) sahip bir masaüstü uygulamasına dönüştürmek.

### ⚙️ Kurulum ve Çalıştırma

**Yöntem 1: CMake ile (Önerilen)**
Bu proje ana derleme sistemi olarak CMake kullanmaktadır ve kesinlikle **C++20 veya üzeri** bir standart gerektirir (alt sürümler desteklenmemektedir).
```bash
git clone https://github.com/zngsr/SequenceAnalyzer.git
cd SequenceAnalyzer
mkdir build && cd build
cmake ..
make
./SequenceAnalyzer
```

**Yöntem 2: Hızlı Derleme (g++ ile)**
Eğer sisteminizde CMake kurulu değilse, kaynak dosyalarını doğrudan derleyebilirsiniz (C++20 veya üzeri gereklidir).
```bash
git clone https://github.com/zngsr/SequenceAnalyzer.git
cd SequenceAnalyzer
g++ -std=c++20 main.cpp DNASequence.cpp -o SequenceAnalyzer
./SequenceAnalyzer
```

---
*Biologist by Degree, Developer by Design.*
**[Zeng Sarı](https://www.zengsari.com)**