#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reverseorder.h"

void reverseorder(std::string date1, std::string date2){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }

    std::string junk;   
    getline(fin, junk); 

    std::string date;
    double eastSt, eastEl, westSt, westEl;

    std::string array[365];
    double welevation[365];
    int j = 0;
    bool startDate = false;


    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
      fin.ignore(INT_MAX, '\n'); 
      if (date1 == date) {
        startDate = true;
      }
      if (startDate) {
        array[j] = date;
        welevation[j] = westEl;
        j++;
      }
      if (date2 == date){
        startDate = false;
      }
    }

      fin.close();
      for(int i = j - 1; i >= 0; i--){
        std::cout << array[i] << " " << welevation[i] << std::endl;
      }


  }
