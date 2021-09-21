#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

const int size_buffer = 26;
int alphabet[26];
int start_alphabet = 'a';
int index_cur = 0;
int sleep_consumer = 0;

void *Producer()
{
    while (1)
    {
        if (!sleep_consumer)
            continue;

        if (index_cur != size_buffer)
        {
            alphabet[index_cur] = start_alphabet + index_cur;
            printf("Produce a char: %c\n", alphabet[index_cur++]);
        }
        else
        {
            printf("Produced all alphabet\n");
            sleep_consumer = 0;
        }
    }
}

void *Consumer()
{
    while (1)
    {
        if (sleep_consumer)
            continue;

        if (index_cur != 0)
        {
            printf("Consume a char: %c\n", alphabet[--index_cur]);
            alphabet[index_cur] = '@';
        }
        else
        {
            printf("Consumed all alphabet\n");
            sleep_consumer = 1;
        }
    }
}

int main()
{
    pthread_t first_tread;
    pthread_t second_tread;

    pthread_create(&first_tread, NULL, Producer, NULL);
    pthread_create(&second_tread, NULL, Consumer, NULL);

    pthread_join(first_tread, NULL);
    pthread_join(second_tread, NULL);

    return 0;
}