#ifndef TYPES_H
#define TYPES_H

#include "config.h"

#include <map>
#include <string>
#include <variant>

#ifdef QT_SUPPORT
#include <QMetaObject>
#include <QVariant>
#endif

class IType {};

class VersionNumber
{
private:
    int m_majorVersion = 0;
    int m_minorVersion = 0;
    int m_microVersion = 0;
    int m_tag = NONE;
public:
    VersionNumber() {}
    VersionNumber(int majorVersion) { m_majorVersion = majorVersion; }
    VersionNumber(int majorVersion, int minorVersion)
    {
        m_majorVersion = majorVersion;
        m_minorVersion = minorVersion;
    }
    VersionNumber(int majorVersion, int minorVersion, int microVersion)
    {
        m_majorVersion = majorVersion;
        m_minorVersion = minorVersion;
        m_microVersion = microVersion;
    }
    VersionNumber(int majorVersion, int minorVersion, int microVersion, int tag)
    {
        m_majorVersion = majorVersion;
        m_minorVersion = minorVersion;
        m_microVersion = microVersion;
        m_tag = tag;
    }

    enum Tag {
        NONE,
        ALPHA,
        BETA,
        RELEASE_CANDIDENT
    };

    int majorVersion() const { return m_majorVersion; }
    void setMajorVersion(int val) { m_majorVersion = val; }

    int minorVersion() const { return m_minorVersion; }
    void setMinorVersion(int val) { m_minorVersion = val; }

    int microVersion() const { return m_microVersion; }
    void setMicroVersion(int val) { m_microVersion = val; }

    int tag() const { return m_tag; }
    void setTag(int val) { m_tag = val; }

    bool operator==(const VersionNumber &other)
    {
        return majorVersion() == other.majorVersion() &&
               minorVersion() == other.minorVersion() &&
               microVersion() == other.microVersion() &&
               tag() == other.tag();
    }

    bool operator!=(const VersionNumber &other)
    {
        return majorVersion() != other.majorVersion() ||
               minorVersion() != other.minorVersion() ||
               microVersion() != other.microVersion() ||
               tag() != other.tag();
    }
};

typedef std::variant<double, float, int, IType, IType*, std::string, VersionNumber> VariantType;

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
#ifdef QT_SUPPORT
    // Unfortunately, a template has to be used here. Otherwise Qt has a massive hissy fit
    template<typename T> QVariant toQVariant() { return QVariant::fromValue<T>(m_variant); }
#endif
    std::string toString() { return std::get<std::string>(m_variant); }
    VariantType variant() { return m_variant; }
};

typedef std::map<std::string, Variant> VariantMap;

#ifdef QT_SUPPORT
Q_DECLARE_METATYPE(IType)
Q_DECLARE_METATYPE(VersionNumber)
#endif

#endif // TYPES_H
