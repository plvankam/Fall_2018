#include<cstdlib>
#include<fstream>
#include<cstdio>  // for perror()
#include<iostream>// for   cerr()


int main(int argc, char**argv)
{

    if(argc != 3) {
        std::cerr << "usage: copy FROM TO\n";
        return EXIT_FAILURE;
    }

    // open the input file
    std::ifstream in(argv[1]);
    if(!in) {
        std::perror(argv[1]);
        return EXIT_FAILURE;
    }

    // open the output file
    std::ofstream out(argv[2]);
    if(!out) {
        std::perror(argv[2]);
        return EXIT_FAILURE;
    }

    // copy the input to the
    // output file 
    // one character at a time 
    char c;
    while(in.get(c)) out.put(c);
    out.close();
    // make sure the output was written
    if(!out) {
        std::perror(argv[2]);
        return EXIT_FAILURE;
    }


    return 0;
}
