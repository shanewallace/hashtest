/**

The provided source code is a program that generates and iterates through all possible byte combinations. 
It calculates the SHA-256 hash value for each combination and keeps track of the smallest hash value found along with the corresponding byte sequence.

**/    



#include <iostream>
#include <iomanip>
#include <vector>
#include <openssl/sha.h>

std::string sha256(const std::vector<unsigned char>& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256Context;
    SHA256_Init(&sha256Context);
    SHA256_Update(&sha256Context, data.data(), data.size());
    SHA256_Final(hash, &sha256Context);

    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (unsigned char c : hash) {
        ss << std::setw(2) << static_cast<int>(c);
    }

    return ss.str();
}

void printResult(const std::string& smallestHash, const std::vector<unsigned char>& sequence) {
    std::cout << smallestHash << "\t";
    for (unsigned char c : sequence) {
        std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(c);
    }
    std::cout << std::dec << std::endl;
}

void iterateBytes(const std::vector<unsigned char>& latestSequence) {
    std::string smallestHash;
    std::vector<unsigned char> sequence = latestSequence;

    while (true) {
        std::string hash = sha256(sequence);
        if (smallestHash.empty() || hash < smallestHash) {
            smallestHash = hash;
            printResult(smallestHash, sequence);
        }

        // Increment the sequence
        int i = sequence.size() - 1;
        while (i >= 0 && ++sequence[i] == 0) {
            --i;
        }

        // Exit the loop if all combinations have been generated
        if (i < 0) {
            break;
        }
    }
}

int main() {
    std::string latestSequence;
    std::cout << "Enter the latest sequence (leave empty for fresh start): ";
    std::getline(std::cin, latestSequence);

    std::vector<unsigned char> latestSequenceBytes;
    for (size_t i = 0; i < latestSequence.length(); i += 2) {
        std::string byteString = latestSequence.substr(i, 2);
        unsigned char byte = static_cast<unsigned char>(std::stoi(byteString, nullptr, 16));
        latestSequenceBytes.push_back(byte);
    }

    iterateBytes(latestSequenceBytes);

    return 0;
}
