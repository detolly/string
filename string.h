

namespace detolly {
namespace string {

#define STRING_BUFFERSIZE 32
#define STRING_INDEX_NOT_FOUND -1

class string {
	private:
		unsigned long		m_bufferSize = STRING_BUFFERSIZE;
		size_t				m_length = 0;
		char*				m_buffer;
		//bool				m_shouldDispose = true;

		void				add(const char*);
		void				createOrExpandBufferFromChars(const char* chars);
		void				expand_buffer(unsigned);

	public:
		string				();
		string				(char*);
		string				(const char*);
		string				(const string&);

		~string				();

		const char*			chars()										const;
		size_t				length()									const;

		int					indexOf(const char* const, unsigned=0)		const;

		string				substring(unsigned, unsigned=0)				const;

		string&	operator =	(const char*);
		string&	operator =	(string& const);

		string&	operator +=	(const char*);
		string&	operator +=	(string& const);

		string	operator +	(const char*)								const;
		string	operator +	(string& const)								const;

		string	operator *	(unsigned)									const;
		string&	operator *= (unsigned);

		string& operator -=	(string& const);
		string& operator -=	(const char*);

		string operator -	(string& const)								const;
		string operator -	(const char*)								const;

		//operator const char* ();
	};
	
}
}
