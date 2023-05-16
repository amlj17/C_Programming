//
//  Compilador GTK.c
//  
//
//  Created by Andres Moguel on 4/27/21.
//

#include <stdio.h>
gcc -g -Wall -o $1 $1.c `pkg-config --cflags --libs gtk+-2.0`
