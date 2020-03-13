

namespace detolly {
namespace string {

#define STRING_BUFFERSIZE 32;

class string {
	private:
		unsigned long		m_bufferSize = STRING_BUFFERSIZE;
		unsigned int		m_length = 0;
		char*				m_buffer;
		//bool				m_shouldDispose = true;

		void				add(const char*);
		void				createOrExpandBufferFromChars(const char* chars);
		void				expand_buffer(int);

	public:
		string				();
		string				(const char*);
		string				(char*);
		string				(string&);

		~string				();

		const char*			chars()										const;
		unsigned int		length()									const;

		unsigned int		indexOf(const char* const)					const;

		string				substring(unsigned int)						const;
		string				substring(unsigned int, unsigned int)		const;

		string& operator =	(const char*);
		string& operator =	(string& const);

		string& operator +=	(const char*);
		string& operator +=	(string& const);

		string  operator +	(const char*);
		string  operator +	(string& const);

		//operator const char* ();
	};
	
}
}
