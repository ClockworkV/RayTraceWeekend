#pragma once

#include "vec3.h"

class ray
{
public:
	ray(const vec3& p, const vec3& v):P(p), V(v){}
	vec3 origin() const {return P;}
	vec3 direction() const {return V;}
	vec3 point_at_parameter(float t) const {return P + V * t;}

private:
	vec3 P;
	vec3 V;
};