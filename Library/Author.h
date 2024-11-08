#pragma once
#include <iostream>
#include <optional>
#include <chrono>
#include <memory>
#include <vector>
#include "Book.h"

namespace Library
{
	class Author;

	bool operator==(const Author& lha, const Author& rha);
	std::wstring ToString(const Author& author);

	class Book;

	class Author final
	{
	private:
		std::string familyName;
		std::string firstName;
		std::optional<std::string> patronymicName;
		std::string fullName;
		std::optional<std::chrono::year_month_day> birthDate;
		std::optional<std::chrono::year_month_day> deathDate;
		//std::vector<std::weak_ptr<Book>> books;
	public:
		Author(const std::string& familyName,
			const std::string& firstName,
			const std::optional<std::string>& patronymicName = std::nullopt,
			const std::optional<std::chrono::year_month_day>& birthDate = std::nullopt,
			const std::optional<std::chrono::year_month_day>& deathDate = std::nullopt);

		static std::shared_ptr<Author> CreateAuthor(
			const std::string& familyName,
			const std::string& firstName,
			const std::optional<std::string>& patronymicName = std::nullopt,
			const std::optional<std::chrono::year_month_day>& birthDate = std::nullopt,
			const std::optional<std::chrono::year_month_day>& deathDate = std::nullopt);

		std::string ToString() const;
		std::string FamilyName() const noexcept;
		std::string FirstName() const noexcept;
		std::string PatronymicName() const noexcept;
		std::string FullName() const noexcept;
	};

}

