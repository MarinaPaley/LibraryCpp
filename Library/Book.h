#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Shelf.h"
#include "Author.h"

namespace Library
{
	class Shelf;
	class Author;
	class Book;

	bool operator==(const Book& lha, const Book& rha);
	std::wstring ToString(const Book& book);

	class Book final : public std::enable_shared_from_this<Book>
	{
	private:
		std::string title;
		std::shared_ptr<Shelf> shelf;
		std::vector<std::shared_ptr<Author>> authors;
		Book(const std::string& title);
	public:
		
		static std::shared_ptr<Book> CreateBook(const std::string& title);
		std::shared_ptr<Shelf> Shelf;
		bool ChangeShelf(std::shared_ptr<Library::Shelf>& shelf);
		std::string ToString() const;
		std::vector<std::shared_ptr<Author>>& GetAuthors() noexcept;
		const std::vector<std::shared_ptr<Author>>& GetAuthors() const noexcept;
	};
}
