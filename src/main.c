<<<<<<< HEAD
//__author__ = ali sadeghi
#include "include/clike.h"
=======
//__author__ = "Mehdi Mehran , Ali Sadeghi , Erfan Moghadasian , Paniz Falahati nezhad
#include "clike.h"
>>>>>>> parent of e5778b8 (include)
#include <stdio.h>


int main(int argc,char** argv) {



    if (argc>2){
        printf("plese insert input file\n\n");
        return 1;
    }
clike_compile_file(argv[1]);
return 0;
}
