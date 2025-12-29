/*
1) 删除并用 history.txt 的当前内容重建 backup.dat（backup 不包含今天内容）。
2) 将 today.txt 追加到 history.txt；相邻两篇之间必须“恰好一行空行”分隔；
3) 限定使用 fgetc/fputc 进行内容复制/追加；today.txt 末尾恰好一个换行。
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void copy_file(const char *src_path, const char *dst_path)
{
    FILE *src = fopen(src_path, "r");
    if (!src) {
        perror("无法打开源文件（history.txt）");
        exit(1);
    }
    FILE *dst = fopen(dst_path, "w");
    if (!dst) {
        perror("无法创建目标文件（backup.dat）");
        fclose(src);
        exit(1);
    }
    int ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dst);
    }
    fclose(src);
    fclose(dst);
}

int main(void)
{
    const char *path_today   = "/Users/jackthinshin/Desktop/2025 Autumn C Lesson/Lesson 27-12.29/diary/today.txt";
    const char *path_history = "/Users/jackthinshin/Desktop/2025 Autumn C Lesson/Lesson 27-12.29/diary/history.txt";
    const char *path_backup  = "/Users/jackthinshin/Desktop/2025 Autumn C Lesson/Lesson 27-12.29/backup/backup.dat";
    remove(path_backup);
    copy_file(path_history, path_backup);
    FILE *fp_history_append = fopen(path_history, "a");
    if (!fp_history_append) {
        perror("无法以追加方式打开 history.txt");
        exit(1);
    }
    fputc('\n', fp_history_append);
    FILE *fp_today = fopen(path_today, "r");
    if (!fp_today) {
        perror("无法打开 today.txt");
        fclose(fp_history_append);
        exit(1);
    }
    int ch;
    while ((ch = fgetc(fp_today)) != EOF) {
        fputc(ch, fp_history_append);
    }
    fclose(fp_today);
    fclose(fp_history_append);
    return 0;
}