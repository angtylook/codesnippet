#include <pthread.h>
#include <stdio.h>

static const char* kExtroverts[] = {
    "Albert Chon",
    "John Carlo Buenaflar",
    "Jessica Guo",
    "Sona Allahverdiyeva",
    "Yun Zhang",
    "Tagolong Introvert Jerry Cain"
};

static const size_t kNumExtroverts = sizeof(kExtroverts)/sizeof(kExtroverts[0]) - 1;

static void* recharge(void* args) {
    const char* name = kExtroverts[*(size_t*)args];
    printf("Hey, I'm %s. Empowered to meet you.\n", name);
    return NULL;
}

int main() {
    printf("Let's hear from %zu extroverts.\n", kNumExtroverts);
    pthread_t extroverts[kNumExtroverts];
    for(size_t i = 0; i < kNumExtroverts; i++)
        pthread_create(&extroverts[i], NULL, recharge, &i);
    for(size_t j = 0; j < kNumExtroverts; j++)
        pthread_join(extroverts[j], NULL);
    printf("Everyone's recharged!\n");
    return 0;
}

