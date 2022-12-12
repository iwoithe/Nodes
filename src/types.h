#ifndef TYPES_H
#define TYPES_H

#include <map>
#include <string>
#include <variant>

class Variant;

class IType {};

typedef std::variant<double, float, int, IType*, std::string> VariantType;
typedef std::map<std::string, Variant> VariantMap;

class Variant
{
private:
    VariantType m_variant;
public:
    static Variant fromValue(VariantType val)
    {
        Variant v = Variant();
        v.setValue(val);
        return v;
    }
    template<typename T> static Variant fromValue(T val)
    {
        Variant v = Variant();
        v.setValue(val);
        return v;
    }
    template<typename T> T value() { return std::get<T>(m_variant); }
    template<typename T> T valueToType() { return static_cast<T>(toIType()); }
    void setValue(Variant val) { m_variant = val.variant(); };
    void setValue(VariantType val) { m_variant = val; };

    double toDouble() { return std::get<double>(m_variant); }
    float toFloat() { return std::get<float>(m_variant); }
    int toInt() { return std::get<int>(m_variant); }
    IType* toIType() { return std::get<IType*>(m_variant); }
    std::string toString() { return std::get<std::string>(m_variant); }
    VariantType variant() { return m_variant; }
};

#endif // TYPES_H
