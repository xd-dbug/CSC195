#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

namespace mathlib {

	template<typename T>
	class Fractions {

	public:
		Fractions() : numerator(0), denominator(1) {}

		Fractions(T num, T denom) : numerator(num), denominator(denom) {
			if (denominator == 0) {
				throw invalid_argument("Denominator cannot be zero.");
			}
		}

		T getNumerator() const {
			return numerator;
		}

		T getDenominator() const {
			return denominator;
		}

		Fractions<T> operator+(const Fractions<T>& other) const {
			T num = numerator * other.denominator + other.numerator * denominator;
			T denom = denominator * other.denominator;
			return Fractions<T>(num, denom);
		}

		Fractions<T> operator-(const Fractions<T>& other) const {
			T num = numerator * other.denominator - other.numerator * denominator;
			T denom = denominator * other.denominator;
			return Fractions<T>(num, denom);
		}

		Fractions<T> operator*(const Fractions<T>& other) const {
			T num = numerator * other.numerator;
			T denom = denominator * other.denominator;
			return Fractions<T>(num, denom);
		}

		Fractions<T> operator/(const Fractions<T>& other) const {
			if (other.numerator == 0) {
				throw std::invalid_argument("Cannot divide by zero.");
			}
			T num = numerator * other.denominator;
			T denom = denominator * other.numerator;
			return Fractions<T>(num, denom);
		}

		bool operator==(const Fractions<T>& other) const {
			return (numerator * other.denominator == other.numerator * denominator);
		}
		bool operator!=(const Fractions<T>& other) const {
			return !(*this == other);
		}
		bool operator<(const Fractions<T>& other) const {
			return (numerator * other.denominator < other.numerator * denominator);
		}
		bool operator>(const Fractions<T>& other) const {
			return (numerator * other.denominator > other.numerator * denominator);
		}
		bool operator<=(const Fractions<T>& other) const {
			return (numerator * other.denominator <= other.numerator * denominator);
		}
		bool operator>=(const Fractions<T>& other) const {
			return (numerator * other.denominator >= other.numerator * denominator);
		}

		friend ostream& operator<<(ostream& os, const Fractions<T>& f) {
			os << f.numerator << "/" << f.denominator;
			return os;
		}

		friend istream& operator>>(istream& is, Fractions<T>& f) {
			char slash;
			is >> f.numerator >> slash >> f.denominator;
			if (f.denominator == 0) {
				throw std::invalid_argument("Denominator cannot be zero.");
			}
			return is;
		}

		void simplify() {
			T gcd = findGCD(numerator, denominator);
			numerator /= gcd;
			denominator /= gcd;
		}

		static T findGCD(T a, T b) {
			if constexpr (is_unsigned<T>::value || is_integral<T>::value) {
				while (b != 0) {
					T temp = b;
					b = a % b;
					a = temp;
				}
				return a;
			}
			else {
				return 1;
			}
		}

		double toDouble() const {
			return static_cast<double>(numerator) / denominator;
		}

	private:
		T numerator;
		T denominator;
	};

};
