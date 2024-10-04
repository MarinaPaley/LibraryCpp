#pragma once
#include <iostream>
#include <optional>
#include <chrono>

namespace Library
{
	class Author;

	bool operator==(const Author& lha, const Author& rha);
	std::wstring ToString(const Author& author);

	class Author final
	{
	private:
		std::string familyName;
		std::string firstName;
		std::optional<std::string> patronymicName;
		std::string fullName;
		std::optional<std::chrono::year_month_day> birthDate;
		std::optional<std::chrono::year_month_day> deathDate;
	public:
		Author(const std::string& familyName,
			const std::string& firstName,
			const std::optional<std::string>& patronymicName,
			const std::optional<std::chrono::year_month_day>& birthDate,
			const std::optional<std::chrono::year_month_day>& deathDate);

		std::string ToString() const;
		std::string FamilyName() const;
		std::string FirstName() const;
		std::string PatronymicName() const;
		std::string FullName() const;
	};

}

