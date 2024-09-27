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
		std::unique_ptr<Shelf> shelf;
	public:
		Book(const std::string& title,
		std::unique_ptr<Shelf> shelf);
	};
}
