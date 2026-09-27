#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void substitute(const char* story, char nouns[][50], int* ni, char adverbs[][50], int* avi, char verbs[][50],
     int* vi, char adjectives[][50], int* aji) {
    char out[1000] = "";
    const char* p = story;
    while (*p) {
        if (strncmp(p, "[N]", 3) == 0) { strcat(out, nouns[(*ni)++]); p += 3; }
        else if (strncmp(p, "[AV]", 4) == 0) { strcat(out, adverbs[(*avi)++]); p += 4; }
        else if (strncmp(p, "[V]", 3) == 0) { strcat(out, verbs[(*vi)++]); p += 3; }
        else if (strncmp(p, "[AJ]", 4) == 0) { strcat(out, adjectives[(*aji)++]); p += 4; }
        else { int len = strlen(out); out[len] = *p; out[len+1] = '\0'; p++; }
    }
    printf("%s\n", out);
}
int main() {
    char story[1000], line[100];
    char nouns[100][50], adverbs[100][50], verbs[100][50], adjectives[100][50];
    int n_cnt = 0, av_cnt = 0, v_cnt = 0, aj_cnt = 0, mode = 0;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (!fgets(story, sizeof(story), stdin)) return 0;
    story[strcspn(story, "\r\n")] = 0;
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\r\n")] = 0;
        if (strcmp(line, "END") == 0) break;
        if (strcmp(line, "NOUNS") == 0) { mode = 1; continue; }
        if (strcmp(line, "ADVERBS") == 0) { mode = 2; continue; }
        if (strcmp(line, "VERBS") == 0) { mode = 3; continue; }
        if (strcmp(line, "ADJECTIVES") == 0) { mode = 4; continue; }
        if (mode == 1) strcpy(nouns[n_cnt++], line);
        else if (mode == 2) strcpy(adverbs[av_cnt++], line);
        else if (mode == 3) strcpy(verbs[v_cnt++], line);
        else if (mode == 4) strcpy(adjectives[aj_cnt++], line);
    }
    int ni = 0, avi = 0, vi = 0, aji = 0;
    substitute(story, nouns, &ni, adverbs, &avi, verbs, &vi, adjectives, &aji);
    substitute(story, nouns, &ni, adverbs, &avi, verbs, &vi, adjectives, &aji);
    return 0;
}
