#include "helper.h"

int main(int argc, char *argv[])
{
    string mode = argv[1];
    vector<string> arglist(argv + 2, argv + argc);

    if(mode == "-a")
        algorithm_mode(arglist);
    else
        comparison_mode(arglist);
    return 0;
}