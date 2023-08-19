#include <upo/list.h>
#include <assert.h>
#include <string.h>

static void test_empty_list();
static void test_comparators();
static void test_insertions();


static int int_compare(const void *a, const void *b);
static int string_compare(const void *a, const void *b);

int main(void)
{
    fprintf(stdout, "Testing comparators... ");
    fflush(stdout);
    test_comparators();
    printf("OK\n");

    fprintf(stdout, "Testing empty list and null values... ");
    fflush(stdout);
    test_empty_list();
    printf("OK\n");

    fprintf(stdout, "Testing data additions... ");
    fflush(stdout);
    test_insertions();
    printf("OK\n");
}

void test_empty_list()
{
    upo_list_t list = upo_list_create(int_compare);
    upo_list_t list2 = upo_list_create(int_compare);

    assert(upo_list_is_empty(list) == 1);
    assert(upo_list_is_empty(list2) == 1);

    upo_list_destroy(list, 1);
    upo_list_destroy(list2, 0);

    list = NULL;
    list2 = NULL;

    upo_list_destroy(list, 0);
    upo_list_append(list, &"Hello");
    upo_list_insert_after(list, &"Hello", &"Hello");
    upo_list_insert_before(list, &"Hello", &"Hello");
    assert(upo_list_size(list) == 0);
    assert(upo_list_size(list2) == 0);
}

void test_insertions()
{
    upo_list_t list = upo_list_create(string_compare);

    const char* sary[] = {"Hello", "world", "Welcome", "back"};

    upo_list_insert_after(list, &sary[0], &sary[1]);
    assert(upo_list_size(list) == 1);
    upo_list_insert_before(list, &sary[1], &sary[0]);
    assert(upo_list_size(list) == 2);
    upo_list_insert_before(list, &sary[2], &sary[0]);
    assert(upo_list_size(list) == 3);

    assert(upo_list_get_value(list, 0) == &sary[1]);
    assert(upo_list_get_value(list, 1) == &sary[2]);
    assert(upo_list_get_value(list, 2) == &sary[0]);

    upo_list_destroy(list, 0);
}

void test_comparators()
{
    int a = 0;
    int b = 1;

    assert(int_compare(&a, &b) == 1);
    assert(int_compare(&a, &a) == 0);
    assert(int_compare(&b, &a) == -1);

    char *str1 = "Hello";
    char *str2 = "Hello";

    assert(string_compare(&str1, &str2) == 0);
}

int int_compare(const void *a, const void *b)
{
    const int aa = *(int *)a;
    const int bb = *(int *)b;

    return (aa < bb) - (aa > bb);
}

int string_compare(const void *a, const void *b)
{
    const char* aa = *(char**)a;
    const char* bb = *(char**)b;

    return strcmp(aa, bb);
}