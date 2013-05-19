//
//  decrypt.c
//  pollux
//
//  Created by Guillaume Legrain & Thibaut Vercueil on 3/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"
#include "decrypt.h"

char *pollux_decode(char *morse_mess){
    char *symb=NULL;
    symb = (char *)malloc(400*sizeof(char));
    size_t mess_length = strlen(morse_mess);
    for (int i=0; i < mess_length ; i++) {
        if ( morse_mess[i] == '0' || morse_mess[i] == '3' || morse_mess[i] == '7' || morse_mess[i] == '8' || morse_mess[i] == 'A' || morse_mess[i] =='E' || morse_mess[i] =='F' || morse_mess[i] == 'M' ||  morse_mess[i] =='O' || morse_mess[i] =='P' || morse_mess[i] =='Q' || morse_mess[i] =='X' || morse_mess[i] =='Y' ||  morse_mess[i] =='Z') {
            symb[i]='.';}
        
        if ( morse_mess[i] == '1' || morse_mess[i] == '4' || morse_mess[i] == '5' || morse_mess[i] == 'B' || morse_mess[i] == 'C' || morse_mess[i] =='G' || morse_mess[i] =='J' || morse_mess[i] == 'N' ||  morse_mess[i] =='R' || morse_mess[i] =='T' || morse_mess[i] =='W' ) {
            symb[i]='-';}
        
        if ( morse_mess[i] == '2' || morse_mess[i] == '6' || morse_mess[i] == '9' || morse_mess[i] == 'D' || morse_mess[i] == 'H' || morse_mess[i] =='I' || morse_mess[i] =='K' || morse_mess[i] == 'L' ||  morse_mess[i] =='S' || morse_mess[i] =='U' || morse_mess[i] =='V' ) {
            symb[i]=' ';}
    }
    return symb;
}

char *strAddChar(char *s1, char c){
    char *s;
    s = s1;
    s = s + strlen(s1); // the position to write
    *s = c; // this should be on the place where the null char
    s++;
    *s = 0; // add a new null string
    return(s1);
}


char *morse_decode(char *ciph_mess){
    
    char *morse_mess = pollux_decode(ciph_mess);
    char *morse_decoded=NULL;
    morse_decoded = (char *)malloc(200*sizeof(char));
    //char *codeOfLetter;
    //codeOfLetter = (char *)malloc(6*sizeof(char));
    
    
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
    
    
    size_t i,j;
    int k=0;
    int security=0;
    size_t mess_length = strlen(morse_mess);
    for (i=0; i<mess_length; ) {
        int length_morse_tbl = sizeof(morse_tbl)/sizeof(*morse_tbl);
        for (j=0; j<sizeof(morse_tbl)/sizeof(*morse_tbl); j++) {
            size_t size = strlen(morse_tbl[j].code); 
            char* a = &morse_mess[i];
            a=a;
            int result = memcmp(morse_tbl[j].code, &morse_mess[i], size);
            if (result == 0) {
                morse_decoded[k] = morse_tbl[j].letter;
                i += size;
                k++;
                security = 0; //secure infinite loop when message can not be decoded.
                break;
            }
            security++;
            if (security > length_morse_tbl ){
                i = mess_length+1; //to get out of the loop
                break;
            }
        }
    }
    morse_decoded[k] = '\0';
    //    int l=0;
    //    for (int i=0; l<10; i++) {
    //        int j=0 ;
    //        char *temp;
    //        temp = (char *)malloc(6*sizeof(char));
    //        // temp = (char *)malloc(5*sizeof(char));
    //        while (morse_mess[i] != ' ') {
    //            //strAddChar(temp, morse_mess[j+i]);
    //            temp[j]= morse_mess[i+j];
    //            temp[strlen(temp)+1]= '\0';
    //            j++;
    //        }
    //        i+=j;
    //        if (temp[strlen(temp)-1]!= 32)
    //            temp[strlen(temp)]= 32;
    //        temp[strlen(temp)+1]= '\0';
    //        for (int k=0; k<27; k++) {
    //            char *haha = morse_tbl[k].code;
    //            int compare = strcmp(temp, haha);
    //            if (compare == 0) {
    //                morse_decoded[l] = morse_tbl[k].letter;
    //                l++;
    //                //temp="";
    //                break;
    //            }
    //        }
    //        
    //    }
    
    return morse_decoded;
    
}