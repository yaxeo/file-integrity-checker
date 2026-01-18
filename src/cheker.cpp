#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

std::string sha256(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file) return "";

    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    char buffer[1024];
    while (file.good()) {
        file.read(buffer, sizeof(buffer));
        SHA256_Update(&ctx, buffer, file.gcount());
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &ctx);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];

    return ss.str();
}

int main() {
    std::string filePath;
    std::string savedHash;
    std::string currentHash;

    std::cout << "Enter file path: ";
    std::cin >> filePath;

    currentHash = sha256(filePath);
    if (currentHash.empty()) {
        std::cout << "Error reading file.\n";
        return 1;
    }

    std::ifstream baseline("hashes/baseline.txt");
    if (baseline.good()) {
        baseline >> savedHash;
        if (savedHash == currentHash)
            std::cout << "File integrity OK.\n";
        else
            std::cout << "WARNING: File has been modified!\n";
    } else {
        std::ofstream out("hashes/baseline.txt");
        out << currentHash;
        std::cout << "Baseline hash created.\n";
    }

    return 0;
}
