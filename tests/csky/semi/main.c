/*
 * Copyright (c) 2021 T-Head Semiconductor Co., Ltd. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
void test_open(void)
{
    FILE *f = fopen ("test1.txt", "w+");
    if (f == NULL) {
        printf ("open test1.txt(w+) failed.\n");
        return;
    }
    printf ("open test1.txt(w+) \t\t-------- OK.\n");
    fclose(f);

    f = fopen ("test1.txt", "r");
    if (f == NULL) {
        printf ("open test1.txt(r) failed.\n");
        return;
    }
    printf ("open test1.txt(r) \t\t-------- OK.\n");
    fclose(f);

    f = fopen ("test1.txt", "r+");
    if (f == NULL) {
        printf ("open test1.txt(r+) failed.\n");
        return;
    }
    printf ("open test1.txt(r+) \t\t-------- OK.\n");
    fclose(f);

    f = fopen ("test1.txt", "w");
    if (f == NULL) {
        printf ("open test1.txt(w) failed.\n");
        return;
    }
    printf ("open test1.txt(w) \t\t-------- OK.\n");
    fclose(f);

    f = fopen ("test1.txt", "a");
    if (f == NULL) {
        printf ("open test1.txt(a) failed.\n");
        return;
    }
    printf ("open test1.txt(a) \t\t-------- OK.\n");
    fclose(f);

    f = fopen ("test1.txt", "a+");
    if (f == NULL) {
        printf ("open test1.txt(a+) failed.\n");
        return;
    }
    printf ("open test1.txt(a+) \t\t-------- OK.\n");
    fclose(f);
}

void test_read_write (void)
{
    FILE *f = fopen ("test1.txt", "w+");
    char *text = "this string is written to a file\n";
    char buff[256];
    int ret;

    fwrite (text, strlen(text), 1, f);
    fclose(f);
    f = fopen("test1.txt", "r");
    memset(buff, 0, sizeof(buff));
    fread(buff, strlen(text), 1, f);

    if (strcmp (text, buff) == 0) {
        printf ("read write OK.\n");
    } else {
        printf ("read write failed.\n");
        printf ("Write: %s\n", text);
        printf ("Read: %s\n", buff);
    }
    ret = fseek(f, 0, SEEK_SET);
    memset(buff, 0 , sizeof(buff));
    fread(buff, strlen(text), 1, f);
    if (strcmp (text, buff) == 0) {
        printf ("fseek OK.\n");
    } else {
        printf ("fseek failed.\n");
        printf ("Write: %s\n", text);
        printf ("Read: %s\n", buff);
    }

    ret = ftell(f);
    if (ret < 0) {
        printf("ftell failed.\n");
    } else {
        printf("ftell OK.\n");
    }
    fclose (f);
}
int test_stat()
{
    int ret;
    struct stat st;
    ret = stat("test1.txt", &st);
    if (!ret) {
        printf("stat OK.\n");
    }
    return ret; 
}
int test_remove()
{
    int ret;
    ret = remove("test2.txt");
    if (!ret) {
        printf("remove OK.\n");
    }
    return ret; 
}
int test_system()
{
    int ret;
    ret = system("cp test1.txt test2.txt");
    if (!ret) {
        printf("system OK.\n");
    }
    return ret; 
}
int test_rename()
{
    int ret;
    ret = rename("test1.txt", "test3.txt");
    if (!ret) {
        printf("rename OK.\n");
    }
    return ret; 
}
int test_isatty()
{
  int ret;
  ret = isatty(0);
  if (ret == 1) {
    printf("isatty OK.\n");
  }
  return ret;
}

int test_fstat()
{
    int ret, fd;
    struct stat st;
    fd = open("test3.txt", O_RDONLY, 0644);
    ret = fstat(fd, &st);
    if (!ret) {
        printf("fstat OK.\n");
    }
    close(fd); 
    return ret;
}
int test_fscanf()
{
    char s[80] = {0};
    int ret;
    FILE *f = fopen ("test3.txt", "r+");
    if (!f) {
        printf("fscanf failed\n");
        return -1;
    }
    while(1) {
        ret = fscanf(f, "%s", s);
        if (ret == EOF) {
            goto succeed;
        }
        memset(s, 0, 80);
    }
succeed:
    printf("fscanf succeed\n");
    fclose(f);
    return ret;
}

int test_fgets()
{
    FILE *f = NULL;
    char *ret = NULL;
    char line[80] = {0};
    f = fopen("fgets.log", "r+");
    if (f = NULL) {
        printf("fgets failed\n");
        return -1;
    }
    do {
        ret = fgets(line, 80, f);
        memset(line, 0, 80);
    } while (ret != NULL);
    fclose(f);
    printf("fgets succeed\n");
    return 0;
}
int main(void)
{
    struct timeval val;
    struct stat    st;
    printf ("---------------- Semihosting Test --------------\n");
    gettimeofday(&val, NULL);
    printf("time: sizeof(timeval): %d, %d, %lld\n", sizeof(struct timeval), val.tv_sec, val.tv_usec);
    test_open ();
    test_read_write();
    test_system();
    test_stat();
    test_rename();
    test_fstat();
    test_remove();
    test_isatty();
    test_fscanf();
    test_fgets();
    printf ("--------------- Semihosting Finish --------------\n");
    exit(0);
    return 0;   
}
