#include <iostream>
#include <string>
//function definion 
//gives the sum of the ASCII values of the strings characters
int checksum (std::string word) {
  int i{0};
  //"for" loop istead of "while(true)" loop with "if" statement
  //for (int j = 0; j < static_cast<int>(word.size()); j++) {
  //  i += word[j];
  //}
  //range-based "for" loop instead of the above "for" loop
  for (auto &c : word) {
    i += c;    
  }
  return i;
}
int key_calc (int one_checksum, char one_first_char, int zero_size) {
  return ((one_checksum ^ one_first_char * 3) << (zero_size & 0x1f));
}
//var0 -> arg_num = number of arguments
//var1 -> arg_con = container with the arguments
int main(int arg_num, char *arg_con[]) {
  //define boolean variable that is True when arg_num == 3
  bool three_args {arg_num == 3};
  if (three_args) {
    std::cout << "Correct number of arguments!" << std::endl;
    //var2 -> name = name of the program (with ./ in front of it)
    std::string name{arg_con[0]};
    //var3 -> first_char_first_arg = first character of first given argument
    char first_char_first_arg{*(arg_con[1])};
    //var4 -> name_size = size of the program's name (+2 due to ./)
    auto name_size{name.size()};
    //var5 -> second_arg = integer interpretation of a string
    int second_arg{std::atoi(arg_con[2])};
    //check if the second argument is an integer number different than zero
    if (second_arg == 0) {
      std::cout << "Wrong second argument! The key must be an integer different than zero!" << std::endl;
    }
    else {
      //var6 -> first_arg_checksum = due to the use of func in a bit
      int first_arg_checksum{0};
      //var8 -> first_arg = first given argument (e.g. MNXB11)
      std::string first_arg{arg_con[1]};
      //use of the function in first_arg
      first_arg_checksum = checksum(first_arg);
      int key{0};
      key = key_calc(first_arg_checksum , first_char_first_arg , name_size);
      if (key == second_arg) {
        std::cout << "Correct key!" << std::endl;
      } else {
        std::cout << "Wrong key! The expected key is: " << key << std::endl;
      }
    }
  }
  else {
    std::cout << "Wrong number of arguments! You must give two arguments when you run the program!" << std::endl;
  }
}
