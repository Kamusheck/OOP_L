#pragma once 
#include "vector.hpp"
#include <string>

class Eleven{
private:
  Vector<unsigned char> digits;
  
public:
  Eleven();
  Eleven(const Eleven& other);
  Eleven(Eleven&& other);
  Eleven& operator=(const Eleven& other);
  Eleven& operator=(Eleven&& other);
  unsigned long long to_tencc() const;
  void from_tencc(unsigned long long value) ;
  Eleven(const std::string& str);
  Eleven operator+(const Eleven& other) const;
  Eleven operator-(const Eleven& other) const;
  bool operator==(const Eleven& other) const;
  bool operator!=(const Eleven& other) const;
  bool operator<(const Eleven& other) const;
  bool operator>(const Eleven& other) const;

  void print(std::ostream& os) const;
};