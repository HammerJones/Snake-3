#include "Location.h"

void Location::add(Location loc)
{
	x += loc.x;
	y += loc.y;
}

bool Location::equals(Location loc)
{
	if (loc.x == x && loc.y == y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Location::set(Location loc)
{
	x = loc.x;
	y = loc.y;
}
