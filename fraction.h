#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

template<typename numType = int, typename denomType = int>
struct fraction {
    numType numerator;
    denomType denominator;

    fraction<numType, denomType>()
        : numerator(0), denominator(0) {}

    fraction<numType, denomType>(numType numerator, denomType denominator) :
        numerator(numerator), denominator(denominator) {}

    template<typename nt, typename dt>
    fraction<numType, denomType> operator +(const fraction<nt, dt> & f) const
    {
        if (denominator == f.denominator) return fraction<numType, denomType>(numerator + f.numerator, denominator);
        return fraction<numType, denomType>(
                    (numerator * f.denominator) + (f.numerator * denominator),
                    denominator * f.denominator);
    }

    template<typename nt, typename dt>
    fraction<numType, denomType> operator -(const fraction<nt, dt> & f) const
    {
        if (denominator == f.denominator) return fraction<numType, denomType>(numerator - f.numerator, denominator);
        return fraction<numType, denomType>(
                    (numerator * f.denominator) - (f.numerator * denominator),
                    denominator * f.denominator);
    }

    template<typename nt, typename dt>
    fraction<numType, denomType> operator *(const fraction<nt, dt> & f) const
    {
        return fraction<numType, denomType>(numerator * f.numerator, denominator * f.denominator);
    }

    template<typename nt, typename dt>
    fraction<numType, denomType> operator /(const fraction<nt, dt> & f) const
    {
        return fraction<numType, denomType>(numerator * f.denominator, denominator * f.numerator);
    }

    template<typename nt, typename dt>
    fraction<numType, denomType> & operator +=(const fraction<nt, dt> & f)
    {
        if (denominator == f.denominator) numerator += f.numerator;
        else
        {
            numerator = (numerator * f.denominator) + (f.numerator * denominator);
            denominator *= f.denominator;
        }
        return *this;
    }

    template<typename nt, typename dt>
    fraction<numType, denomType> & operator -=(const fraction<nt, dt> & f)
    {
        if (denominator == f.denominator) numerator -= f.numerator;
        else
        {
            numerator = (numerator * f.denominator) - (f.numerator * denominator);
            denominator *= f.denominator;
        }
        return *this;
    }

    template<typename nt, typename dt>
    fraction<numType, denomType> & operator *=(const fraction<nt, dt> & f)
    {
        numerator *= f.numerator, denominator *= f.denominator;
        return *this;
    }

    template<typename nt, typename dt>
    fraction<numType, denomType> & operator /=(const fraction<nt, dt> & f)
    {
        numerator *= f.denominator, denominator *= f.numerator;
        return *this;
    }

    fraction<numType, denomType> operator +(const numType & value) const
    {
        return fraction<numType, denomType>(numerator + (value * denominator), denominator);
    }

    fraction<numType, denomType> operator -(const numType & value) const
    {
        return fraction<numType, denomType>(numerator - (value * denominator), denominator);
    }

    fraction<numType, denomType> operator *(const numType & value) const
    {
        return fraction<numType, denomType>(numerator * value, denominator);
    }

    fraction<numType, denomType> operator /(const denomType & value) const
    {
        return fraction<numType, denomType>(numerator, denominator * value);
    }

    fraction<numType, denomType> & operator +=(const numType & value)
    {
        numerator += value * denominator;
        return *this;
    }

    fraction<numType, denomType> & operator -=(const denomType & value)
    {
        denominator -= value * denominator;
        return *this;
    }

    fraction<numType, denomType> & operator *=(const numType & value)
    {
        numerator *= value;
        return *this;
    }

    fraction<numType, denomType> & operator /=(const denomType & value)
    {
        denominator *= value;
        return *this;
    }

    fraction<numType, denomType> operator -() const
    {
        return fraction<numType, denomType>(-numerator, denominator);
    }

    fraction<numType, denomType> & operator ++()
    {
        numerator += denominator;
        return *this;
    }

    fraction<numType, denomType> operator ++(int)
    {
        fraction<numType, denomType> tempFraction(numerator, denominator);
        numerator += denominator;
        return tempFraction;
    }

    fraction<numType, denomType> & operator --()
    {
        numerator -= denominator;
        return *this;
    }

    fraction<numType, denomType> operator --(int)
    {
        fraction<numType, denomType> tempFraction(numerator, denominator);
        numerator -= denominator;
        return tempFraction;
    }

    template<typename nt, typename dt>
    fraction<numType, denomType> & operator =(const fraction<nt, dt> & f)
    {
        numerator = f.numerator, denominator = f.denominator;
        return *this;
    }

    template<typename type>
    fraction<numType, denomType> & operator =(const type & value)
    {
        numerator = value, denominator /= denominator;
        return *this;
    }

    template<typename nt, typename dt>
    bool operator ==(const fraction<nt, dt> & f) const
    {
        return (double(numerator) / double(denominator) == double(f.numerator) / double(f.denominator));
    }

    template<typename type>
    bool operator ==(const type & value) const
    {
        return (type(numerator) / type(denominator) == value);
    }

    template<typename nt, typename dt>
    bool operator !=(const fraction<nt, dt> & f) const
    {
        return (double(numerator) / double(denominator) != double(f.numerator) / double(f.denominator));
    }

    template<typename type>
    bool operator !=(const type & value) const
    {
        return (type(numerator) / type(denominator) != value);
    }

    template<typename nt, typename dt>
    bool operator >(const fraction<nt, dt> & f) const
    {
        return (double(numerator) / double(denominator) > double(f.numerator) / double(f.denominator));
    }

    template<typename type>
    bool operator >(const type & value) const
    {
        return (type(numerator) / type(denominator) > value);
    }

    template<typename nt, typename dt>
    bool operator <(const fraction<nt, dt> & f) const
    {
        return (double(numerator) / double(denominator) < double(f.numerator) / double(f.denominator));
    }

    template<typename type>
    bool operator <(const type & value) const
    {
        return (type(numerator) / type(denominator) < value);
    }

    template<typename nt, typename dt>
    bool operator >=(const fraction<nt, dt> & f) const
    {
        return (double(numerator) / double(denominator) >= double(f.numerator) / double(f.denominator));
    }

    template<typename type>
    bool operator >=(const type & value) const
    {
        return (type(numerator) / type(denominator) >= value);
    }

    template<typename nt, typename dt>
    bool operator <=(const fraction<nt, dt> & f) const
    {
        return (double(numerator) / double(denominator) <= double(f.numerator) / double(f.denominator));
    }

    template<typename type>
    bool operator <=(const type & value) const
    {
        return (type(numerator) / type(denominator) <= value);
    }

    template<typename nt, typename dt>
    operator fraction<nt, dt>() const
    {
        return fraction<nt, dt>(numerator, denominator);
    }

    template<typename type>
    operator type() const
    {
        return type(numerator) / type(denominator);
    }
};

template<typename numType, typename denomType>
std::ostream & operator <<(std::ostream & stream, const fraction<numType, denomType> & fraction)
{
    stream << fraction.numerator << "/" << fraction.denominator;
    return stream;
}

#endif // FRACTION_H
