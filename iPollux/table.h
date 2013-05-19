//
//  table.h
//  pollux
//
//  Created by Guillaume Legrain on 3/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef pollux_table_h
#define pollux_table_h
//translation tables
typedef struct {
    const char letter;  //ex: 'A'
    const char *code;   //ex:  ".-"
} tbl_array; //ex: tbl_array morse_code[]={{'a',".-"},{'b',"-..."}}


#endif
