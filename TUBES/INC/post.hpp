#ifndef POST_HPP
#define POST_HPP

#include <iostream>
#include <string>
using namespace std;

struct Post {
    int id;
    string content;
    int likes;
};

struct PostNode {
    Post info;           // record
    PostNode* next;      // link ke post berikutnya
};

PostNode* createPostNode(int id, string content);
void addPost(PostNode* &firstPost, int id, string content);
void deletePost(PostNode* &firstPost, int id);
void viewPosts(PostNode* firstPost);
int countPosts(PostNode* firstPost);

#endif
