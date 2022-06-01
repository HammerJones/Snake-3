#pragma once


class Location
{
public:
	int x;
	int y;

	void add(Location loc);
	bool equals(Location loc);
	void set(Location loc);
};