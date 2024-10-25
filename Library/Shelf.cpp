#include "Shelf.h"

Library::Shelf::Shelf(const std::string& name)
	:name{name}
{
}

std::shared_ptr<Library::Shelf> Library::Shelf::CreateShelf(const std::string& name)
{
	return std::make_shared<Shelf>(Shelf{ name });
}

bool Library::Shelf::AddBook(const std::shared_ptr<Book>& book)
{
	this->books.push_back(book);
	book.get()->Shelf = shared_from_this();
	return true;
}

bool Library::Shelf::RemoveBook(const std::shared_ptr<Book>& book)
{
	//this->books.erase(std::remove(this->books.begin(), this->books.end(), book), this->books.end());
	book.get()->Shelf = nullptr;
	return true;
}

std::size_t Library::Shelf::BookCount() const noexcept
{
	return this->books.size();
}

std::string Library::Shelf::ToString() const noexcept
{
	return this->name;
}

bool Library::operator==(const Shelf& lha, const Shelf& rha)
{
	return lha.ToString() == rha.ToString();
}

std::wstring Library::ToString(const Shelf& shelf)
{
	auto temp = shelf.ToString();
	return { temp.cbegin(), temp.cend() };
}
