#pragma once
#include <string>
#include <memory>
#include "Shelf.h"
namespace Library
{
	class Book
	{
	private:
		std::string title;
		
	public:
		Book(const std::string& title);
	};
}
