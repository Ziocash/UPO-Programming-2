#include <assert.h>
#include "playlist_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <upo/list.h>

int album_comparator(const void *a, const void *b)
{
    const entry_t aa = *(entry_t*)a;
    const entry_t bb = *(entry_t*)b;

    return strcmp(aa.album, bb.album);
}

void *create_entry(char *title, char *artist, char *album)
{
    entry_t *entry = malloc(sizeof(entry_t));
    if(entry == NULL)
    {
        perror("Error on creating entry");
        abort();
    }
    entry->album = album;
    entry->artist = artist;
    entry->title = title;
    return entry;
}

int main(void)
{
    upo_list_t list = upo_list_create(album_comparator);
    void *e1 = create_entry("Sospeso", "Francesco Ciccotti", "Unknown album");
    upo_list_append(list, e1);
    assert(upo_list_size(list) == 1);
    void *e2 = create_entry("Rema", "Calm Down", "Unknown album");
    upo_list_append(list, e2);
    assert(upo_list_size(list) == 2);
    upo_list_destroy(list, 1);
}