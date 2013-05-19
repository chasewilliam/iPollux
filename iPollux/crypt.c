//
//  crypt.c
//  pollux
//
//  Created by Guillaume Legrain & Thibaut Vercueil on 3/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "table.h"
#include "crypt.h"

char *morse_encode(char *mess){
    char *morse_encoded;
    morse_encoded = (char *)malloc(5*strlen(mess)*sizeof(char));
    
    //Morse code alphabet translation table
    const tbl_array morse_tbl[]={
        { 'a', ".- "   },{ 'b', "-... " },{ 'c', "-.-. " },{ 'd', "-.. "  },
        { 'e', ". "    },{ 'f', "..-. " },{ 'g', "--. "  },{ 'h', ".... " },
        { 'i', ".. "   },{ 'j', ".--- " },{ 'k', ".-.- " },{ 'l', ".-.. " },
        { 'm', "-- "   },{ 'n', "-. "   },{ 'o', "--- "  },{ 'p', ".--. " },
        { 'q', "--.- " },{ 'r', ".-. "  },{ 's', "... "  },{ 't', "- "    },
        { 'u', "..- "  },{ 'v', "...- " },{ 'w', ".-- "  },{ 'x', "-..- " },
        { 'y', "-.-- " },{ 'z', "--.. " },{ '.', ".-.-.-"},{ ',', "--..--"},
        { '?', "..--.."},{  27, ".----."},{ '!', "-.-.--"},{ ' ', " "     },
        { '/', "-..-." },{ '(', "-.--." },{ ')', "-.--.-"},{ '&', ".-..." },
        { ':', "---..."},{ ';', "-.-.-."},{ '=', "-...-" },{ '+', ".-.-." },
        { '-', "-....-"},{ '_', "..--.-"},{ 92,  ".-..-."},{ '$', "...-..-"},
        { '@', ".--.-."},{ '0', "-----" },{ '1', ".----" },{ '2', "..---" },
        { '3', "...--" },{ '4', "....-" },{ '5', "....." },{ '6', "-...." },
        { '7', "--..." },{ '8', "---.." },{ '9', "----." },{ 133, ".--.-" },
        { 135, "-.-.." },{ 138, ".-..-" },{ 130, "..-.." },
    };
    
    //for each letter in the mess put the equivalent in morse code into morse_encoded
    for (int i=0; mess[i]; i++) {  //for each letter
        for (int j=0;j<sizeof(morse_tbl)/sizeof(*morse_tbl);j++) {   //with given letter find equivalent in morse
            if (tolower(mess[i]) == morse_tbl[j].letter) {
                //morse_encoded[i] = *morse_tbl[j].code;
                strcat(morse_encoded, morse_tbl[j].code); //concatenate the morse code to morse_ecoded (which may contain more than one char each time)
                break;
            }
        }
    }
    
    
    //morse_encoded morse_mess[i] .-.. --- .-. . --   .. .--. ... ..- -- ";
    return morse_encoded;
}
char *pollux_encode(char *mess,int maxes, int maxpt, int mines, int minpt) {
    
    char *codemorse2 = morse_encode(mess);
    //char codemorse2[] = ".-..- .. -......-";
    //size_t nbr2 = strlen(codemorse2);
    char *pollux;
    pollux = (char *)malloc(200*sizeof(char));
    int value;
    
    for (int j=0; codemorse2[j]; j++) {
        char signe = codemorse2[j];
        
        if (signe == '.') {
            value = rand() % maxpt + minpt;
            if (value == 1) {pollux[j]= '0';}
            if (value == 2) {pollux[j]= '3';}
            if (value == 3) {pollux[j]= '7';}
            if (value == 4) {pollux[j]= '8';}
            if (value == 5) {pollux[j]= 'A';}
            if (value == 6) {pollux[j]= 'E';}
            if (value == 7) {pollux[j]= 'F';}
            if (value == 8) {pollux[j]= 'M';}
            if (value == 9) {pollux[j]= 'O';}
            if (value == 10) {pollux[j]= 'P';}
            if (value == 11) {pollux[j]= 'Q';}
            if (value == 12) {pollux[j]= 'X';}
            if (value == 13) {pollux[j]= 'Y';}
            if (value == 14) {pollux[j]= 'Z';}
        }
        
        if (signe == '-') {
            value = rand() % maxes + mines;
            if (value== 1) {pollux[j]= '1';}
            if (value== 2) {pollux[j]= '4';}
            if (value== 3) {pollux[j]= '5';}
            if (value== 4) {pollux[j]= 'B';}
            if (value== 5) {pollux[j]= 'C';}
            if (value== 6) {pollux[j]= 'G';}
            if (value== 7) {pollux[j]= 'J';}
            if (value== 8) {pollux[j]= 'N';}
            if (value== 9) {pollux[j]= 'R';}
            if (value== 10) {pollux[j]= 'T';}
            if (value== 11) {pollux[j]= 'W';}
        }
        
        if (signe == ' ') {
            value = rand() % maxes + mines;
            if (value== 1) {pollux[j]= '2';}
            if (value== 2) {pollux[j]= '6';}
            if (value== 3) {pollux[j]= '9';}
            if (value== 4) {pollux[j]= 'D';}
            if (value== 5) {pollux[j]= 'H';}
            if (value== 6) {pollux[j]= 'I';}
            if (value== 7) {pollux[j]= 'K';}
            if (value== 8) {pollux[j]= 'L';}
            if (value== 9) {pollux[j]= 'S';}
            if (value== 10) {pollux[j]= 'U';}
            if (value== 11) {pollux[j]= 'V';}
        }
    }
    return pollux;
}