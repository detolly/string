

namespace detolly {
namespace string {

#define STRING_BUFFERSIZE 64;

class string {
	private:
		unsigned long		m_bufferSize = STRING_BUFFERSIZE;
		unsigned int		m_length = 0;
		char*				m_buffer;

		void				expand_buffer(int);
		void				add(const char*);

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

		operator const char* ();
	};
	
}
}
