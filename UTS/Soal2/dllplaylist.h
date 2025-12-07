#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <iostream>
#include <iomanip>
using namespace std;

struct Song {
    string title;
    string artist;
    int durationSec;
    int playCount;
    float rating;
    float popularityScore;
};

struct node {
    Song data;
    node* next;
    node* prev;
};

struct list {
    node* head;
    node* tail;
};

bool isEmpty(list L);
void createList(list& L);
node* allocate(string title, string artist, int durationSec, int playCount, float rating);
void deallocate(node*& P);
void insertFirst(list& L, node* P);
void insertLast(list& L, node* P);
void insertAfter(list& L, node* Q, node* P);
void insertBefore(list& L, node* Q, node* P);
void delFirst(list& L);
void delLast(list& L);
void delAfter(list& L, node* Q);
void delBefore(list& L, node* Q);
void updateAtPosition(list& L, int posisi, string title, string artist, int durationSec, int playCount, float rating);
void updateBefore(list& L, node* Q, string title, string artist, int durationSec, int playCount, float rating);
void viewList(list L);
void searchByPopularityScore(list L, float minScore, float maxScore);
float calculatePopularityScore(int playCount, float rating);

#endif