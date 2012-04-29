
#include <iostream>
#include <sstream>
//#include <typeinfo>
#include "container.h"

GContainer::Container::~Container(){
  DeleteAll();
  delete _containerIterator;
  _containerIterator = NULL;
}
GContainer::Container::Container(){
  _containerIterator = NULL;
}
GContainer::Container::Container(const std::string name,
				 const std::string type,
				 const std::string value){
  this->AddElement(name,type,value);
}
GContainer::BClass * GContainer::Container::GetElement(std::string name){
  std::map<std::string, BClass *>::const_iterator Itr = _map.find(name);
  if(Itr != _map.end()){
    return Itr->second;
  }
  return NULL;
}
GContainer::ContainerIterator::ContainerIterator(std::map<std::string,BClass *> *map){
  _map = map;
}
GContainer::ContainerIterator::~ContainerIterator(){
  _map = NULL;
}
GContainer::ContainerIterator * GContainer::Container::GetIterator(){
  if(_containerIterator == NULL){

  } else {
    _containerIterator = new ContainerIterator(&_map);
  }
  return _containerIterator;
}
bool GContainer::ContainerIterator::Find(std::string name){
  iterator = _map->find(name);
  if(iterator != _map->end()){
    return true;
  } else {
    return false;
  }
}
bool GContainer::ContainerIterator::Begin(){
  iterator = _map->begin();
  if(iterator != _map->end()){
    return true;
  } else {
    return false;
  }
}
bool GContainer::ContainerIterator::Next(){
  iterator++;
  if(iterator != _map->end()){
    return true;
  } else {
    return false;
  }
}
bool GContainer::ContainerIterator::Previous(){
  iterator--;
  if(iterator != _map->end()){
    return true;
  } else {
    return false;
  }
}
bool GContainer::BClass::Contains(BClass *test){
 std::string type = this->getType();
  if(type == "string"){
    data<std::string> *rhs,*lhs;
    lhs = (data<std::string> *)(this);
    rhs = (data<std::string> *)(test);
    std::string s1 = lhs->getVal();
    std::string s2 = rhs->getVal();
    
    // TODO: add substring stuff
    return false;
    
  } else {
    return false;
  }
}
bool GContainer::BClass::operator<(BClass *test){
  std::string type = this->getType();
  if(type == "string"){
    data<std::string> *rhs,*lhs;
    lhs = (data<std::string> *)(this);
    rhs = (data<std::string> *)(test);
    return (lhs->getVal() < rhs->getVal());
  } else if (type == "float"){
    data<float> *rhs,*lhs;
    lhs = (data<float> *)(this);
    rhs = (data<float> *)(test);
    return (lhs->getVal() < rhs->getVal());
  } else if (type == "int"){
    data<int> *rhs,*lhs;
    lhs = (data<int> *)(this);
    rhs = (data<int> *)(test);
    return (lhs->getVal() < rhs->getVal());
  } else if (type == "date"){
    // data<date> *rhs,*lhs;
    // lhs = (data<date> *)(this);
    // rhs = (data<date> *)(test);
    //    return (lhs->getVal() < rhs->getVal());
    return (false);
  } else if (type == "bool"){
    data<bool> *rhs,*lhs;
    lhs = (data<bool> *)(this);
    rhs = (data<bool> *)(test);
    return (lhs->getVal() < rhs->getVal());    
  }
}
bool GContainer::BClass::operator<=(BClass *test){
  std::string type = this->getType();
  if(type == "string"){
    data<std::string> *rhs,*lhs;
    lhs = (data<std::string> *)(this);
    rhs = (data<std::string> *)(test);
    return (lhs->getVal() <= rhs->getVal());
  } else if (type == "float"){
    data<float> *rhs,*lhs;
    lhs = (data<float> *)(this);
    rhs = (data<float> *)(test);
    return (lhs->getVal() <= rhs->getVal());
  } else if (type == "int"){
    data<int> *rhs,*lhs;
    lhs = (data<int> *)(this);
    rhs = (data<int> *)(test);
    return (lhs->getVal() <= rhs->getVal());
  } else if (type == "date"){
    // data<date> *rhs,*lhs;
    // lhs = (data<date> *)(this);
    // rhs = (data<date> *)(test);
    //    return (lhs->getVal() < rhs->getVal());
    return (false);
  } else if (type == "bool"){
    data<bool> *rhs,*lhs;
    lhs = (data<bool> *)(this);
    rhs = (data<bool> *)(test);
    return (lhs->getVal() <= rhs->getVal());    
  }
}
bool GContainer::BClass::operator>(BClass *test){
  std::string type = this->getType();
  if(type == "string"){
    data<std::string> *rhs,*lhs;
    lhs = (data<std::string> *)(this);
    rhs = (data<std::string> *)(test);
    return (lhs->getVal() > rhs->getVal());
  } else if (type == "float"){
    data<float> *rhs,*lhs;
    lhs = (data<float> *)(this);
    rhs = (data<float> *)(test);
    return (lhs->getVal() > rhs->getVal());
  } else if (type == "int"){
    data<int> *rhs,*lhs;
    lhs = (data<int> *)(this);
    rhs = (data<int> *)(test);
    return (lhs->getVal() > rhs->getVal());
  } else if (type == "date"){
    // data<date> *rhs,*lhs;
    // lhs = (data<date> *)(this);
    // rhs = (data<date> *)(test);
    //    return (lhs->getVal() < rhs->getVal());
    return (false);
  } else if (type == "bool"){
    data<bool> *rhs,*lhs;
    lhs = (data<bool> *)(this);
    rhs = (data<bool> *)(test);
    return (lhs->getVal() > rhs->getVal());
  }
}
bool GContainer::BClass::operator>=(BClass *test){
  std::string type = this->getType();
  if(type == "string"){
    data<std::string> *rhs,*lhs;
    lhs = (data<std::string> *)(this);
    rhs = (data<std::string> *)(test);
    return (lhs->getVal() >= rhs->getVal());
  } else if (type == "float"){
    data<float> *rhs,*lhs;
    lhs = (data<float> *)(this);
    rhs = (data<float> *)(test);
    return (lhs->getVal() >= rhs->getVal());
  } else if (type == "int"){
    data<int> *rhs,*lhs;
    lhs = (data<int> *)(this);
    rhs = (data<int> *)(test);
    return (lhs->getVal() >= rhs->getVal());
  } else if (type == "date"){
    // data<date> *rhs,*lhs;
    // lhs = (data<date> *)(this);
    // rhs = (data<date> *)(test);
    //    return (lhs->getVal() < rhs->getVal());
    return (false);
  } else if (type == "bool"){
    data<bool> *rhs,*lhs;
    lhs = (data<bool> *)(this);
    rhs = (data<bool> *)(test);
    return (lhs->getVal() >= rhs->getVal());    
  }
}
bool GContainer::BClass::operator==(BClass *test){
  std::string type = this->getType();
  if(type == "string"){
    data<std::string> *rhs,*lhs;
    lhs = (data<std::string> *)(this);
    rhs = (data<std::string> *)(test);
    return (lhs->getVal() == rhs->getVal());
  } else if (type == "float"){
    data<float> *rhs,*lhs;
    lhs = (data<float> *)(this);
    rhs = (data<float> *)(test);
    return (lhs->getVal() == rhs->getVal());
  } else if (type == "int"){
    data<int> *rhs,*lhs;
    lhs = (data<int> *)(this);
    rhs = (data<int> *)(test);
    return (lhs->getVal() == rhs->getVal());
  } else if (type == "date"){
    // data<date> *rhs,*lhs;
    // lhs = (data<date> *)(this);
    // rhs = (data<date> *)(test);
    //    return (lhs->getVal() < rhs->getVal());
    return (false);
  } else if (type == "bool"){
    data<bool> *rhs,*lhs;
    lhs = (data<bool> *)(this);
    rhs = (data<bool> *)(test);
    return (lhs->getVal() == rhs->getVal());    
  }
}
bool GContainer::BClass::operator!=(BClass *test){
  std::string type = this->getType();
  if(type == "string"){
    data<std::string> *rhs,*lhs;
    lhs = (data<std::string> *)(this);
    rhs = (data<std::string> *)(test);
    return (lhs->getVal() != rhs->getVal());
  } else if (type == "float"){
    data<float> *rhs,*lhs;
    lhs = (data<float> *)(this);
    rhs = (data<float> *)(test);
    return (lhs->getVal() != rhs->getVal());
  } else if (type == "int"){
    data<int> *rhs,*lhs;
    lhs = (data<int> *)(this);
    rhs = (data<int> *)(test);
    return (lhs->getVal() != rhs->getVal());
  } else if (type == "date"){
    // data<date> *rhs,*lhs;
    // lhs = (data<date> *)(this);
    // rhs = (data<date> *)(test);
    //    return (lhs->getVal() < rhs->getVal());
    return (false);
  } else if (type == "bool"){
    data<bool> *rhs,*lhs;
    lhs = (data<bool> *)(this);
    rhs = (data<bool> *)(test);
    return (lhs->getVal() != rhs->getVal());    
  }
}
bool GContainer::Container::AddElement(const std::string name,
				       const std::string type,
				       const std::string value){
  std::string type_value;
  if(type == "string"     ||
     type == "str"        ||
     type == "String"     ||
     type == "STRING"     ||
     type == "std::string" ){
    type_value = "string";
    BClass *newData = new data<std::string>(type_value,value);
    _map[name] = newData;
  }
  else if(type == "int"     ||
	  type == "INT"     ||
	  type == "Int" ){
    type_value = "int";
    std::stringstream string_to_int;
    int int_val = 0;
    string_to_int << value;
    string_to_int >> int_val;
    BClass *newData = new data<int>(type_value,int_val);
    _map[name] = newData;
  }
  else if(type == "float"     ||
	  type == "FLOAT"     ||
	  type == "Float" ){
    type_value = "float";
    std::stringstream string_to_float;
    float float_val = 0;
    string_to_float << value;
    string_to_float >> float_val;
    BClass *newData = new data<float>(type_value,float_val);
    _map[name] = newData;
  }
  else if(type == "bool"     ||
	  type == "boolean"     ||
	  type == "BOOL" ){
    type_value = "bool";
    bool bool_val = false;
    if(value == "TRUE" ||
       value == "True" ||
       value == "true" ||
       value == "1"){
      bool_val = true;
    }
    BClass *newData = new data<bool>(type_value,bool_val);
    _map[name] = newData;
  }
  else if (type == "Date" ||
	   type == "date" ||
	   type == "DATE" ){
    std::string new_date = value;
    Date::date temp_date;
    memset(&temp_date,0,sizeof(temp_date));
    char *delete_me;
    char *temp = (char *) new_date.c_str();
    struct tm *tmp;
    short diff;
    time_t utc_time, local_time;
    time(&utc_time);
    tmp = gmtime(&utc_time);
    time(&local_time);
    utc_time = mktime(tmp);
    diff = (short) difftime(local_time,utc_time) / (60 * 60);
    delete_me = temp;
    char *date;
    char *time = NULL;
    int   new_int;
    int   a,b;
    date = strtok(temp,"T");
    time = strtok(NULL,"T");
    time = strtok(time,"Z");
    date = strtok(date,"-,/");
    new_int = atoi(date);
    a = 12;
    b = 1;
    if( new_int > a || new_int < b ){
      std::cout << "new_date.month = " << new_int
		<< " And is out of range. " << std::endl;
      return false;
    }
    else{
      temp_date.month = new_int;    
    }
    date = strtok(NULL,"-,/");
    temp_date.day = atoi(date);
    
    date = strtok(NULL,"-,/");
    new_int = atoi(date);
    a = 2040;
    b = 1900;
    if( new_int > a || new_int < b ){
      std::cout << "new_date.year = " << new_int
		<< " And is out of range. " << std::endl;
    }
    else{
      temp_date.year = new_int;    
    }
    if(time){
      time = strtok(time,":");
      new_int = (short) atoi(time);
      new_int += diff;
      while( new_int < 0 ){
	new_int += 24;
      }
      while( new_int > 24 ){
	new_int -= 24;
      }
      a = 24;
      b = 0;
      if( new_int > a || new_int < b ){
	std::cout << "new_date._time.hours = " << new_int
		  << " And is out of range. " << std::endl;
      }
      else{
	temp_date._time.hours = new_int;
      }
      
      time = strtok(NULL,":");
      new_int = (short) atoi(time);
      a = 60;
      b = 0;
      if( new_int > a || new_int < b ){
	std::cout << "new_date._time.minutes = " << new_int
		  << " And is out of range. " << std::endl;
      }
      else{
	temp_date._time.minutes = new_int;
      }
      
      time = strtok(NULL,":");
      new_int = (short) atoi(time);
      a = 60;
      b = 0;
      if( new_int > a || new_int < b ){
	std::cout << "new_date._time.seconds = " << new_int
		  << " And is out of range. " << std::endl;
      }
      else{
	temp_date._time.seconds = new_int;
      }
    }
    //    free(tmp);
    std::string type = "date";
    BClass *newData = new data<Date::date>(type,temp_date);
    _map[name] = newData;
    
  }
  
  return true;
}

bool GContainer::Container::GetElement(const std::string name,
				       float &val){
  std::map<std::string, BClass *>::const_iterator Itr = _map.find(name);
  if(Itr != _map.end()){
    val = ((data<float> *)Itr->second)->getVal();
    return true;
  }
  return false;
}
bool GContainer::Container::GetElement(const std::string name,
				       int &val){
  std::map<std::string, BClass *>::const_iterator Itr = _map.find(name);
  if(Itr != _map.end()){
    val = (dynamic_cast<data<int> *> (Itr->second))->getVal();
    return true;
  }
  return false;
}
bool GContainer::Container::GetElement(const std::string name,
				       Date::date &val){
  std::map<std::string, BClass *>::const_iterator Itr = _map.find(name);
  if(Itr != _map.end()){
    val = ((data<Date::date> *)Itr->second)->getVal();
    return true;
  }
  return false;
}
bool GContainer::Container::GetElement(const std::string name,
				       std::string &val){
  std::map<std::string, BClass *>::const_iterator Itr = _map.find(name);
  if(Itr != _map.end()){
    val = ((data<std::string> *)Itr->second)->getVal();
    return true;
  }
  return false;
}
bool GContainer::Container::GetElement(const std::string name,
				       bool &val){
  std::map<std::string, BClass *>::const_iterator Itr = _map.find(name);
  if(Itr != _map.end()){
    val = ((data<bool> *)Itr->second)->getVal();
    return true;
  }
  return false;
}
bool GContainer::Container::DeleteElement(const std::string name){
  std::map<std::string, BClass *>::iterator Itr = _map.find(name);
  if(Itr != _map.end()){
    _map.erase(Itr);
    delete Itr->second;
    return true;
  }
  return false;
}

template <typename T>
bool GContainer::Container::PopElement(const std::string name, T &val){
  if(GetElement(name, val)){
    if(DeleteElement(name)){
      return true;
    }
  }
  return false;
}
bool GContainer::Container::DeleteAll(){
  std::map<std::string, BClass *>::iterator Itr = _map.begin();
  for(; Itr != _map.end(); Itr++){
    delete Itr->second;
    Itr->second = NULL;
  }
}
