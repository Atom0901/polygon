//
//  dialog.hpp
//  dialog
//
//  Created by Ivan Yakovenko on 15/10/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef dialog_
#define dialog_


#pragma GCC visibility push(default)

class dialog
{
public:
    dialog() {};
    void hello(const char *);
    int get_int(const char *, int size);
    float get_float(const char *, float size);
    int menu(int N);
    
};

#pragma GCC visibility pop
#endif

