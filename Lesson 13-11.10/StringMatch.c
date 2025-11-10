/*
字符串匹配
1）BF (Brute Force)算法
    主串（目标串）:st = "ababbab"; len1 = strlen(st);
    子串（模式串）:sp = "abb"; len2 = strlen(sp);
    for (i = 0; i <= len1 - len2; i++) {
        for (j = 0; j < len2; j++) {
            if (st[i + j] != sp[j])
                break;
        }
        if (j == len2) {
            return i;
        }
    }
    return -1;
}
*/