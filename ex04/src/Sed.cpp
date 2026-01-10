#include "Sed.hpp"
#include <sstream>

Sed::Sed(std::string filename) : _filename(filename) {
}

Sed::~Sed() {
}

std::string Sed::_readFile(void) const {
    std::ifstream ifs(this->_filename.c_str());
    if (!ifs.is_open()) {
        std::cerr << "Error: could not open file " << this->_filename << std::endl;
        // In a real generic class we might throw, but here we just exit or return empty.
        // Returning empty might be ambiguous (empty file vs error).
        // Let's exit(1) or similar as simple error handling is permitted.
        // Better: return empty and handle it in replace?
        // Or throw invalid_argument.
        throw std::invalid_argument("File not found or unreadable");
    }
    
    std::stringstream buffer;
    buffer << ifs.rdbuf();
    ifs.close();
    return buffer.str();
}

void Sed::_writeFile(const std::string& content) const {
    std::string outFilename = this->_filename + ".replace";
    std::ofstream ofs(outFilename.c_str());
    if (!ofs.is_open()) {
        std::cerr << "Error: could not create file " << outFilename << std::endl;
        throw std::runtime_error("Could not write to output file");
    }
    ofs << content;
    ofs.close();
}

void Sed::replace(std::string s1, std::string s2) {
    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return;
    }

    std::string content;
    try {
        content = this->_readFile();
    } catch (const std::exception& e) {
        // Error already logged in _readFile if needed, or we catch here.
        return;
    }

    std::string result;
    size_t pos = 0;
    size_t matchPos = content.find(s1, pos);

    while (matchPos != std::string::npos) {
        // Append part before match
        result.append(content, pos, matchPos - pos);
        // Append replacement
        result.append(s2);
        // Advance pos
        pos = matchPos + s1.length();
        // Find next
        matchPos = content.find(s1, pos);
    }
    // Append remaining part
    result.append(content, pos, std::string::npos);

    try {
        this->_writeFile(result);
    } catch (const std::exception& e) {
        return;
    }
}
