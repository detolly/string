

namespace detolly {
namespace string {

class string {
	private:
		unsigned long		m_bufferSize = 128;
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

		string& operator =	(const char*);
		string& operator +=	(string&);
		string& operator +=	(const char*);
		string  operator +	(const char*);
		string  operator +	(string&);

		operator const char* ();
	};
	
}
}
