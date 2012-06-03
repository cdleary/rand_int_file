#include <cstdlib>
#include <cstdio>
#include <random>

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
        fprintf(file, "%d\n", r);
    }

    fclose(file);
    return EXIT_SUCCESS;
}
