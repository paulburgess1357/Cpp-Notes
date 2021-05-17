#pragma once
#include <iostream>
#include <string>
#include <vector>

// Simple constructor examples

class BookTracker {

public:

	// ========================== Constructors ==========================

	// Default Constructor
	BookTracker()
		:m_favorite_book{ "None" },
		m_books_read{ nullptr }{
		std::cout << "Calling Default Constructor!" << std::endl;
	}

	// Overloaded Constructor
	BookTracker(const std::string& favorite_book, const int books_read)
		:m_favorite_book{ favorite_book },
		m_books_read{ new int { books_read } }{
		std::cout << "Calling Overloaded Constructor!" << std::endl;
	}

	// Shallow Copy Constructor (Bad with pointers!!)
	// BookTracker(const BookTracker& source)
	//	 :m_favorite_book{ source.m_favorite_book },
	//      m_books_read{ source.m_books_read }{		
	// }

	// Deep Copy Constructor
	BookTracker(const BookTracker& source)
		:m_favorite_book{ source.m_favorite_book },
		m_books_read{ new int {*source.m_books_read} }{
		std::cout << "Calling Deep Copy Constructor!" << std::endl;
	}

	// Move Constructor
	BookTracker(BookTracker&& source)
		:m_favorite_book{ std::move(source.m_favorite_book) },
		m_books_read{ source.m_books_read }{
		source.m_books_read = nullptr;
		std::cout << "Calling Move Constructor!" << std::endl;
	}

	~BookTracker() {
		delete m_books_read;
	}

	// ========================== Assignment ==========================

	// Deep Copy Assignment
	BookTracker& operator=(const BookTracker& rhs) {
		std::cout << "Calling Deep Copy Assignment" << std::endl;

		if (this != &rhs) {

			// Free existing lhs resource
			delete this->m_books_read;

			// Copy data
			this->m_books_read = new int{ *rhs.m_books_read };
			this->m_favorite_book = rhs.m_favorite_book;
		}

		return *this;
	}

	// Move Assignment
	BookTracker& operator=(BookTracker&& rhs) {
		std::cout << "Calling Move Assignment" << std::endl;
		if (this != &rhs) {

			// Free existing lhs resource
			delete this->m_books_read;

			// Copy data
			this->m_books_read = rhs.m_books_read;
			this->m_favorite_book = std::move(rhs.m_favorite_book);

			// Free rhs resource
			rhs.m_books_read = nullptr;
		}

		return *this;
	}

	// Other Notes:
	// If you define assignment operators, you can use those inside move/copy
	// constructors instead of writing the code twice!	

	void summary() const {
		int books_read = 0;
		if (m_books_read != nullptr) {
			books_read = *m_books_read;
		}
		std::cout << "Favorite Book: " << m_favorite_book << " | Total Books Read: " << books_read << "\n\n" << std::endl;
	}

private:
	std::string m_favorite_book;
	int* m_books_read;
};

void run_constructor_examples() {

	std::cout << "=========================== Constructors ===========================\n" << std::endl;

	// ================= Default Constructor ================= 
	std::cout << " ========== Default ========== " << std::endl;
	const BookTracker my_default_tracker;
	my_default_tracker.summary();



	// ================ Overloaded Constructor ===============
	std::cout << " ========== Overloaded ========== " << std::endl;
	const BookTracker my_overloaded_tracker{ "Calvin & Hobbes", 10 };
	my_overloaded_tracker.summary();



	// ============ Shallow Copy Constructor (Bad) ===========
	// const BookTracker my_bad_shallow_tracker{ my_overloaded_tracker };
	// my_bad_shallow_tracker.summary();



	// ============== Deep Copy Constructor  =================
	std::cout << " ========== Deep Copy ========== " << std::endl;
	BookTracker my_deep_copy_tracker{ my_overloaded_tracker };
	my_deep_copy_tracker.summary();



	// =============== Move Constructor =======================
	std::cout << " ========== Move ========== " << std::endl;

	// Note that this will null out data in my_deep_copy_tracker
	const BookTracker my_move_tracker{ std::move(my_deep_copy_tracker) };
	my_move_tracker.summary();
	std::cout << "Object we moved from (values null): ";
	my_deep_copy_tracker.summary();

	// Move constructor used in vector
	std::vector<BookTracker> my_vector_of_trackers;
	my_vector_of_trackers.push_back(BookTracker{ "Peanuts", 20 });


	std::cout << "\n\n =========================== Assignment ===========================\n" << std::endl;

	// Deep Copy Assignment
	std::cout << " ========== Deep Copy Assignment========== " << std::endl;

	BookTracker my_tracker{ "Harry Potter", 100 };
	const BookTracker my_other_tracker{ "Dune", 3 };

	my_tracker = my_other_tracker;
	my_other_tracker.summary();
	my_tracker.summary();

	// Move Assignment
	std::cout << " ========== Move Assignment ========== " << std::endl;
	BookTracker my_new_tracker{ "Lord of the Rings", 77 };
	BookTracker my_old_tracker{ "Sword of Truth",14 };

	my_new_tracker = std::move(my_old_tracker);
	my_new_tracker.summary();
	std::cout << "Object we moved from (values null): ";
	my_old_tracker.summary();
	
}