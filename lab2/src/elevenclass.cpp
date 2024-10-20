#include "elevenclass.hpp"
#include "vector.hpp"

Eleven::Eleven() {
    digits.resize(0);
}

unsigned long long Eleven::to_tencc() const{
    unsigned long long result = 0;
    unsigned long long pow = 1;
    for (size_t i = 0 ; i < digits.getsize(); ++i ){
        result += digits[i] * pow;
        pow *= 11;
    }
    return result;
};

void Eleven::from_tencc(unsigned long long value) {
    digits.resize(0);
    do
    {
        unsigned char digit = value % 11;
        digits.pushback(digit);
        value /= 11;
    } while (value > 0);  
}

Eleven::Eleven(const std::string& str){
    for(auto s = str.rbegin(); s != str.rend(); ++s){
        char c = *s;
        if(c >= '0' && c <= '9'){
            digits.pushback(c- '0');
        }
        else if(c == 'A'){
            digits.pushback(10);
        }
        else{
            throw std::invalid_argument("Не те буковки и циферки пишем");
        }
    }
}

Eleven Eleven::operator+(const Eleven& other) const{
    unsigned long long summa = to_tencc() + other.to_tencc();
    Eleven result;
    result.from_tencc(summa);
    return result;
}

Eleven Eleven::operator-(const Eleven& other) const{
    unsigned long long this_num = to_tencc();
    unsigned long long other_num = other.to_tencc();
    if (this_num < other_num){
        throw std::underflow_error("Нос не дорос(число больше первого)");
    }
    unsigned long long diff = this_num - other_num;
    Eleven result;
    result.from_tencc(diff);
    return result;
}

bool Eleven::operator==(const Eleven& other) const{
    return to_tencc()==other.to_tencc();
}

bool Eleven::operator!=(const Eleven& other) const{
    return to_tencc()!=other.to_tencc();
}

bool Eleven::operator>(const Eleven& other) const{
    return to_tencc()>other.to_tencc();
}

bool Eleven::operator<(const Eleven& other) const{
    return to_tencc()<other.to_tencc();
}

void Eleven::print(std::ostream& os) const {
    for (size_t i = digits.getsize(); i > 0; --i) {
        unsigned char digit = digits[i - 1];
        os << (digit < 10 ? char('0' + digit) : char('A' + (digit - 10)));
    }
    os << '\n';
}