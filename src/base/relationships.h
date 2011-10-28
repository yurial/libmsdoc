#ifndef CRELATIONSHIPH
#define CRELATIONSHIPH

#include <list>
#include "ext/refset.h"
#include "content.h"

namespace base
{
class relationships;
class irelationship;

class relationships:
    protected ext::ref::set<irelationship*>
{
public:
typedef irelationship interface;
typedef interface* pinterface;

protected:

public:
typedef ext::ref::set<pinterface> base;
typedef base::iterator iterator;
using   base::insert;
void    save(zip& archive, const string& filename) const throw(exception);
};

class irelationship
{
protected:
relationships::iterator m_relationship;

public:
        irelationship(relationships* rels);
virtual const string    filename() const = 0;
virtual content::type   type() const = 0;
inline  int             rid() const;
};


}//namespace base

#endif

