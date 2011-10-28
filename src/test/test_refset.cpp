#include <iostream>
using std::cout;
using std::endl;

#include "ext/refset.h"

using namespace ext;

int main()
{
typedef ref::set<int> TSet;
TSet refset;
TSet::refit end = refset.end();
TSet::refit ref;
TSet::refit it0 = refset.insert( 20 ).first;
    {
    TSet::refit it1 = refset.insert( 15 ).first;
    ref = it1;
    }
TSet::iterator it2 = refset.insert( 10 ).first;
TSet::iterator it = refset.begin();

for (; it != end; ++it)
    {
    cout << (( it == it0 )? '*' : ' ');
    cout << *it << '-' << TSet::refit( it ).id() << endl;
    }

return 0;
}

