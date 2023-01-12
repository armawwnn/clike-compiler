//__author__ = "Mehdi Mehran , Ali Sadeghi , Erfan Moghadasian , Paniz Falahati nezhad
#include "include/clike.h"
#include <stdio.h>


int main(int argc,char** argv) {



    if (argc>2){
        printf("plese insert input file\n\n");
        return 1;
    }
clike_compile_file(argv[1]);
return 0;
}
