#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Book.h"

namespace Library
{
	class Book;
	class Shelf;
	bool operator==(const Shelf& lha, const Shelf& rha);
	std::wstring ToString(const Shelf& shelf);
	class Shelf final : public std::enable_shared_from_this<Shelf>
	{
	private:
		std::string name;
		std::vector <Book*> books;
	public:
		Shelf(const std::string& name);
		static std::shared_ptr<Shelf> CreateShelf(const std::string& name);
		bool AddBook(std::shared_ptr<Book> book);
		bool RemoveBook(std::shared_ptr<Book> book);
		std::size_t BookCount() const noexcept;
		std::string ToString() const;
	};
}