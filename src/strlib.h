//////////////////////////////////////////////////
//                                              //
//  Created by: Cziria Gergo                    //
//  Date:       2026.03.02                      //
//  Version:    V0.1                            //
//  License:    MIT                             //
//                                              //
//////////////////////////////////////////////////

/*
 *  This is my very own implementation of a string library for C.
 *  This lib will allow you to create strings dynamically, appending characters,
 *  strings, C strings and formatting strings very easly. It has a string view
 *  implementation as well. 
 * 
 *  USAGE:
 *      - create a string_t variable on the stack: string_t example;
 *      - you can initialize it with zero, or use one of the create functions to 
 *        get a fresh string container (or an already sppended one): example = string_create_str();
 *
 */


#ifndef STRLIB_H_
#define STRLIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STR_INIT_CAP 32
#define STR_GROWTH 2

typedef unsigned char byte;

typedef struct {
    byte *data;
    size_t size;
    size_t capacity;
} string_t;

typedef struct {
    byte *data;
    size_t size;
} string_view_t;

typedef struct {
    string_view_t current;
    char *delim;
} string_tok_t;

string_t        string_create(void);                                                    // Creates a string with capacity = STR_INIT_CAP and has '\0' as its first element. Actual size is 0
string_t        string_create_strf(const char *fmt, ...);                               //
string_t        string_str_from_cstr(const char *str);                                  //
string_t        string_str_from_view(string_view_t str);                                //
string_view_t   string_str_to_view(const string_t *str);                                //
string_view_t   string_cstr_to_view(const char *str);                                   //

void            string_append_ch(string_t *str, int ch);                                //
void            string_append_cstr(string_t *str, const char *cstr);                    //
void            string_append_string(string_t *str, const string_t *string);            //
void            string_append_string_view(string_t *str, string_view_t str_view);       //
void            string_append_format(string_t *str, const char *fmt, ...);              //

string_t        string_concat(string_view_t strl, string_view_t strr);                  //
void            string_flush(string_t *str);                                            //
void            string_replace(string_t *str, const int from, const int to);            //
void            string_split(string_t *str, const char *delim);                         //

size_t          string_str_len(const string_t *str);                                    //
size_t          string_view_len(const string_view_t str);                               //

void            string_tok_init(string_tok_t *tok, string_view_t input, char *delim);   //
string_view_t   string_tok_next(string_tok_t *tok);                                     //
string_view_t   string_tok_peek(string_tok_t *tok);                                     //

const byte*     string_str_get_cstr(const string_t str);                                //
const byte*     string_view_get_cstr(const string_view_t);                              //

bool            string_view_eq(const string_view_t str1, const string_view_t str2);     //
bool            string_view_empty(const string_view_t str);                             //

void            string_free(string_t *str);                                             // Frees the memory allocated to str and writes 0 to both size and capacity

#endif