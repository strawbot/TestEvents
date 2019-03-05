
#define RED "\x1B[1;31m"
#define GREEN "\x1B[1;32m"
#define NORMAL "\x1B[39;49m"

#ifdef __cplusplus
extern "C" {
#endif

void init_te();
extern int events, fails;
void eventTest(int n);
void predictFunction(int offset, int msecs);

#ifdef __cplusplus
}
#endif
