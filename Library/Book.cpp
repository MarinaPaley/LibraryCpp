#include <sstream>
#include "Book.h"
#include "Shelf.h"

Library::Book::Book(const std::string& title)
	: title{ title }
{
}

std::shared_ptr<Library::Book> Library::Book::CreateBook(const std::string& title)
{
	return std::make_shared<Book>(Book{ title });
}

bool Library::Book::ChangeShelf(std::shared_ptr<Library::Shelf>& shelf)
{
	if (this->Shelf == nullptr)
	{
		this->Shelf = shelf;
		shelf.get()->AddBook(shared_from_this());
		return true;
	}
	this->Shelf.get()->RemoveBook(shared_from_this());
	//this->Shelf.get().books.erase(std::remove(this->books.begin(), this->books.end(), book), this->books.end());
	this->Shelf = shelf;
	return false;
}

std::string Library::Book::ToString() const
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
