#include <sstream>
#include "Book.h"

Library::Book::Book(const std::string& title)
	: title{ title }
{
}

std::shared_ptr<Library::Book> Library::Book::CreateBook(const std::string& title)
{
	return std::make_shared<Book>(Book{ title });
}

std::string Library::Book::ToString() const noexcept
{
	return this->title;
}

bool Library::operator==(const Book& lha, const Book& rha)
{
	return lha.ToString() == rha.ToString();
}

std::wstring Library::ToString(const Book& book)
{
	auto temp = book.ToString();
	return { temp.cbegin(), temp.cend() };
}
