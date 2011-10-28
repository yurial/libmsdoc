#ifndef EXT_ZIPH
#define EXT_ZIPH

#include "exception.h"
#include "string.h"

namespace libzip
{
#include <zip.h>
}

namespace ext
{
class zip
{
protected:
libzip::zip* m_archive;

public:
        zip() throw();
        zip(const string& filename) throw(exception);
        ~zip() throw(exception);
void    open(const string& filename) throw(exception);
void    close();

void    add_dir(const string& dirname) throw(exception);
void    add_file(const string& filename, const string& buff) throw(exception);
};

}//namespace ext

#endif

