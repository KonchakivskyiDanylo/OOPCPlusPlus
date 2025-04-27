#ifndef STRING_H
#define STRING_H

#include <string>
#include <iostream>

class String {
private:
    char* data;
    size_t length;

    void allocateAndCopy(const char* str, size_t len);

public:
    String();
    String(const char* str);
    String(const std::string& str);
    String(const String& other);
    String(String&& other) noexcept;

    ~String();

    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;
    String& operator=(const char* str);
    String& operator=(const std::string& str);

    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    operator const char* () const;
    operator std::string() const;

    bool operator==(const String& other) const;
    bool operator==(const char* str) const;
    bool operator==(const std::string& str) const;

    bool operator!=(const String& other) const;
    bool operator!=(const char* str) const;
    bool operator!=(const std::string& str) const;

    String operator+(const String& other) const;
    String operator+(const char* str) const;
    String operator+(const std::string& str) const;

    size_t size() const;
    const char* c_str() const;
    std::string str() const;

    friend std::ostream& operator<<(std::ostream& os, const String& str);
};

String operator+(const char* lhs, const String& rhs);
String operator+(const std::string& lhs, const String& rhs);

bool operator==(const char* lhs, const String& rhs);
bool operator==(const std::string& lhs, const String& rhs);

bool operator!=(const char* lhs, const String& rhs);
bool operator!=(const std::string& lhs, const String& rhs);

std::ostream& operator<<(std::ostream& os, const String& str);

#endif