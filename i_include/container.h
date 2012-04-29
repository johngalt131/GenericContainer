
#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <map>

#include "structs.h"

namespace GContainer{

class BClass{
public:
  BClass(){};
  bool operator<(BClass *test);
  bool operator<=(BClass *test);
  bool operator>(BClass *test);
  bool operator>=(BClass *test);
  bool operator==(BClass *test);
  bool operator!=(BClass *test);
  bool Contains(BClass *test);
  virtual ~BClass(){};
  virtual std::string getType() = 0;
private:
};

template <class T>
class data : public BClass
{
public:
  ~data(){};
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

  
class ContainerIterator{
public:
  ContainerIterator(std::map<std::string,BClass *> *map);
  ~ContainerIterator();
  bool Begin();
  bool Next();
  bool Previous();
  bool Find(std::string name);
  std::map<std::string,BClass *>::const_iterator iterator;
private:
  std::map<std::string,BClass *> *_map;
};

class Container{
public:
  Container(const std::string name,
	    const std::string type,
	    const std::string value);
  Container();
  ~Container();
  
  bool DeleteElement(const std::string name);
  bool DeleteAll();
  template <typename T>
  bool PopElement(const std::string name, T &val);

  bool AddElement(const std::string name,
		  const std::string type,
		  const std::string value);
  BClass * GetElement(const std::string name);
 
  ContainerIterator * GetIterator();
  
  // TODO: these can probably be template-ized
  bool GetElement(const std::string name,
		  float &val);
  bool GetElement(const std::string name,
		  int &val);
  bool GetElement(const std::string name,
		  Date::date &val);
  bool GetElement(const std::string name,
		  std::string &val);
  bool GetElement(const std::string name,
		  bool &val);
  
 private:
  ContainerIterator *_containerIterator;
  std::map<std::string,BClass *> _map;
};
} // End namespace
#endif
