// Copyright 2021 NNTU-CS

#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::string word = "";
  std::ifstream file(filename);
  BST<std::string>tree;
  while (!file.eof()) {
    char ch = file.get();
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      if (ch >= 'A' && ch <= 'Z')
        ch += 32;
      word += ch;
    } else if (word != "") {
      tree.add(word);
      word = "";
    }
  }
  file.close();
  return tree;
}
