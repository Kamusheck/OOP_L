#include "vector.hpp"
#include <string>

class Eleven{
private:
  Vector<unsigned char> digits;
  unsigned long long to_tencc() const;
  void from_tencc(unsigned long long value) ;
public:
  Eleven();
  Eleven(const std::string& str);
  Eleven operator+(const Eleven& other) const;
  Eleven operator-(const Eleven& other) const;
  bool operator==(const Eleven& other) const;
  bool operator!=(const Eleven& other) const;
  bool operator<(const Eleven& other) const;
  bool operator>(const Eleven& other) const;

  void print() const;

  friend std::ostream& operator<<(std::ostream& os, const Eleven& num);
};