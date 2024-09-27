#include "Book.h"

Library::Book::Book(const std::string& title,
	std::unique_ptr<Shelf> shelf)
	: title{title}, shelf{std::move(shelf)}
{
}
