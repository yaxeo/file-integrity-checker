## File Integrity Checker (C++)

This project is an educational File Integrity Checker written in C++.  
It verifies whether a file has been modified by comparing cryptographic
hashes (SHA-256) over time.

### Features
- Generates SHA-256 hashes for files
- Creates a baseline hash for integrity comparison
- Detects unauthorized file modifications
- Simple and lightweight implementation

### Security Concepts
- Cryptographic hashing
- File integrity monitoring
- Defensive security (Blue Team)
- Secure file handling in C++

### Usage
On the first run, the program creates a baseline hash.  
On subsequent runs, it compares the current hash with the baseline and
alerts if the file has been modified.

### Disclaimer
This project is for educational purposes only.
