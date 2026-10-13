# CPPs05-09
C++ exercises in 42 Common Core

Exceptions:
	Instead of invalid input or mistake causing a RUNTIME error, we set up that exceptions so we can deal with them more gracefully in the program.

	An exception is for something that goes wrong while the program runs, like an invalid grade arriving from a variable. Without exceptions, the constructor has no way to say “I failed”, because constructors have no return value.

	word = "four";
	try
	{
		std::cout << word.at(4) << std::endl
	}
	catch (...) // (out_of_range& e) catches any error block
	{
		std::cout << "Caught exception!";
	}


	class exception {
		public:
			exception () throw();
			exception (const exception&) throw();
			exception& operator= (const exception&) throw();
			virtual ~exception() throw();
			virtual const char* what() const throw();
		}

		https://en.cppreference.com/cpp/error/exception/what