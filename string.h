

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

		const char*			chars();
		unsigned int		length();

		unsigned int		indexOf(const char*);

		string				substring(unsigned int);
		string				substring(unsigned int, unsigned int);

		string& operator =	(const char*);
		string& operator =	(string&);

		string& operator +=	(const char*);
		string& operator +=	(string&);

		string  operator +	(const char*);
		string  operator +	(string&);

		//operator const char* ();
	};
	
}
}
