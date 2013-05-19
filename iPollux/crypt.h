//
//  crypt.h
//  pollux
//
//  Created by Guillaume Legrain & Thibaut Vercueil on 3/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef pollux_crypt_h
#define pollux_crypt_h

//Will return your mess in morse code
char *morse_encode(char *mess);

//Will return your mess encrypted in pollux
char *pollux_encode(char *mess,int maxes, int maxpt, int minespt, int minpt);



#endif
