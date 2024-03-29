#include <iostream>
#include <fstream>
#include <vector>

int main ()
{
  std::string day {};
  std::string time {};
  std::string costumer {};
  std::string product {};
  std::string day_temp {};
  int available {1}; 
  std::vector <std::string> product_list {};
  std::vector <std::string> costumer_list {};
  
  std::ofstream newdata{"dbnew.txt"};
  std::ifstream data{"db.txt"};
  
  while ( data && newdata.is_open() )
    {
      day_temp = day;
      data >> day;
      data >> time;	
      if ( day != day_temp)
	{
	  if (product_list.size() > 1)
	    newdata << day_temp << "] " << product_list.size() << " " << costumer_list.size() << "\n";
	  product_list.clear();
	  costumer_list.clear();
	  data >> product;
	  data >> costumer;
	  product_list.push_back(product);
	  costumer_list.push_back(costumer);
	}
      else
	{
	  data >> product;
	  data >> costumer;
	  //checks the availibality of product
	  for (size_t i {}; i < product_list.size(); i ++)
	    if ( product == product_list[i] )
	      available = 0 ; 
	  if ( available == 1)
	    product_list.push_back(product);
	  available = 1 ;
	  //checks the availibality of costumer
	  for (size_t i {}; i < costumer_list.size(); i ++)
	    if ( costumer == costumer_list[i] )
	      available = 0 ; 
	  if ( available == 1)
	    costumer_list.push_back(costumer);
	  available = 1 ;
	}
    }
  newdata << day << "] " << product_list.size() << " " << costumer_list.size() << "\n";
  return 0;
}

