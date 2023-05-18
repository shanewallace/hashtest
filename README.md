# hashtest
## Program Explanation

The provided source code is a program that generates and iterates through all possible byte combinations. It calculates the SHA-256 hash value for each combination and keeps track of the smallest hash value found along with the corresponding byte sequence.

### sha256 Function

The `sha256` function calculates the SHA-256 hash of a given vector of bytes. It uses the OpenSSL library's SHA-256 implementation to perform the hash calculation. The resulting hash value is returned as a string.

### printResult Function

The `printResult` function is responsible for printing the smallest hash value found so far and the corresponding byte sequence. It formats the output by converting the bytes to their hexadecimal representation.

### iterateBytes Function

The `iterateBytes` function is the core of the program. It takes the latest sequence of bytes as input and starts iterating through all possible byte combinations. It compares the hash of each combination to the smallest hash value found so far and updates it if a smaller hash value is encountered. It then calls the `printResult` function to print the updated smallest hash value and the corresponding byte sequence.

### Main Function

In the `main` function, the program prompts the user to enter the latest sequence of bytes. If a previous sequence is provided, it is converted from a hexadecimal string to a vector of bytes.

The `iterateBytes` function is called with the latest sequence as the input, and the program begins the process of iterating through byte combinations and finding the smallest hash value.

Once all the byte combinations have been generated and processed, the program exits.

## Summary

This program searches for the smallest SHA-256 hash value among all possible byte sequences. It allows the user to resume the search from a provided sequence or start fresh. The program incrementally generates byte sequences, calculates their hash values, and keeps track of the smallest hash found. It demonstrates the concept of iterating through byte combinations and utilizing the SHA-256 algorithm for hashing.
