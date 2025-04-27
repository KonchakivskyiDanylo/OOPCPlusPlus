#include <iostream>
#include <string>
#include "string.h"

int main() {
    String s1;
    String s2("C-string test");
    std::string stdStr = "STL string test";
    String s3(stdStr);
    String s4(s2);
    String s5(std::move(String("Move constructor test")));

    std::cout << "" << std::endl;
    std::cout << "s1 (default): " << s1 << std::endl;
    std::cout << "s2 (C-string): " << s2 << std::endl;
    std::cout << "s3 (STL-string): " << s3 << std::endl;
    std::cout << "s4 (copy): " << s4 << std::endl;
    std::cout << "s5 (move): " << s5 << std::endl;

    s1 = s2;
    String s6;
    s6 = std::move(s5);
    String s7;
    s7 = "C-string assignment";
    String s8;
    s8 = stdStr;

    std::cout << "" << std::endl;
    std::cout << "s1 (copy assign): " << s1 << std::endl;
    std::cout << "s5 (after move): " << (s5.c_str() ? s5 : "empty") << std::endl;
    std::cout << "s6 (move assign): " << s6 << std::endl;
    std::cout << "s7 (C-string assign): " << s7 << std::endl;
    std::cout << "s8 (STL-string assign): " << s8 << std::endl;

    std::cout << "\n---- Access operator test ----" << std::endl;
    std::cout << "s2[0]: " << s2[0] << std::endl;
    std::cout << "s2[5]: " << s2[5] << std::endl;
    s2[0] = 'D';
    std::cout << "s2 after modification: " << s2 << std::endl;

    std::cout << "" << std::endl;
    const char* cStr = s2;
    std::string stdStr2 = s3;
    std::cout << "s2 as C-string: " << cStr << std::endl;
    std::cout << "s3 as STL-string: " << stdStr2 << std::endl;

    std::cout << "" << std::endl;
    String a("Hello");
    String b("Hello");
    String c("World");

    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != c: " << (a != c) << std::endl;
    std::cout << "a == \"Hello\": " << (a == "Hello") << std::endl;
    std::cout << "a != \"World\": " << (a != "World") << std::endl;
    std::cout << "\"Hello\" == a: " << ("Hello" == a) << std::endl;
    std::cout << "\"World\" != a: " << ("World" != a) << std::endl;

    std::string helloStd = "Hello";
    std::string worldStd = "World";
    std::cout << "a == helloStd: " << (a == helloStd) << std::endl;
    std::cout << "a != worldStd: " << (a != worldStd) << std::endl;
    std::cout << "helloStd == a: " << (helloStd == a) << std::endl;
    std::cout << "worldStd != a: " << (worldStd != a) << std::endl;

    std::cout << "" << std::endl;
    String d("Hello, ");
    String e("world!");
    String f = d + e;
    std::cout << "d + e: " << f << std::endl;

    String g = d + "universe!";
    std::cout << "d + \"universe!\": " << g << std::endl;

    std::string galaxyStd = "galaxy!";
    String h = d + galaxyStd;
    std::cout << "d + galaxyStd: " << h << std::endl;

    String i = "Greetings, " + d;
    std::cout << "\"Greetings, \" + d: " << i << std::endl;

    String j = std::string("Salutations, ") + d;
    std::cout << "std::string(\"Salutations, \") + d: " << j << std::endl;

    std::cout << "" << std::endl;
    String s1mix("Test");
    std::string s2mix = "STL";
    char* p = new char[5] {'C', 'h', 'a', 'r', '\0'};

    String res1 = s1mix + s2mix;
    String res2 = s2mix + s1mix;
    String res3 = p + s1mix;
    String res4 = s1mix + p;

    std::cout << "s1mix + s2mix: " << res1 << std::endl;
    std::cout << "s2mix + s1mix: " << res2 << std::endl;
    std::cout << "p + s1mix: " << res3 << std::endl;
    std::cout << "s1mix + p: " << res4 << std::endl;

    std::cout << "" << std::endl;
    std::cout << "s2 size: " << s2.size() << std::endl;
    std::cout << "s2 c_str: " << s2.c_str() << std::endl;
    std::cout << "s2 str: " << s2.str() << std::endl;

    delete[] p;

    return 0;
}