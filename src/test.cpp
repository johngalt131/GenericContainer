#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "container.h"
typedef std::vector<GContainer::Container *> LIST;
int main(){
  static const int NUM = 100;
  LIST list;
  for (int i = 0;i < 10; i++){
    GContainer::Container *Fred = new GContainer::Container();
    for(int j = 0; j< NUM; j++){
      // Add some ints into Fred
      std::string type = "int";
      std::stringstream val;
      std::stringstream name;
      int int_val = j+12;
      val << int_val;
      name << "Int Number " << j;
      Fred->AddElement(name.str(),type,val.str());
      
      // Now add some floats
      type = "float";
      val.str("");
      name.str("");
      float float_val = (float)j+12.0;
      val << float_val;
      name << "float Number " << j;
      Fred->AddElement(name.str(),type,val.str());
      
      // Now add some string
      type = "string";
      val.str("");
      name.str("");
      std::stringstream s_val;
      s_val << "sjdkkd " << j;
      name << "String Number " << j;
      Fred->AddElement(name.str(),type,s_val.str());
      
      // Now add some string
      type = "date";
      val.str("");
      name.str("");
      std::stringstream d_val;
      d_val << "02/23/2012";
      name << "Date Number " << j;
      Fred->AddElement(name.str(),type,d_val.str());
    }
    std::string test_val;
    std::string name = "String Number 2";
    Fred->GetElement(name,test_val);
    std::cout << test_val << std::endl;
    list.push_back(Fred);
  }
}
