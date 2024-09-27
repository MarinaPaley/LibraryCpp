#pragma once
#include <string>

namespace Library
{
	class Shelf
	{
	private:
		std::string name;
	public:
		Shelf(const std::string& name);
	};
}