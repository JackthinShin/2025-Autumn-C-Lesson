/*
有序链表的各种操作
*/

#include <stdio.h>
#include <stdlib.h>

struct student {
    long num;
    float score;
    struct student *next;
};

#define LEN sizeof(struct student)

static struct student *insert(struct student *head, struct student *p) {
    if (!p) return head;
    p->next = NULL;
    if (head == NULL || p->num < head->num) {
        p->next = head;
        return p;
    }
    struct student *q = head;
    while (q->next && q->next->num < p->num) {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
    return head;
}

static struct student *del(struct student *head, long num) {
    if (head == NULL) {
        printf("List is null!\n");
        return head;
    }
    if (head->num == num) {
        struct student *tmp = head->next;
        printf("Deleted：%ld\n", num);
        free(head);
        return tmp;
    }
    struct student *prev = head;
    struct student *cur = head->next;
    while (cur && cur->num != num) {
        prev = cur;
        cur = cur->next;
    }
    if (cur) {
        printf("Deleted：%ld\n", num);
        prev->next = cur->next;
        free(cur);
    } else {
        printf("%ld not been found!\n", num);
    }
    return head;
}

static struct student *create() {
    struct student *head = NULL;
    long num; 
    float score;
    while (1) {
        scanf("%ld,%f", &num, &score);
        if (num == 0 && score == 0.0f) {
            break;
        }
        struct student *p = (struct student *)malloc(LEN);
        if (!p) {
            fprintf(stderr, "malloc failed\n");
            break;
        }
        p->num = num;
        p->score = score;
        p->next = NULL;
        head = insert(head, p);
    }
    return head;
}

static void print(struct student *head) {
    if (head == NULL) {
        printf("\nSorry! No records now!\n");
        return;
    }
    int cnt = 0; struct student *p = head;
    while (p) { cnt++; p = p->next; }
    printf("\nNow,These %d records are:\n", cnt);
    p = head;
    while (p) {
        printf("%ld  %.1f\n", p->num, p->score);
        p = p->next;
    }
}

int main() {
    struct student *head, *p;
    long del_num;
    int choice;
    printf("*****Create list!*****\n");
    printf("Please input records：(0,0 for exit)\n");
    head=create();
    print(head);
    do {
        printf("\n1. INSERT\t2. DELETE\t0. EXIT\n");
        choice=-1;
        printf("Please Choose: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Please input num and score: ");
                p=(struct student *)malloc(LEN);
                scanf("%ld,%f", &p->num, &p->score);
                head=insert(head, p);
                printf("Inserted：%ld\n", p->num);
                print(head);
                break;
            case 2:
                printf("Please input num: ");
                scanf("%ld", &del_num);
                head=del(head, del_num);
                print(head);
                break;
            case 0:
                break;
            default:
                printf("Error! Input again!\n");
                while(getchar()!='\n');
        }
    } while (choice != 0);
    return 0;
}
