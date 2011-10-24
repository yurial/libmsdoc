#include <iostream>
using std::cout;
using std::endl;

#include "crefset.h"

using libmsdoc::internal::CRefSet;
using namespace libmsdoc;

int main()
{
typedef CRefSet<int> TSet;
TSet refset;
TSet::iterator end = refset.end();
TRef ref;
TSet::iterator it0 = refset.insert( 20 );
    {
    TSet::iterator it1 = refset.insert( 30 );
    ref = it1;
    }
TSet::iterator it2 = refset.insert( 10 );
TSet::iterator it = refset.begin();

for (; it != end; ++it)
    {
    cout << (( it == it0 )? '*' : ' ');
    cout << *it << '-' << it.id() << endl;
    }

return 0;
}

