// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
BST<std::string>TREE;
char FromAToa = 'a' - 'A';
    std::string Word = "";
    std::ifstream file(filename);
if (!file) {
std::cout << "File error!" << std::endl;
return TREE;
}
while (!file.eof()) {
char Char = file.get();
if ((Char >= 'a' && Char <= 'z') || (Char >= 'A' && Char <= 'Z')) {
if (Char >= 'A' && Char <= 'Z')
Char += FromAToa;
Word += Char;
} else if (Word != "") {
TREE.add(Word);
Word = "";
}
}
file.close();
return TREE;
}
