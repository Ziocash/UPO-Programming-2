#ifndef PLAYLIST_LIST_H
#define PLAYLIST_LIST_H

#include <stdio.h>

struct entry_s
{
    char *title;
    char *artist;
    char *album;
};

typedef struct entry_s entry_t;

static void *create_entry(char *title, char *artist, char *album);

static int album_comparator(const void *a, const void *b);

#endif