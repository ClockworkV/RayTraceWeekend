#pragma once
#include <algorithm>
#include <numeric>

class vec3
{
public:
	vec3() = default;
	vec3(float x, float y, float z):e{x, y, z}{}
	float x(){return e[0];}
	float y(){return e[1];}
	float z(){return e[2];}
	float r(){return e[0];}
	float g(){return e[1];}
	float b(){return e[2];}

	const vec3& operator+() const {return *this;}
	vec3 operator-() const {return vec3{-e[0], -e[1], -e[2]};}
	float& operator[](int i){return e[i];}
	float operator[](int i) const {return e[i];}

	vec3& operator+=(const vec3& rhs);
	vec3& operator-=(const vec3& rhs);
	vec3& operator/=(const vec3& rhs);
	vec3& operator*=(const vec3& rhs);
	vec3& operator/=(float t);
	vec3& operator*=(float t);

	float length_squared() const;
	float length() const;

	void make_unit_length();

	static vec3 ones(){return {1.0f, 1.0f, 1.0f};}
	static vec3 zeros(){return {0.0f, 0.0f, 0.0f};}

private:
	friend std::istream& operator>>(std::istream& is, vec3& v);
	friend std::istream& operator<<(std::ostream& is, const vec3& v);
	float e[3] = {};
};


inline std::istream& operator>>(std::istream& is, vec3& v)
{
	is >> v.e[0] >> v.e[1] >> v.e[2];
	return is;
}

inline std::ostream& operator>>(std::ostream& os, const vec3& v)
{
	os << v[0] << ' ' << v[1] << ' ' << v[2];
	return os;
}


inline vec3 unit_vector(vec3 v)
{
	v.make_unit_length();
	return v;
}

inline vec3 operator+(vec3 lhs, const vec3& rhs)
{
	lhs += rhs;
	return lhs;
}

inline vec3 operator-(vec3 lhs, const vec3& rhs)
{
	lhs -= rhs;
	return lhs;
}

inline vec3 operator/(vec3 lhs, const vec3& rhs)
{
	lhs /= rhs;
	return lhs;
}

inline vec3 operator*(vec3 lhs, const vec3& rhs)
{
	lhs *= rhs;
	return lhs;
}

inline vec3 operator*(float t, vec3 v)
{
	v *= t;
	return v;
}
inline vec3 operator*(vec3 v, float t)
{
	v *= t;
	return v;
}
inline vec3 operator/(vec3 v, float t)
{
	v /= t;
	return v;
}

inline float dot(const vec3& lhs, const vec3& rhs)
{
	return lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2];
}

inline vec3 cross(const vec3& lhs, const vec3& rhs)
{
	return vec3(
		lhs[1] * rhs[2] - lhs[2] * rhs[1],
		-(lhs[0] * rhs[2] - lhs[2] * rhs[0]),
		lhs[0] * rhs[1] - lhs[1] * rhs[0]
	);
}



//= Implementations
vec3& vec3::operator+=(const vec3& rhs){
	e[0] += rhs.e[0];
	e[1] += rhs.e[1];
	e[2] += rhs.e[2];
	return *this;
}

vec3& vec3::operator-=(const vec3& rhs){
	e[0] -= rhs.e[0];
	e[1] -= rhs.e[1];
	e[2] -= rhs.e[2];
	return *this;
}

vec3& vec3::operator/=(const vec3& rhs){
	e[0] /= rhs.e[0];
	e[1] /= rhs.e[1];
	e[2] /= rhs.e[2];
	return *this;
}

vec3& vec3::operator*=(const vec3& rhs){
	e[0] *= rhs.e[0];
	e[1] *= rhs.e[1];
	e[2] *= rhs.e[2];
	return *this;
}

vec3& vec3::operator/=(float t){
	e[0] /= t;
	e[1] /= t;
	e[2] /= t;
	return *this;
}

vec3& vec3::operator*=(float t){
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}

float vec3::length_squared() const
{
	return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}
float vec3::length() const
{
	return std::sqrt(length_squared());
}

void vec3::make_unit_length()
{
	float k = 1/ length();
	(*this) *= k;
}
