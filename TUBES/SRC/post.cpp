#include "../include/post.hpp"

PostNode* createPostNode(int id, string content) {
    PostNode* P = new PostNode;
    P->info.id = id;
    P->info.content = content;
    P->info.likes = 0;
    P->next = nullptr;
    return P;
}

void addPost(PostNode* &firstPost, int id, string content) {
    PostNode* P = createPostNode(id, content);

    if (firstPost == nullptr) {
        firstPost = P;
    } else {
        PostNode* Q = firstPost;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deletePost(PostNode* &firstPost, int id) {
    if (firstPost == nullptr) return;

    if (firstPost->info.id == id) {
        PostNode* temp = firstPost;
        firstPost = firstPost->next;
        delete temp;
        return;
    }

    PostNode* P = firstPost;
    while (P->next != nullptr && P->next->info.id != id) {
        P = P->next;
    }

    if (P->next != nullptr) {
        PostNode* temp = P->next;
        P->next = temp->next;
        delete temp;
    }
}

void viewPosts(PostNode* firstPost) {
    if (firstPost == nullptr) {
        cout << "  (Belum ada postingan)" << endl;
        return;
    }

    while (firstPost != nullptr) {
        cout << "  [" << firstPost->info.id << "] "
             << firstPost->info.content
             << " (Likes: " << firstPost->info.likes << ")" << endl;
        firstPost = firstPost->next;
    }
}

int countPosts(PostNode* firstPost) {
    int count = 0;
    while (firstPost != nullptr) {
        count++;
        firstPost = firstPost->next;
    }
    return count;
}