#include <cstdlib>
#include <cstdio>
#include <random>

const char *
itoa(int32_t v)
{
    static char buf[512];

    if (0 == v) {
        buf[0] = '0';
        buf[1] = '\0';
        return buf;
    }

    bool negative = v < 0;

    size_t i = 0;
    while (0 != v) {
        int32_t q = v / 10;
        int32_t r = v % 10;
        buf[i++] = r + 0x30;
        v = q;
    }

    if (negative)
        buf[i++] = '-';

    for (size_t j = 0; j < i / 2; ++j)
        std::swap(buf[j], buf[i-j-1]);

    buf[i] = '\0';
    return buf;
}

int
main(int argc, char **argv)
{
    if (2 != argc) {
        fprintf(stderr, "Usage: %s <elem_count>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long long count = atoll(argv[1]);

    std::mt19937 rng;
    rng.seed(time(NULL));

    std::uniform_int<int32_t> dist;

    FILE *file = fopen("vec_gen.out", "w");
    if (NULL == file) {
        perror("could not open vector file for writing");
        return EXIT_FAILURE;
    }

    for (long long i = 0; i < count; ++i) {
        int32_t r = dist(rng);
        fputs(itoa(r), file);
        fputc('\n', file);
    }

    fclose(file);
    return EXIT_SUCCESS;
}
