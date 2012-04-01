#ifndef CONTAINER_H
#define CONTIANER_H


#include <string>
#include <map>

#include "structs.h"

namespace GContainer{

class BClass{
public:
  BClass(){};
  virtual ~BClass(){};
  virtual std::string getType() = 0;
private:
};

template <typename T>
class data : public BClass
{
public:
  virtual ~data(){};
  data(std::string type,T t){
    _value = t;
    _type = type;
  };
  void setVal(T t){_value = t;};
  T getVal(){return _value;};
  std::string getType(){return _type;};
private:
  std::string _type;
  T _value;
};

class Container{
public:
  Container(){};
  ~Container(){};
  bool addElement(const std::string name,
		  const std::string type,
		  const std::string value);
  BClass * getElement(const std::string name);
  bool getElement(const std::string name,
		  float &val);
  bool getElement(const std::string name,
		  int &val);
  bool getElement(const std::string name,
		  Date::date &val);
  bool getElement(const std::string name,
		  std::string &val);
  bool getElement(const std::string name,
		  bool &val);
  
 private:
  std::map<std::string,BClass *> _map;
};
} // End namespace
#endif
