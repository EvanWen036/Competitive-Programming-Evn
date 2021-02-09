#include "testlib.h"

#include <string>

using namespace std;

pattern pnum("0|-?[1-9][0-9]*");

bool isNumeric(const string& p)
{
    return pnum.matches(p);
}

int main(int argc, char * argv[])
{
    setName("compare two signed huge integers");
    registerTestlibCmd(argc, argv);
    
    string ja = ans.readWord();
    string pa = ouf.readWord();

    if (!isNumeric(ja))
        quitf(_fail, "0 pts");

    if (!ans.seekEof())
        quitf(_fail, "0 pts");
    
    if (!isNumeric(pa))
        quitf(_pe, "0 pts");

    if (ja != pa)
        quitf(_wa, "0 pts");
    
    quitf(_ok, "1 pt");
}