#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main(){

  std::cout << "Enter date: 07/24/2018" << std::endl;
  std::cout << "East Basin Storage: " << get_east_storage("07/24/2018") << " billion gallons" << std::endl;

  std::cout << "Enter date: 02/05/2018" << std::endl;
  std::cout << "East Basin Storage: " << get_east_storage("02/05/2018") << " billion gallons" << std::endl;

  std::cout << "Enter date: 06/12/2018" << std::endl;
  std::cout << "East Basin Storage: " << get_east_storage("06/12/2018") << " billion gallons" << std::endl;

  std::cout << "Minimum storage in the East Basin: " << get_min_east() << " billion gallons" << std::endl;
  std::cout << "Maximum storage in the East Basin: " << get_max_east() << " billion gallons" << std::endl;

  std::cout << "10/21/2018 " << compare_basins("10/21/2021") << std::endl;
  std::cout << "11/24/2018 " << compare_basins("11/24/2021") << std::endl;
  std::cout << "12/31/2018 " << compare_basins("12/31/2021") << std::endl;

  reverseorder("01/20/2018","01/31/2018");


  return 0;
}
