#define BUFFER_LENGTH 103

#ifndef STRUCTURE
#define STRUCTURE
void structure(void(*)(char(*)[]));
#endif

#ifndef PIGIFY
#define PIGIFY
void pigify(char (*)[]);
#endif

#ifndef IS_VOWEL
#define IS_VOWEL
int is_vowel(char, int);
#endif

#ifndef ANGLOFY
#define ANGLOFY
void anglofy(char (*)[]);
#endif

#ifndef PUSH
#define PUSH
void push(char (*)[], int *, const char);
#endif

#ifndef FLUSH_BUFFER
#define FLUSH_BUFFER
void flush_buffer(char(*)[], int *);
#endif

#ifndef TEST_HOOKS
#define TEST_HOOKS
int push_th();
int flush_buffer_th();
#endif
