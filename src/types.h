#ifndef TYPES_H
#define TYPES_H

#include <map>
#include <string>
#include <variant>

typedef std::variant<double, float, int, std::string> Variant;
typedef std::map<std::string, Variant> VariantMap;

#endif // TYPES_H
