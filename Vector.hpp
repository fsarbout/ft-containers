#pragma once

class Test
{
private:
	float _f;
	float _f2;
public:
	Test(/* args */);
	Test(float f1, float f2);
	~Test();
	operator int() const;
	int cast() const;
};