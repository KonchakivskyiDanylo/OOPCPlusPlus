#include "string.h"
#include <cstring>
#include <stdexcept>

void String::allocateAndCopy(const char* str, size_t len) {
    data = new char[len + 1];
    if (str) {
        std::memcpy(data, str, len);
    }
    data[len] = '\0';
    length = len;
}

String::String() : data(nullptr), length(0) {
    allocateAndCopy("", 0);
}

String::String(const char* str) : data(nullptr), length(0) {
    if (str) {
        allocateAndCopy(str, std::strlen(str));
    }
    else {
        allocateAndCopy("", 0);
    }
}

String::String(const std::string& str) : data(nullptr), length(0) {
    allocateAndCopy(str.c_str(), str.length());
}

String::String(const String& other) : data(nullptr), length(0) {
    allocateAndCopy(other.data, other.length);
}

String::String(String&& other) noexcept : data(nullptr), length(0) {
    data = other.data;
    length = other.length;
    other.data = nullptr;
    other.length = 0;
}

String::~String() {
    delete[] data;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        allocateAndCopy(other.data, other.length);
    }
    return *this;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
    }
    return *this;
}

String& String::operator=(const char* str) {
    delete[] data;
    if (str) {
        allocateAndCopy(str, std::strlen(str));
    }
    else {
        allocateAndCopy("", 0);
    }
    return *this;
}

String& String::operator=(const std::string& str) {
    delete[] data;
    allocateAndCopy(str.c_str(), str.length());
    return *this;
}

char& String::operator[](size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const char& String::operator[](size_t index) const {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

String::operator const char* () const {
    return data;
}

String::operator std::string() const {
    return std::string(data);
}

bool String::operator==(const String& other) const {
    return std::strcmp(data, other.data) == 0;
}

bool String::operator==(const char* str) const {
    if (!str) return length == 0;
    return std::strcmp(data, str) == 0;
}

bool String::operator==(const std::string& str) const {
    return std::strcmp(data, str.c_str()) == 0;
}

bool String::operator!=(const String& other) const {
    return !(*this == other);
}

bool String::operator!=(const char* str) const {
    return !(*this == str);
}

bool String::operator!=(const std::string& str) const {
    return !(*this == str);
}

String String::operator+(const String& other) const {
    size_t newLength = length + other.length;
    char* newData = new char[newLength + 1];
    std::memcpy(newData, data, length);
    std::memcpy(newData + length, other.data, other.length);
    newData[newLength] = '\0';

    String result;
    delete[] result.data;
    result.data = newData;
    result.length = newLength;
    return result;
}

String String::operator+(const char* str) const {
    if (!str) return *this;

    size_t strLen = std::strlen(str);
    size_t newLength = length + strLen;
    char* newData = new char[newLength + 1];
    std::memcpy(newData, data, length);
    std::memcpy(newData + length, str, strLen);
    newData[newLength] = '\0';

    String result;
    delete[] result.data;
    result.data = newData;
    result.length = newLength;
    return result;
}

String String::operator+(const std::string& str) const {
    size_t strLen = str.length();
    size_t newLength = length + strLen;
    char* newData = new char[newLength + 1];
    std::memcpy(newData, data, length);
    std::memcpy(newData + length, str.c_str(), strLen);
    newData[newLength] = '\0';

    String result;
    delete[] result.data;
    result.data = newData;
    result.length = newLength;
    return result;
}

size_t String::size() const {
    return length;
}

const char* String::c_str() const {
    return data;
}

std::string String::str() const {
    return std::string(data);
}

String operator+(const char* lhs, const String& rhs) {
    if (!lhs) return rhs;

    size_t lhsLen = std::strlen(lhs);
    size_t newLength = lhsLen + rhs.size();
    char* newData = new char[newLength + 1];
    std::memcpy(newData, lhs, lhsLen);
    std::memcpy(newData + lhsLen, rhs.c_str(), rhs.size());
    newData[newLength] = '\0';

    String result;
    result = String(newData);
    delete[] newData;
    return result;
}

String operator+(const std::string& lhs, const String& rhs) {
    size_t lhsLen = lhs.length();
    size_t newLength = lhsLen + rhs.size();
    char* newData = new char[newLength + 1];
    std::memcpy(newData, lhs.c_str(), lhsLen);
    std::memcpy(newData + lhsLen, rhs.c_str(), rhs.size());
    newData[newLength] = '\0';

    String result;
    result = String(newData);
    delete[] newData;
    return result;
}

bool operator==(const char* lhs, const String& rhs) {
    return rhs == lhs;
}

bool operator==(const std::string& lhs, const String& rhs) {
    return rhs == lhs;
}

bool operator!=(const char* lhs, const String& rhs) {
    return rhs != lhs;
}

bool operator!=(const std::string& lhs, const String& rhs) {
    return rhs != lhs;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.data;
    return os;
}