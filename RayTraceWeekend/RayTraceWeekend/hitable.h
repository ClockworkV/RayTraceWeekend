#pragma once

#include "ray.h"

struct hit_record{
	float t;
	vec3 p;
	vec3 normal;
};

struct interval
{
	interval(float min, float max):t_min(min), t_max(max){}
	bool contains(float t){return t >= t_min && t <= t_max;}
	float t_min;
	float t_max;
};


class hitable
{
public:
	virtual bool hit(const ray& r, interval range, hit_record& rec) const = 0;
};