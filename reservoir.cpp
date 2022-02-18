#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

double get_east_storage(std::string date)
{
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); 
  }

  std::string junk;      
  getline(fin, junk); 

  std::string date01;
  double eastSt, eastEl, westSt, westEl;
  while(fin >> date01 >> eastSt >> eastEl >> westSt >> westEl) {
    fin.ignore(INT_MAX, '\n'); 
    if (date01 == date){
      return eastSt;
    }
  }

    fin.close();
    return eastSt;

}

double get_min_east() {
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); 
  }

  std::string junk;       
  getline(fin, junk); 

  std::string date;
  double eastSt, eastEl, westSt, westEl;
  double min = INT_MAX;
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    fin.ignore(INT_MAX, '\n'); 
    if (eastSt < min){
      min = eastSt;
  }
    }
    fin.close();
    return min;
}

double get_max_east() {
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); 
  }

  std::string junk;        
  getline(fin, junk); 

  std::string date;
  double eastSt, eastEl, westSt, westEl;
  double max = INT_MIN;
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    fin.ignore(INT_MAX, '\n'); 
    if (eastSt > max){
      max = eastSt;
    }
  }
    fin.close();
    return max;
}

double get_west_storage(std::string date){
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); 
  }

  std::string junk; 
  getline(fin, junk); 

  std::string date01;
  double eastSt, eastEl, westSt, westEl;
  while(fin >> date01 >> eastSt >> eastEl >> westSt >> westEl) {
    fin.ignore(INT_MAX, '\n'); 
    if (date01 == date){
      return westSt;
    }
  }
    fin.close();
    return westSt;
}

std::string compare_basins(std::string date)
{
	double west = get_west_storage(date);
  double east = get_east_storage(date);

    if (west > east){
      return "West";
    }
    else if (east > west){
      return "East";
    }
    else if (east == west){
      return "Equal";
    }
    return "null";
}
