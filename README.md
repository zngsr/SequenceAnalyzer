# Sequence Analyzer 🧬💻

*(Scroll down for Turkish 🇹🇷)*

🇬🇧 **English**

A powerful, console-based (CLI) bioinformatics engine built with **C++** and **Object-Oriented Programming (OOP)**. Designed to handle large genomic datasets, this tool bridges the gap between biology and software engineering by performing rapid biological transformations and sequence analyses directly from the terminal.

### 📊 Project Status: Stable / Maintenance

> The core functionality of the Sequence Analyzer is now **complete**. The project has reached its v2.0.0 milestone and is currently in maintenance mode. Active feature development is paused, but the repository will be actively maintained for bug fixes and stability improvements.

### 🛠️ Features (v2.0.0)

* **High-Performance File I/O:** Reads massive `.fasta` and `.fna` files in milliseconds, automatically cleaning trailing spaces and invalid characters.
* **Automated Report Generation:** Exports analysis results into neatly formatted `.txt` files in the Documents folder, adhering to the standard 80-character FASTA format.
* **Execution Timer:** Built-in benchmarking to track processing speeds of large genomes.
* **Advanced Sequence Statistics:** Calculates total sequence length, GC (Guanine-Cytosine) content percentage, and exact nucleotide frequencies (A, T, G, C counts).
* **Strand Generation:** Instantly generates Complementary and Reverse Complementary sequences.
* **Dual-Engine Transcription:** 
  * *Biological Transcription:* Synthesizes mRNA from the template strand.
  * *Standard Bioinformatics Transcription:* Direct T -> U conversion from the coding strand.

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

Biyoloji bilimini ve yazılım dünyasını birleştiren, **C++** ve **Nesne Yönelimli Programlama (OOP)** mimarisi üzerine kurulu yüksek performanslı bir biyoinformatik konsol (CLI) motorudur. Büyük genomik veri setlerini işlemek üzere tasarlanan bu araç, temel biyolojik dönüşümleri saniyeler içinde doğrudan terminal üzerinden gerçekleştirir.

### 📊 Proje Durumu: Kararlı Sürüm / Bakım Modu

Sequence Analyzer'ın planlanan temel özellikleri **tamamlanmıştır**. Proje v2.0.0 sürümüne ulaşmış olup, aktif yeni özellik geliştirme süreci şimdilik duraklatılmıştır. Ancak, keşfedilen hataların (bug) çözümü ve sistem kararlılığının artırılması için proje aktif olarak bakıma devam edecektir.

### 🛠️ Özellikler (v2.0.0)

* **Yüksek Performanslı Dosya Okuma:** Devasa `.fasta` ve `.fna` dosyalarını milisaniyeler içinde okur, boşlukları ve geçersiz karakterleri otomatik temizler.
* **Otomatik Rapor Üretimi:** Analiz sonuçlarını uluslararası 80-karakterlik FASTA standardına uygun olarak Belgeler klasörüne `.txt` formatında kaydeder.
* **Kronometre (Benchmark):** Büyük genomların işlenme hızını ölçen entegre süre ölçer.
* **Gelişmiş Dizi İstatistikleri:** Toplam uzunluk ve GC oranının yanı sıra, net nükleotid frekanslarını (A, T, G, C sayıları) hesaplar.
* **İplik Üretimi:** Verilen sekansın Tamamlayıcı (Complement) ve Ters-Tamamlayıcı (Reverse Complement) dizilimlerini oluşturur.
* **Çift Motorlu Transkripsiyon:** 
  * *Biyolojik Transkripsiyon:* Kalıp iplikten mRNA sentezler.
  * *Standart Biyoinformatik Transkripsiyon:* Anlamlı iplikten doğrudan T -> U dönüşümü yapar.

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