#pragma once

#include "hitable.h"

class hitable_list : public hitable
{
public:
	hitable_list(hitable** l, int n):list(l), list_size(n){}
	bool hit(const ray& r, interval range, hit_record& rec) const override;

private:
	hitable** list;
	int list_size;
};

bool hitable_list::hit(const ray& r, interval range, hit_record& rec) const
{
	hit_record temp_rec;
	bool hit_anything = false;
	float closest_so_far = range.t_max;
	for(int i = 0; i < list_size; ++i)
	{
		if(list[i]->hit(r, {range.t_min, closest_so_far}, temp_rec))
		{
			hit_anything = true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}
	return hit_anything;
}
