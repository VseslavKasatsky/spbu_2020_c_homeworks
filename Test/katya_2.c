
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cleaner(const char* inf, const char* outf);

int cleaner(const char* inf, const char* outf)
{
    int i = 0, j, k, flag = 0;
    char buf[10001];
    char* str;
    const char* t = ".,;:?!()[] ";
    FILE *IN, *OUT;

    if (!(IN = fopen(inf, "r")))
        return -1;
    if (!(OUT = fopen(outf, "w"))) {
        fclose(IN);
        return -1;
    }

    while (!feof(IN)) {
        if (!(fgets(buf, 10001, IN))) {
            if (feof(IN)) {
                fclose(IN);
                fclose(OUT);
                return 0;
            }
            fclose(IN);
            fclose(OUT);
            return -2;
        }
        for (i = 0; buf[i]; i++) {
            if (buf[i] == '\n') {
                buf[i] = 0;
                break;
            }
        }
        if (!(str = (char*)malloc((i + 1) * sizeof(char)))) {
            fclose(IN);
            fclose(OUT);
            return -3;
        }
        str = strcpy(str, buf);
        for (i = 0; str[i]; i++) {
            if (!strchr(t, str[i])) {
                char* buffer = (char*)malloc(100 * sizeof(char));
                int counter = 0;
                for (j = i; str[j]; j++) {
                    if (strchr(t, str[j])) {
                        if (counter == 2) {
                            flag = 1;
                        }
                        if (counter == 3 && buffer[0] == buffer[1] && buffer[0] == buffer[2]) {
                            flag = 1;
                        }
                        if (counter >= 4 && buffer[0] == buffer[counter - 2] && buffer[1] == buffer[counter - 1]) {
                            flag = 1;
                        }
                        break;
                    }
                    buffer[counter] = str[j];
                    counter++;
                }
                free(buffer);
                if (flag == 1) {
                    for (k = i; k < j; k++)
                        fprintf(OUT, "%c", str[k]);
                    i = j - 1;
                    flag = 0;
                } else
                    i = j - 1;
            }
        }
        fprintf(OUT, "\n");
        free(str);
    }

    return 0;
}

int main(void)
{
    int res;
    res = cleaner("scanned.txt", "cleaned.txt");

    if (res == -1) {
        printf("Can not open file");
        return -1;
    }
    if (res == -2) {
        printf("Can not read");
    }
    if (res == -3) {
        printf("Not enough memory");
        return -3;
    }
    return 0;
}
