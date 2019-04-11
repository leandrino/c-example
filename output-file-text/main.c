#include<stdio.h>
#include<string.h>
#include<stdlib.h>

static const char alphabet[] = "abcd";
static const int alphabet_size = sizeof(alphabet) - 1;

void brute_impl(char * str, int index, int max_depth)
{
    int i;
    for (i = 0; i < alphabet_size; ++i)
    {
        str[index] = alphabet[i];

        if (index == max_depth - 1)
        {
            printf("%s\n", str); // put check() here instead
        }
        else
        {
            brute_impl(str, index + 1, max_depth);
        }
    }
}

void brute_sequential(int max_len)
{
    /** malloc()
     *
     * The malloc() function reserves a block of memory of
     * the specified number of bytes. And, it returns a pointer
     * of type void which can be casted into pointer of any form.
     *
     */
    char * buf = malloc(max_len + 1);
    int i;

    for (i = 8; i <= max_len; ++i)
    {
        /** \brief
         *
         * memset() is used to fill a block of memory with
         * a particular value. The syntax of memset()
         * function is as follows :
         * -> ptr: Starting address of memory to be filled;
         * -> x: Value to be filled;
         * -> n: Number of bytes to be filled starting
         * ex: void *memset(void *ptr, int x, size_t n);
         */

        memset(buf, 0, max_len + 1);
        brute_impl(buf, 0, i);
    }
    /** free()
     *
     * Dynamically allocated memory created with either calloc()
     * or malloc() doesn't get freed on their own. You must
     * explicitly use free() to release the space.
     *
     */
    free(buf);
}

int main(void)
{
    freopen("output.txt","w",stdout);
    brute_sequential(8);
    return 0;
}
